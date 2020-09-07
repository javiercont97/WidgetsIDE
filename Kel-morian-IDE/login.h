#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

#include "ide.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget {
	Q_OBJECT

public:
	Login(QWidget *parent = nullptr);
	~Login();

private slots:
	void onLoginClicked();

private:
	Ui::Login *ui;

	IDE ide;
};
#endif // LOGIN_H
