TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    strategy.h \
    observer.h \
    decorator.h \
    factorymethod.h \
    abstractfactory.h \
    singleton.h \
    command.h \
    adapter.h

