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
    QPushButton *betHistoryButton;
    QTextBrowser *teamStatsTextArea;
    QTextBrowser *betHistoryTextArea;
    QWidget *bestTeamsTab;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *bestTeamLabel;
    QComboBox *bestTeamComboBox;
    QTextBrowser *bestTeamsTextArea;
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
    QTextBrowser *compTextArea;
    QWidget *leagueAnalysisTab;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *leagueLabel;
    QComboBox *leagueComboBox;
    QWidget *teamListTab;
    QTextBrowser *teamListTextArea;
    QWidget *prevBetsTab;
    QTabWidget *prevBetsTabInner;
    QWidget *betDateSearchTab;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *startDateLabel;
    QLineEdit *startDateLineEdit;
    QLabel *endDateLabel;
    QLineEdit *endDateLineEdit;
    QPushButton *dateSearchButton;
    QTextBrowser *betDateSearchStatTextArea;
    QTextBrowser *betDateSearchBetsTextArea;
    QWidget *betWeekTab;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *betWeekLabel;
    QComboBox *betWeekComboBox;
    QTextBrowser *betWeekBetsTextArea;
    QTextBrowser *betWeekStatsTextArea;
    QWidget *betTypeSearchTab;
    QTextBrowser *betTypeStatsTextArea;
    QTextBrowser *betTypeBetsTextArea;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *betTypeLabel;
    QComboBox *betTypeComboBox;
    QWidget *calculatorTab;
    QPushButton *calculateButton;
    QTextBrowser *calculateTextArea;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *oddsLabel;
    QLineEdit *oddsLineEdit;
    QLabel *oddsExampleLabel;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_9;
    QLabel *whichSystemLabel;
    QLineEdit *whichSystemLineEdit;
    QLabel *whichSystemExampleLabel;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_10;
    QLabel *howManyMatchLabel;
    QLineEdit *howManyMatcLineEdit;
    QMenuBar *menubar;
    QMenu *menuSe_enekler;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1293, 800);
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QString::fromUtf8("exitAction"));
        actionBa_ka_Bi_i = new QAction(MainWindow);
        actionBa_ka_Bi_i->setObjectName(QString::fromUtf8("actionBa_ka_Bi_i"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        rootTabWidget = new QTabWidget(centralwidget);
        rootTabWidget->setObjectName(QString::fromUtf8("rootTabWidget"));
        rootTabWidget->setGeometry(QRect(10, 0, 1291, 771));
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
        teamAnalysisTabWidget->setGeometry(QRect(0, 0, 1281, 741));
        sizePolicy.setHeightForWidth(teamAnalysisTabWidget->sizePolicy().hasHeightForWidth());
        teamAnalysisTabWidget->setSizePolicy(sizePolicy);
        teamStatsTab = new QWidget();
        teamStatsTab->setObjectName(QString::fromUtf8("teamStatsTab"));
        layoutWidget = new QWidget(teamStatsTab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 381, 31));
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

        betHistoryButton = new QPushButton(teamStatsTab);
        betHistoryButton->setObjectName(QString::fromUtf8("betHistoryButton"));
        betHistoryButton->setGeometry(QRect(890, 30, 179, 29));
        sizePolicy2.setHeightForWidth(betHistoryButton->sizePolicy().hasHeightForWidth());
        betHistoryButton->setSizePolicy(sizePolicy2);
        betHistoryButton->setFont(font1);
        teamStatsTextArea = new QTextBrowser(teamStatsTab);
        teamStatsTextArea->setObjectName(QString::fromUtf8("teamStatsTextArea"));
        teamStatsTextArea->setGeometry(QRect(-5, 71, 671, 621));
        betHistoryTextArea = new QTextBrowser(teamStatsTab);
        betHistoryTextArea->setObjectName(QString::fromUtf8("betHistoryTextArea"));
        betHistoryTextArea->setGeometry(QRect(670, 70, 601, 621));
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

        bestTeamsTextArea = new QTextBrowser(bestTeamsTab);
        bestTeamsTextArea->setObjectName(QString::fromUtf8("bestTeamsTextArea"));
        bestTeamsTextArea->setGeometry(QRect(0, 70, 1141, 641));
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

        compTextArea = new QTextBrowser(compareTwoTab);
        compTextArea->setObjectName(QString::fromUtf8("compTextArea"));
        compTextArea->setGeometry(QRect(0, 100, 1141, 641));
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
        teamListTextArea = new QTextBrowser(teamListTab);
        teamListTextArea->setObjectName(QString::fromUtf8("teamListTextArea"));
        teamListTextArea->setGeometry(QRect(0, 0, 1141, 751));
        rootTabWidget->addTab(teamListTab, QString());
        prevBetsTab = new QWidget();
        prevBetsTab->setObjectName(QString::fromUtf8("prevBetsTab"));
        prevBetsTabInner = new QTabWidget(prevBetsTab);
        prevBetsTabInner->setObjectName(QString::fromUtf8("prevBetsTabInner"));
        prevBetsTabInner->setGeometry(QRect(6, 9, 1271, 731));
        betDateSearchTab = new QWidget();
        betDateSearchTab->setObjectName(QString::fromUtf8("betDateSearchTab"));
        layoutWidget4 = new QWidget(betDateSearchTab);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 10, 621, 29));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        startDateLabel = new QLabel(layoutWidget4);
        startDateLabel->setObjectName(QString::fromUtf8("startDateLabel"));
        startDateLabel->setFont(font);

        horizontalLayout_5->addWidget(startDateLabel);

        startDateLineEdit = new QLineEdit(layoutWidget4);
        startDateLineEdit->setObjectName(QString::fromUtf8("startDateLineEdit"));
        sizePolicy.setHeightForWidth(startDateLineEdit->sizePolicy().hasHeightForWidth());
        startDateLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(startDateLineEdit);

        endDateLabel = new QLabel(layoutWidget4);
        endDateLabel->setObjectName(QString::fromUtf8("endDateLabel"));
        endDateLabel->setFont(font);

        horizontalLayout_5->addWidget(endDateLabel);

        endDateLineEdit = new QLineEdit(layoutWidget4);
        endDateLineEdit->setObjectName(QString::fromUtf8("endDateLineEdit"));
        sizePolicy.setHeightForWidth(endDateLineEdit->sizePolicy().hasHeightForWidth());
        endDateLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(endDateLineEdit);

        dateSearchButton = new QPushButton(layoutWidget4);
        dateSearchButton->setObjectName(QString::fromUtf8("dateSearchButton"));
        dateSearchButton->setFont(font2);

        horizontalLayout_5->addWidget(dateSearchButton);

        betDateSearchStatTextArea = new QTextBrowser(betDateSearchTab);
        betDateSearchStatTextArea->setObjectName(QString::fromUtf8("betDateSearchStatTextArea"));
        betDateSearchStatTextArea->setGeometry(QRect(670, 50, 601, 651));
        betDateSearchBetsTextArea = new QTextBrowser(betDateSearchTab);
        betDateSearchBetsTextArea->setObjectName(QString::fromUtf8("betDateSearchBetsTextArea"));
        betDateSearchBetsTextArea->setGeometry(QRect(0, 50, 661, 651));
        prevBetsTabInner->addTab(betDateSearchTab, QString());
        betWeekTab = new QWidget();
        betWeekTab->setObjectName(QString::fromUtf8("betWeekTab"));
        layoutWidget5 = new QWidget(betWeekTab);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(3, 10, 591, 27));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        betWeekLabel = new QLabel(layoutWidget5);
        betWeekLabel->setObjectName(QString::fromUtf8("betWeekLabel"));
        sizePolicy3.setHeightForWidth(betWeekLabel->sizePolicy().hasHeightForWidth());
        betWeekLabel->setSizePolicy(sizePolicy3);
        betWeekLabel->setFont(font);

        horizontalLayout_6->addWidget(betWeekLabel);

        betWeekComboBox = new QComboBox(layoutWidget5);
        betWeekComboBox->setObjectName(QString::fromUtf8("betWeekComboBox"));

        horizontalLayout_6->addWidget(betWeekComboBox);

        betWeekBetsTextArea = new QTextBrowser(betWeekTab);
        betWeekBetsTextArea->setObjectName(QString::fromUtf8("betWeekBetsTextArea"));
        betWeekBetsTextArea->setGeometry(QRect(0, 50, 661, 651));
        betWeekStatsTextArea = new QTextBrowser(betWeekTab);
        betWeekStatsTextArea->setObjectName(QString::fromUtf8("betWeekStatsTextArea"));
        betWeekStatsTextArea->setGeometry(QRect(670, 50, 601, 651));
        prevBetsTabInner->addTab(betWeekTab, QString());
        betTypeSearchTab = new QWidget();
        betTypeSearchTab->setObjectName(QString::fromUtf8("betTypeSearchTab"));
        betTypeStatsTextArea = new QTextBrowser(betTypeSearchTab);
        betTypeStatsTextArea->setObjectName(QString::fromUtf8("betTypeStatsTextArea"));
        betTypeStatsTextArea->setGeometry(QRect(670, 40, 601, 651));
        betTypeBetsTextArea = new QTextBrowser(betTypeSearchTab);
        betTypeBetsTextArea->setObjectName(QString::fromUtf8("betTypeBetsTextArea"));
        betTypeBetsTextArea->setGeometry(QRect(0, 40, 661, 651));
        layoutWidget_2 = new QWidget(betTypeSearchTab);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 10, 591, 27));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        betTypeLabel = new QLabel(layoutWidget_2);
        betTypeLabel->setObjectName(QString::fromUtf8("betTypeLabel"));
        sizePolicy3.setHeightForWidth(betTypeLabel->sizePolicy().hasHeightForWidth());
        betTypeLabel->setSizePolicy(sizePolicy3);
        betTypeLabel->setFont(font);

        horizontalLayout_7->addWidget(betTypeLabel);

        betTypeComboBox = new QComboBox(layoutWidget_2);
        betTypeComboBox->setObjectName(QString::fromUtf8("betTypeComboBox"));

        horizontalLayout_7->addWidget(betTypeComboBox);

        prevBetsTabInner->addTab(betTypeSearchTab, QString());
        rootTabWidget->addTab(prevBetsTab, QString());
        calculatorTab = new QWidget();
        calculatorTab->setObjectName(QString::fromUtf8("calculatorTab"));
        calculateButton = new QPushButton(calculatorTab);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setGeometry(QRect(620, 60, 101, 31));
        calculateButton->setFont(font2);
        calculateTextArea = new QTextBrowser(calculatorTab);
        calculateTextArea->setObjectName(QString::fromUtf8("calculateTextArea"));
        calculateTextArea->setGeometry(QRect(10, 130, 721, 192));
        layoutWidget6 = new QWidget(calculatorTab);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 90, 531, 27));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        oddsLabel = new QLabel(layoutWidget6);
        oddsLabel->setObjectName(QString::fromUtf8("oddsLabel"));
        sizePolicy3.setHeightForWidth(oddsLabel->sizePolicy().hasHeightForWidth());
        oddsLabel->setSizePolicy(sizePolicy3);
        oddsLabel->setFont(font);

        horizontalLayout_8->addWidget(oddsLabel);

        oddsLineEdit = new QLineEdit(layoutWidget6);
        oddsLineEdit->setObjectName(QString::fromUtf8("oddsLineEdit"));
        sizePolicy.setHeightForWidth(oddsLineEdit->sizePolicy().hasHeightForWidth());
        oddsLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(oddsLineEdit);

        oddsExampleLabel = new QLabel(layoutWidget6);
        oddsExampleLabel->setObjectName(QString::fromUtf8("oddsExampleLabel"));
        sizePolicy3.setHeightForWidth(oddsExampleLabel->sizePolicy().hasHeightForWidth());
        oddsExampleLabel->setSizePolicy(sizePolicy3);
        oddsExampleLabel->setFont(font);

        horizontalLayout_8->addWidget(oddsExampleLabel);

        layoutWidget7 = new QWidget(calculatorTab);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(10, 50, 351, 27));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        whichSystemLabel = new QLabel(layoutWidget7);
        whichSystemLabel->setObjectName(QString::fromUtf8("whichSystemLabel"));
        sizePolicy3.setHeightForWidth(whichSystemLabel->sizePolicy().hasHeightForWidth());
        whichSystemLabel->setSizePolicy(sizePolicy3);
        whichSystemLabel->setFont(font);

        horizontalLayout_9->addWidget(whichSystemLabel);

        whichSystemLineEdit = new QLineEdit(layoutWidget7);
        whichSystemLineEdit->setObjectName(QString::fromUtf8("whichSystemLineEdit"));
        sizePolicy.setHeightForWidth(whichSystemLineEdit->sizePolicy().hasHeightForWidth());
        whichSystemLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(whichSystemLineEdit);

        whichSystemExampleLabel = new QLabel(layoutWidget7);
        whichSystemExampleLabel->setObjectName(QString::fromUtf8("whichSystemExampleLabel"));
        sizePolicy3.setHeightForWidth(whichSystemExampleLabel->sizePolicy().hasHeightForWidth());
        whichSystemExampleLabel->setSizePolicy(sizePolicy3);
        whichSystemExampleLabel->setFont(font);

        horizontalLayout_9->addWidget(whichSystemExampleLabel);

        layoutWidget8 = new QWidget(calculatorTab);
        layoutWidget8->setObjectName(QString::fromUtf8("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(10, 10, 151, 27));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        howManyMatchLabel = new QLabel(layoutWidget8);
        howManyMatchLabel->setObjectName(QString::fromUtf8("howManyMatchLabel"));
        sizePolicy3.setHeightForWidth(howManyMatchLabel->sizePolicy().hasHeightForWidth());
        howManyMatchLabel->setSizePolicy(sizePolicy3);
        howManyMatchLabel->setFont(font);

        horizontalLayout_10->addWidget(howManyMatchLabel);

        howManyMatcLineEdit = new QLineEdit(layoutWidget8);
        howManyMatcLineEdit->setObjectName(QString::fromUtf8("howManyMatcLineEdit"));
        sizePolicy.setHeightForWidth(howManyMatcLineEdit->sizePolicy().hasHeightForWidth());
        howManyMatcLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(howManyMatcLineEdit);

        rootTabWidget->addTab(calculatorTab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1293, 21));
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
        prevBetsTabInner->setCurrentIndex(0);


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
        teamAnalysisButton->setText(QApplication::translate("MainWindow", "\304\260STAT\304\260ST\304\260KLER\304\260", nullptr));
#ifndef QT_NO_TOOLTIP
        betHistoryButton->setToolTip(QApplication::translate("MainWindow", "T\304\261klay\304\261nca sonu\303\247lar g\303\266r\303\274n\303\274r.", nullptr));
#endif // QT_NO_TOOLTIP
        betHistoryButton->setText(QApplication::translate("MainWindow", "GE\303\207M\304\260\305\236 BAH\304\260SLER\304\260N", nullptr));
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
        startDateLabel->setText(QApplication::translate("MainWindow", "Ba\305\237lang\304\261\303\247 Tarihi", nullptr));
        endDateLabel->setText(QApplication::translate("MainWindow", "Biti\305\237 Tarihi", nullptr));
        endDateLineEdit->setText(QString());
        dateSearchButton->setText(QApplication::translate("MainWindow", "Ara", nullptr));
        prevBetsTabInner->setTabText(prevBetsTabInner->indexOf(betDateSearchTab), QApplication::translate("MainWindow", "Zaman Ara", nullptr));
        betWeekLabel->setText(QApplication::translate("MainWindow", "B\303\274lten Haftas\304\261: ", nullptr));
        prevBetsTabInner->setTabText(prevBetsTabInner->indexOf(betWeekTab), QApplication::translate("MainWindow", "Hafta Ara", nullptr));
        betTypeLabel->setText(QApplication::translate("MainWindow", "Bahis T\303\274r\303\274: ", nullptr));
        prevBetsTabInner->setTabText(prevBetsTabInner->indexOf(betTypeSearchTab), QApplication::translate("MainWindow", "Bahis T\303\274r\303\274 Ara", nullptr));
        rootTabWidget->setTabText(rootTabWidget->indexOf(prevBetsTab), QApplication::translate("MainWindow", "Ge\303\247mi\305\237 Bahisler", nullptr));
        calculateButton->setText(QApplication::translate("MainWindow", "Hesapla", nullptr));
        oddsLabel->setText(QApplication::translate("MainWindow", "Oranlar: ", nullptr));
        oddsExampleLabel->setText(QApplication::translate("MainWindow", "\303\226rn(1.2,3.5,4.2)", nullptr));
        whichSystemLabel->setText(QApplication::translate("MainWindow", "Sistem Ka\303\247: ", nullptr));
        whichSystemLineEdit->setText(QString());
        whichSystemExampleLabel->setText(QApplication::translate("MainWindow", "\303\226rn(2,3,4)", nullptr));
        howManyMatchLabel->setText(QApplication::translate("MainWindow", "Ka\303\247 Ma\303\247: ", nullptr));
        rootTabWidget->setTabText(rootTabWidget->indexOf(calculatorTab), QApplication::translate("MainWindow", "Sistem Oran Hesaplama", nullptr));
        menuSe_enekler->setTitle(QApplication::translate("MainWindow", "Se\303\247enekler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
