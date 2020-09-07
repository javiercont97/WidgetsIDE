#ifndef IDE_H
#define IDE_H

#include <QMainWindow>

#include <QGraphicsScene>

namespace Ui {
	class IDE;
}

class IDE : public QMainWindow {
	Q_OBJECT

public:
	explicit IDE(QWidget *parent = nullptr);
	~IDE();

private slots:
	QGraphicsItem* getSelectedItem();
	void initWidgetList();
	void initCanvas();
	void init();

private:
	Ui::IDE *ui;

	QGraphicsScene *scene;
	QGraphicsRectItem *canvasRect;

};

#endif // IDE_H
