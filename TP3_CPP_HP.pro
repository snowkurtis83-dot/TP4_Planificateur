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
        sequenceactions.cpp

HEADERS += \
    actionrobot.h \
    contexterobot.h \
    deplacer.h \
    fermerpince.h \
    ouvrirpince.h \
    sequenceactions.h
