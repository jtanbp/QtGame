#include "gamewindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QKeyEvent>
#include <iostream>

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent),
    gameInfo(new QLabel(this)),
    gameWindow(new QWidget(this)),
    player(new QLabel(gameWindow)),
    difficulty(difficulty_easy),
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

    connect(animationTimer, &QTimer::timeout, this, &GameWindow::updateAnimation);
    //animationTimer->start(100);

    connect(positionUpdateTimer, &QTimer::timeout, this, &GameWindow::updatePosition);
    //positionUpdateTimer->start(16); // Update the position at 60 FPS

//    health = 3;
//    score = 0;
//    healthLabel->setText(tr("Health: %1").arg(health));
//    playerScore->setText(tr("Score: %1").arg(score));
//    gamePaused = false;

    isHurt = false;

    createEnemy();
    createBombs();
    restartGame();
    //startBombSpawning();
}

GameWindow::~GameWindow() {
    delete animationTimer;
    delete positionUpdateTimer;
    delete backgroundMovie;
}

void GameWindow::keyPressEvent(QKeyEvent *event) {
    if (event->isAutoRepeat() || isShouting || isHurt || gamePaused) {
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

void GameWindow::keyReleaseEvent(QKeyEvent *event) {
    if (event->isAutoRepeat()) {
        return;
    }

    switch (event->key()) {
    case Qt::Key_W:
        movingUp = false;
        break;
    case Qt::Key_A:
        movingLeft = false;
        break;
    case Qt::Key_S:
        movingDown = false;
        break;
    case Qt::Key_D:
        movingRight = false;
        break;
    }
}

void GameWindow::createGameInfo() {
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

void GameWindow::createGameWindow() {
    gameWindow->setFixedSize(680, 600);

    // Set the background using QMovie
    backgroundMovie = new QMovie(":/images/background.gif");
    QLabel *backgroundLabel = new QLabel(gameWindow);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setFixedSize(680, 600);
    backgroundLabel->setMovie(backgroundMovie);
    backgroundMovie->start();
}

void GameWindow::createPlayer() {
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

    player = new QLabel(gameWindow);
    player->setPixmap(idleFrames[idleFrameIndex]);
    player->setFixedSize(maxWidth, maxHeight);
    //player->move(0, 600 - maxHeight - 200); // Set such that player model does not go above 200 pixels
}

void GameWindow::updateAnimation() {
    if (isJumping || isShouting || gamePaused) {
        return; // Do not update the idle or running animation if the player is jumping or shooting.
    }

    if (movingLeft || movingRight || movingUp || movingDown) {
        runningFrameIndex = (runningFrameIndex + 1) % runningFrames.size();
        player->setPixmap(runningFrames[runningFrameIndex].transformed(movingLeft ? QTransform().scale(-1, 1) : QTransform()));
    } else {
        idleFrameIndex = (idleFrameIndex + 1) % idleFrames.size();
        player->setPixmap(idleFrames[idleFrameIndex].transformed(movingLeft ? QTransform().scale(-1, 1) : QTransform()));
    }
}

void GameWindow::updatePosition() {
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

void GameWindow::jump() {
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

// Enter Animation to Shout, only on the 4th frame the Music Note appears
void GameWindow::shoot() {
    isShouting = true;
    shoutFrameIndex = 0;

    QTimer *shoutTimer = new QTimer(this);
    connect(shoutTimer, &QTimer::timeout, [=]() {
        if (shoutFrameIndex < shoutFrames.size()) {
            player->setPixmap(shoutFrames[shoutFrameIndex]);

            if (shoutFrameIndex == 4) {
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

    shoutTimer->start(50); // set how fast to shout.
}

void GameWindow::shootMusicNote() {
    QLabel *musicNote = new QLabel(gameWindow);
    musicNote->setPixmap(musicNoteFrames[musicNoteFrameIndex]);
    musicNote->setFixedSize(41, 51);
    musicNote->move(player->x() + player->width(), player->y() + player->height() / 2 - musicNote->height() / 2);
    musicNote->show();

    musicNotes.append(musicNote);

    QTimer *musicNoteTimer = new QTimer(this);
    musicNoteAnimationTimers.append(musicNoteTimer);
    connect(musicNoteTimer, &QTimer::timeout, [this, musicNote, musicNoteTimer]() {
        musicNoteFrameIndex = (musicNoteFrameIndex + 1) % musicNoteFrames.size();
        musicNote->setPixmap(musicNoteFrames[musicNoteFrameIndex]);
        int newX = musicNote->x() + 5;
        if (newX > gameWindow->width() || gamePaused) { //if gamePaused remove all musicNotes
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

void GameWindow::checkMusicCollision() {
    if (damageBuffer) {
        return;
    }

    QRect enemyRect(enemy->pos(), enemy->size());

    for (int i = 0; i < musicNotes.size(); ++i) {
            QLabel *musicNote = musicNotes[i];
            if (!musicNote) {
                continue;
            }
            QRect noteRect(musicNote->pos(), musicNote->size());
            if (enemyRect.intersects(noteRect)) {
                updateScore();
//                damageBuffer = true;
//                musicNotes.removeAt(i);
//                //QTimer* musicTimer =
//                musicNoteAnimationTimers[i]->stop();
//                //musicTimer->stop();
//                //delete musicTimer;
//                musicNoteAnimationTimers.removeAt(i);
//                delete musicNote;

//                QTimer::singleShot(1000, this, [this]() {
//                    // For 1 seconds, prevent further damage on the enemy
//                    damageBuffer = false;
//                });

                break;
            }
    }
}

void GameWindow::updateScore() {
    score = score + difficulty;
    playerScore->setText(tr("Score: %1").arg(score));
}

void GameWindow::createEnemy() {
    enemy = new QLabel(gameWindow);
    enemyPixmap = QPixmap(":/images/enemy.png").scaled(128,128,Qt::KeepAspectRatio);
    enemy->setPixmap(enemyPixmap);
    enemy->setFixedSize(enemyPixmap.size());
    enemy->move(gameWindow->width() - enemy->width(), 0);
    enemy->show();

    enemyMoveTimer = new QTimer(this);
    connect(enemyMoveTimer, &QTimer::timeout, this, &GameWindow::moveEnemy);
    //enemyMoveTimer->start(100);
}

// Function to move enemy in a specific parabola that is similar to the Sine wave
void GameWindow::moveEnemy() {
    int maxY = gameWindow->height() - 150 - enemy->height(); // maximum vertical position of pixmap
    int newY = (maxY * (1 + qSin(QTime::currentTime().msecsSinceStartOfDay() * 0.001))) / 2;
    enemy->move(gameWindow->width() - enemy->width(), newY + 150);
}

// Function to add all bombs images to a list of Pixmaps (intended to have 3 different bombs)
void GameWindow::createBombs() {
    for (int i = 0; i < 3; ++i) {
            QPixmap bombPixmap = QPixmap(QString(":/images/bomb/%1.png").arg(i)).scaled(32,32,Qt::KeepAspectRatio);
            bombPixmaps.append(bombPixmap);
    }
}

void GameWindow::spawnBomb() {
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
        if (newX + bomb->width() < 0 || gamePaused) { //if game is paused, remove all bombs
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

void GameWindow::clearBombs() {
    for (int i = bombs.size() - 1; 0 < bombs.size(); i--) {
        QLabel *bomb = bombs[i];
        if (!bomb) {
                return;
        }
        bombs.removeAt(i);
        bombAnimationTimers[i]->stop();
        bombAnimationTimers.removeAt(i);
        delete bomb;
    }
}

void GameWindow::startBombSpawning() {
    bombSpawnTimer = new QTimer(this);
    connect(bombSpawnTimer, &QTimer::timeout, this, &GameWindow::spawnBomb);
    int spawnrate = 1000;

    switch (difficulty) {
    case difficulty_easy:
        spawnrate = 1000;
        break;
    case difficulty_medium:
        spawnrate = 500;
        break;
    case difficulty_hard:
        spawnrate = 250;
        break;
    }

    bombSpawnTimer->start(spawnrate); // Adjust this value to change the bomb spawn rate
}

void GameWindow::stopBombSpawning() {
    if (bombSpawnTimer) {
        bombSpawnTimer->stop();
        delete bombSpawnTimer;
        bombSpawnTimer = nullptr;
    }
}

void GameWindow::checkCollisions() {
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
            bombs.removeAt(i);
            bombAnimationTimers[i]->stop();
            bombAnimationTimers.removeAt(i);
            delete bomb;

            hurtPlayer();
            break;
        }
    }
}

void GameWindow::hurtPlayer() {
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
        if (!gamePaused) {
            animationTimer->start();
        }
    });

    healthLabel->setText(tr("Health: %1").arg(health));

    // Game ends when health is 0
    if (health <= 0) {
            pauseGame();
            movingLeft = false;
            movingRight = false;
            movingUp = false;
            movingDown = false;


            player->setPixmap(QPixmap(QString(":/images/miku_die/2.png")));

            QMessageBox::StandardButton reply;
            reply = QMessageBox::information(this, tr("Game Over"), tr("You have lost all your lives!"));
            if (reply == QMessageBox::Ok) {
                restartGame();
            }
    }
}

void GameWindow::pauseGame() {
    gamePaused = true;
    enemyMoveTimer->stop();
    stopBombSpawning();
    clearBombs();
    animationTimer->stop();
    positionUpdateTimer->stop();
}

void GameWindow::restartGame() {
    // Reset health
    health = 3;
    healthLabel->setText(tr("Health: %1").arg(health));
    score = 0;
    playerScore->setText(tr("Score: %1").arg(score));
    enemyMoveTimer->start(100);
    startBombSpawning();
    animationTimer->start(100);
    positionUpdateTimer->start(16);
    player->move(0, 600 - 200);
    gamePaused = false;
}


