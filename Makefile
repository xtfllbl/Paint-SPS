#############################################################################
# Makefile for building: SPSShow
# Generated by qmake (2.01a) (Qt 4.6.3) on: ?? 3? 9 14:58:15 2011
# Project:  qjdspsshow.pro
# Template: app
# Command: /home/xtf/qtsdk-2010.04/qt/bin/qmake -spec ../../qtsdk-2010.04/qt/mkspecs/linux-g++-64 -unix CONFIG+=debug -o Makefile qjdspsshow.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -g -D_REENTRANT -Wall -W $(DEFINES)
CXXFLAGS      = -m64 -pipe -g -D_REENTRANT -Wall -W $(DEFINES)
INCPATH       = -I../../qtsdk-2010.04/qt/mkspecs/linux-g++-64 -I. -I../../qtsdk-2010.04/qt/include/QtCore -I../../qtsdk-2010.04/qt/include/QtGui -I../../qtsdk-2010.04/qt/include -I. -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-rpath,/home/xtf/qtsdk-2010.04/qt/lib
LIBS          = $(SUBLIBS)  -L/home/xtf/qtsdk-2010.04/qt/lib -lQtGui -L/home/xtf/qtsdk-2010.04/qt/lib -L/usr/X11R6/lib64 -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/xtf/qtsdk-2010.04/qt/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		qjd_sps_mainwindow.cpp \
		qjd_sps_widget.cpp \
		qjd_sps_openfile.cpp \
		qjd_sps_combinefiles.cpp \
		qjd_sps_option.cpp \
		qjd_sps_help.cpp moc_qjd_sps_mainwindow.cpp \
		moc_qjd_sps_widget.cpp \
		moc_qjd_sps_openfile.cpp \
		moc_qjd_sps_combinefiles.cpp \
		moc_qjd_sps_option.cpp \
		moc_qjd_sps_help.cpp \
		qrc_image.cpp \
		qrc_styles.cpp
OBJECTS       = main.o \
		qjd_sps_mainwindow.o \
		qjd_sps_widget.o \
		qjd_sps_openfile.o \
		qjd_sps_combinefiles.o \
		qjd_sps_option.o \
		qjd_sps_help.o \
		moc_qjd_sps_mainwindow.o \
		moc_qjd_sps_widget.o \
		moc_qjd_sps_openfile.o \
		moc_qjd_sps_combinefiles.o \
		moc_qjd_sps_option.o \
		moc_qjd_sps_help.o \
		qrc_image.o \
		qrc_styles.o
DIST          = ../../qtsdk-2010.04/qt/mkspecs/common/g++.conf \
		../../qtsdk-2010.04/qt/mkspecs/common/unix.conf \
		../../qtsdk-2010.04/qt/mkspecs/common/linux.conf \
		../../qtsdk-2010.04/qt/mkspecs/qconfig.pri \
		../../qtsdk-2010.04/qt/mkspecs/features/qt_functions.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/qt_config.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/exclusive_builds.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/default_pre.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/debug.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/default_post.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/qt.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/unix/thread.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/moc.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/warn_on.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/resources.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/uic.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/yacc.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/lex.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/include_source_dir.prf \
		qjdspsshow.pro
QMAKE_TARGET  = SPSShow
DESTDIR       = 
TARGET        = SPSShow

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_qjd_sps_mainwindow.h ui_qjd_sps_openfile.h ui_qjd_sps_combinefiles.h ui_qjd_sps_option.h ui_qjd_sps_help.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: qjdspsshow.pro  ../../qtsdk-2010.04/qt/mkspecs/linux-g++-64/qmake.conf ../../qtsdk-2010.04/qt/mkspecs/common/g++.conf \
		../../qtsdk-2010.04/qt/mkspecs/common/unix.conf \
		../../qtsdk-2010.04/qt/mkspecs/common/linux.conf \
		../../qtsdk-2010.04/qt/mkspecs/qconfig.pri \
		../../qtsdk-2010.04/qt/mkspecs/features/qt_functions.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/qt_config.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/exclusive_builds.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/default_pre.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/debug.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/default_post.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/qt.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/unix/thread.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/moc.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/warn_on.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/resources.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/uic.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/yacc.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/lex.prf \
		../../qtsdk-2010.04/qt/mkspecs/features/include_source_dir.prf \
		/home/xtf/qtsdk-2010.04/qt/lib/libQtGui.prl \
		/home/xtf/qtsdk-2010.04/qt/lib/libQtCore.prl
	$(QMAKE) -spec ../../qtsdk-2010.04/qt/mkspecs/linux-g++-64 -unix CONFIG+=debug -o Makefile qjdspsshow.pro
../../qtsdk-2010.04/qt/mkspecs/common/g++.conf:
../../qtsdk-2010.04/qt/mkspecs/common/unix.conf:
../../qtsdk-2010.04/qt/mkspecs/common/linux.conf:
../../qtsdk-2010.04/qt/mkspecs/qconfig.pri:
../../qtsdk-2010.04/qt/mkspecs/features/qt_functions.prf:
../../qtsdk-2010.04/qt/mkspecs/features/qt_config.prf:
../../qtsdk-2010.04/qt/mkspecs/features/exclusive_builds.prf:
../../qtsdk-2010.04/qt/mkspecs/features/default_pre.prf:
../../qtsdk-2010.04/qt/mkspecs/features/debug.prf:
../../qtsdk-2010.04/qt/mkspecs/features/default_post.prf:
../../qtsdk-2010.04/qt/mkspecs/features/qt.prf:
../../qtsdk-2010.04/qt/mkspecs/features/unix/thread.prf:
../../qtsdk-2010.04/qt/mkspecs/features/moc.prf:
../../qtsdk-2010.04/qt/mkspecs/features/warn_on.prf:
../../qtsdk-2010.04/qt/mkspecs/features/resources.prf:
../../qtsdk-2010.04/qt/mkspecs/features/uic.prf:
../../qtsdk-2010.04/qt/mkspecs/features/yacc.prf:
../../qtsdk-2010.04/qt/mkspecs/features/lex.prf:
../../qtsdk-2010.04/qt/mkspecs/features/include_source_dir.prf:
/home/xtf/qtsdk-2010.04/qt/lib/libQtGui.prl:
/home/xtf/qtsdk-2010.04/qt/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec ../../qtsdk-2010.04/qt/mkspecs/linux-g++-64 -unix CONFIG+=debug -o Makefile qjdspsshow.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/SPSShow1.0.0 || $(MKDIR) .tmp/SPSShow1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/SPSShow1.0.0/ && $(COPY_FILE) --parents qjd_sps_mainwindow.h qjd_sps_widget.h qjd_sps_openfile.h qjd_sps_combinefiles.h qjd_sps_option.h qjd_sps_help.h .tmp/SPSShow1.0.0/ && $(COPY_FILE) --parents image.qrc styles.qrc .tmp/SPSShow1.0.0/ && $(COPY_FILE) --parents main.cpp qjd_sps_mainwindow.cpp qjd_sps_widget.cpp qjd_sps_openfile.cpp qjd_sps_combinefiles.cpp qjd_sps_option.cpp qjd_sps_help.cpp .tmp/SPSShow1.0.0/ && $(COPY_FILE) --parents qjd_sps_mainwindow.ui qjd_sps_openfile.ui qjd_sps_combinefiles.ui qjd_sps_option.ui qjd_sps_help.ui .tmp/SPSShow1.0.0/ && $(COPY_FILE) --parents qjdspsshow_cn.ts qjsspsshow_en.ts .tmp/SPSShow1.0.0/ && (cd `dirname .tmp/SPSShow1.0.0` && $(TAR) SPSShow1.0.0.tar SPSShow1.0.0 && $(COMPRESS) SPSShow1.0.0.tar) && $(MOVE) `dirname .tmp/SPSShow1.0.0`/SPSShow1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/SPSShow1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_qjd_sps_mainwindow.cpp moc_qjd_sps_widget.cpp moc_qjd_sps_openfile.cpp moc_qjd_sps_combinefiles.cpp moc_qjd_sps_option.cpp moc_qjd_sps_help.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_qjd_sps_mainwindow.cpp moc_qjd_sps_widget.cpp moc_qjd_sps_openfile.cpp moc_qjd_sps_combinefiles.cpp moc_qjd_sps_option.cpp moc_qjd_sps_help.cpp
moc_qjd_sps_mainwindow.cpp: qjd_sps_widget.h \
		qjd_sps_option.h \
		ui_qjd_sps_option.h \
		qjd_sps_openfile.h \
		ui_qjd_sps_openfile.h \
		qjd_sps_combinefiles.h \
		ui_qjd_sps_combinefiles.h \
		qjd_sps_help.h \
		ui_qjd_sps_help.h \
		qjd_sps_mainwindow.h
	/home/xtf/qtsdk-2010.04/qt/bin/moc $(DEFINES) $(INCPATH) qjd_sps_mainwindow.h -o moc_qjd_sps_mainwindow.cpp

moc_qjd_sps_widget.cpp: qjd_sps_option.h \
		ui_qjd_sps_option.h \
		qjd_sps_widget.h
	/home/xtf/qtsdk-2010.04/qt/bin/moc $(DEFINES) $(INCPATH) qjd_sps_widget.h -o moc_qjd_sps_widget.cpp

moc_qjd_sps_openfile.cpp: ui_qjd_sps_openfile.h \
		qjd_sps_openfile.h
	/home/xtf/qtsdk-2010.04/qt/bin/moc $(DEFINES) $(INCPATH) qjd_sps_openfile.h -o moc_qjd_sps_openfile.cpp

moc_qjd_sps_combinefiles.cpp: ui_qjd_sps_combinefiles.h \
		qjd_sps_combinefiles.h
	/home/xtf/qtsdk-2010.04/qt/bin/moc $(DEFINES) $(INCPATH) qjd_sps_combinefiles.h -o moc_qjd_sps_combinefiles.cpp

moc_qjd_sps_option.cpp: ui_qjd_sps_option.h \
		qjd_sps_option.h
	/home/xtf/qtsdk-2010.04/qt/bin/moc $(DEFINES) $(INCPATH) qjd_sps_option.h -o moc_qjd_sps_option.cpp

moc_qjd_sps_help.cpp: ui_qjd_sps_help.h \
		qjd_sps_help.h
	/home/xtf/qtsdk-2010.04/qt/bin/moc $(DEFINES) $(INCPATH) qjd_sps_help.h -o moc_qjd_sps_help.cpp

compiler_rcc_make_all: qrc_image.cpp qrc_styles.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_image.cpp qrc_styles.cpp
qrc_image.cpp: image.qrc \
		pg/00.png \
		pg/25.png \
		pg/90.png \
		pg/15.png \
		pg/80.png \
		pg/05.png \
		pg/70.png \
		pg/95.png \
		pg/60.png \
		pg/85.png \
		pg/100.png \
		pg/50.png \
		pg/75.png \
		pg/40.png \
		pg/65.png \
		pg/30.png \
		pg/55.png \
		pg/20.png \
		pg/45.png \
		pg/10.png \
		pg/35.png \
		image/index_5.png \
		image/wheel.png \
		image/32px-Crystal_Clear_mimetype_source_r.png \
		image/gnome-stock-gnome-run.png \
		image/s.png \
		image/Torchlight_qt.png \
		image/10.png \
		image/7.png \
		image/index_6.png \
		image/120px-Torchlight_viewmag_plus.png \
		image/Crystal_Clear_action_button_cancel.png \
		image/rightclick.png \
		image/1.png \
		image/index_0.png \
		image/Nuvola_filesystems_folder_blue_open.png \
		image/8.png \
		image/index_7.png \
		image/32px-Crystal_Clear_app_database.png \
		image/receiveline.png \
		image/wrong.png \
		image/2.png \
		image/Nuvola_filesystems_folder_grey_open.png \
		image/index_1.png \
		image/9.png \
		image/32px-Crystal_Clear_action_db_remove.png \
		image/Crystal_Clear_action_exit.png \
		image/leftclick.png \
		image/3.png \
		image/index_2.png \
		image/fang.png \
		image/sr.png \
		image/32px-Crystal_Clear_action_viewmag-.png \
		image/4.png \
		image/32px-Crystal_Clear_action_db_add.png \
		image/index_3.png \
		image/Crystal_Clear_action_decrypted.png \
		image/plus.png \
		image/5.png \
		image/index_4.png \
		image/120px-Torchlight_viewmag_minus.png \
		image/Crystal_Clear_action_reload.png \
		image/32px-Crystal_Clear_action_viewmag+.png \
		image/Torchlight_help.png \
		image/Nuvola_filesystems_folder_yellow_open.png \
		image/r.png \
		image/32px-Crystal_Clear_action_db_update.png \
		image/Crystal_Clear_action_apply.png \
		image/edit-select-all.png \
		image/6.png
	/home/xtf/qtsdk-2010.04/qt/bin/rcc -name image image.qrc -o qrc_image.cpp

qrc_styles.cpp: styles.qrc \
		styles/scrollbar_h_body_hover.png \
		styles/lineEditBg.png \
		styles/scrollbar_upArrow_pressed.png \
		styles/checkBox_focus.png \
		styles/closeWindowButton.png \
		styles/radioButton_pressed.png \
		styles/radioButton_checked_disabled.png \
		styles/headerViewArrow_down.png \
		styles/stylesheet.qss \
		styles/imageFrameBg.png \
		styles/minimizeWindowButton_hover.png \
		styles/scrollbar_h_leftArrow.png \
		styles/scrollbar_downArrow_pressed.png \
		styles/wsToolbarButton1.png \
		styles/minimizeWindowButton_pressed.png \
		styles/normalButton_disabled.png \
		styles/arrowDown.png \
		styles/radioButton_checked_pressed.png \
		styles/lineEditBg_pressed.png \
		styles/sessionOffButton_hover.png \
		styles/wsToolbarButton2_disabled.png \
		styles/arrowDown_disabled.png \
		styles/lineEditBg_hover.png \
		styles/scrollbar_body.png \
		styles/wsChatDisplayBg.png \
		styles/checkBox_pressed.png \
		styles/normalButton_default.png \
		styles/tabBarBg_hover.png \
		styles/radioButton_checked_focus.png \
		styles/toolbarButton_hover.png \
		styles/wsToolbarButton3_pressed.png \
		styles/wsToolbarButton1_pressed.png \
		styles/minimizeWindowButton.png \
		styles/sessionButton_pressed.png \
		styles/scrollbar_h_rightArrow_pressed.png \
		styles/scrollbar_h_rightArrow_hover.png \
		styles/radioButton_focus.png \
		styles/arrowUp_pressed.png \
		styles/headerViewArrow_up.png \
		styles/scrollbar_upArrow_hover.png \
		styles/scrollbar_h_leftArrow_pressed.png \
		styles/scrollbar_downArrow.png \
		styles/arrowDown_pressed.png \
		styles/menuButton_hover.png \
		styles/checkBox_checked_focus.png \
		styles/widgetButtonSmall_hover.png \
		styles/scrollbar_h_rightArrow.png \
		styles/workstationWidgetBg_focus.png \
		styles/scrollbar_bg.png \
		styles/checkBox_checked_pressed.png \
		styles/normalButton_hover.png \
		styles/arrowDown_focus.png \
		styles/sessionOffButton.png \
		styles/checkBox_hover.png \
		styles/scrollbar_body_hover.png \
		styles/checkBox_checked_hover.png \
		styles/wsToolbarButton2.png \
		styles/menuButton_focus.png \
		styles/menuButton_pressed.png \
		styles/widgetButton_pressed.png \
		styles/normalButton_focus.png \
		styles/closeWindowButton_hover.png \
		styles/tabBarBg.png \
		styles/radioButton_hover.png \
		styles/webcamWidgetBg.png \
		styles/arrowUp.png \
		styles/arrowUp_disabled.png \
		styles/workstationWidgetBg.png \
		styles/listWidgetBg.png \
		styles/sessionCloseButton.png \
		styles/notityWindowClose_pressed.png \
		styles/wsToolbarButton1_hover.png \
		styles/menuButton.png \
		styles/checkBox_checked.png \
		styles/checkBox.png \
		styles/normalButton_pressed.png \
		styles/closeWindowButton_pressed.png \
		styles/scrollbar_h_bg.png \
		styles/radioButton_checked.png \
		styles/progressBarBg.png \
		styles/radioButton_checked_hover.png \
		styles/widgetButtonSmall.png \
		styles/wsToolbarButton1_disabled.png \
		styles/notityWindowClose.png \
		styles/tabBarBg_selected.png \
		styles/tabBarBg_disabled.png \
		styles/checkBox_disabled.png \
		styles/wsToolbarButton3.png \
		styles/scrollbar_downArrow_hover.png \
		styles/sessionCloseButton_hover.png \
		styles/webcamWidgetBg_focus.png \
		styles/scrollbar_body_pressed.png \
		styles/widgetButton_hover.png \
		styles/lineEditBg_disabled.png \
		styles/scrollbar_upArrow.png \
		styles/wsToolbarButton3_disabled.png \
		styles/radioButton.png \
		styles/tabBg.png \
		styles/progressBar.png \
		styles/radioButton_disabled.png \
		styles/checkBox_checked_disabled.png \
		styles/sessionButton.png \
		styles/sessionOffButton_pressed.png \
		styles/arrowUp_focus.png \
		styles/arrowUp_hover.png \
		styles/widgetButtonSmall_pressed.png \
		styles/listWidgetBg2.png \
		styles/sessionButton_hover.png \
		styles/scrollbar_h_leftArrow_hover.png \
		styles/notityWindowClose_hover.png \
		styles/wsToolbarButton3_hover.png \
		styles/arrowDown_hover.png \
		styles/sessionCloseButton_pressed.png \
		styles/toolbarButton_pressed.png \
		styles/normalButton.png \
		styles/scrollbar_h_body_pressed.png \
		styles/widgetButton.png \
		styles/scrollbar_h_body.png \
		styles/wsToolbarButton2_hover.png \
		styles/wsToolbarButton2_pressed.png
	/home/xtf/qtsdk-2010.04/qt/bin/rcc -name styles styles.qrc -o qrc_styles.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_qjd_sps_mainwindow.h ui_qjd_sps_openfile.h ui_qjd_sps_combinefiles.h ui_qjd_sps_option.h ui_qjd_sps_help.h
compiler_uic_clean:
	-$(DEL_FILE) ui_qjd_sps_mainwindow.h ui_qjd_sps_openfile.h ui_qjd_sps_combinefiles.h ui_qjd_sps_option.h ui_qjd_sps_help.h
ui_qjd_sps_mainwindow.h: qjd_sps_mainwindow.ui
	/home/xtf/qtsdk-2010.04/qt/bin/uic qjd_sps_mainwindow.ui -o ui_qjd_sps_mainwindow.h

ui_qjd_sps_openfile.h: qjd_sps_openfile.ui
	/home/xtf/qtsdk-2010.04/qt/bin/uic qjd_sps_openfile.ui -o ui_qjd_sps_openfile.h

ui_qjd_sps_combinefiles.h: qjd_sps_combinefiles.ui
	/home/xtf/qtsdk-2010.04/qt/bin/uic qjd_sps_combinefiles.ui -o ui_qjd_sps_combinefiles.h

ui_qjd_sps_option.h: qjd_sps_option.ui
	/home/xtf/qtsdk-2010.04/qt/bin/uic qjd_sps_option.ui -o ui_qjd_sps_option.h

ui_qjd_sps_help.h: qjd_sps_help.ui
	/home/xtf/qtsdk-2010.04/qt/bin/uic qjd_sps_help.ui -o ui_qjd_sps_help.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp qjd_sps_mainwindow.h \
		qjd_sps_widget.h \
		qjd_sps_option.h \
		ui_qjd_sps_option.h \
		qjd_sps_openfile.h \
		ui_qjd_sps_openfile.h \
		qjd_sps_combinefiles.h \
		ui_qjd_sps_combinefiles.h \
		qjd_sps_help.h \
		ui_qjd_sps_help.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

qjd_sps_mainwindow.o: qjd_sps_mainwindow.cpp qjd_sps_mainwindow.h \
		qjd_sps_widget.h \
		qjd_sps_option.h \
		ui_qjd_sps_option.h \
		qjd_sps_openfile.h \
		ui_qjd_sps_openfile.h \
		qjd_sps_combinefiles.h \
		ui_qjd_sps_combinefiles.h \
		qjd_sps_help.h \
		ui_qjd_sps_help.h \
		ui_qjd_sps_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qjd_sps_mainwindow.o qjd_sps_mainwindow.cpp

qjd_sps_widget.o: qjd_sps_widget.cpp qjd_sps_widget.h \
		qjd_sps_option.h \
		ui_qjd_sps_option.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qjd_sps_widget.o qjd_sps_widget.cpp

qjd_sps_openfile.o: qjd_sps_openfile.cpp qjd_sps_openfile.h \
		ui_qjd_sps_openfile.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qjd_sps_openfile.o qjd_sps_openfile.cpp

qjd_sps_combinefiles.o: qjd_sps_combinefiles.cpp qjd_sps_combinefiles.h \
		ui_qjd_sps_combinefiles.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qjd_sps_combinefiles.o qjd_sps_combinefiles.cpp

qjd_sps_option.o: qjd_sps_option.cpp qjd_sps_option.h \
		ui_qjd_sps_option.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qjd_sps_option.o qjd_sps_option.cpp

qjd_sps_help.o: qjd_sps_help.cpp qjd_sps_help.h \
		ui_qjd_sps_help.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qjd_sps_help.o qjd_sps_help.cpp

moc_qjd_sps_mainwindow.o: moc_qjd_sps_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qjd_sps_mainwindow.o moc_qjd_sps_mainwindow.cpp

moc_qjd_sps_widget.o: moc_qjd_sps_widget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qjd_sps_widget.o moc_qjd_sps_widget.cpp

moc_qjd_sps_openfile.o: moc_qjd_sps_openfile.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qjd_sps_openfile.o moc_qjd_sps_openfile.cpp

moc_qjd_sps_combinefiles.o: moc_qjd_sps_combinefiles.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qjd_sps_combinefiles.o moc_qjd_sps_combinefiles.cpp

moc_qjd_sps_option.o: moc_qjd_sps_option.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qjd_sps_option.o moc_qjd_sps_option.cpp

moc_qjd_sps_help.o: moc_qjd_sps_help.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qjd_sps_help.o moc_qjd_sps_help.cpp

qrc_image.o: qrc_image.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_image.o qrc_image.cpp

qrc_styles.o: qrc_styles.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_styles.o qrc_styles.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

