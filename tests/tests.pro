TEMPLATE = app
TARGET = tests

OBJECTS_DIR = obj

QT += opengl core gui
CONFIG += console c++11
CONFIG -= app_bundle

HEADERS += \

SOURCES += \
    src/main.cpp \
    src/GridTest.cpp \

DEPENDPATH += . ../terrainLib
INCLUDEPATH = ../terrainLib/include
INCLUDEPATH += \
    /usr/local/include/glm/glm \
    /usr/local/include/glm \
    /usr/local/include


QMAKE_CXXFLAGS += -O3 -std=c++11 -msse -msse2 -msse3

LIBS += -L../terrainLib/lib -lterrain -lgtest -pthread

linux:{
    LIBS += -lGL -lGLU -lGLEW -lassimp
}

mac:{
  LIBS+= -L/usr/local/lib -lassimp
  QMAKE_CXXFLAGS += -arch x86_64
}