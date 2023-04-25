#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QtWidgets>
#include <QLabel>
#include <QTimer>
#include <QPixmap>
#include <QMovie>

typedef enum {
    difficulty_placeholder, // = 0
    difficulty_easy, // = 1;
    difficulty_medium, // = 2;
    difficulty_hard,  // = 3;
} difficulty_t;

class GameWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private slots:
    void updateAnimation();

private:
    QLabel *gameInfo;
    QWidget *gameWindow;
    QMovie *backgroundMovie;
    QLabel *player;
    QLabel *playerScore;
    int score;
    int difficulty;

    QList<QLabel *> musicNotes;
    QList<QPointer<QTimer>> musicNoteAnimationTimers;
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
    bool damageBuffer;

    void createGameInfo();
    void createGameWindow();
    void createPlayer();
    void updatePosition();
    void jump();
    void shoot();
    void shootMusicNote();
    void checkMusicCollision();
    void updateScore();

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
    void clearBombs();
    void startBombSpawning();
    void stopBombSpawning();
    void checkCollisions();
    void hurtPlayer();
    void pauseGame();
    void restartGame();
};

#endif // GAMEWINDOW_H
