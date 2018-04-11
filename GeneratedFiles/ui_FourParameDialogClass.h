/********************************************************************************
** Form generated from reading UI file 'FourParameDialogClass.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOURPARAMEDIALOGCLASS_H
#define UI_FOURPARAMEDIALOGCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FourParameDialogClass
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *OK;
    QPushButton *Cancal;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_1;
    QLineEdit *lineEdit_1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_4;

    void setupUi(QWidget *FourParameDialogClass)
    {
        if (FourParameDialogClass->objectName().isEmpty())
            FourParameDialogClass->setObjectName(QStringLiteral("FourParameDialogClass"));
        FourParameDialogClass->resize(487, 135);
        layoutWidget = new QWidget(FourParameDialogClass);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(380, 30, 95, 65));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        OK = new QPushButton(layoutWidget);
        OK->setObjectName(QStringLiteral("OK"));

        verticalLayout_2->addWidget(OK);

        Cancal = new QPushButton(layoutWidget);
        Cancal->setObjectName(QStringLiteral("Cancal"));

        verticalLayout_2->addWidget(Cancal);

        layoutWidget1 = new QWidget(FourParameDialogClass);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 14, 361, 115));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_1 = new QLabel(layoutWidget1);
        label_1->setObjectName(QStringLiteral("label_1"));

        horizontalLayout->addWidget(label_1);

        lineEdit_1 = new QLineEdit(layoutWidget1);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));
        lineEdit_1->setMaximumSize(QSize(70, 50));
        lineEdit_1->setCursor(QCursor(Qt::SizeVerCursor));

        horizontalLayout->addWidget(lineEdit_1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(layoutWidget1);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(layoutWidget1);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_3->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_4 = new QLineEdit(layoutWidget1);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_4->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(FourParameDialogClass);

        QMetaObject::connectSlotsByName(FourParameDialogClass);
    } // setupUi

    void retranslateUi(QWidget *FourParameDialogClass)
    {
        FourParameDialogClass->setWindowTitle(QApplication::translate("FourParameDialogClass", "FourParameDialogClass", 0));
        OK->setText(QApplication::translate("FourParameDialogClass", "OK", 0));
        Cancal->setText(QApplication::translate("FourParameDialogClass", "CANCAL", 0));
        label_1->setText(QApplication::translate("FourParameDialogClass", "TextLabel", 0));
        lineEdit_1->setText(QApplication::translate("FourParameDialogClass", "0.2", 0));
        label_2->setText(QApplication::translate("FourParameDialogClass", "TextLabel", 0));
        lineEdit_2->setText(QApplication::translate("FourParameDialogClass", "100", 0));
        label_3->setText(QApplication::translate("FourParameDialogClass", "TextLabel", 0));
        lineEdit_3->setText(QApplication::translate("FourParameDialogClass", "0.1", 0));
        label_4->setText(QApplication::translate("FourParameDialogClass", "TextLabel", 0));
        lineEdit_4->setText(QApplication::translate("FourParameDialogClass", "0.4", 0));
    } // retranslateUi

};

namespace Ui {
    class FourParameDialogClass: public Ui_FourParameDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOURPARAMEDIALOGCLASS_H
