/********************************************************************************
** Form generated from reading UI file 'sampleeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMPLEEDITOR_H
#define UI_SAMPLEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "lineeditwithstatus.h"
#include "maxlengthtextedit.h"
#include "plaintoolbutton.h"

QT_BEGIN_NAMESPACE

class Ui_SampleEditor
{
public:
    QGroupBox *m_groupQuestionEditor;
    QGridLayout *gridLayout;
    QLabel *label;
    MaxLengthTextEdit *m_txtQuestion;
    QLabel *label_2;
    MaxLengthTextEdit *m_txtAnswer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout1;
    PlainToolButton *m_btnQuestionAdd;
    PlainToolButton *m_btnQuestionDown;
    PlainToolButton *m_btnQuestionRemove;
    PlainToolButton *m_btnQuestionUp;
    QSpacerItem *spacerItem;
    QListWidget *m_listQuestions;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout2;
    QLabel *label_3;
    LineEditWithStatus *m_txtAuthor;
    QLabel *label_4;
    LineEditWithStatus *m_txtName;
    QLabel *label_5;
    LineEditWithStatus *m_txtNumberOfQuestions;

    void setupUi(QWidget *SampleEditor)
    {
        if (SampleEditor->objectName().isEmpty())
            SampleEditor->setObjectName(QStringLiteral("SampleEditor"));
        SampleEditor->resize(595, 439);
        m_groupQuestionEditor = new QGroupBox(SampleEditor);
        m_groupQuestionEditor->setObjectName(QStringLiteral("m_groupQuestionEditor"));
        m_groupQuestionEditor->setGeometry(QRect(0, 0, 319, 334));
        gridLayout = new QGridLayout(m_groupQuestionEditor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(m_groupQuestionEditor);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_txtQuestion = new MaxLengthTextEdit(m_groupQuestionEditor);
        m_txtQuestion->setObjectName(QStringLiteral("m_txtQuestion"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(m_txtQuestion->sizePolicy().hasHeightForWidth());
        m_txtQuestion->setSizePolicy(sizePolicy);
        m_txtQuestion->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_txtQuestion->setTabChangesFocus(true);
        m_txtQuestion->setAcceptRichText(false);

        gridLayout->addWidget(m_txtQuestion, 0, 1, 1, 1);

        label_2 = new QLabel(m_groupQuestionEditor);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        m_txtAnswer = new MaxLengthTextEdit(m_groupQuestionEditor);
        m_txtAnswer->setObjectName(QStringLiteral("m_txtAnswer"));
        sizePolicy.setHeightForWidth(m_txtAnswer->sizePolicy().hasHeightForWidth());
        m_txtAnswer->setSizePolicy(sizePolicy);
        m_txtAnswer->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_txtAnswer->setTabChangesFocus(true);
        m_txtAnswer->setAcceptRichText(false);

        gridLayout->addWidget(m_txtAnswer, 1, 1, 1, 1);

        groupBox_2 = new QGroupBox(SampleEditor);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(325, 0, 270, 428));
        gridLayout1 = new QGridLayout(groupBox_2);
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        m_btnQuestionAdd = new PlainToolButton(groupBox_2);
        m_btnQuestionAdd->setObjectName(QStringLiteral("m_btnQuestionAdd"));
        m_btnQuestionAdd->setIconSize(QSize(24, 24));

        gridLayout1->addWidget(m_btnQuestionAdd, 1, 0, 1, 1);

        m_btnQuestionDown = new PlainToolButton(groupBox_2);
        m_btnQuestionDown->setObjectName(QStringLiteral("m_btnQuestionDown"));
        m_btnQuestionDown->setEnabled(false);
        m_btnQuestionDown->setIconSize(QSize(24, 24));

        gridLayout1->addWidget(m_btnQuestionDown, 1, 3, 1, 1);

        m_btnQuestionRemove = new PlainToolButton(groupBox_2);
        m_btnQuestionRemove->setObjectName(QStringLiteral("m_btnQuestionRemove"));
        m_btnQuestionRemove->setEnabled(false);
        m_btnQuestionRemove->setIconSize(QSize(24, 24));

        gridLayout1->addWidget(m_btnQuestionRemove, 1, 1, 1, 1);

        m_btnQuestionUp = new PlainToolButton(groupBox_2);
        m_btnQuestionUp->setObjectName(QStringLiteral("m_btnQuestionUp"));
        m_btnQuestionUp->setEnabled(false);
        m_btnQuestionUp->setIconSize(QSize(24, 24));

        gridLayout1->addWidget(m_btnQuestionUp, 1, 2, 1, 1);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem, 1, 4, 1, 1);

        m_listQuestions = new QListWidget(groupBox_2);
        m_listQuestions->setObjectName(QStringLiteral("m_listQuestions"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_listQuestions->sizePolicy().hasHeightForWidth());
        m_listQuestions->setSizePolicy(sizePolicy1);

        gridLayout1->addWidget(m_listQuestions, 0, 0, 1, 5);

        groupBox_3 = new QGroupBox(SampleEditor);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 340, 319, 88));
        gridLayout2 = new QGridLayout(groupBox_3);
        gridLayout2->setObjectName(QStringLiteral("gridLayout2"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout2->addWidget(label_3, 0, 0, 1, 1);

        m_txtAuthor = new LineEditWithStatus(groupBox_3);
        m_txtAuthor->setObjectName(QStringLiteral("m_txtAuthor"));

        gridLayout2->addWidget(m_txtAuthor, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout2->addWidget(label_4, 1, 0, 1, 1);

        m_txtName = new LineEditWithStatus(groupBox_3);
        m_txtName->setObjectName(QStringLiteral("m_txtName"));

        gridLayout2->addWidget(m_txtName, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout2->addWidget(label_5, 2, 0, 1, 1);

        m_txtNumberOfQuestions = new LineEditWithStatus(groupBox_3);
        m_txtNumberOfQuestions->setObjectName(QStringLiteral("m_txtNumberOfQuestions"));
        m_txtNumberOfQuestions->setEnabled(true);

        gridLayout2->addWidget(m_txtNumberOfQuestions, 2, 1, 1, 1);


        retranslateUi(SampleEditor);

        QMetaObject::connectSlotsByName(SampleEditor);
    } // setupUi

    void retranslateUi(QWidget *SampleEditor)
    {
        SampleEditor->setWindowTitle(QApplication::translate("SampleEditor", "Form", 0));
        m_groupQuestionEditor->setTitle(QApplication::translate("SampleEditor", "Question editor", 0));
        label->setText(QApplication::translate("SampleEditor", "Question", 0));
        m_txtQuestion->setHtml(QApplication::translate("SampleEditor", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>", 0));
        label_2->setText(QApplication::translate("SampleEditor", "Answers", 0));
        m_txtAnswer->setHtml(QApplication::translate("SampleEditor", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>", 0));
        groupBox_2->setTitle(QApplication::translate("SampleEditor", "Active questions", 0));
#ifndef QT_NO_TOOLTIP
        m_btnQuestionAdd->setToolTip(QApplication::translate("SampleEditor", "Add new question.", 0));
#endif // QT_NO_TOOLTIP
        m_btnQuestionAdd->setText(QApplication::translate("SampleEditor", "...", 0));
#ifndef QT_NO_TOOLTIP
        m_btnQuestionDown->setToolTip(QApplication::translate("SampleEditor", "Move question down.", 0));
#endif // QT_NO_TOOLTIP
        m_btnQuestionDown->setText(QApplication::translate("SampleEditor", "...", 0));
#ifndef QT_NO_TOOLTIP
        m_btnQuestionRemove->setToolTip(QApplication::translate("SampleEditor", "Remove selected question.", 0));
#endif // QT_NO_TOOLTIP
        m_btnQuestionRemove->setText(QApplication::translate("SampleEditor", "...", 0));
#ifndef QT_NO_TOOLTIP
        m_btnQuestionUp->setToolTip(QApplication::translate("SampleEditor", "Move question up.", 0));
#endif // QT_NO_TOOLTIP
        m_btnQuestionUp->setText(QApplication::translate("SampleEditor", "...", 0));
#ifndef QT_NO_TOOLTIP
        m_listQuestions->setToolTip(QApplication::translate("SampleEditor", "This list contains already added questions.", 0));
#endif // QT_NO_TOOLTIP
        groupBox_3->setTitle(QApplication::translate("SampleEditor", "Sample metadata", 0));
        label_3->setText(QApplication::translate("SampleEditor", "Author", 0));
        label_4->setText(QApplication::translate("SampleEditor", "Sample name", 0));
        label_5->setText(QApplication::translate("SampleEditor", "Number of questions", 0));
    } // retranslateUi

};

namespace Ui {
    class SampleEditor: public Ui_SampleEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMPLEEDITOR_H
