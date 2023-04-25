QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gamewindow.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    scores.cpp \
    signup.cpp \
    user.cpp

HEADERS += \
    Utility.h \
    gamewindow.h \
    login.h \
    mainwindow.h \
    scores.h \
    signup.h \
    user.h

FORMS += \
    login.ui \
    mainwindow.ui \
    scores.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    UserData.json \
    gameBkg.jpg \
    images/background.gif \
    images/black.png \
    images/bomb/0.png \
    images/bomb/1.png \
    images/bomb/2.png \
    images/enemy.png \
    images/miku_die/0.png \
    images/miku_die/1.png \
    images/miku_die/2.png \
    images/miku_idling/0.png \
    images/miku_idling/1.png \
    images/miku_idling/10.png \
    images/miku_idling/11.png \
    images/miku_idling/12.png \
    images/miku_idling/13.png \
    images/miku_idling/14.png \
    images/miku_idling/15.png \
    images/miku_idling/16.png \
    images/miku_idling/17.png \
    images/miku_idling/18.png \
    images/miku_idling/19.png \
    images/miku_idling/2.png \
    images/miku_idling/3.png \
    images/miku_idling/4.png \
    images/miku_idling/5.png \
    images/miku_idling/6.png \
    images/miku_idling/7.png \
    images/miku_idling/8.png \
    images/miku_idling/9.png \
    images/miku_jump/0.png \
    images/miku_jump/1.png \
    images/miku_jump/2.png \
    images/miku_jump/3.png \
    images/miku_jump/4.png \
    images/miku_jump/5.png \
    images/miku_jump/6.png \
    images/miku_jump/7.png \
    images/miku_jump/8.png \
    images/miku_running/0.png \
    images/miku_running/1.png \
    images/miku_running/2.png \
    images/miku_running/3.png \
    images/miku_running/4.png \
    images/miku_running/5.png \
    images/miku_running/6.png \
    images/miku_running/7.png \
    images/miku_shout/0.png \
    images/miku_shout/1.png \
    images/miku_shout/2.png \
    images/miku_shout/3.png \
    images/miku_shout/4.png \
    images/miku_shout/5.png \
    images/miku_shout/6.png \
    images/miku_shout/7.png \
    images/musicnote/0.png \
    images/musicnote/1.png \
    images/musicnote/10.png \
    images/musicnote/11.png \
    images/musicnote/12.png \
    images/musicnote/13.png \
    images/musicnote/14.png \
    images/musicnote/15.png \
    images/musicnote/16.png \
    images/musicnote/17.png \
    images/musicnote/2.png \
    images/musicnote/3.png \
    images/musicnote/4.png \
    images/musicnote/5.png \
    images/musicnote/6.png \
    images/musicnote/7.png \
    images/musicnote/8.png \
    images/musicnote/9.png

RESOURCES += \
    Resources.qrc
