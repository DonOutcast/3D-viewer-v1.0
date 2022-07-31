QT       += core gui openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = 3D_simba
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
include(QtGifImage-master/src/gifimage/qtgifimage.pri)
SOURCES += \
    ../s21_3D_Viewer.c \
    glwidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../lib.h \
    glwidget.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

#LIBS += -lglu32

#DISTFILES += \
#    freeglut.dll
#    glew32.dll

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
