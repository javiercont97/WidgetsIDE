QT       += core gui
QT       += quickwidgets  ## qt quick support
QT       += network       ## http request support
QT       += websockets       ## websockets request support
QT       += mqtt             ## mqtt support


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

RC_ICONS = icon.ico

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
    api/wstt.cpp \
    editor/codeeditor.cpp \
    editor/codehighlighter.cpp \
    editor/linenumberarea.cpp \
    ide.cpp \
    main.cpp \
    preview/quickpreview.cpp \
    tools/templateselector.cpp

HEADERS += \
    api/wstt.h \
    editor/codeeditor.h \
    editor/codehighlighter.h \
    editor/linenumberarea.h \
    ide.h \
    preview/quickpreview.h \
    tools/templateselector.h

FORMS += \
    ide.ui \
    preview/quickpreview.ui \
    tools/templateselector.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    assets.qrc
