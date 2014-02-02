TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lglut -lGLU -lGL -lGLEW
QMAKE_LDFLAGS += -lGLEW -lglut -lGL


SOURCES += main.cpp \
    LoadShaders.cpp

HEADERS += \
    LoadShaders.h

OTHER_FILES += \
    fragment.frag \
    vertex.vert

