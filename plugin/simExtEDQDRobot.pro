QT -= core
QT -= gui

TARGET = simExtEDQDRobot
TEMPLATE = lib

DEFINES -= UNICODE
DEFINES += QT_COMPIL
CONFIG += shared plugin
INCLUDEPATH += "../include"
INCLUDEPATH += "EDQD-3D/include"

*-msvc* {
    QMAKE_CXXFLAGS += -O2
    QMAKE_CXXFLAGS += -W3
}
*-g++* {
    QMAKE_CXXFLAGS += -O3
    QMAKE_CXXFLAGS += -Wall
    QMAKE_CXXFLAGS += -Wno-unused-parameter
    QMAKE_CXXFLAGS += -Wno-strict-aliasing
    QMAKE_CXXFLAGS += -Wno-empty-body
    QMAKE_CXXFLAGS += -Wno-write-strings

    QMAKE_CXXFLAGS += -Wno-unused-but-set-variable
    QMAKE_CXXFLAGS += -Wno-unused-local-typedefs
    QMAKE_CXXFLAGS += -Wno-narrowing

    QMAKE_CFLAGS += -O3
    QMAKE_CFLAGS += -Wall
    QMAKE_CFLAGS += -Wno-strict-aliasing
    QMAKE_CFLAGS += -Wno-unused-parameter
    QMAKE_CFLAGS += -Wno-unused-but-set-variable
    QMAKE_CFLAGS += -Wno-unused-local-typedefs
}

win32 {
    DEFINES += WIN_SIM
}

macx {
    DEFINES += MAC_SIM
}

unix:!macx {
    DEFINES += LIN_SIM
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

HEADERS += \
    simExtEDQDRobot.h \
    EDQD-3D/include/Robot.h \
    EDQD-3D/include/EDQDRobot.h \
    EDQD-3D/include/CylinderEDQDRobot.h \
    EDQD-3D/include/Controller.h \
    EDQD-3D/include/EDQDController.h \
    EDQD-3D/include/CylinderEDQDController.h \
    EDQD-3D/include/World.h \
    ../include/scriptFunctionData.h \
    ../include/scriptFunctionDataItem.h \
    ../include/simLib.h 

SOURCES += \
    simExtEDQDRobot.cpp \
    EDQD-3D/src/Robot.cpp \
    EDQD-3D/src/EDQDRobot.cpp \
    EDQD-3D/src/CylinderEDQDRobot.cpp \
    EDQD-3D/src/Controller.cpp \
    EDQD-3D/src/EDQDController.cpp \
    EDQD-3D/src/CylinderEDQDController.cpp \
    EDQD-3D/src/World.cpp \
    ../common/scriptFunctionData.cpp \
    ../common/scriptFunctionDataItem.cpp \
    ../common/simLib.cpp