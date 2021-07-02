#############################################################################
# Makefile for building: lending_system
# Generated by qmake (3.1) (Qt 5.15.2)
# Project:  lending_system.pro
# Template: app
# Command: /usr/lib64/qt5/bin/qmake -o Makefile lending_system.pro
#############################################################################

MAKEFILE      = Makefile

EQ            = =

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -Wall -Wextra -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -Wextra -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -I. -I/usr/include/qt5 -I/usr/include/qt5/QtWidgets -I/usr/include/qt5/QtGui -I/usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++
QMAKE         = /usr/lib64/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/lib64/qt5/bin/qmake -install qinstall
QINSTALL_PROGRAM = /usr/lib64/qt5/bin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = lending_system1.0.0
DISTDIR = /home/raphael/htw/prog/beleg/lending_system/.tmp/lending_system1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS) /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so -lGL -lpthread   
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = book.cpp \
		cd.cpp \
		lending_system.cpp \
		main.cpp \
		mainwindow.cpp \
		medium.cpp \
		person.cpp \
		person_dialog.cpp moc_mainwindow.cpp \
		moc_person_dialog.cpp
OBJECTS       = book.o \
		cd.o \
		lending_system.o \
		main.o \
		mainwindow.o \
		medium.o \
		person.o \
		person_dialog.o \
		moc_mainwindow.o \
		moc_person_dialog.o
DIST          = /usr/lib64/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib64/qt5/mkspecs/common/unix.conf \
		/usr/lib64/qt5/mkspecs/common/linux.conf \
		/usr/lib64/qt5/mkspecs/common/sanitize.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt5/mkspecs/common/g++-base.conf \
		/usr/lib64/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt5/mkspecs/qconfig.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_bluetooth.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_bluetooth_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_designer.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_designer_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_multimedia_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmlmodels.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmlmodels_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmlworkerscript.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmlworkerscript_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickshapes_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_script.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_script_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_svg.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_svg_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_uiplugin.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_webkit.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_webkit_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_webkitwidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xkbcommon_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib64/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt5/mkspecs/features/qt_config.prf \
		/usr/lib64/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib64/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib64/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt5/mkspecs/features/toolchain.prf \
		/usr/lib64/qt5/mkspecs/features/default_pre.prf \
		/usr/lib64/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib64/qt5/mkspecs/features/default_post.prf \
		/usr/lib64/qt5/mkspecs/features/warn_on.prf \
		/usr/lib64/qt5/mkspecs/features/qt.prf \
		/usr/lib64/qt5/mkspecs/features/resources_functions.prf \
		/usr/lib64/qt5/mkspecs/features/resources.prf \
		/usr/lib64/qt5/mkspecs/features/moc.prf \
		/usr/lib64/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib64/qt5/mkspecs/features/uic.prf \
		/usr/lib64/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib64/qt5/mkspecs/features/file_copies.prf \
		/usr/lib64/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib64/qt5/mkspecs/features/exceptions.prf \
		/usr/lib64/qt5/mkspecs/features/yacc.prf \
		/usr/lib64/qt5/mkspecs/features/lex.prf \
		lending_system.pro book.h \
		cd.h \
		lending_system.h \
		mainwindow.h \
		medium.h \
		person.h \
		person_dialog.h \
		ui_lending_system.h \
		ui_person_dialog.h book.cpp \
		cd.cpp \
		lending_system.cpp \
		main.cpp \
		mainwindow.cpp \
		medium.cpp \
		person.cpp \
		person_dialog.cpp
QMAKE_TARGET  = lending_system
DESTDIR       = 
TARGET        = lending_system


first: all
####### Build rules

lending_system: ui_lending_system.h ui_person_dialog.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: lending_system.pro /usr/lib64/qt5/mkspecs/linux-g++/qmake.conf /usr/lib64/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib64/qt5/mkspecs/common/unix.conf \
		/usr/lib64/qt5/mkspecs/common/linux.conf \
		/usr/lib64/qt5/mkspecs/common/sanitize.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt5/mkspecs/common/g++-base.conf \
		/usr/lib64/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt5/mkspecs/qconfig.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_bluetooth.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_bluetooth_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_designer.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_designer_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_multimedia_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmlmodels.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmlmodels_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmlworkerscript.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmlworkerscript_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickshapes_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_script.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_script_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_svg.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_svg_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_uiplugin.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_webkit.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_webkit_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_webkitwidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xkbcommon_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib64/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt5/mkspecs/features/qt_config.prf \
		/usr/lib64/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib64/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib64/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt5/mkspecs/features/toolchain.prf \
		/usr/lib64/qt5/mkspecs/features/default_pre.prf \
		/usr/lib64/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib64/qt5/mkspecs/features/default_post.prf \
		/usr/lib64/qt5/mkspecs/features/warn_on.prf \
		/usr/lib64/qt5/mkspecs/features/qt.prf \
		/usr/lib64/qt5/mkspecs/features/resources_functions.prf \
		/usr/lib64/qt5/mkspecs/features/resources.prf \
		/usr/lib64/qt5/mkspecs/features/moc.prf \
		/usr/lib64/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib64/qt5/mkspecs/features/uic.prf \
		/usr/lib64/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib64/qt5/mkspecs/features/file_copies.prf \
		/usr/lib64/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib64/qt5/mkspecs/features/exceptions.prf \
		/usr/lib64/qt5/mkspecs/features/yacc.prf \
		/usr/lib64/qt5/mkspecs/features/lex.prf \
		lending_system.pro
	$(QMAKE) -o Makefile lending_system.pro
/usr/lib64/qt5/mkspecs/features/spec_pre.prf:
/usr/lib64/qt5/mkspecs/common/unix.conf:
/usr/lib64/qt5/mkspecs/common/linux.conf:
/usr/lib64/qt5/mkspecs/common/sanitize.conf:
/usr/lib64/qt5/mkspecs/common/gcc-base.conf:
/usr/lib64/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib64/qt5/mkspecs/common/g++-base.conf:
/usr/lib64/qt5/mkspecs/common/g++-unix.conf:
/usr/lib64/qt5/mkspecs/qconfig.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_bluetooth.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_bluetooth_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_designer.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_designer_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_designercomponents_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_edid_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_multimedia.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_multimedia_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qml.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qml_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmlmodels.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmlmodels_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmlworkerscript.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmlworkerscript_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quick.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quick_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quickshapes_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_script.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_script_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_svg.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_svg_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_uiplugin.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_webkit.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_webkit_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_webkitwidgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_webkitwidgets_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xkbcommon_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib64/qt5/mkspecs/features/qt_functions.prf:
/usr/lib64/qt5/mkspecs/features/qt_config.prf:
/usr/lib64/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib64/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib64/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib64/qt5/mkspecs/features/toolchain.prf:
/usr/lib64/qt5/mkspecs/features/default_pre.prf:
/usr/lib64/qt5/mkspecs/features/resolve_config.prf:
/usr/lib64/qt5/mkspecs/features/default_post.prf:
/usr/lib64/qt5/mkspecs/features/warn_on.prf:
/usr/lib64/qt5/mkspecs/features/qt.prf:
/usr/lib64/qt5/mkspecs/features/resources_functions.prf:
/usr/lib64/qt5/mkspecs/features/resources.prf:
/usr/lib64/qt5/mkspecs/features/moc.prf:
/usr/lib64/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib64/qt5/mkspecs/features/uic.prf:
/usr/lib64/qt5/mkspecs/features/unix/thread.prf:
/usr/lib64/qt5/mkspecs/features/qmake_use.prf:
/usr/lib64/qt5/mkspecs/features/file_copies.prf:
/usr/lib64/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib64/qt5/mkspecs/features/exceptions.prf:
/usr/lib64/qt5/mkspecs/features/yacc.prf:
/usr/lib64/qt5/mkspecs/features/lex.prf:
lending_system.pro:
qmake: FORCE
	@$(QMAKE) -o Makefile lending_system.pro

qmake_all: FORCE


all: Makefile lending_system

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib64/qt5/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents book.h cd.h lending_system.h mainwindow.h medium.h person.h person_dialog.h ui_lending_system.h ui_person_dialog.h $(DISTDIR)/
	$(COPY_FILE) --parents book.cpp cd.cpp lending_system.cpp main.cpp mainwindow.cpp medium.cpp person.cpp person_dialog.cpp $(DISTDIR)/
	$(COPY_FILE) --parents lending_system.ui person_dialog.ui $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_objc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_objc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: /usr/lib64/qt5/mkspecs/features/data/dummy.cpp
	g++ -pipe -O2 -Wall -Wextra -dM -E -o moc_predefs.h /usr/lib64/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_mainwindow.cpp moc_person_dialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_person_dialog.cpp
moc_mainwindow.cpp: mainwindow.h \
		ui_lending_system.h \
		lending_system.h \
		medium.h \
		person.h \
		moc_predefs.h \
		/usr/lib64/qt5/bin/moc
	/usr/lib64/qt5/bin/moc $(DEFINES) --include /home/raphael/htw/prog/beleg/lending_system/moc_predefs.h -I/usr/lib64/qt5/mkspecs/linux-g++ -I/home/raphael/htw/prog/beleg/lending_system -I/home/raphael/htw/prog/beleg/lending_system -I/usr/include/qt5 -I/usr/include/qt5/QtWidgets -I/usr/include/qt5/QtGui -I/usr/include/qt5/QtCore -I/usr/lib/gcc/x86_64-pc-linux-gnu/10.3.0/include/g++-v10 -I/usr/lib/gcc/x86_64-pc-linux-gnu/10.3.0/include/g++-v10/x86_64-pc-linux-gnu -I/usr/lib/gcc/x86_64-pc-linux-gnu/10.3.0/include/g++-v10/backward -I/usr/lib/gcc/x86_64-pc-linux-gnu/10.3.0/include -I/usr/lib/gcc/x86_64-pc-linux-gnu/10.3.0/include-fixed -I/usr/include mainwindow.h -o moc_mainwindow.cpp

moc_person_dialog.cpp: person_dialog.h \
		ui_person_dialog.h \
		moc_predefs.h \
		/usr/lib64/qt5/bin/moc
	/usr/lib64/qt5/bin/moc $(DEFINES) --include /home/raphael/htw/prog/beleg/lending_system/moc_predefs.h -I/usr/lib64/qt5/mkspecs/linux-g++ -I/home/raphael/htw/prog/beleg/lending_system -I/home/raphael/htw/prog/beleg/lending_system -I/usr/include/qt5 -I/usr/include/qt5/QtWidgets -I/usr/include/qt5/QtGui -I/usr/include/qt5/QtCore -I/usr/lib/gcc/x86_64-pc-linux-gnu/10.3.0/include/g++-v10 -I/usr/lib/gcc/x86_64-pc-linux-gnu/10.3.0/include/g++-v10/x86_64-pc-linux-gnu -I/usr/lib/gcc/x86_64-pc-linux-gnu/10.3.0/include/g++-v10/backward -I/usr/lib/gcc/x86_64-pc-linux-gnu/10.3.0/include -I/usr/lib/gcc/x86_64-pc-linux-gnu/10.3.0/include-fixed -I/usr/include person_dialog.h -o moc_person_dialog.cpp

compiler_moc_objc_header_make_all:
compiler_moc_objc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_lending_system.h ui_person_dialog.h
compiler_uic_clean:
	-$(DEL_FILE) ui_lending_system.h ui_person_dialog.h
ui_lending_system.h: lending_system.ui \
		/usr/lib64/qt5/bin/uic
	/usr/lib64/qt5/bin/uic lending_system.ui -o ui_lending_system.h

ui_person_dialog.h: person_dialog.ui \
		/usr/lib64/qt5/bin/uic
	/usr/lib64/qt5/bin/uic person_dialog.ui -o ui_person_dialog.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_predefs_clean compiler_moc_header_clean compiler_uic_clean 

####### Compile

book.o: book.cpp book.h \
		medium.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o book.o book.cpp

cd.o: cd.cpp cd.h \
		medium.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cd.o cd.cpp

lending_system.o: lending_system.cpp lending_system.h \
		medium.h \
		person.h \
		book.h \
		cd.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o lending_system.o lending_system.cpp

main.o: main.cpp mainwindow.h \
		ui_lending_system.h \
		lending_system.h \
		medium.h \
		person.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		ui_lending_system.h \
		lending_system.h \
		medium.h \
		person.h \
		book.h \
		cd.h \
		person_dialog.h \
		ui_person_dialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

medium.o: medium.cpp medium.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o medium.o medium.cpp

person.o: person.cpp person.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o person.o person.cpp

person_dialog.o: person_dialog.cpp person_dialog.h \
		ui_person_dialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o person_dialog.o person_dialog.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_person_dialog.o: moc_person_dialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_person_dialog.o moc_person_dialog.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

