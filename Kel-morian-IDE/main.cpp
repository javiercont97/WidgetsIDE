//#include "login.h"

#include "ide.h"

#include <QApplication>

#include <QStyleFactory>
#include <QDebug>

#include <QQmlContext>
#include "api/wstt.h"

#include <QQuickStyle>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);

    qmlRegisterType<WSTT>("IMT.IoTLabsWS", 1, 0, "IoTLabsWS");

    a.setApplicationName("IMT IoT labs IDE");
    a.setApplicationDisplayName("IoT app editor");

    a.setWindowIcon(QIcon(":/icons/imt-Logo.jpg"));

    QQuickStyle::setStyle("Material");

    IDE w;
    w.show();
	return a.exec();
}
