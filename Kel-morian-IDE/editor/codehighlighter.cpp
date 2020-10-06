#include "codehighlighter.h"

CodeHighLighter::CodeHighLighter(QTextDocument *parent): QSyntaxHighlighter(parent) {
    HighlightingRule rule;

    QColor magenta = QColor(249, 38, 114);
    QColor green = QColor(166, 226, 46);
    QColor cyan = QColor(102, 217, 239);
    QColor orange = QColor(253, 151, 31);
    QColor purple = QColor(174, 129, 255);
    QColor yellow = QColor(231, 219, 96);

    primaryKeywordFormat.setForeground(magenta);

    const QString keywordPatterns[] = {
        QStringLiteral("\\bimport\\b"), QStringLiteral("\\bexport\\b"), QStringLiteral("\\bdefault\\b"),
        QStringLiteral("\\bif\\b"), QStringLiteral("\\belse\\b"), QStringLiteral("\\bdo\\b"),
        QStringLiteral("\\bwhile\\b"), QStringLiteral("\\bfor\\b"), QStringLiteral("\\bswitch\\b"),
        QStringLiteral("\\breturn\\b"), QStringLiteral("\\bthrow\\b"), QStringLiteral("\\bextends\\b"),
        QStringLiteral("\\bimplements\\b")
    };

    for (const QString &pattern : keywordPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = primaryKeywordFormat;
        rules.append(rule);
    }

    const QString secondaryKeywordPAtterns[] = {
        QStringLiteral("\\blet\\b"), QStringLiteral("\\bclass\\b"), QStringLiteral("\\bconst\\b"),
        QStringLiteral("\\benum\\b"), QStringLiteral("\\bvar\\b"), QStringLiteral("\\bfunction\\b")
    };

    secondaryKeywordFormat.setForeground(cyan);
    secondaryKeywordFormat.setFontItalic(true);

    for (const QString &pattern : secondaryKeywordPAtterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = secondaryKeywordFormat;
        rules.append(rule);
    }

    thisKeywordFormat.setForeground(orange);
    thisKeywordFormat.setFontItalic(true);
    rule.pattern = QRegularExpression(QStringLiteral("\\bthis\\b"));
    rule.format = thisKeywordFormat;
    rules.append(rule);


    staticKeywordFormat.setForeground(green);
    rule.pattern = QRegularExpression(QStringLiteral("\\bstatic\\b"));
    rule.format = staticKeywordFormat;
    rules.append(rule);


    // ===================== highlight js class definition with bold and darkmagenta font
    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(magenta);
    rule.pattern = QRegularExpression(QStringLiteral("\\bQ[A-Za-z]+\\b"));
    rule.format = classFormat;
    rules.append(rule);

    // ===================== highlight js quotation definition with darkgreen font
    quotationFormat.setForeground(yellow);
    rule.pattern = QRegularExpression(QStringLiteral("(\".*\")|(`.*`)"));
    rule.format = quotationFormat;
    rules.append(rule);

    // ===================== highlight js function definition with italic and blue font
    functionFormat.setFontItalic(true);
    functionFormat.setForeground(green);
    rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+[\r\n\t\f\v ]*(?=\\()"));
    rule.format = functionFormat;
    rules.append(rule);

    // ===================== highlight js single-line comment definition with darkgray font
    singleLineCommentFormat.setForeground(Qt::darkGray);
    rule.pattern = QRegularExpression(QStringLiteral("//[^\n]*"));
    rule.format = singleLineCommentFormat;
    rules.append(rule);

    // ===================== highlight qml item with magenta font
    qmlItem.setForeground(magenta);
    rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+[\r\n\t\f\v ]*(?=\\{)"));
    rule.format = qmlItem;
    rules.append(rule);

    // ===================== highlight qml item property with cyan font
    qmlProperty.setForeground(cyan);
    rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_\\.]*(?=\\:)"));
    rule.format = qmlProperty;
    rules.append(rule);

    // ===================== highlight js milti-line comment definition with darkred font
    multiLineCommentFormat.setForeground(Qt::darkGray);

    commentStartExpression = QRegularExpression(QStringLiteral("/\\*"));
    commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));
}



void CodeHighLighter::highlightBlock(const QString &text) {
    // ===================== run highlight rules when the text block changes
    for (const HighlightingRule &rule : qAsConst(rules)) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }


    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);

    while (startIndex >= 0) {
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                    + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}

