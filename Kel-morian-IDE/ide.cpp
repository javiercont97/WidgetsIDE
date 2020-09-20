#include "ide.h"
#include "ui_ide.h"


IDE::IDE(QWidget *parent): QMainWindow(parent),ui(new Ui::IDE) {
	ui->setupUi(this);
    this->setWindowTitle("New file");
    init();

    this->setCentralWidget(ui->plainTextEdit);
}

IDE::~IDE() {
	delete ui;
}

void IDE::init() {

}

void IDE::on_actionNew_Project_triggered() {
    this->setWindowTitle("New file");
    ui->plainTextEdit->clear();
    ui->statusbar->showMessage("");
    fileName.clear();
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
        ui->plainTextEdit->setPlainText(file.readAll());
        this->setWindowTitle(name);

        fileName = path;

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

        stream << ui->plainTextEdit->toPlainText();
        this->setWindowTitle(name);

        ui->statusbar->showMessage("Saving", 1000);

        fileName = path;
        file.close();
    } else {
        QMessageBox::critical(this, "Could not save the file", file.errorString());
    }
}

void IDE::on_actionExit_program_2_triggered() {
    // TODO: Ask to save file before closing

    QApplication::exit();
}

void IDE::on_actionCopy_triggered() {
    ui->plainTextEdit->copy();
}

void IDE::on_actionCut_triggered() {
    ui->plainTextEdit->cut();
}

void IDE::on_actionPaste_triggered() {
    ui->plainTextEdit->paste();
}

void IDE::on_actionSelect_all_triggered() {
    ui->plainTextEdit->selectAll();
}



void IDE::on_actionRun_triggered() {
//    save();
//    editor.setPath("D:\\Javier\\QtLearning\\delayButton\\main.qml");
//    QuickPreview *preview = new QuickPreview();
//    preview->setSource(QUrl("file:///D:/Javier/UCB/Proyecto/Mainframe/applications/Kel-morian-IDE-II/Kel-morian-IDE/Tester.qml"));

//    preview->show();
}

void IDE::on_actionDeploy_triggered() {
    // tar.exe -a -c -f out.zip test.qml sign.png    // this works on windows 10. Compress
    // tar.exe -x -f out.zip  // this also works on windows 10. Uncompress
}
