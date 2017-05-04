#include("$${PWD}/../../OS-detect.pri")

QT += core gui widgets

TARGET = lumina-password
target.path = $${L_BINDIR}
TEMPLATE = app

SOURCES += main.cpp \
    MainUI.cpp

HEADERS  += \
    MainUI.h

FORMS    += \
    MainUI.ui

desktop.files=lumina-password.desktop
desktop.path=$${L_SHAREDIR}/applications/

INSTALLS += target desktop
