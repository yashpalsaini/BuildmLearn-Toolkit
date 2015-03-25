/********************************************************************************
** Form generated from reading UI file 'sampleitem.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMPLEITEM_H
#define UI_SAMPLEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SampleItem
{
public:
    QGridLayout *gridLayout;
    QLabel *m_lblQuestionNumber;
    QFrame *line;
    QLabel *m_lblQuestionText;
    QLabel *m_lblAnswerText;
    QSpacerItem *spacerItem;
    QLabel *m_lblWarning;
    QHBoxLayout *hboxLayout;
    QPushButton *m_btnNext;
    QPushButton *m_btnPrevious;

    void setupUi(QWidget *SampleItem)
    {
        if (SampleItem->objectName().isEmpty())
            SampleItem->setObjectName(QStringLiteral("SampleItem"));
        SampleItem->resize(283, 329);
        gridLayout = new QGridLayout(SampleItem);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        m_lblQuestionNumber = new QLabel(SampleItem);
        m_lblQuestionNumber->setObjectName(QStringLiteral("m_lblQuestionNumber"));

        gridLayout->addWidget(m_lblQuestionNumber, 0, 0, 1, 1);

        line = new QFrame(SampleItem);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 1);

        m_lblQuestionText = new QLabel(SampleItem);
        m_lblQuestionText->setObjectName(QStringLiteral("m_lblQuestionText"));

        gridLayout->addWidget(m_lblQuestionText, 2, 0, 1, 1);

        m_lblAnswerText = new QLabel(SampleItem);
        m_lblAnswerText->setObjectName(QStringLiteral("m_lblAnswerText"));

        gridLayout->addWidget(m_lblAnswerText, 3, 0, 1, 1);

        spacerItem = new QSpacerItem(265, 71, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 4, 0, 1, 1);

        m_lblWarning = new QLabel(SampleItem);
        m_lblWarning->setObjectName(QStringLiteral("m_lblWarning"));
        m_lblWarning->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(m_lblWarning, 5, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        m_btnNext = new QPushButton(SampleItem);
        m_btnNext->setObjectName(QStringLiteral("m_btnNext"));

        hboxLayout->addWidget(m_btnNext);

        m_btnPrevious = new QPushButton(SampleItem);
        m_btnPrevious->setObjectName(QStringLiteral("m_btnPrevious"));

        hboxLayout->addWidget(m_btnPrevious);


        gridLayout->addLayout(hboxLayout, 6, 0, 1, 1);


        retranslateUi(SampleItem);

        QMetaObject::connectSlotsByName(SampleItem);
    } // setupUi

    void retranslateUi(QWidget *SampleItem)
    {
        SampleItem->setWindowTitle(QApplication::translate("SampleItem", "Form", 0));
        m_lblQuestionNumber->setText(QApplication::translate("SampleItem", "Question number", 0));
        m_lblQuestionText->setText(QApplication::translate("SampleItem", "Question text", 0));
        m_lblAnswerText->setText(QApplication::translate("SampleItem", "Answer text", 0));
        m_lblWarning->setText(QString());
        m_btnNext->setText(QApplication::translate("SampleItem", "&Next", 0));
        m_btnPrevious->setText(QApplication::translate("SampleItem", "&Submit", 0));
    } // retranslateUi

};

namespace Ui {
    class SampleItem: public Ui_SampleItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMPLEITEM_H
