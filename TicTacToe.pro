TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        AiUtils.cpp \
        DisplayUtils.cpp \
        Game.cpp \
        GameUtils.cpp \
        InputUtils.cpp \
        MenuUtils.cpp \
        main.cpp

HEADERS += \
    AiUtils.h \
    DisplayUtils.h \
    Game.h \
    GameUtils.h \
    InputUtils.h \
    MenuUtils.h \
    types.h
