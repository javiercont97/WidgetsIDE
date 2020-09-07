#include "resizehandle.h"
#include "resizableitem.h"

#include <QGraphicsSceneMouseEvent>

ResizeHandle::ResizeHandle(Placement p): handlePlace(p) {
    setFlag(QGraphicsItem::ItemIsMovable);
}

void ResizeHandle::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    ResizableItem *rect = dynamic_cast<ResizableItem*>(parentItem());

	switch (handlePlace) {
    case TOP_LEFT:
        if(rect) {
            QRectF bound = rect->selectorFrameBounds();
            bound.setTop(event->pos().y());
            bound.setLeft(event->pos().x());
            rect->setSelectorFrameBounds(bound);
        }
        break;
	case TOP_RIGHT:
        if(rect) {
            QRectF bound = rect->selectorFrameBounds();
            bound.setTop(event->pos().y());
            bound.setRight(event->pos().x());
            rect->setSelectorFrameBounds(bound);
        }
		break;
	case BOTTOM_LEFT:
        if(rect) {
            QRectF bound = rect->selectorFrameBounds();
            bound.setBottom(event->pos().y());
            bound.setLeft(event->pos().x());
            rect->setSelectorFrameBounds(bound);
        }
	break;
	case BOTTOM_RIGHT:
        if(rect) {
            QRectF bound = rect->selectorFrameBounds();
            bound.setBottom(event->pos().y());
            bound.setRight(event->pos().x());
            rect->setSelectorFrameBounds(bound);
        }
	break;
	default:
		// DO NOTHING
		break;
	}
}
