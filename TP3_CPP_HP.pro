TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        actionrobot.cpp \
        contexterobot.cpp \
        deplacer.cpp \
        fermerpince.cpp \
        mainacompleter.cpp \
        ouvrirpince.cpp \
        rotation_angle.cpp \
        sequenceactions.cpp

HEADERS += \
    actionrobot.h \
    contexterobot.h \
    deplacer.h \
    fermerpince.h \
    ouvrirpince.h \
    rotation_angle.h \
    sequenceactions.h
