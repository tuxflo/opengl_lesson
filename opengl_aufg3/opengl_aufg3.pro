TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lglut -lGLU -lGL
QMAKE_LDFLAGS += -lGLU -lglut -lGL -lGLEW
QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp \
    point.cpp \
    line.cpp \
    mouse_func.cpp \
    global.cpp

HEADERS += \
    point.h \
    line.h \
    mouse_func.h \
    global.h

