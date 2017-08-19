QT += core network sql
QT -= gui

CONFIG += c++11

TARGET = HttpServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    net/simplehttpserver.cpp \
    tools/debug.cpp \
    macaccess.cpp

HEADERS += \
    net/simplehttpserver.h \
    tools/debug.h \
    macaccess.h
