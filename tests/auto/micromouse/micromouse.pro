
include(../gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     \
    mazetest.h \
    breadthfirstgpstests.h \
    navigator_test.h \
    ir_interpolate_test.h

SOURCES +=     main.cpp
