
include(../gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     tst_micromouse.h \
    mazetest.h

SOURCES +=     main.cpp
