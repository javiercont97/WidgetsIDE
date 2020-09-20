//#include "login.h"

#include "ide.h"

#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);

    a.setApplicationName("Kel-morian IDE");
    a.setApplicationDisplayName("IoT app editor");


    IDE w;
    w.show();

//	Login w;
//	w.show();
	return a.exec();
}
