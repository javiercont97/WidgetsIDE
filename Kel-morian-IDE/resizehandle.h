#ifndef RESIZEHANDLE_H
#define RESIZEHANDLE_H

#include <QGraphicsRectItem>

class ResizeHandle : public QGraphicsRectItem {
public:
	enum Placement {
		TOP_LEFT,
		TOP,
		TOP_RIGHT,
		RIGHT,
		BOTTOM_RIGHT,
		BOTTOM,
		BOTTOM_LEFT,
		LEFT
	};

	explicit ResizeHandle(Placement p);

	// QGraphicsItem interface
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private:
	Placement handlePlace;
};

#endif // RESIZEHANDLE_H
