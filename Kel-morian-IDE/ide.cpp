#include "ide.h"
#include "ui_ide.h"
#include <tools/templateselector.h>

#include <QQuickItem>
#include <QQmlContext>
#include <QQmlEngine>
#include <QProcess>

#include <QSplitter>
#include <QSplitterHandle>

#include <QDesktopServices>

#include <QMessageBox>


IDE::IDE(QWidget *parent): QMainWindow(parent),ui(new Ui::IDE) {
    ui->setupUi(this);
    this->setWindowTitle("New file");
    init();

    this->setCentralWidget(ui->splitter_2);

    ui->previewZone->engine()->addImportPath("qrc:/");
    ui->previewZone->engine()->importModule(":/Controls/qmldir");

    connect(ui->previewZone->engine(), &QQmlEngine::warnings, this, &IDE::onPreviewWarnings);
}

IDE::~IDE() {
    delete ui;
}

void IDE::onPreviewWarnings(QList<QQmlError> errors) {
    foreach(QQmlError err, errors) {
        ui->loggingZone->appendPlainText(err.toString());
    }
}

void IDE::init() {
    ui->previewZone->setSource( QUrl("qrc:/PreviewLoader.qml"));
}

void IDE::updatePreview() {
    ui->loggingZone->clear();
    ui->previewZone->rootObject()->setProperty("sourcePath", "");
    ui->previewZone->engine()->clearComponentCache();

    //qInfo() << ui->previewZone->engine()->importPathList();

    ui->previewZone->rootObject()->setProperty("sourcePath", "file:///" + fileName);
}

void IDE::on_actionNew_Project_triggered() {
    QString path;
    path = QFileDialog::getSaveFileName(this, "New file", QDir::homePath(), "*.qml");

    if(path.isEmpty()) {
        return;
    }

    QFile file(path);

    TemplateSelector selector;
    selector.exec();

    ui->codeEditor->clear();
    ui->codeEditor->setPlainText(selector.getCode());


    if(file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        QString name = file.fileName().split("/")[file.fileName().split("/").length()-1];
        this->setWindowTitle(name);

        stream << ui->codeEditor->toPlainText();
        this->setWindowTitle(name);

        ui->statusbar->showMessage("Saving", 1000);

        fileName = path;

        file.close();

        ui->statusbar->showMessage("");

        updatePreview();
    } else {
        QMessageBox::critical(this, "Could not create the file", file.errorString());
    }
}

void IDE::on_actionOpen_Project_triggered() {
    QString path = QFileDialog::getOpenFileName(this, "Open file", QDir::homePath(), "*.qml");
    if(path.isEmpty()) {
        return;
    }

    QFile file(path);

    if(file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        QString name = file.fileName().split("/")[file.fileName().split("/").length()-1];
        ui->codeEditor->setPlainText(file.readAll());
        this->setWindowTitle(name);

        fileName = path;
        updatePreview();

        file.close();
    } else {
        QMessageBox::critical(this, "Could not open the file", file.errorString());
    }
}

void IDE::on_actionSave_triggered() {
    QString path;
    if(!fileName.isEmpty()) {
        path = fileName;
    } else {
        path = QFileDialog::getSaveFileName(this, "Save file", QDir::homePath(), "*.qml");
    }

    if(path.isEmpty()) {
        return;
    }

    QFile file(path);

    if(file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        QString name = file.fileName().split("/")[file.fileName().split("/").length()-1];

        stream << ui->codeEditor->toPlainText();
        this->setWindowTitle(name);

        ui->statusbar->showMessage("Saving", 1000);

        fileName = path;

        file.close();
        updatePreview();

    } else {
        QMessageBox::critical(this, "Could not save the file", file.errorString());
    }
}

void IDE::on_actionExit_program_2_triggered() {
    // TODO: Ask to save file before closing

    QApplication::exit();
}

void IDE::on_actionCopy_triggered() {
    ui->codeEditor->copy();
}

void IDE::on_actionCut_triggered() {
    ui->codeEditor->cut();
}

void IDE::on_actionPaste_triggered() {
    ui->codeEditor->paste();
}

void IDE::on_actionSelect_all_triggered() {
    ui->codeEditor->selectAll();
}

void IDE::on_actionRun_triggered() {
    QString path;
    QString name ;

    if(!fileName.isEmpty()) {
        path = fileName;
    } else {
        path = QFileDialog::getSaveFileName(this, "Save file", QDir::homePath(), "*.qml");
    }

    if(path.isEmpty()) {
        return;
    }

    QFile file(path);

    if(file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        name = file.fileName().split("/")[file.fileName().split("/").length()-1];

        stream << ui->codeEditor->toPlainText();
        this->setWindowTitle(name);

        ui->statusbar->showMessage("Saving", 1000);

        fileName = path;

        file.close();
        updatePreview();

    } else {
        QMessageBox::critical(this, "Could not save the file", file.errorString());
    }


    QuickPreview *preview = new QuickPreview();
    preview->setWindowTitle(name);
    preview->setSource("file:///" + path);

    preview->show();
}

void IDE::on_actionDeploy_triggered() {
    // tar.exe -a -c -f out.zip test.qml sign.png    // this works on windows 10. Compress
    // tar.exe -x -f out.zip  // this also works on windows 10. Uncompress
    if(fileName.isEmpty()) {
        QMessageBox::warning(this, "Could not create package", "There is nothing to pack.\nMake sure you saved your project");
        return;
    }

    QString outputPackage = QFileDialog::getSaveFileName(this, "Save file", QDir::homePath(), "*.zip");

    if(outputPackage.isEmpty()) {
        return;
    }

    QDir temp(outputPackage);
    temp.cdUp();

    QString temporalFile = temp.filePath("userApp.qml");
    QFile file(temporalFile);

    if(file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);

        stream << ui->codeEditor->toPlainText();

        ui->statusbar->showMessage("Packaging");
        file.close();

        QProcess *process = new QProcess(this);

        process->start("tar.exe", QStringList() << "-a" << "-c" << "-f" << outputPackage << "--dir=" + temp.path() << "userApp.qml");
    } else {
        QMessageBox::critical(this, "Could not package the project", file.errorString());
    }
}

void IDE::on_actionButton_triggered() {
    ui->codeEditor->insertPlainText("Button {\n"
                                    "  text: \"Button\"\n"
                                    "\n"
                                    "  onClicked: {\n"
                                    "    // this is a javascript function provided as callback for on click event\n"
                                    "    console.log(`${text} was clicked`)  // access to this button text property\n"
                                    "  }\n"
                                    "}\n");
}

void IDE::on_actionSwitch_triggered() {
    ui->codeEditor->insertPlainText("Switch {\n"
                                    "  text: \"Switch\"\n"
                                    "\n"
                                    "  onCheckedChanged: {\n"
                                    "    // this is a javascript function provided as callback for on click event\n"
                                    "    console.log(`${text} was switched to ${checked}`)  // access to this switch text and checked properties\n"
                                    "  }\n"
                                    "}\n");
}

void IDE::on_actionGauge_triggered() {
    ui->codeEditor->insertPlainText("CircularGauge {\n"
                                    "  id: gauge\n"
                                    "  value: 0\n"

                                    "\n"
                                    "  // Animate neddle movement\n"
                                    "  Behavior on value {\n"
                                    "    NumberAnimation {\n"
                                    "      duration: 1000\n"
                                    "    }\n"
                                    "  }\n"
                                    "}\n");}

void IDE::on_actionLabel_triggered() {
    ui->codeEditor->insertPlainText("Label {\n"
                                    "  text: \"Label text\"\n"
                                    "}\n");
}

void IDE::on_actionDial_triggered() {
    ui->codeEditor->insertPlainText("Dial {\n"
                                    "  value: 0\n"
                                    "\n"
                                    "  onValueChanged: {\n"
                                    "    // this is a javascript function provided as callback for on value changed event\n"
                                    "    console.log(`Value changed to ${value}`)  // access to this dial value property\n"
                                    "  }\n"
                                    "}\n");
}


void IDE::on_actionAbout_triggered() {
    QDesktopServices::openUrl ( QUrl("http:/imt-iotlabs.net/docs/editor/intro/") );
}

void IDE::on_actionAbout_Qt_triggered() {
    QMessageBox::aboutQt(this, "About Qt");
}
