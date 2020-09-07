#ifndef RESIZABLEITEM_H
#define RESIZABLEITEM_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <resizehandle.h>

class ResizableItem: public QGraphicsRectItem {
public:
    ResizableItem();

    QRectF selectorFrameBounds() const;
    void setSelectorFrameBounds(QRectF bounds);

    void drawHandlesIfNecessary();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    void drawHandles();

    QRectF topLeftHandle;
    QRectF topRightHandle;
    QRectF bottomLeftHandle;
    QRectF bottomRightHandle;

    QList<ResizeHandle *> handles;
    bool handlesDrawn = false;
};

#endif // RESIZABLEITEM_H
