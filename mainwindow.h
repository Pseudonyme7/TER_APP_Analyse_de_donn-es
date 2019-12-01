#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QObject>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setTabModels();
    void createDockWindows();
    void makeQcheckboxes();
    void addNewGroupDD(QString name);
    QString setText();
    int setInteger();
    double setDouble();
    QStringList setItem();

private slots:
    void on_pushButton_clicked();

    void on_BoutonCreatGroup_clicked();

    void on_BoutonDelGroup_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QDockWidget *dock1;
    QDockWidget *dock2;
    QDockWidget *dock3;
    QDockWidget *dock4;
    QDockWidget *dock5;


    QGroupBox *groupBoxDataDes;
    QListWidgetItem *itemCheckable;
};

#endif // MAINWINDOW_H
