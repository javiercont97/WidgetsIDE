#include "codeeditor.h"
#include "linenumberarea.h"

#include <QPainter>
#include <QTextBlock>
#include <QDebug>

CodeEditor::CodeEditor(QWidget *parent): QPlainTextEdit(parent) {
    lineNumberArea = new LineNumberArea(this);

    connect(this, &CodeEditor::blockCountChanged, this, &CodeEditor::updateLineNumberAreaWidth);
    connect(this, &CodeEditor::updateRequest, this, &CodeEditor::updateLineNumberArea);
    connect(this, &CodeEditor::cursorPositionChanged, this, &CodeEditor::highlightCurrentLine);

    updateLineNumberAreaWidth(0);
    highlightCurrentLine();

    highlighter.setDocument(this->document());
}

void CodeEditor::lineNumberPaintEvent(QPaintEvent *event) {
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), QColor(48, 48, 48));


    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = qRound(blockBoundingGeometry(block).translated(contentOffset()).top());
    int bottom = top + qRound(blockBoundingRect(block).height());


    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::lightGray);
//            painter.save();
            QFont f = this->font();  // font size in ide.ui file
            painter.setFont(f);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);

//            painter.restore();
        }

        block = block.next();
        top = bottom;
        bottom = top + qRound(blockBoundingRect(block).height());
        ++blockNumber;
    }
}

int CodeEditor::lineNumberAreaWidth() {
    int digits = 1;
    int max = qMax(1, blockCount());

    while(max >= 10) {
        max /= 10;
        digits++;
    }

    int space = 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;
    return space;
}

void CodeEditor::resizeEvent(QResizeEvent *event) {
    QPlainTextEdit::resizeEvent(event);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void CodeEditor::updateLineNumberAreaWidth(int newBlockCount) {
    Q_UNUSED(newBlockCount);
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void CodeEditor::highlightCurrentLine() {
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

//        QColor lineColor = QColor(Qt::yellow).lighter(160);
        QColor lineColor = QColor(QColor(70, 70, 70));

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

void CodeEditor::commentCurrentLine() {
    if(!isReadOnly()) {
        QTextBlock tb = this->document()->findBlockByLineNumber(this->textCursor().blockNumber());
        QString s = tb.text();
        if(s.startsWith("//")) {
            s.remove(0, 2);
        } else {
            s = "//" + s;
        }

        QTextCursor cursor = this->textCursor();
        cursor.select(QTextCursor::LineUnderCursor);
        cursor.removeSelectedText();
        this->setTextCursor(cursor);

        this->insertPlainText(s);
    }
}

void CodeEditor::insertIndentation() {
    if(!isReadOnly()) {
        QTextBlock tb = this->document()->findBlockByLineNumber(this->textCursor().blockNumber());
        QString s = tb.text();

        QString currentIntentation = "";
        int i = 0;
        while(s.at(i) == " ") {
            currentIntentation += " ";
            i ++;
        }

        if(s.endsWith("{")) {
            currentIntentation += "    ";
        }
        currentIntentation = "\n" + currentIntentation;

        this->insertPlainText(currentIntentation);
    }
}

void CodeEditor::updateLineNumberArea(const QRect &rect, int dy) {
    if(dy) {
        lineNumberArea->scroll(0, dy);
    } else {
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());
    }

    if(rect.contains(viewport()->rect())) {
        updateLineNumberAreaWidth(0);
    }
}

void CodeEditor::keyPressEvent(QKeyEvent *event) {
    if(event->modifiers() == Qt::Modifier::CTRL && event->key() == Qt::Key_Slash){
        this->commentCurrentLine();
        //QPlainTextEdit::keyPressEvent(event);
    } else if (event->key() == Qt::Key_Return) {
        this->insertIndentation();
        //QPlainTextEdit::keyPressEvent(event);
    } else {
        QPlainTextEdit::keyPressEvent(event);
    }
}
