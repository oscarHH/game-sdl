TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    game.cpp \
    pice.cpp \
    board.cpp

DEFINES += SDL_MAIN_HANDLED

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Desktop/SDL2-2.0.4/lib/x86/ -lSDL2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Desktop/SDL2-2.0.4/lib/x86/ -lSDL2d
else:unix: LIBS += -L$$PWD/../../../Desktop/SDL2-2.0.4/lib/x86/ -lSDL2

INCLUDEPATH += $$PWD/../../../Desktop/SDL2-2.0.4/include
DEPENDPATH += $$PWD/../../../Desktop/SDL2-2.0.4/include

HEADERS += \
    game.h \
    pice.h \
    board.h \
    definitions.h
