#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QtWidgets>
#include <QLabel>
#include <QTimer>
#include <QPixmap>
#include <QMovie>
#include "bomb.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer *timer;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private slots:
    void updateAnimation();
    void removeMusicNote();

private:
    QLabel *gameInfo;
    QWidget *gameWindow;
    QMovie *backgroundMovie;
    QLabel *player;

    QList<QLabel *> musicNotes;
    QList<QTimer *> musicNoteAnimationTimers;
    int maxHeightNote;
    int maxWidthNote;

    QList<QPixmap> idleFrames;
    QList<QPixmap> runningFrames;
    QList<QPixmap> shoutFrames;
    QList<QPixmap> jumpFrames;
    QList<QPixmap> musicNoteFrames;
    int idleFrameIndex;
    int runningFrameIndex;
    int shoutFrameIndex;
    int jumpFrameIndex;
    int musicNoteFrameIndex;
    QTimer *animationTimer;
    QTimer *positionUpdateTimer;

    bool movingLeft;
    bool movingRight;
    bool movingUp;
    bool movingDown;
    bool isJumping;
    bool isShouting;

    void createGameInfo();
    void createGameWindow();
    void createPlayer();
    void updatePosition();
    void jump();
    void shoot();
    void shootMusicNote();
    void updateMusicNoteAnimation(QLabel *musicNote);

    //Phase 2
    QLabel *enemy;
    QTimer *enemyMoveTimer;
    QList<QLabel *> bombs;
    QList<QTimer *> bombAnimationTimers;
    QTimer *bombSpawnTimer;
    QPixmap enemyPixmap;
    QList<QPixmap> bombPixmaps;
    int health;
    QLabel *healthLabel;
    bool isHurt;
    bool gamePaused;

    void createEnemy();
    void moveEnemy();
    void createBombs();
    void spawnBomb();
    void startBombSpawning();
    void stopBombSpawning();
    void checkCollisions();
    void hurtPlayer();
    void pauseGame();
    void restartGame();
};

#endif // MAINWINDOW_H
