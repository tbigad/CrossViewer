QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = "CrossViewer"
TEMPLATE = app
OBJECTS_DIR = build/obj
MOC_DIR = build/moc
QMAKE_CXXFLAGS += -std=c++11 -pthread
QMAKE_MAC_SDK = macosx10.11

SOURCES += ../src/*.cpp

HEADERS  += ../src/*.h

FORMS    += ../ui/*.ui
