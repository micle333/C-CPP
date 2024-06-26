QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    plot.cpp \
    qcustomplot.cpp \
    smart_calc.c

HEADERS += \
    mainwindow.h \
    plot.h \
    qcustomplot.h \
    smart_calc.h \
    utils.h

FORMS += \
    mainwindow.ui \
    plot.ui

RESOURCES += \
    icons.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${untitled_try}/bin
else: unix:!android: target.path = /opt/$${untitled_try}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    source/coma_left.png
