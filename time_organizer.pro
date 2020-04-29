QT       += core gui
QT      += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ui/agendadialog.cpp \
    ui/edittaskgroupdialog.cpp \
    ui/taskgroupdialog.cpp \
    ui/todolistdialog.cpp \
    utilities/dataaggregator.cpp \
    models/event.cpp \
    ui/eventdialog.cpp \
    utilities/functions.cpp \
    ui/keyshortcutsdialog.cpp \
    main.cpp \
    ui/mainwindow.cpp \
    models/mycalendar.cpp \
    ui/mycalendaradddialog.cpp \
    ui/mycalendardialog.cpp \
    models/task.cpp \
    models/task_group.cpp

HEADERS += \
    ui/agendadialog.h \
    ui/edittaskgroupdialog.h \
    ui/taskgroupdialog.h \
    ui/todolistdialog.h \
    utilities/dataaggregator.h \
    models/event.h \
    ui/eventdialog.h \
    utilities/functions.h \
    ui/keyshortcutsdialog.h \
    ui/mainwindow.h \
    models/mycalendar.h \
    ui/mycalendaradddialog.h \
    ui/mycalendardialog.h \
    models/task.h \
    models/task_group.h

FORMS += \
    ui/agendadialog.ui \
    ui/edittaskgroupdialog.ui \
    ui/eventdialog.ui \
    ui/keyshortcutsdialog.ui \
    ui/mainwindow.ui \
    ui/mycalendaradddialog.ui \
    ui/mycalendardialog.ui \
    ui/taskgroupdialog.ui \
    ui/todolistdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ui/resources.qrc
