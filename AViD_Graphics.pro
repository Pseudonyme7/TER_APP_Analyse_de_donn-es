#-------------------------------------------------
#
# Project created by QtCreator 2019-04-22T20:40:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AViD_Graphics
unix:LIBS += -lGLU
TEMPLATE = app
INCLUDEPATH += \
            $$(VK_SDK_PATH)/Include/

#
#C:/VulkanSDK/1.1.106.0/Include/

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        avid_graphic_widget.cpp \
    avid_shape.cpp \
    avid_circle.cpp \
    avid_polygon.cpp \
    avid_graphic_buffer.cpp \
    myopenglwidget.cpp \
    myvulkanwidget.cpp \
    vulkanrenderer.cpp \
    agw_factory.cpp

HEADERS += \
        avid_graphic_widget.h \
    avid_point.h \
    avid_shape.h \
    avid_circle.h \
    avid_polygon.h \
    avid_graphic_buffer.h \
    myopenglwidget.h \
    myvulkanwidget.h \
    vulkanrenderer.h \
    agw_factory.h

FORMS += \
        avid_graphic_widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    shaders.qrc
