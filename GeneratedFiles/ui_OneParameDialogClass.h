/********************************************************************************
** Form generated from reading UI file 'OneParameDialogClass.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONEPARAMEDIALOGCLASS_H
#define UI_ONEPARAMEDIALOGCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OneParameDialogClass
{
public:
    QPushButton *OK;
    QPushButton *Cancal;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_1;
    QLineEdit *lineEdit_1;

    void setupUi(QDialog *OneParameDialogClass)
    {
        if (OneParameDialogClass->objectName().isEmpty())
            OneParameDialogClass->setObjectName(QStringLiteral("OneParameDialogClass"));
        OneParameDialogClass->resize(388, 104);
        OK = new QPushButton(OneParameDialogClass);
        OK->setObjectName(QStringLiteral("OK"));
        OK->setGeometry(QRect(280, 20, 93, 28));
        Cancal = new QPushButton(OneParameDialogClass);
        Cancal->setObjectName(QStringLiteral("Cancal"));
        Cancal->setGeometry(QRect(280, 60, 93, 28));
        layoutWidget = new QWidget(OneParameDialogClass);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 252, 23));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(layoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));

        horizontalLayout->addWidget(label_1);

        lineEdit_1 = new QLineEdit(layoutWidget);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_1->sizePolicy().hasHeightForWidth());
        lineEdit_1->setSizePolicy(sizePolicy);
        lineEdit_1->setMinimumSize(QSize(40, 0));
        lineEdit_1->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(lineEdit_1);


        retranslateUi(OneParameDialogClass);

        QMetaObject::connectSlotsByName(OneParameDialogClass);
    } // setupUi

    void retranslateUi(QDialog *OneParameDialogClass)
    {
        OneParameDialogClass->setWindowTitle(QApplication::translate("OneParameDialogClass", "OneParameDialogClass", 0));
        OK->setText(QApplication::translate("OneParameDialogClass", "PushButton", 0));
        Cancal->setText(QApplication::translate("OneParameDialogClass", "PushButton", 0));
        label_1->setText(QApplication::translate("OneParameDialogClass", "TextLabel", 0));
        lineEdit_1->setText(QApplication::translate("OneParameDialogClass", "0.1", 0));
    } // retranslateUi

};

namespace Ui {
    class OneParameDialogClass: public Ui_OneParameDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEPARAMEDIALOGCLASS_H
