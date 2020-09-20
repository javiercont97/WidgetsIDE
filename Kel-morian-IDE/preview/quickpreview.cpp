#include "quickpreview.h"
#include "ui_quickpreview.h"

QuickPreview::QuickPreview(QWidget *parent): QWidget(parent), ui(new Ui::QuickPreview) {
    ui->setupUi(this);
}

QuickPreview::~QuickPreview() {
    delete ui;
}

void QuickPreview::setSource(QUrl source) {
    ui->quickWidget->setSource(source);
}
