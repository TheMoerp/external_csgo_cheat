QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aimbot.cpp \
    antiflash.cpp \
    bhop.cpp \
    changehotkeys.cpp \
    changeskinlayout.cpp \
    config.cpp \
    main.cpp \
    mainwindow.cpp \
    memory.cpp \
    offsets.cpp \
    patternscan.cpp \
    radar.cpp \
    skinchanger.cpp \
    structures.cpp \
    triggerbot.cpp \
    wallhack.cpp \
    weapon.cpp

HEADERS += \
    aimbot.h \
    antiflash.h \
    bhop.h \
    changehotkeys.h \
    changeskinlayout.h \
    config.h \
    mainwindow.h \
    memory.h \
    offsets.h \
    patternscan.h \
    radar.h \
    skinchanger.h \
    structures.h \
    triggerbot.h \
    wallhack.h \
    weapon.h

FORMS += \
    changeHotKeys.ui \
    changeSkinLayout.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    skinlayout.txt
