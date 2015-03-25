/********************************************************************************
** Form generated from reading UI file 'samplesimulator.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMPLESIMULATOR_H
#define UI_SAMPLESIMULATOR_H

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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SampleSimulator
{
public:
    QHBoxLayout *hboxLayout;
    QStackedWidget *m_phoneWidget;
    QWidget *m_pageStopped;
    QHBoxLayout *hboxLayout1;
    QLabel *m_lblHeading_2;
    QWidget *m_pageWelcome;
    QVBoxLayout *vboxLayout;
    QSpacerItem *spacerItem;
    QLabel *m_lblHeading;
    QFrame *line_2;
    QLabel *m_lblAuthor;
    QSpacerItem *spacerItem1;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacerItem2;
    QPushButton *m_btnStart;
    QSpacerItem *spacerItem3;
    QWidget *m_pageFinish;
    QVBoxLayout *vboxLayout1;
    QLabel *label;
    QFrame *line;
    QSpacerItem *spacerItem4;
    QGridLayout *gridLayout;
    QSpacerItem *spacerItem5;
    QPushButton *m_btnExit;
    QSpacerItem *spacerItem6;
    QPushButton *m_btnRestart;

    void setupUi(QWidget *SampleSimulator)
    {
        if (SampleSimulator->objectName().isEmpty())
            SampleSimulator->setObjectName(QStringLiteral("SampleSimulator"));
        SampleSimulator->resize(378, 339);
        hboxLayout = new QHBoxLayout(SampleSimulator);
        hboxLayout->setSpacing(0);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        m_phoneWidget = new QStackedWidget(SampleSimulator);
        m_phoneWidget->setObjectName(QStringLiteral("m_phoneWidget"));
        m_pageStopped = new QWidget();
        m_pageStopped->setObjectName(QStringLiteral("m_pageStopped"));
        hboxLayout1 = new QHBoxLayout(m_pageStopped);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        m_lblHeading_2 = new QLabel(m_pageStopped);
        m_lblHeading_2->setObjectName(QStringLiteral("m_lblHeading_2"));
        m_lblHeading_2->setAlignment(Qt::AlignCenter);

        hboxLayout1->addWidget(m_lblHeading_2);

        m_phoneWidget->addWidget(m_pageStopped);
        m_pageWelcome = new QWidget();
        m_pageWelcome->setObjectName(QStringLiteral("m_pageWelcome"));
        vboxLayout = new QVBoxLayout(m_pageWelcome);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        spacerItem = new QSpacerItem(20, 116, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);

        m_lblHeading = new QLabel(m_pageWelcome);
        m_lblHeading->setObjectName(QStringLiteral("m_lblHeading"));
        m_lblHeading->setAlignment(Qt::AlignCenter);

        vboxLayout->addWidget(m_lblHeading);

        line_2 = new QFrame(m_pageWelcome);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line_2);

        m_lblAuthor = new QLabel(m_pageWelcome);
        m_lblAuthor->setObjectName(QStringLiteral("m_lblAuthor"));
        m_lblAuthor->setAlignment(Qt::AlignCenter);

        vboxLayout->addWidget(m_lblAuthor);

        spacerItem1 = new QSpacerItem(20, 115, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem2);

        m_btnStart = new QPushButton(m_pageWelcome);
        m_btnStart->setObjectName(QStringLiteral("m_btnStart"));
        m_btnStart->setEnabled(false);

        hboxLayout2->addWidget(m_btnStart);

        spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem3);


        vboxLayout->addLayout(hboxLayout2);

        m_phoneWidget->addWidget(m_pageWelcome);
        m_pageFinish = new QWidget();
        m_pageFinish->setObjectName(QStringLiteral("m_pageFinish"));
        vboxLayout1 = new QVBoxLayout(m_pageFinish);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        label = new QLabel(m_pageFinish);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        vboxLayout1->addWidget(label);

        line = new QFrame(m_pageFinish);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        vboxLayout1->addWidget(line);

        spacerItem4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem5, 0, 2, 2, 1);

        m_btnExit = new QPushButton(m_pageFinish);
        m_btnExit->setObjectName(QStringLiteral("m_btnExit"));

        gridLayout->addWidget(m_btnExit, 1, 1, 1, 1);

        spacerItem6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem6, 0, 0, 2, 1);

        m_btnRestart = new QPushButton(m_pageFinish);
        m_btnRestart->setObjectName(QStringLiteral("m_btnRestart"));

        gridLayout->addWidget(m_btnRestart, 0, 1, 1, 1);


        vboxLayout1->addLayout(gridLayout);

        m_phoneWidget->addWidget(m_pageFinish);

        hboxLayout->addWidget(m_phoneWidget);


        retranslateUi(SampleSimulator);

        m_phoneWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SampleSimulator);
    } // setupUi

    void retranslateUi(QWidget *SampleSimulator)
    {
        SampleSimulator->setWindowTitle(QApplication::translate("SampleSimulator", "Form", 0));
        m_lblHeading_2->setText(QApplication::translate("SampleSimulator", "<span style=\" font-size:18pt;\">Sample Question Answer</span>", 0));
        m_lblHeading->setText(QApplication::translate("SampleSimulator", "Heading", 0));
        m_lblAuthor->setText(QApplication::translate("SampleSimulator", "Author", 0));
        m_btnStart->setText(QApplication::translate("SampleSimulator", "&Start", 0));
        label->setText(QApplication::translate("SampleSimulator", "You have completed the sample", 0));
        m_btnExit->setText(QApplication::translate("SampleSimulator", "&Exit", 0));
        m_btnRestart->setText(QApplication::translate("SampleSimulator", "&Restart", 0));
    } // retranslateUi

};

namespace Ui {
    class SampleSimulator: public Ui_SampleSimulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMPLESIMULATOR_H
