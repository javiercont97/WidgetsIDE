#include "ide.h"
#include "ui_ide.h"

#include <QList>
#include <QListWidgetItem>
#include <QGraphicsRectItem>

#include <resizableitem.h> // resizable rectangle

IDE::IDE(QWidget *parent): QMainWindow(parent),ui(new Ui::IDE) {
	ui->setupUi(this);

	this->setCentralWidget(ui->splitter);  // set central widget
	init();


	for(int i=0;i<3;i++) {
        ResizableItem *rect = new ResizableItem();
        rect->setRect(-200 * i + 205, 0, 200, 100);
        scene->addItem(rect);

		rect->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable);

		rect->setBrush(QBrush(Qt::GlobalColor::darkCyan));
		rect->setParentItem(canvasRect);
	}
}

IDE::~IDE() {
	delete ui;
}

QGraphicsItem *IDE::getSelectedItem() {
	if(scene->selectedItems().count() > 0) {
		return scene->selectedItems().at(0);
	}
	return nullptr;
}


void IDE::initWidgetList() {
	QList<QListWidgetItem*> items;
	items << new QListWidgetItem("Button");
	items << new QListWidgetItem("Slider");
	items << new QListWidgetItem("Dial");
	items << new QListWidgetItem("Switch");

	items << new QListWidgetItem("Gauge");
	items << new QListWidgetItem("Display");

	ui->widgetsList->setSpacing(5);
	ui->widgetsList->setViewMode(QListWidget::ViewMode::IconMode); // ????

	foreach(QListWidgetItem *item, items) {
		ui->widgetsList->addItem(item);
	}
}

void IDE::initCanvas() {
	scene = new QGraphicsScene(this);

	QBrush bbrush(QColor(64, 64, 64, 255)); // setup a solid gray background
	//	QBrush bbrush(QColor(64, 64, 64, 50), Qt::BrushStyle::CrossPattern); // setup a gray grid

	scene->setBackgroundBrush(bbrush);

	scene->setSceneRect(-300, -200, 600, 400);


	QGraphicsRectItem *canvasRect = scene->addRect(-300, -200, 600, 400);
	canvasRect->setFlags(QGraphicsItem::ItemIsSelectable);
	canvasRect->setBrush(QBrush(Qt::GlobalColor::white));
	//	canvasRect->setBrush(QBrush(Qt::GlobalColor::white, Qt::BrushStyle::CrossPattern));
	//	canvasRect->setFlag(QGraphicsItem::ItemClipsChildrenToShape);  // clips children items to canvasRect bounds // not working after scene is set

	ui->uiCanvas->setScene(scene);
}

void IDE::init() {
	initCanvas();
	initWidgetList();
}
