QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/armiescontroller.cpp \
	Controller/entitiescontroller.cpp \
	Model/ainu.cpp \
	Model/army.cpp \
	View/EntityView/ainudetailshard.cpp \
	View/EntityView/dwarfdetailshard.cpp \
	View/EntityView/elfdetailshard.cpp \
	View/EntityView/entitydetailshard.cpp \
	View/EntityView/hobbitdetailshard.cpp \
	View/EntityView/humandetailshard.cpp \
	View/EntityView/humanoiddetailshard.cpp \
	View/EntityView/maiadetailshard.cpp \
	View/EntityView/orcdetailshard.cpp \
	View/EntityView/valadetailshard.cpp \
	View/entitydetailview.cpp \
	View/entitylistview.cpp \
	datasave.cpp \
	Model/dwarf.cpp \
	Model/elf.cpp \
	Model/entity.cpp \
	Model/hobbit.cpp \
	Model/human.cpp \
	Model/humanoid.cpp \
	Model/maia.cpp \
	View/armiesview.cpp \
	View/entitiesview.cpp \
	entityvector.cpp \
	main.cpp \
	mainwindow.cpp \
	Model/orc.cpp \
	serializer.cpp \
	Model/vala.cpp

HEADERS += \
    Controller/armiescontroller.h \
	Controller/entitiescontroller.h \
	Model/ainu.h \
	Model/army.h \
	View/EntityView/ainudetailshard.h \
	View/EntityView/dwarfdetailshard.h \
	View/EntityView/elfdetailshard.h \
	View/EntityView/entitydetailshard.h \
	View/EntityView/hobbitdetailshard.h \
	View/EntityView/humandetailshard.h \
	View/EntityView/humanoiddetailshard.h \
	View/EntityView/maiadetailshard.h \
	View/EntityView/orcdetailshard.h \
	View/EntityView/valadetailshard.h \
	View/entitydetailview.h \
	View/entitylistview.h \
	datasave.h \
	Model/dwarf.h \
	Model/elf.h \
	Model/entity.h \
	Model/hobbit.h \
	Model/human.h \
	Model/humanoid.h \
	Model/maia.h \
	View/armiesview.h \
	View/entitiesview.h \
	entityvector.h \
	mainwindow.h \
	Model/orc.h \
	serializer.h \
	Model/vala.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
