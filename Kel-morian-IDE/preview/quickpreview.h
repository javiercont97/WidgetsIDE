#ifndef QUICKPREVIEW_H
#define QUICKPREVIEW_H

#include <QWidget>

namespace Ui {
class QuickPreview;
}

class QuickPreview : public QWidget {
    Q_OBJECT

public:
    explicit QuickPreview(QWidget *parent = nullptr);
    ~QuickPreview();

    void setSource(QUrl source);

private:
    Ui::QuickPreview *ui;
};

#endif // QUICKPREVIEW_H
