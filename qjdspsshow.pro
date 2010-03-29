TARGET = SPSShow
TEMPLATE = app
CONFIG += qt debug
QMAKE_LFAGS+= -static

DEPENDPATH += . debug
INCLUDEPATH += .
SOURCES += main.cpp \
    qjd_sps_mainwindow.cpp \
    qjd_sps_widget.cpp \
    qjd_sps_openfile.cpp \
    qjd_sps_combinefiles.cpp \
    qjd_sps_option.cpp \
    qjd_sps_help.cpp
HEADERS += qjd_sps_mainwindow.h \
    qjd_sps_widget.h \
    qjd_sps_openfile.h \
    qjd_sps_combinefiles.h \
    qjd_sps_option.h \
    qjd_sps_help.h
FORMS += qjd_sps_mainwindow.ui \
    qjd_sps_openfile.ui \
    qjd_sps_combinefiles.ui \
    qjd_sps_option.ui \
    qjd_sps_help.ui
RESOURCES += image.qrc
TRANSLATIONS =qjdspsshow_cn.ts \
                        qjsspsshow_en.ts
