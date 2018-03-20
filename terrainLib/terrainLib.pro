TEMPLATE = lib
TARGET = terrainLib

DEFINES += TERRAIN

OBJECTS_DIR = obj 
UI_DIR = ui

QT += opengl core gui
CONFIG += ocnsole c++11 
CONFIG -= app_bundle 
DESTDIR = $$PWD/lib

SOURCES += \
    src/Grid.cpp \
    src/Noise.cpp \
    src/MarchingCube.cpp \
    src/Polygon.cpp

HEADERS += \
    include/Grid.h \
    include/Noise.h \
    include/McData.h \
    include/MarchingCube.h \
    include/Polygon.h

INCLUDEPATH += \
    /usr/local/include/glm/glm \
    /usr/local/include/glm \
    /usr/local/include \
    $$PWD/include

QMAKE_CXXFLAGS += -O3 -std=c++11 -msse -msse2 -msse3 -arch x86_64

linux:{
    LIBS += -lGL -lGLU -lGLEW -lassimp
}

mac:{
  LIBS+= -L/usr/local/lib -lassimp
  QMAKE_CXXFLAGS += -arch x86_64
}
