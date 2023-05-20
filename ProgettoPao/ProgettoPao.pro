QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ainur.cpp \
    army.cpp \
    dwarf.cpp \
    elf.cpp \
    entity.cpp \
    hobbit.cpp \
    human.cpp \
    humanoid.cpp \
    maiar.cpp \
    main.cpp \
    mainwindow.cpp \
    orc.cpp \
    qontainer.cpp \
    valar.cpp \
    serializer.cpp

HEADERS += \
    ainur.h \
    army.h \
    dwarf.h \
    elf.h \
    entity.h \
    hobbit.h \
    human.h \
    humanoid.h \
    maiar.h \
    mainwindow.h \
    orc.h \
    qontainer.h \
    valar.h \
    serializer.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
