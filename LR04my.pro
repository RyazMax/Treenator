#-------------------------------------------------
#
# Project created by QtCreator 2019-06-07T22:31:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LR04my
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Builder/basemodelbuilder.cpp \
    Builder/modelbuilder.cpp \
    Commands/commands.cpp \
    Drawer/basedrawer.cpp \
    Drawer/basedrawerimp.cpp \
    Drawer/modeldrawer.cpp \
    Drawer/qtdrawerimp.cpp \
    Managers/cameramanager.cpp \
    Managers/drawmanager.cpp \
    Managers/modelmanager.cpp \
    Managers/objectmanager.cpp \
    Managers/uploadmanager.cpp \
    Model/modeledgesiterator.cpp \
    Model/modelvertsiterator.cpp \
    Object/compobjiterator.cpp \
    Object/compositeobject.cpp \
    Object/invisibleobject.cpp \
    Object/object3d.cpp \
    Object/visibleobject.cpp \
    Uploader/textfileloaderimp.cpp \
    basetransformator.cpp \
    basetransformatorimp.cpp \
    baseuploader.cpp \
    baseuploaderimp.cpp \
    camera.cpp \
    cameratransformatorimp.cpp \
    coords3d.cpp \
    edge.cpp \
    main.cpp \
    mainwindow.cpp \
    matrix.cpp \
    mediator.cpp \
    modeltransformatorimp.cpp \
    modeluploader.cpp \
    point3d.cpp \
    transformations.cpp \
    treesegment.cpp \
    treeskeleton.cpp \
    verticle.cpp \
    viewerfacade.cpp \
    viewerscene.cpp \
    Exceptions/baseexception.cpp \
    Exceptions/iteratorexception.cpp \
    Exceptions/matrixexception.cpp \
    Model/vertixmodel.cpp \
    Model/wiremodel.cpp \
    Model/polygionmodel.cpp \
    polygon.cpp \
    Drawer/zbufferdrawer.cpp \
    Model/modelpolygoniterator.cpp \
    Builder/polygonmodelbuilder.cpp \
    vec3i.cpp \
    compositefunctionsystem.cpp \
    treeskeletonbuilder.cpp \
    basefunctionsystem.cpp \
    treepolygonbuilder.cpp \
    light.cpp \
    Drawer/qtimagedrawerimp.cpp

QMAKE_CXXFLAGS += -O2

FORMS += \
        mainwindow.ui

HEADERS += \
    Builder/basemodelbuilder.h \
    Builder/modelbuilder.h \
    Commands/commands.h \
    Drawer/basedrawer.h \
    Drawer/basedrawerimp.h \
    Drawer/modeldrawer.h \
    Drawer/qtdrawerimp.h \
    Managers/basemanager.h \
    Managers/cameramanager.h \
    Managers/drawmanager.h \
    Managers/modelmanager.h \
    Managers/objectmanager.h \
    Managers/uploadmanager.h \
    Model/modeledgesiterator.h \
    Model/modelvertsiterator.h \
    Object/compobjiterator.h \
    Object/compositeobject.h \
    Object/invisibleobject.h \
    Object/object3d.h \
    Object/visibleobject.h \
    Uploader/textfileloaderimp.h \
    basetransformator.h \
    basetransformatorimp.h \
    baseuploader.h \
    baseuploaderimp.h \
    camera.h \
    cameratransformatorimp.h \
    coords3d.h \
    edge.h \
    mainwindow.h \
    matrix.h \
    mediator.h \
    modeltransformatorimp.h \
    modeluploader.h \
    point3d.h \
    transformations.h \
    treesegment.h \
    treeskeleton.h \
    verticle.h \
    viewerfacade.h \
    viewerscene.h \
    Exceptions/baseexception.h \
    Exceptions/iteratorexception.h \
    Exceptions/matrixexception.h \
    Model/vertixmodel.h \
    Model/wiremodel.h \
    Model/polygionmodel.h \
    polygon.h \
    Drawer/zbufferdrawer.h \
    Model/modelpolygoniterator.h \
    Builder/polygonmodelbuilder.h \
    vec3i.h \
    basefunctionsystem.h \
    compositefunctionsystem.h \
    treeskeletonbuilder.h \
    basefunctionsystem.h \
    treepolygonbuilder.h \
    matrix3.h \
    light.h \
    Drawer/qtimagedrawerimp.h \
    params.h
