#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "Files.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	QString sometext;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
	void setSomeText(const std::string&);
	void setFilePaths(const std::vector<std::filesystem::path>&, const std::vector<std::filesystem::path>&);
private slots:
    void on_bestTeamComboBox_activated(const QString &arg1);

    void on_teamAnalysisButton_clicked();

    void on_teamAnalysisTabWidget_currentChanged(int index);

    void on_rootTabWidget_currentChanged(int index);

    void on_leagueComboBox_activated(const QString &arg1);

    void on_compTwoComboBox_activated(int index);

    void on_bestTeamComboBox_activated(int index);

    void on_leagueComboBox_activated(int index);

    void on_compareButton_clicked();

private:
    Ui::MainWindow *ui;
	std::vector<std::filesystem::path> match_files;
	std::vector<std::filesystem::path> team_files;
};
#endif // MAINWINDOW_H
