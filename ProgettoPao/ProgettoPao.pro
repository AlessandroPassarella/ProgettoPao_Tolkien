QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Components/backtopbar.cpp \
    Components/basetopbar.cpp \
    Model/ainu.cpp \
    Model/army.cpp \
    Model/dwarf.cpp \
    Model/elf.cpp \
    Model/entity.cpp \
    Model/hobbit.cpp \
    Model/human.cpp \
    Model/humanoid.cpp \
    Model/maia.cpp \
    View/armiesview.cpp \
    View/entitiesview.cpp \
    View/viewinterface.cpp \
    main.cpp \
    mainwindow.cpp \
    Model/orc.cpp \
    Model/model.cpp \
    qontainer.cpp \
    serializer.cpp \
    Model/vala.cpp

HEADERS += \
    Components/backtopbar.h \
    Components/basetopbar.h \
    Model/ainu.h \
    Model/army.h \
    Model/dwarf.h \
    Model/elf.h \
    Model/entity.h \
    Model/hobbit.h \
    Model/human.h \
    Model/humanoid.h \
    Model/maia.h \
    View/armiesview.h \
    View/entitiesview.h \
    View/viewinterface.h \
    mainwindow.h \
    Model/orc.h \
    Model/model.h \
    qontainer.h \
    serializer.h \
    Model/vala.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
