#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QObject>
#include <QGraphicsItem>

class CanvasWidget : public QObject, QGraphicsItem {
	Q_OBJECT
public:
	explicit CanvasWidget(QObject *parent = nullptr);

signals:

};

#endif // CANVASWIDGET_H
