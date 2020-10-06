#ifndef CODEHIGHLIGHTER_H
#define CODEHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class CodeHighLighter : public QSyntaxHighlighter {
public:
    CodeHighLighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightingRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };

    QVector<HighlightingRule> rules;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat primaryKeywordFormat;
    QTextCharFormat secondaryKeywordFormat;
    QTextCharFormat staticKeywordFormat;
    QTextCharFormat thisKeywordFormat;

    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
    QTextCharFormat qmlItem;
    QTextCharFormat qmlProperty;
};

#endif // CODEHIGHLIGHTER_H
