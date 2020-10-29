#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>
#include "codehighlighter.h"

class CodeEditor : public QPlainTextEdit {
    Q_OBJECT
public:
    CodeEditor(QWidget *parent = nullptr);

    void lineNumberPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

protected:
    void resizeEvent(QResizeEvent *event) override;
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void commentCurrentLine();
    void insertIndentation();
    void updateLineNumberArea(const QRect &rect, int dy);

private:
    QWidget *lineNumberArea;

    CodeHighLighter highlighter;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // CODEEDITOR_H
