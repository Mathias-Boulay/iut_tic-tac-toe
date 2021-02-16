TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        AiUtils.cpp \
        DisplayUtils.cpp \
        GameUtils.cpp \
        InputUtils.cpp \
        main.cpp

HEADERS += \
    AiUtils.h \
    DisplayUtils.h \
    GameUtils.h \
    InputUtils.h \
    types.h
