/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionOpen;
    QAction *actionClear;
    QAction *actionSelect;
    QAction *actionCoordinate;
    QAction *actionBackGroundSelect;
    QAction *actionBlack;
    QAction *actionWhite;
    QAction *actionGreen;
    QAction *actionRed;
    QAction *actionBule;
    QAction *actionIncrease;
    QAction *actionDecrease;
    QAction *actionRansac;
    QAction *actionRansacPlane;
    QAction *actionFeatureValue;
    QAction *actionEuropeCluster;
    QAction *actionFeatureOutput;
    QAction *actionTop_View;
    QAction *actionLeft_View;
    QAction *actionMain_View;
    QAction *actionSave;
    QAction *actionObbCube;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuBackGround;
    QMenu *menuColor;
    QMenu *menuPointSize;
    QMenu *menuThreeView;
    QMenu *menuTool;
    QMenu *menuFeature;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(777, 570);
        actionOpen = new QAction(MainWindowClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/MainWindow/Resources/open.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionClear = new QAction(MainWindowClass);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/MainWindow/Resources/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon1);
        actionSelect = new QAction(MainWindowClass);
        actionSelect->setObjectName(QStringLiteral("actionSelect"));
        actionCoordinate = new QAction(MainWindowClass);
        actionCoordinate->setObjectName(QStringLiteral("actionCoordinate"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MainWindow/Resources/Coordinate.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionCoordinate->setIcon(icon2);
        actionBackGroundSelect = new QAction(MainWindowClass);
        actionBackGroundSelect->setObjectName(QStringLiteral("actionBackGroundSelect"));
        actionBlack = new QAction(MainWindowClass);
        actionBlack->setObjectName(QStringLiteral("actionBlack"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/MainWindow/Resources/Black.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionBlack->setIcon(icon3);
        actionWhite = new QAction(MainWindowClass);
        actionWhite->setObjectName(QStringLiteral("actionWhite"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/MainWindow/Resources/White.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionWhite->setIcon(icon4);
        actionGreen = new QAction(MainWindowClass);
        actionGreen->setObjectName(QStringLiteral("actionGreen"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/MainWindow/Resources/Green.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGreen->setIcon(icon5);
        actionRed = new QAction(MainWindowClass);
        actionRed->setObjectName(QStringLiteral("actionRed"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/MainWindow/Resources/Red.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRed->setIcon(icon6);
        actionBule = new QAction(MainWindowClass);
        actionBule->setObjectName(QStringLiteral("actionBule"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/MainWindow/Resources/Blue.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBule->setIcon(icon7);
        actionIncrease = new QAction(MainWindowClass);
        actionIncrease->setObjectName(QStringLiteral("actionIncrease"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/MainWindow/Resources/\347\202\271\345\242\236\345\244\247.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIncrease->setIcon(icon8);
        actionDecrease = new QAction(MainWindowClass);
        actionDecrease->setObjectName(QStringLiteral("actionDecrease"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/MainWindow/Resources/\347\202\271\345\207\217\345\260\217.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDecrease->setIcon(icon9);
        actionRansac = new QAction(MainWindowClass);
        actionRansac->setObjectName(QStringLiteral("actionRansac"));
        actionRansacPlane = new QAction(MainWindowClass);
        actionRansacPlane->setObjectName(QStringLiteral("actionRansacPlane"));
        actionFeatureValue = new QAction(MainWindowClass);
        actionFeatureValue->setObjectName(QStringLiteral("actionFeatureValue"));
        actionEuropeCluster = new QAction(MainWindowClass);
        actionEuropeCluster->setObjectName(QStringLiteral("actionEuropeCluster"));
        actionFeatureOutput = new QAction(MainWindowClass);
        actionFeatureOutput->setObjectName(QStringLiteral("actionFeatureOutput"));
        actionTop_View = new QAction(MainWindowClass);
        actionTop_View->setObjectName(QStringLiteral("actionTop_View"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/MainWindow/Resources/fushi.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTop_View->setIcon(icon10);
        actionLeft_View = new QAction(MainWindowClass);
        actionLeft_View->setObjectName(QStringLiteral("actionLeft_View"));
        QIcon icon11;
        icon11.addFile(QStringLiteral("Resources/zuoshi.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLeft_View->setIcon(icon11);
        actionMain_View = new QAction(MainWindowClass);
        actionMain_View->setObjectName(QStringLiteral("actionMain_View"));
        QIcon icon12;
        icon12.addFile(QStringLiteral("Resources/zhengshi.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMain_View->setIcon(icon12);
        actionSave = new QAction(MainWindowClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/MainWindow/Resources/save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon13);
        actionObbCube = new QAction(MainWindowClass);
        actionObbCube->setObjectName(QStringLiteral("actionObbCube"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/MainWindow/Resources/20180408201117.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionObbCube->setIcon(icon14);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 777, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuBackGround = new QMenu(menuView);
        menuBackGround->setObjectName(QStringLiteral("menuBackGround"));
        menuColor = new QMenu(menuView);
        menuColor->setObjectName(QStringLiteral("menuColor"));
        menuPointSize = new QMenu(menuView);
        menuPointSize->setObjectName(QStringLiteral("menuPointSize"));
        menuThreeView = new QMenu(menuView);
        menuThreeView->setObjectName(QStringLiteral("menuThreeView"));
        menuTool = new QMenu(menuBar);
        menuTool->setObjectName(QStringLiteral("menuTool"));
        menuFeature = new QMenu(menuTool);
        menuFeature->setObjectName(QStringLiteral("menuFeature"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuTool->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClear);
        menuFile->addAction(actionSave);
        menuView->addAction(menuBackGround->menuAction());
        menuView->addAction(actionSelect);
        menuView->addAction(menuColor->menuAction());
        menuView->addAction(menuPointSize->menuAction());
        menuView->addAction(actionCoordinate);
        menuView->addAction(menuThreeView->menuAction());
        menuBackGround->addAction(actionBackGroundSelect);
        menuBackGround->addAction(actionBlack);
        menuBackGround->addAction(actionWhite);
        menuColor->addAction(actionRed);
        menuColor->addAction(actionGreen);
        menuColor->addAction(actionBule);
        menuPointSize->addAction(actionIncrease);
        menuPointSize->addAction(actionDecrease);
        menuThreeView->addAction(actionTop_View);
        menuThreeView->addAction(actionLeft_View);
        menuThreeView->addAction(actionMain_View);
        menuTool->addAction(actionRansac);
        menuTool->addAction(menuFeature->menuAction());
        menuTool->addAction(actionEuropeCluster);
        menuTool->addAction(actionObbCube);
        menuFeature->addAction(actionRansacPlane);
        menuFeature->addAction(actionFeatureValue);
        menuFeature->addAction(actionFeatureOutput);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindowClass", "Open", 0));
        actionClear->setText(QApplication::translate("MainWindowClass", "Clear", 0));
        actionSelect->setText(QApplication::translate("MainWindowClass", "Select", 0));
        actionCoordinate->setText(QApplication::translate("MainWindowClass", "Coordinate", 0));
        actionBackGroundSelect->setText(QApplication::translate("MainWindowClass", "BackGroundSelect", 0));
        actionBlack->setText(QApplication::translate("MainWindowClass", "Black", 0));
        actionWhite->setText(QApplication::translate("MainWindowClass", "White", 0));
        actionGreen->setText(QApplication::translate("MainWindowClass", "Green", 0));
        actionRed->setText(QApplication::translate("MainWindowClass", "Red", 0));
        actionBule->setText(QApplication::translate("MainWindowClass", "Bule", 0));
        actionIncrease->setText(QApplication::translate("MainWindowClass", "Increase", 0));
        actionDecrease->setText(QApplication::translate("MainWindowClass", "Decrease", 0));
        actionRansac->setText(QApplication::translate("MainWindowClass", "Ransac", 0));
        actionRansacPlane->setText(QApplication::translate("MainWindowClass", "RansacPlane", 0));
        actionFeatureValue->setText(QApplication::translate("MainWindowClass", "FeatureValue", 0));
        actionEuropeCluster->setText(QApplication::translate("MainWindowClass", "EuropeCluster", 0));
        actionFeatureOutput->setText(QApplication::translate("MainWindowClass", "FeatureOutput", 0));
        actionTop_View->setText(QApplication::translate("MainWindowClass", "Top View", 0));
        actionLeft_View->setText(QApplication::translate("MainWindowClass", "Left View", 0));
        actionMain_View->setText(QApplication::translate("MainWindowClass", "Main View", 0));
        actionSave->setText(QApplication::translate("MainWindowClass", "Save", 0));
        actionObbCube->setText(QApplication::translate("MainWindowClass", "ObbCube", 0));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", 0));
        menuView->setTitle(QApplication::translate("MainWindowClass", "View", 0));
        menuBackGround->setTitle(QApplication::translate("MainWindowClass", "BackGround", 0));
        menuColor->setTitle(QApplication::translate("MainWindowClass", "Color", 0));
        menuPointSize->setTitle(QApplication::translate("MainWindowClass", "PointSize", 0));
        menuThreeView->setTitle(QApplication::translate("MainWindowClass", "threeView", 0));
        menuTool->setTitle(QApplication::translate("MainWindowClass", "PclPlug", 0));
        menuFeature->setTitle(QApplication::translate("MainWindowClass", "Feature", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
