#include "quickpreview.h"
#include "ui_quickpreview.h"
#include <QQmlEngine>

QuickPreview::QuickPreview(QWidget *parent): QWidget(parent), ui(new Ui::QuickPreview) {
    ui->setupUi(this);

    ui->quickWidget->engine()->addImportPath("qrc:/");
    ui->quickWidget->engine()->importModule(":/Controls/qmldir");
}

QuickPreview::~QuickPreview() {
    delete ui;
}

void QuickPreview::setSource(QUrl source) {
    ui->quickWidget->setSource(source);
}
