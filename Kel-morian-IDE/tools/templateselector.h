#ifndef TEMPLATESELECTOR_H
#define TEMPLATESELECTOR_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class TemplateSelector;
}

class TemplateSelector : public QDialog {
    Q_OBJECT

public:
    explicit TemplateSelector(QWidget *parent = nullptr);
    ~TemplateSelector();

    QString getCode() const;

private:
    void selectionChanged(QListWidgetItem *i);

private:
    Ui::TemplateSelector *ui;

    QString code;
};

#endif // TEMPLATESELECTOR_H
