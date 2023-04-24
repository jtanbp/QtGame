#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QKeyEvent>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    timer(new QTimer),
    gameInfo(new QLabel(this)),
    gameWindow(new QWidget(this)),
    player(new QLabel(gameWindow)),
    idleFrameIndex(0),
    runningFrameIndex(0),
    shoutFrameIndex(0),
    jumpFrameIndex(0),
    musicNoteFrameIndex(0),
    animationTimer(new QTimer(this)),
    positionUpdateTimer(new QTimer(this)),
    movingLeft(false),
    movingRight(false),
    movingUp(false),
    movingDown(false),
    isJumping(false),
    isShouting(false),
    damageBuffer(false)
{

    setFixedSize(900, 600);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    setCentralWidget(new QWidget());
    centralWidget()->setLayout(mainLayout);

    createGameInfo();
    createGameWindow();
    createPlayer();

    mainLayout->addWidget(gameWindow);
    mainLayout->addWidget(gameInfo);

    connect(animationTimer, &QTimer::timeout, this, &MainWindow::updateAnimation);
    animationTimer->start(100);

    connect(positionUpdateTimer, &QTimer::timeout, this, &MainWindow::updatePosition);
    positionUpdateTimer->start(16); // Update the position at 60 FPS

    health = 3;
    score = 0;
    isHurt = false;
    gamePaused = false;
    healthLabel->setText(tr("Health: %1").arg(health)); // Update Health Counter on Screen
    playerScore->setText(tr("Score: %1").arg(score)); // Update Score Counter on Screen

    createEnemy();
    createBombs();
    startBombSpawning();
}

MainWindow::~MainWindow() {
    delete animationTimer;
    delete positionUpdateTimer;
    delete backgroundMovie;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->isAutoRepeat() || isShouting || isHurt) {
        return;
    }

    switch (event->key()) {
    case Qt::Key_W:
        if (isJumping) {
            return;
        }
        movingUp = true;
        break;
    case Qt::Key_A:
        movingLeft = true;
        break;
    case Qt::Key_S:
        if (isJumping) {
            return;
        }
        movingDown = true;
        break;
    case Qt::Key_D:
        movingRight = true;
        break;
    case Qt::Key_Q:
        if (!isJumping) {
            jump();
        }
        break;
    case Qt::Key_E:
        if (!isShouting) {
            shoot();
        }
        break;
    }
}


void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (event->isAutoRepeat()) {
        return;
    }

    switch (event->key()) {
    case Qt::Key_W:
        movingUp = false;
        break;
    case Qt::Key_A:
        movingLeft = false;
        //movingRight = false;
        break;
    case Qt::Key_S:
        movingDown = false;
        break;
    case Qt::Key_D:
        movingRight = false;
        //movingLeft = false;
        break;
//    case Qt::Key_E:
//        isShouting = false;
//        break;
    }
}

void MainWindow::createGameInfo() {
    QVBoxLayout *gameInfoLayout = new QVBoxLayout();
    gameInfo->setLayout(gameInfoLayout);
    gameInfo->setFixedSize(200, 600);
    gameInfo->setStyleSheet("background-color: #2E8B57;");

    QLabel *playerIcon = new QLabel();
    playerIcon->setPixmap(QPixmap(":/images/black.png"));
    playerIcon->setFixedSize(32, 32);
    playerIcon->setScaledContents(true);

    QLabel *playerName = new QLabel("Player Name");
    playerScore = new QLabel();
    healthLabel = new QLabel();

    QPushButton *leaderboardButton = new QPushButton("Leaderboard");
    QPushButton *restartButton = new QPushButton("Restart");
    QPushButton *logoutButton = new QPushButton("Log Out");

    leaderboardButton->setFocusPolicy(Qt::NoFocus);
    restartButton->setFocusPolicy(Qt::NoFocus);
    logoutButton->setFocusPolicy(Qt::NoFocus);

    gameInfoLayout->addWidget(playerIcon);
    gameInfoLayout->addWidget(playerName);
    gameInfoLayout->addWidget(playerScore);
    gameInfoLayout->addWidget(healthLabel);
    gameInfoLayout->addStretch(); // To create a gap from top and bottom
    gameInfoLayout->addWidget(leaderboardButton);
    gameInfoLayout->addWidget(restartButton);
    gameInfoLayout->addWidget(logoutButton);
}

void MainWindow::createGameWindow() {
    gameWindow->setFixedSize(680, 600);

    // Set the background using QMovie
    backgroundMovie = new QMovie(":/images/background.gif");
    QLabel *backgroundLabel = new QLabel(gameWindow);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setFixedSize(680, 600);
    backgroundLabel->setMovie(backgroundMovie);
    backgroundMovie->start();
}

void MainWindow::createPlayer() {
    int maxWidth = 0;
    int maxHeight = 0;

    for (int i = 0; i < 20; ++i) {
        QPixmap frame = QPixmap(QString(":/images/miku_idling/%1.png").arg(i));
        idleFrames.append(frame);
        maxWidth = qMax(maxWidth, frame.width());
        maxHeight = qMax(maxHeight, frame.height());
    }

    for (int i = 0; i < 8; ++i) {
        QPixmap frame = QPixmap(QString(":/images/miku_running/%1.png").arg(i));
        runningFrames.append(frame);
        maxWidth = qMax(maxWidth, frame.width());
        maxHeight = qMax(maxHeight, frame.height());
    }

    for (int i = 0; i < 8; ++i) {
        QPixmap frame = QPixmap(QString(":/images/miku_shout/%1.png").arg(i));
        shoutFrames.append(frame);
        maxWidth = qMax(maxWidth, frame.width());
        maxHeight = qMax(maxHeight, frame.height());
    }

    for (int i = 0; i < 9; ++i) {
        QPixmap frame = QPixmap(QString(":/images/miku_jump/%1.png").arg(i));
        jumpFrames.append(frame);
        maxWidth = qMax(maxWidth, frame.width());
        maxHeight = qMax(maxHeight, frame.height());
    }

    for (int i = 0; i < 18; ++i) {
        QPixmap frame = QPixmap(QString(":/images/musicnote/%1.png").arg(i));
        musicNoteFrames.append(frame);
        maxWidthNote = qMax(maxWidthNote, frame.width());
        maxHeightNote = qMax(maxHeightNote, frame.height());
    }
//     std::cout << "Number of jumpFrames: " << jumpFrames.size() << "\n";
//     std::cout << "Number of musicNoteFrames: " << musicNoteFrames.size() << "\n";

    player = new QLabel(gameWindow);
    player->setPixmap(idleFrames[idleFrameIndex]);
    player->setFixedSize(maxWidth, maxHeight);
    player->move(0, 600 - maxHeight - 200); // Set such that player model does not go above 200 pixels
}

void MainWindow::updateAnimation() {
    if (isJumping || isShouting) {
        return; // Do not update the idle or running animation if the player is jumping or shooting.
    }

    if (movingLeft || movingRight || movingUp || movingDown) {
        runningFrameIndex = (runningFrameIndex + 1) % runningFrames.size();
        player->setPixmap(runningFrames[runningFrameIndex].transformed(movingLeft ? QTransform().scale(-1, 1) : QTransform()));
    } else {
        idleFrameIndex = (idleFrameIndex + 1) % idleFrames.size();
        player->setPixmap(idleFrames[idleFrameIndex].transformed(movingLeft ? QTransform().scale(-1, 1) : QTransform()));
    }
    //player->setFixedSize(player->pixmap().size());
}

void MainWindow::updatePosition() {
    QPoint newPos = player->pos();
    int newX = newPos.x();
    int newY = newPos.y();

    if (movingLeft && newX > 0) {
            newX -= 5;
    }
    if (movingRight && newX < gameWindow->width() - player->width()) {
            newX += 5;
    }
    if (movingUp && newY > gameWindow->height() - player->height() - 200) {
            newY -= 5;
    }
    if (movingDown && newY < gameWindow->height() - player->height() - 10) {
            newY += 5;
    }

    newPos.setX(newX);
    newPos.setY(newY);
    player->move(newPos);
}

void MainWindow::jump() {
    isJumping = true;
    jumpFrameIndex = 0;
    int initialHeight = player->pos().y(); // Store the initial height when the jump starts

    QTimer *jumpTimer = new QTimer(this);
    connect(jumpTimer, &QTimer::timeout, [=]() {
        if (jumpFrameIndex < jumpFrames.size()) {
            player->setPixmap(jumpFrames[jumpFrameIndex].transformed(movingLeft ? QTransform().scale(-1, 1) : QTransform()));

            // Update the player's vertical position
            qreal t = jumpFrameIndex / qreal(jumpFrames.size() - 1);
            qreal parabolicT = -4 * t * (t - 1);
            int newY = initialHeight - parabolicT * 150; // Adjust this value to change the jump height
            player->move(player->pos().x(), newY);

            jumpFrameIndex++;
        } else {
            jumpTimer->stop();
            player->move(player->pos().x(), initialHeight); // Reset the position to the initial height when the jump ends
            isJumping = false;
            delete jumpTimer;
        }
    });

    jumpTimer->start(100); // Adjust this value to change the jump duration
}


void MainWindow::shoot() {
    isShouting = true;
    shoutFrameIndex = 0;
    std::cout << "Shout beings\n";

    QTimer *shoutTimer = new QTimer(this);
    connect(shoutTimer, &QTimer::timeout, [=]() {
        if (shoutFrameIndex < shoutFrames.size()) {
            player->setPixmap(shoutFrames[shoutFrameIndex]);

            if (shoutFrameIndex == 4) {
                std::cout << "Music Note beings\n";
                shootMusicNote();
            }

            shoutFrameIndex++;
        } else {
            shoutTimer->stop();
            isShouting = false;
            shoutFrameIndex = 0;
            delete shoutTimer;
        }
    });

    shoutTimer->start(100);
}

void MainWindow::shootMusicNote() {
    QLabel *musicNote = new QLabel(gameWindow);
    musicNote->setPixmap(musicNoteFrames[musicNoteFrameIndex]);
    musicNote->setFixedSize(41, 51);
    musicNote->move(player->x() + player->width(), player->y() + player->height() / 2 - musicNote->height() / 2);
    musicNote->show();

    musicNotes.append(musicNote);

    QTimer *musicNoteTimer = new QTimer(this);
    connect(musicNoteTimer, &QTimer::timeout, [this, musicNote, musicNoteTimer]() {
        musicNoteFrameIndex = (musicNoteFrameIndex + 1) % musicNoteFrames.size();
        musicNote->setPixmap(musicNoteFrames[musicNoteFrameIndex]);
        int newX = musicNote->x() + 5;
        if (newX > gameWindow->width()) {
            int noteIndex = musicNotes.indexOf(musicNote);
            if (noteIndex != -1) {
                QLabel *note = musicNotes[noteIndex];
                musicNotes.removeAt(noteIndex);
                musicNoteTimer->stop();
                delete musicNoteTimer;
                delete note;
            }
        } else {
            musicNote->move(newX, musicNote->y());
        }
        checkMusicCollision();
    });
    musicNoteTimer->start(16);
}


void MainWindow::checkMusicCollision() {
    if (damageBuffer) {
        return;
    }

    QRect enemyRect(enemy->pos(), enemy->size());
    //bool collision = false;
    for (int i = 0; i < musicNotes.size(); ++i) {
            QLabel *musicNote = musicNotes[i];
            if (!musicNote) {
                continue;
            }
            QRect noteRect(musicNote->pos(), musicNote->size());
            if (enemyRect.intersects(noteRect)) {
                updateScore();
                damageBuffer = true;
                QTimer::singleShot(1000, this, [this]() {
                    // After 1.5 seconds, revert back to normal
                    damageBuffer = false;
                    animationTimer->start();
                });
                //musicNotesToRemove[i] = true;
                break;
            }
    }
}

void MainWindow::removeMarkedMusicNotes() {
    for (int i = musicNotes.size() - 1; i >= 0; --i) {
            if (musicNotesToRemove[i]) {
                QLabel *musicNote = musicNotes[i];
                QTimer *timer = musicNoteAnimationTimers[i];
                QObject::disconnect(timer, nullptr, this, nullptr); // Disconnect the timer
                timer->stop();
                musicNoteAnimationTimers.removeAt(i);
                musicNotes.removeAt(i);
                musicNotesToRemove.removeAt(i);
                delete timer;
                delete musicNote;
            }
    }
}

void MainWindow::updateScore() {
    score++;
    playerScore->setText(tr("Score: %1").arg(score));
}


//void MainWindow::removeMusicNote() {
//    QTimer *timer = qobject_cast<QTimer *>(sender());
//    if (!timer) {
//            return;
//    }

//    // Find music note associated with the timer
//    int noteIndex = musicNoteAnimationTimers.indexOf(timer);
//    if (noteIndex == -1) {
//            return;
//    }

//    QLabel *note = musicNotes[noteIndex];

//    // Remove MusicNote with the Timer at index
//    musicNotes.removeAt(noteIndex);
//    musicNoteAnimationTimers.removeAt(noteIndex);
//    delete timer;
//    delete note;
//}

void MainWindow::createEnemy() {
    enemy = new QLabel(gameWindow);
    enemyPixmap = QPixmap(":/images/enemy.png").scaled(128,128,Qt::KeepAspectRatio);
    enemy->setPixmap(enemyPixmap);
    enemy->setFixedSize(enemyPixmap.size());
    enemy->move(gameWindow->width() - enemy->width(), 0);
    enemy->show();

    enemyMoveTimer = new QTimer(this);
    connect(enemyMoveTimer, &QTimer::timeout, this, &MainWindow::moveEnemy);
    enemyMoveTimer->start(100);
}

void MainWindow::moveEnemy() {
    int maxY = gameWindow->height() - 150 - enemy->height(); // maximum vertical position of pixmap
    int newY = (maxY * (1 + qSin(QTime::currentTime().msecsSinceStartOfDay() * 0.001))) / 2;
    enemy->move(gameWindow->width() - enemy->width(), newY + 150);
}

void MainWindow::createBombs() {
    for (int i = 0; i < 3; ++i) {
            QPixmap bombPixmap = QPixmap(QString(":/images/bomb/%1.png").arg(i)).scaled(32,32,Qt::KeepAspectRatio);
            bombPixmaps.append(bombPixmap);
    }
}

void MainWindow::spawnBomb() {
    QLabel *bomb = new QLabel(gameWindow);
    if (!bomb) {
            qWarning("Failed to create bomb QLabel");
            return;
    }
    bomb->setPixmap(bombPixmaps[rand() % bombPixmaps.size()]);
    bomb->setFixedSize(32, 32);
    bomb->move(gameWindow->width() - bomb->width() - enemy->width(), enemy->y() + enemy->height() / 2 - bomb->height() / 2);
    bomb->show();
    bombs.append(bomb);

    QTimer *bombPositionTimer = new QTimer(this);
    bombAnimationTimers.append(bombPositionTimer);
    connect(bombPositionTimer, &QTimer::timeout, [this, bomb]() {
        int newX = bomb->x() - 5;
        if (newX + bomb->width() < 0) {
            QTimer *timer = qobject_cast<QTimer *>(sender());
            int bombIndex = bombAnimationTimers.indexOf(timer);
            if (bombIndex != -1) {
                bombs.removeAt(bombIndex);
                bombAnimationTimers.removeAt(bombIndex);
                delete timer;
                delete bomb;
            }
        } else {
            bomb->move(newX, bomb->y());
        }
        checkCollisions();
    });
    bombPositionTimer->start(16);
}


void MainWindow::startBombSpawning() {
    bombSpawnTimer = new QTimer(this);
    connect(bombSpawnTimer, &QTimer::timeout, this, &MainWindow::spawnBomb);
    bombSpawnTimer->start(1000); // Adjust this value to change the bomb spawn rate
}

void MainWindow::stopBombSpawning() {
    bombSpawnTimer->stop();
    delete bombSpawnTimer;
}

void MainWindow::checkCollisions() {
    if (isHurt || !player) {
            return;
    }

    QRect playerRect(player->pos().x() + player->width()/2, player->pos().y() + player->height()/2, 35, 45);

    for (int i = 0; i < bombs.size(); ++i) {
        QLabel *bomb = bombs[i];
        if (!bomb) {
            continue;
        }
        QRect bombRect(bomb->pos().x(), bomb->pos().y(), 20, 20);
        if (playerRect.intersects(bombRect)) {
            hurtPlayer();
            //QLabel *bomb = bombs[i];
            bombs.removeAt(i);
            bombAnimationTimers[i]->stop();
            bombAnimationTimers.removeAt(i);
            delete bomb;
            break;
        }
    }
}


void MainWindow::hurtPlayer() {
    std::cout << "Player is hurt\n";
    if (isHurt) {
            return;
    }

    isHurt = true;
    movingLeft = false;
    movingRight = false;
    movingUp = false;
    movingDown = false;
    health--;

    QPixmap originalPixmap = player->pixmap(); // Save the original pixmap
    player->setPixmap(QPixmap(QString(":/images/miku_die/0.png")));
    animationTimer->stop();

    QTimer::singleShot(1500, this, [this, originalPixmap]() {
        // After 1.5 seconds, revert back to normal
        player->setPixmap(originalPixmap);
        isHurt = false;
        animationTimer->start();
    });

    healthLabel->setText(tr("Health: %1").arg(health));

    if (health <= 0) {
            animationTimer->stop();
            movingLeft = false;
            movingRight = false;
            movingUp = false;
            movingDown = false;
            player->setPixmap(QPixmap(QString(":/images/miku_die/2.png")));
            pauseGame();
            QMessageBox::StandardButton reply;
            reply = QMessageBox::information(this, tr("Game Over"), tr("You have lost all your lives!"));
            if (reply == QMessageBox::Ok) {
                restartGame();
            }
    }
}



void MainWindow::pauseGame() {
    gamePaused = !gamePaused;

    if (gamePaused) {
            enemyMoveTimer->stop();
            bombSpawnTimer->stop();
//            for (QTimer *timer : bombSpawnTimer) {
//            timer->stop();
//            }
    } else {
            enemyMoveTimer->start();
            bombSpawnTimer->start();
//            for (QTimer *timer : bombSpawnTimer) {
//            timer->start();
//            }
    }
}

void MainWindow::restartGame() {
    // Remove all bombs on the screen
    for (QLabel *bomb : bombs) {
            delete bomb;
    }
    bombs.clear();

    // Reset health
    health = 3;
    healthLabel->setText(tr("Health: %1").arg(health));
}


