contains(QT_VERSION, ^4\\..*) {
	message("Qt 4")
	QT		+= qt3support network xml
	VPATH		+= common/GUI-QT
	HEADERS		+= common/GUI-QT/DRMPlot-qwt5.h
	SOURCES		+= common/GUI-QT/DRMPlot-qwt5.cpp
	unix {
		INCLUDEPATH	+= /usr/include/qwt-qt4
		LIBS 		+= -lqwt-qt4
	}
	win32 {
		INCLUDEPATH	+= libs/qwt5
		LIBS 		+= qwt5.lib
	}
}
count(QT_VERSION, 0) {
	message("Qt 3")
	VPATH		+= common/GUI-QT/qt2
	HEADERS		+= common/GUI-QT/DRMPlot.h
	SOURCES		+= common/GUI-QT/DRMPlot.cpp
	unix {
		INCLUDEPATH	+= /usr/include/qwt
		LIBS 		+= -lqwt
	}
	win32 {
		INCLUDEPATH	+= libs/qwt
		LIBS 		+= qwt.lib
	}
}
include("dream-common.pro")
FORMS		+= TransmDlgbase.ui fdrmdialogbase.ui AnalogDemDlgbase.ui fmdialogbase.ui
FORMS		+= AMSSDlgbase.ui systemevalDlgbase.ui MultimediaDlgbase.ui
FORMS		+= LiveScheduleDlgbase.ui StationsDlgbase.ui EPGDlgbase.ui
FORMS		+= GeneralSettingsDlgbase.ui MultSettingsDlgbase.ui AboutDlgbase.ui
