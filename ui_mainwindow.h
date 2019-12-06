/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *exitAction;
    QAction *actionBa_ka_Bi_i;
    QWidget *centralwidget;
    QTabWidget *rootTabWidget;
    QWidget *teamAnalysisTab;
    QTabWidget *teamAnalysisTabWidget;
    QWidget *teamStatsTab;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *teamAnalysisLabel;
    QLineEdit *teamAnalysisLineEdit;
    QPushButton *teamAnalysisButton;
    QWidget *bestTeamsTab;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *bestTeamLabel;
    QComboBox *bestTeamComboBox;
    QWidget *compareTwoTab;
    QPushButton *compareButton;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *homeTeamLabel;
    QLineEdit *homeTeamLineEdit;
    QLabel *awayTeamLabel;
    QLineEdit *awayTeamLineEdit;
    QLabel *compTwoLeagueLabel;
    QComboBox *compTwoComboBox;
    QWidget *leagueAnalysisTab;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *leagueLabel;
    QComboBox *leagueComboBox;
    QWidget *teamListTab;
    QTextBrowser *mainTextArea;
    QMenuBar *menubar;
    QMenu *menuSe_enekler;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(976, 723);
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QString::fromUtf8("exitAction"));
        actionBa_ka_Bi_i = new QAction(MainWindow);
        actionBa_ka_Bi_i->setObjectName(QString::fromUtf8("actionBa_ka_Bi_i"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        rootTabWidget = new QTabWidget(centralwidget);
        rootTabWidget->setObjectName(QString::fromUtf8("rootTabWidget"));
        rootTabWidget->setGeometry(QRect(10, 0, 841, 131));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rootTabWidget->sizePolicy().hasHeightForWidth());
        rootTabWidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        rootTabWidget->setFont(font);
        teamAnalysisTab = new QWidget();
        teamAnalysisTab->setObjectName(QString::fromUtf8("teamAnalysisTab"));
        teamAnalysisTabWidget = new QTabWidget(teamAnalysisTab);
        teamAnalysisTabWidget->setObjectName(QString::fromUtf8("teamAnalysisTabWidget"));
        teamAnalysisTabWidget->setGeometry(QRect(0, 0, 841, 111));
        sizePolicy.setHeightForWidth(teamAnalysisTabWidget->sizePolicy().hasHeightForWidth());
        teamAnalysisTabWidget->setSizePolicy(sizePolicy);
        teamStatsTab = new QWidget();
        teamStatsTab->setObjectName(QString::fromUtf8("teamStatsTab"));
        layoutWidget = new QWidget(teamStatsTab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 361, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        teamAnalysisLabel = new QLabel(layoutWidget);
        teamAnalysisLabel->setObjectName(QString::fromUtf8("teamAnalysisLabel"));
        teamAnalysisLabel->setFont(font);

        horizontalLayout->addWidget(teamAnalysisLabel);

        teamAnalysisLineEdit = new QLineEdit(layoutWidget);
        teamAnalysisLineEdit->setObjectName(QString::fromUtf8("teamAnalysisLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(teamAnalysisLineEdit->sizePolicy().hasHeightForWidth());
        teamAnalysisLineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(teamAnalysisLineEdit);

        teamAnalysisButton = new QPushButton(layoutWidget);
        teamAnalysisButton->setObjectName(QString::fromUtf8("teamAnalysisButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(teamAnalysisButton->sizePolicy().hasHeightForWidth());
        teamAnalysisButton->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        teamAnalysisButton->setFont(font1);

        horizontalLayout->addWidget(teamAnalysisButton);

        teamAnalysisTabWidget->addTab(teamStatsTab, QString());
        bestTeamsTab = new QWidget();
        bestTeamsTab->setObjectName(QString::fromUtf8("bestTeamsTab"));
        layoutWidget1 = new QWidget(bestTeamsTab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 448, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        bestTeamLabel = new QLabel(layoutWidget1);
        bestTeamLabel->setObjectName(QString::fromUtf8("bestTeamLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(bestTeamLabel->sizePolicy().hasHeightForWidth());
        bestTeamLabel->setSizePolicy(sizePolicy3);
        bestTeamLabel->setFont(font);

        horizontalLayout_2->addWidget(bestTeamLabel);

        bestTeamComboBox = new QComboBox(layoutWidget1);
        bestTeamComboBox->addItem(QString());
        bestTeamComboBox->addItem(QString());
        bestTeamComboBox->addItem(QString());
        bestTeamComboBox->addItem(QString());
        bestTeamComboBox->addItem(QString());
        bestTeamComboBox->addItem(QString());
        bestTeamComboBox->addItem(QString());
        bestTeamComboBox->addItem(QString());
        bestTeamComboBox->addItem(QString());
        bestTeamComboBox->addItem(QString());
        bestTeamComboBox->setObjectName(QString::fromUtf8("bestTeamComboBox"));
        sizePolicy.setHeightForWidth(bestTeamComboBox->sizePolicy().hasHeightForWidth());
        bestTeamComboBox->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(bestTeamComboBox);

        teamAnalysisTabWidget->addTab(bestTeamsTab, QString());
        rootTabWidget->addTab(teamAnalysisTab, QString());
        compareTwoTab = new QWidget();
        compareTwoTab->setObjectName(QString::fromUtf8("compareTwoTab"));
        compareButton = new QPushButton(compareTwoTab);
        compareButton->setObjectName(QString::fromUtf8("compareButton"));
        compareButton->setGeometry(QRect(0, 60, 101, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        compareButton->setFont(font2);
        layoutWidget2 = new QWidget(compareTwoTab);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 20, 831, 27));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        homeTeamLabel = new QLabel(layoutWidget2);
        homeTeamLabel->setObjectName(QString::fromUtf8("homeTeamLabel"));
        homeTeamLabel->setFont(font);

        horizontalLayout_3->addWidget(homeTeamLabel);

        homeTeamLineEdit = new QLineEdit(layoutWidget2);
        homeTeamLineEdit->setObjectName(QString::fromUtf8("homeTeamLineEdit"));
        sizePolicy.setHeightForWidth(homeTeamLineEdit->sizePolicy().hasHeightForWidth());
        homeTeamLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(homeTeamLineEdit);

        awayTeamLabel = new QLabel(layoutWidget2);
        awayTeamLabel->setObjectName(QString::fromUtf8("awayTeamLabel"));
        awayTeamLabel->setFont(font);

        horizontalLayout_3->addWidget(awayTeamLabel);

        awayTeamLineEdit = new QLineEdit(layoutWidget2);
        awayTeamLineEdit->setObjectName(QString::fromUtf8("awayTeamLineEdit"));
        sizePolicy.setHeightForWidth(awayTeamLineEdit->sizePolicy().hasHeightForWidth());
        awayTeamLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(awayTeamLineEdit);

        compTwoLeagueLabel = new QLabel(layoutWidget2);
        compTwoLeagueLabel->setObjectName(QString::fromUtf8("compTwoLeagueLabel"));
        compTwoLeagueLabel->setFont(font);

        horizontalLayout_3->addWidget(compTwoLeagueLabel);

        compTwoComboBox = new QComboBox(layoutWidget2);
        compTwoComboBox->addItem(QString());
        compTwoComboBox->addItem(QString());
        compTwoComboBox->addItem(QString());
        compTwoComboBox->setObjectName(QString::fromUtf8("compTwoComboBox"));
        sizePolicy1.setHeightForWidth(compTwoComboBox->sizePolicy().hasHeightForWidth());
        compTwoComboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(compTwoComboBox);

        rootTabWidget->addTab(compareTwoTab, QString());
        leagueAnalysisTab = new QWidget();
        leagueAnalysisTab->setObjectName(QString::fromUtf8("leagueAnalysisTab"));
        layoutWidget3 = new QWidget(leagueAnalysisTab);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(6, 20, 261, 41));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        leagueLabel = new QLabel(layoutWidget3);
        leagueLabel->setObjectName(QString::fromUtf8("leagueLabel"));
        sizePolicy3.setHeightForWidth(leagueLabel->sizePolicy().hasHeightForWidth());
        leagueLabel->setSizePolicy(sizePolicy3);
        leagueLabel->setFont(font);

        horizontalLayout_4->addWidget(leagueLabel);

        leagueComboBox = new QComboBox(layoutWidget3);
        leagueComboBox->addItem(QString());
        leagueComboBox->addItem(QString());
        leagueComboBox->addItem(QString());
        leagueComboBox->addItem(QString());
        leagueComboBox->addItem(QString());
        leagueComboBox->setObjectName(QString::fromUtf8("leagueComboBox"));
        sizePolicy.setHeightForWidth(leagueComboBox->sizePolicy().hasHeightForWidth());
        leagueComboBox->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(leagueComboBox);

        rootTabWidget->addTab(leagueAnalysisTab, QString());
        teamListTab = new QWidget();
        teamListTab->setObjectName(QString::fromUtf8("teamListTab"));
        rootTabWidget->addTab(teamListTab, QString());
        mainTextArea = new QTextBrowser(centralwidget);
        mainTextArea->setObjectName(QString::fromUtf8("mainTextArea"));
        mainTextArea->setGeometry(QRect(0, 140, 981, 561));
        sizePolicy.setHeightForWidth(mainTextArea->sizePolicy().hasHeightForWidth());
        mainTextArea->setSizePolicy(sizePolicy);
        mainTextArea->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 976, 21));
        menuSe_enekler = new QMenu(menubar);
        menuSe_enekler->setObjectName(QString::fromUtf8("menuSe_enekler"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuSe_enekler->menuAction());
        menuSe_enekler->addAction(actionBa_ka_Bi_i);
        menuSe_enekler->addSeparator();
        menuSe_enekler->addAction(exitAction);

        retranslateUi(MainWindow);

        rootTabWidget->setCurrentIndex(0);
        teamAnalysisTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\304\260DDDA ANAL\304\260Z", nullptr));
        exitAction->setText(QApplication::translate("MainWindow", "\303\207\304\261k\304\261\305\237", nullptr));
        actionBa_ka_Bi_i->setText(QApplication::translate("MainWindow", "Ba\305\237ka Bi\305\237i", nullptr));
#ifndef QT_NO_TOOLTIP
        rootTabWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        teamAnalysisLabel->setToolTip(QApplication::translate("MainWindow", "Tak\304\261m listesindeki isimlerden biri olmal\304\261!", nullptr));
#endif // QT_NO_TOOLTIP
        teamAnalysisLabel->setText(QApplication::translate("MainWindow", "Tak\304\261m \304\260smi :", nullptr));
#ifndef QT_NO_TOOLTIP
        teamAnalysisButton->setToolTip(QApplication::translate("MainWindow", "T\304\261klay\304\261nca sonu\303\247lar g\303\266r\303\274n\303\274r.", nullptr));
#endif // QT_NO_TOOLTIP
        teamAnalysisButton->setText(QApplication::translate("MainWindow", "ARA", nullptr));
        teamAnalysisTabWidget->setTabText(teamAnalysisTabWidget->indexOf(teamStatsTab), QApplication::translate("MainWindow", "Tak\304\261m \304\260statisti\304\237i", nullptr));
        bestTeamLabel->setText(QApplication::translate("MainWindow", "S\304\261ralama \303\207e\305\237idi :", nullptr));
        bestTeamComboBox->setItemText(0, QApplication::translate("MainWindow", "En \304\260yi Sonu\303\247 Alanlar", nullptr));
        bestTeamComboBox->setItemText(1, QApplication::translate("MainWindow", "En K\303\266t\303\274 Sonu\303\247 Alanlar", nullptr));
        bestTeamComboBox->setItemText(2, QApplication::translate("MainWindow", "En \303\207ok Gol Atanlar", nullptr));
        bestTeamComboBox->setItemText(3, QApplication::translate("MainWindow", "En Az Gol Atanlar", nullptr));
        bestTeamComboBox->setItemText(4, QApplication::translate("MainWindow", "En \303\207ok Gol Yiyenler", nullptr));
        bestTeamComboBox->setItemText(5, QApplication::translate("MainWindow", "En Az Gol Yiyenler", nullptr));
        bestTeamComboBox->setItemText(6, QApplication::translate("MainWindow", "Ma\303\247lar\304\261nda En \303\207ok Gol Olanlar", nullptr));
        bestTeamComboBox->setItemText(7, QApplication::translate("MainWindow", "Ma\303\247lar\304\261nda En Az Gol Olanlar", nullptr));
        bestTeamComboBox->setItemText(8, QApplication::translate("MainWindow", "Ma\303\247lar\304\261nda En \303\207ok Geri D\303\266n\303\274\305\237 Ya\305\237ayanlar", nullptr));
        bestTeamComboBox->setItemText(9, QApplication::translate("MainWindow", "En \303\207ok Korner", nullptr));

        teamAnalysisTabWidget->setTabText(teamAnalysisTabWidget->indexOf(bestTeamsTab), QApplication::translate("MainWindow", "En \304\260yi Tak\304\261mlar", nullptr));
        rootTabWidget->setTabText(rootTabWidget->indexOf(teamAnalysisTab), QApplication::translate("MainWindow", "Tak\304\261m Analizi", nullptr));
        compareButton->setText(QApplication::translate("MainWindow", "Kar\305\237\304\261la\305\237t\304\261r", nullptr));
        homeTeamLabel->setText(QApplication::translate("MainWindow", "Ev Sahibi :", nullptr));
        awayTeamLabel->setText(QApplication::translate("MainWindow", "Deplasman :", nullptr));
        compTwoLeagueLabel->setText(QApplication::translate("MainWindow", "Hangi Ma\303\247lara G\303\266re?", nullptr));
        compTwoComboBox->setItemText(0, QApplication::translate("MainWindow", "Sadece Lig", nullptr));
        compTwoComboBox->setItemText(1, QApplication::translate("MainWindow", "Sadece \305\236amp. Ligi", nullptr));
        compTwoComboBox->setItemText(2, QApplication::translate("MainWindow", "Her \304\260kisi de", nullptr));

        rootTabWidget->setTabText(rootTabWidget->indexOf(compareTwoTab), QApplication::translate("MainWindow", "Tak\304\261m Kar\305\237\304\261la\305\237t\304\261rma", nullptr));
        leagueLabel->setText(QApplication::translate("MainWindow", "Lig Se\303\247 :", nullptr));
        leagueComboBox->setItemText(0, QApplication::translate("MainWindow", "Almanya", nullptr));
        leagueComboBox->setItemText(1, QApplication::translate("MainWindow", "\304\260ngiltere", nullptr));
        leagueComboBox->setItemText(2, QApplication::translate("MainWindow", "\304\260spanya", nullptr));
        leagueComboBox->setItemText(3, QApplication::translate("MainWindow", "\304\260talya", nullptr));
        leagueComboBox->setItemText(4, QApplication::translate("MainWindow", "T\303\274rkiye", nullptr));

        rootTabWidget->setTabText(rootTabWidget->indexOf(leagueAnalysisTab), QApplication::translate("MainWindow", "Lig Analizi", nullptr));
        rootTabWidget->setTabText(rootTabWidget->indexOf(teamListTab), QApplication::translate("MainWindow", "Tak\304\261m Listesi", nullptr));
        menuSe_enekler->setTitle(QApplication::translate("MainWindow", "Se\303\247enekler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
