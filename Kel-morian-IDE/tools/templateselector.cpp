#include "templateselector.h"
#include "ui_templateselector.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

TemplateSelector::TemplateSelector(QWidget *parent): QDialog(parent), ui(new Ui::TemplateSelector) {
    ui->setupUi(this);

    connect(ui->listWidget, &QListWidget::itemClicked, this, &TemplateSelector::selectionChanged);
}

TemplateSelector::~TemplateSelector() {
    delete ui;
}

void TemplateSelector::selectionChanged(QListWidgetItem *i) {
    QString path;
    if(i->text() == "Empty") {
        path = ":/Empty.qml";
    } else if(i->text() == "Gauge") {
        path = ":/GaugePreview.qml";
    } else if(i->text() == "Button array") {
        path = ":/ButtonArray.qml";
    } else if(i->text() == "Switch array") {
        path = ":/SwitchArray.qml";
    }
    ui->quickWidget->setSource("qrc" + path);

    if(path.isEmpty()) {
        return;
    }

    QFile file(path);

    if(file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        QString name = file.fileName().split("/")[file.fileName().split("/").length()-1];
        code = stream.readAll();

        file.close();
    } else {
        QMessageBox::critical(this, "Could not open the template file", file.errorString());
    }
}


QString TemplateSelector::getCode() const {
    return code;
}
