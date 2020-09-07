#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent): QWidget(parent), ui(new Ui::Login) {
	ui->setupUi(this);

	// connect login button
	connect(ui->btnLogin, &QPushButton::clicked, this, &Login::onLoginClicked);
}

Login::~Login() {
	delete ui;
}

void Login::onLoginClicked() {
	ide.show();
	this->close();
}
