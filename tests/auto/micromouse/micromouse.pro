include(../gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

DEFINES += BUILD_FOR_PC

HEADERS +=     \
    mazetest.h \
    breadthfirstgpstests.h \
    navigator_test.h \
    ir_interpolate_test.h \
    driver_test.h \
    $$files(../../../src/src/*.h)

SOURCES +=     \
    $$files(../../../src/src/*.cpp) \
    testmain.cpp

INCLUDEPATH += ../../../src/src
