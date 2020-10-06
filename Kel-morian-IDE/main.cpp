//#include "login.h"

#include "ide.h"

#include <QApplication>

#include <QStyleFactory>
#include <QDebug>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);

    a.setApplicationName("Kel-morian IDE");
    a.setApplicationDisplayName("IoT app editor");

    a.setWindowIcon(QIcon(":/icons/icon.png"));
    IDE w;
    w.show();
	return a.exec();
}
