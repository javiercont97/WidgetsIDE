#include "resizableitem.h"
#include <QPen>
#include <QGraphicsScene>
#include <QPainter>


ResizableItem::ResizableItem() {

}

QRectF ResizableItem::selectorFrameBounds() const {
    return rect();
}

void ResizableItem::setSelectorFrameBounds(QRectF bounds) {
    prepareGeometryChange();
    setRect(bounds);
    update();
}

void ResizableItem::drawHandlesIfNecessary() {
    if(isSelected()) {
        drawHandles();
    } else {
        foreach(ResizeHandle *item, handles) {
            scene()->removeItem(item);
        }
        qDeleteAll(handles);
        handles.clear();
        handlesDrawn = false;
    }
}

QRectF ResizableItem::boundingRect() const {
    return selectorFrameBounds();
}

void ResizableItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();
//    painter->setBrush(brush());
//    painter->drawRect(rect());
    drawHandlesIfNecessary();

    painter->restore();
    QGraphicsRectItem::paint(painter, option, widget);
}

void ResizableItem::drawHandles() {
    if(handles.count() == 0) {
        handles.append(new ResizeHandle(ResizeHandle::TOP_LEFT));
        handles.append(new ResizeHandle(ResizeHandle::TOP_RIGHT));
        handles.append(new ResizeHandle(ResizeHandle::BOTTOM_LEFT));
        handles.append(new ResizeHandle(ResizeHandle::BOTTOM_RIGHT));
    }

    QPen handlePen;
    QBrush handleBrush(Qt::gray);

    QPointF topLeftCorner = boundingRect().topLeft() + QPointF(-12.0, -12.0);
    topLeftHandle = QRectF(topLeftCorner, QSize(12, 12));
    handles[0]->setRect(topLeftHandle);
    if(!handles.isEmpty() && (!handlesDrawn)) {
        handles[0]->setPen(handlePen);
        handles[0]->setBrush(handleBrush);
        scene()->addItem(handles[0]);
        handles[0]->setParentItem(this);
    }

    QPointF topRightCorner = boundingRect().topRight() + QPointF(0, -12.0);
    topRightHandle = QRectF(topRightCorner, QSize(12, 12));
    handles[1]->setRect(topRightHandle);
    if(!handles.isEmpty() && (!handlesDrawn)) {
        handles[1]->setPen(handlePen);
        handles[1]->setBrush(handleBrush);
        scene()->addItem(handles[1]);
        handles[1]->setParentItem(this);
    }

    QPointF bottomLeftCorner = boundingRect().bottomLeft() + QPointF(-12.0, 12.0);
    bottomLeftHandle = QRectF(bottomLeftCorner, QSize(12, 12));
    handles[2]->setRect(bottomLeftHandle);
    if(!handles.isEmpty() && (!handlesDrawn)) {
        handles[2]->setPen(handlePen);
        handles[2]->setBrush(handleBrush);
        scene()->addItem(handles[2]);
        handles[2]->setParentItem(this);
    }

    QPointF bottomRightCorner = boundingRect().bottomRight() + QPointF(0, 12.0);
    bottomRightHandle = QRectF(bottomRightCorner, QSize(12, 12));
    handles[3]->setRect(bottomRightHandle);
    if(!handles.isEmpty() && (!handlesDrawn)) {
        handles[3]->setPen(handlePen);
        handles[3]->setBrush(handleBrush);
        scene()->addItem(handles[3]);
        handles[3]->setParentItem(this);
    }

    handlesDrawn = true;
}
