#ifndef IDE_H
#define IDE_H

#include <QMainWindow>
#include <preview/quickpreview.h>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
	class IDE;
}

class IDE : public QMainWindow {
	Q_OBJECT

public:
	explicit IDE(QWidget *parent = nullptr);
	~IDE();

private slots:
    void on_actionNew_Project_triggered();
    void on_actionOpen_Project_triggered();
    void on_actionSave_triggered();

    void on_actionRun_triggered();

    void on_actionExit_program_2_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionSelect_all_triggered();

    void on_actionDeploy_triggered();

private:
    void init();
    Ui::IDE *ui;

    QString fileName;
};


#endif // IDE_H
