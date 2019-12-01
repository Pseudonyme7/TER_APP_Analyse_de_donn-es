#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QObject>
#include <iostream>
#include <QDebug>
#include <QPropertyAnimation>
#include <QLinearGradient>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    createDockWindows();
    setTabModels();
    ui->TableauPrincipal->move(0,0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTabModels(){
    QStandardItemModel *model =new QStandardItemModel();

    QFile file(":/a.txt");
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);

        QString line = stream.readLine();
        QStringList list = line.simplified().split(',');
        model->setHorizontalHeaderLabels(list);

        int row = 0;
        QStandardItem *newItem = 0;
        while (!stream.atEnd()) {
            line = stream.readLine();
            if (!line.startsWith('#') && line.contains(',')) {
                list = line.simplified().split(',');
                for (int col = 0; col < list.length(); ++col){
                    newItem = new QStandardItem(list.at(col));
                    model->setItem(row, col, newItem);
                }
                ++row;
            }
        }
    }

    file.close();
    ui->Table1->setModel(model);
    ui->Table2->setModel(model);
}

void MainWindow::on_pushButton_clicked()
{
    QPoint PointDepart1 = dock1->pos();
    QPoint PointDepart2 = dock2->pos();
    QPoint PointDepart3 = dock3->pos();
    QPoint PointDepart4 = dock4->pos();
    QPoint PointDepart5 = dock5->pos();

    QPoint *PointDepartT = new QPoint(ui->TableauPrincipal->pos());
    QPoint *PointArriveT = new QPoint(-500, -300);
    //Si les tables sont cachées
    QPoint *PointArrive1 = new QPoint(dock1->x(),40);
    QPoint *PointArrive2 = new QPoint(dock2->x(),40);
    QPoint *PointArrive3 = new QPoint(dock3->x(),40);
    QPoint *PointArrive4 = new QPoint(0,dock4->y());
    QPoint *PointArrive5 = new QPoint(0,dock5->y());
    //Si les tables sont apparentes
    QPoint *PointArrive7 = new QPoint(dock1->x(), -500);//Si les tables sont cachées
    QPoint *PointArrive8 = new QPoint(dock2->x(), -500);
    QPoint *PointArrive9 = new QPoint(dock3->x(), -500);
    QPoint *PointArrive10 = new QPoint(-500, dock4->y());
    QPoint *PointArrive11 = new QPoint(-500, dock5->y());



    if(dock1->y()< 0){//SHOW
        QPropertyAnimation *animation = new QPropertyAnimation(dock1, "pos");
        animation->setDuration(2000);
        animation->setStartValue(PointDepart1);
        animation->setEndValue(*PointArrive1);

        QPropertyAnimation *animation2 = new QPropertyAnimation(dock2, "pos");
        animation2->setDuration(2000);
        animation2->setStartValue(PointDepart2);
        animation2->setEndValue(*PointArrive2);

        QPropertyAnimation *animation3 = new QPropertyAnimation(dock3, "pos");
        animation3->setDuration(2000);
        animation3->setStartValue(PointDepart3);
        animation3->setEndValue(*PointArrive3);

        QPropertyAnimation *animation4 = new QPropertyAnimation(dock4, "pos");
        animation4->setDuration(2000);
        animation4->setStartValue(PointDepart4);
        animation4->setEndValue(*PointArrive4);

        QPropertyAnimation *animation5 = new QPropertyAnimation(dock5, "pos");
        animation5->setDuration(2000);
        animation5->setStartValue(PointDepart5);
        animation5->setEndValue(*PointArrive5);


        animation->start();
        animation2->start();
        animation3->start();
        animation4->start();
        animation5->start();
    }
    else{//HIDE
        QPropertyAnimation *animation = new QPropertyAnimation(dock1, "pos");
        animation->setDuration(1800);
        animation->setStartValue(PointDepart1);
        animation->setEndValue(*PointArrive7);

        QPropertyAnimation *animation2 = new QPropertyAnimation(dock2, "pos");
        animation2->setDuration(1800);
        animation2->setStartValue(PointDepart2);
        animation2->setEndValue(*PointArrive8);

        QPropertyAnimation *animation3 = new QPropertyAnimation(dock3, "pos");
        animation3->setDuration(1800);
        animation3->setStartValue(PointDepart3);
        animation3->setEndValue(*PointArrive9);

        QPropertyAnimation *animation4 = new QPropertyAnimation(dock4, "pos");
        animation4->setDuration(1800);
        animation4->setStartValue(PointDepart4);
        animation4->setEndValue(*PointArrive10);

        QPropertyAnimation *animation5 = new QPropertyAnimation(dock5, "pos");
        animation5->setDuration(1800);
        animation5->setStartValue(PointDepart5);
        animation5->setEndValue(*PointArrive11);

        QPropertyAnimation *animation6 = new QPropertyAnimation(ui->TableauPrincipal, "pos");
        animation6->setDuration(1800);
        animation6->setStartValue(*PointDepartT);
        animation6->setEndValue(*PointArriveT);


        animation->start();
        animation2->start();
        animation3->start();
        animation4->start();
        animation5->start();
        //QTimer::singleShot(700, animation6, SLOT(start()));
/*
        QPropertyAnimation *animation6 = new QPropertyAnimation(ui->TableauPrincipal, "geometry");
        animation6->setDuration(5000);
        animation6->setStartValue(ui->TableauPrincipal->geometry());
        animation6->setEndValue(QRect(-100, -100, this->width()-30, this->height()-30));*/

        //connect(animation6, SIGNAL(finished()), animation6, SLOT());

        animation6->start();

        dock1;
        dock2->updateGeometry();
        dock3->updateGeometry();/*

        removeDockWidget(dock1);
        removeDockWidget(dock2);
        removeDockWidget(dock3);
        removeDockWidget(dock4);
        removeDockWidget(dock5);*/


    }
}

void MainWindow::createDockWindows(){
    makeQcheckboxes();
    /*
    dock1 = new QDockWidget(tr("Data set"), this);
    dock2 = new QDockWidget(tr("Data Statistics"), this);
    dock3 = new QDockWidget(tr("FDs"), this);
    dock4 = new QDockWidget(tr("Data Description"), this);
    dock5 = new QDockWidget(tr("Data Mining"), this);

    //dock1->setAllowedAreas(Qt::TopDockWidgetArea | Qt::RightDockWidgetArea);
    //dock2->setAllowedAreas(Qt::TopDockWidgetArea | Qt::RightDockWidgetArea);

    dock3->setWidget(ui->B56);//FDs
    addDockWidget(Qt::TopDockWidgetArea, dock3);

    dock1->setMinimumWidth(400);
    dock1->setWidget(ui->Table1);
    addDockWidget(Qt::TopDockWidgetArea, dock1);
    dock2->setMinimumWidth(400);
    dock2->setWidget(ui->Table2);
    addDockWidget(Qt::TopDockWidgetArea, dock2);

    dock4->setWidget(groupBoxDataDes);//Data Description
    addDockWidget(Qt::LeftDockWidgetArea, dock4);

    dock5->setWidget(ui->B58);// Data Mining
    addDockWidget(Qt::LeftDockWidgetArea, dock5);*/
    dock3 = new QDockWidget(tr("dock3"), this);
    dock3->setAllowedAreas(Qt::TopDockWidgetArea);
    //dock3->setWidget(customerList);
    addDockWidget(Qt::TopDockWidgetArea, dock3);

    dock1 = new QDockWidget(tr("dock1"), this);
    dock1->setWidget(ui->Table1);
    addDockWidget(Qt::TopDockWidgetArea, dock1);

    dock2 = new QDockWidget(tr("dock2"), this);
    dock2->setWidget(ui->Table2);
    addDockWidget(Qt::TopDockWidgetArea, dock2);

    dock4 = new QDockWidget(tr("dock4"), this);
    dock4->setWidget(groupBoxDataDes);
    addDockWidget(Qt::LeftDockWidgetArea, dock4);

    dock5 = new QDockWidget(tr("dock5"), this);
    //dock5->setWidget();
    addDockWidget(Qt::LeftDockWidgetArea, dock5);
}

void MainWindow::makeQcheckboxes(){
    groupBoxDataDes = new QGroupBox();

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(ui->BoutonCreatGroup);
    vbox->addWidget(ui->BoutonDelGroup);
    vbox->addWidget(ui->ListGroup);
    //vbox->addStretch(1);
    groupBoxDataDes->setLayout(vbox);
}

void MainWindow::addNewGroupDD(QString name){
    itemCheckable = new QListWidgetItem(name, ui->ListGroup);
    itemCheckable->setFlags(itemCheckable->flags() | Qt::ItemIsUserCheckable);
    itemCheckable->setCheckState(Qt::Unchecked);
    ui->ListGroup->addItem(itemCheckable);
}


void MainWindow::on_BoutonCreatGroup_clicked()
{
    QString GroupAdded = setText();
    if(GroupAdded != "BLANK")
        addNewGroupDD(GroupAdded);
    else {
        qDebug()<<"Chaine non conforme";
    }
}

void MainWindow::on_BoutonDelGroup_clicked()
{
    QString GroupDeleted = setText();
    qDeleteAll(ui->ListGroup->findItems(GroupDeleted, Qt::MatchExactly));
    if(GroupDeleted != "BLANK")
        qDeleteAll(ui->ListGroup->findItems(GroupDeleted, Qt::MatchExactly));
    else {
        qDebug()<<"Groupe non existant";
    }
}

int MainWindow::setInteger()
{

    bool ok;
    int i = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
                                 tr("Percentage:"), 25, 0, 100, 1, &ok);
    if (ok)
        return i;

}

double MainWindow::setDouble()
{

    bool ok;
    double d = QInputDialog::getDouble(this, tr("QInputDialog::getDouble()"),
                                       tr("Amount:"), 37, -10000, 10000, 2, &ok);
    if (ok)
        return d;

}

QStringList MainWindow::setItem()
{
    QStringList items;
    items << tr("Spring") << tr("Summer") << tr("Fall") << tr("Winter");

    bool ok;
    QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"),
                                         tr("Season:"), items, 0, false, &ok);
    if (ok && !item.isEmpty())
        return items;
}

QString MainWindow::setText()
{

    bool ok;
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                         tr("User name:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty())
        return text;
    else {
        return "BLANK";
    }

}



void MainWindow::on_pushButton_2_clicked()
{
    QPoint PointDepart1 = dock1->pos();
    QPoint PointDepart2 = dock2->pos();
    QPoint PointDepart3 = dock3->pos();
    QPoint PointDepart4 = dock4->pos();
    QPoint PointDepart5 = dock5->pos();

    QPoint *PointDepartT = new QPoint(ui->TableauPrincipal->pos());
    QPoint *PointArriveT = new QPoint(-500, -300);
    //Si les tables sont cachées
    QPoint *PointArrive1 = new QPoint(dock1->x(),40);
    QPoint *PointArrive2 = new QPoint(dock2->x(),40);
    QPoint *PointArrive3 = new QPoint(dock3->x(),40);
    QPoint *PointArrive4 = new QPoint(0,dock4->y());
    QPoint *PointArrive5 = new QPoint(0,dock5->y());
    //Si les tables sont apparentes
    QPoint *PointArrive7 = new QPoint(dock1->x(), -500);//Si les tables sont cachées
    QPoint *PointArrive8 = new QPoint(dock2->x(), -500);
    QPoint *PointArrive9 = new QPoint(dock3->x(), -500);
    QPoint *PointArrive10 = new QPoint(-100, dock4->y());
    QPoint *PointArrive11 = new QPoint(-500, dock5->y());
    if(dock1->y()< 0){//SHOW
        dock1->move(*PointArrive1);
        dock2->move(*PointArrive2);
        dock3->move(*PointArrive3);
        dock4->move(*PointArrive4);
        dock5->move(*PointArrive5);
        createDockWindows();
        ui->TableauPrincipal->move(5,5);
        int w = this->width() - groupBoxDataDes->width() - 10;
        int h = this->height() - ui->Table1->height() -10;
        qDebug()<<"w ="<<w<<"h ="<<h;

        qDebug()<<this->width()<<this->height()<<ui->ListGroup->width()<<ui->Table1->height();
        ui->TableauPrincipal->resize(w, h);
        qDebug()<<"Dimensions Tableau ="<<ui->TableauPrincipal->size();
    }
    else{//HIDE
        dock1->move(*PointArrive7);
        dock2->move(*PointArrive8);
        dock3->move(*PointArrive9);
        dock4->move(*PointArrive10);
        dock5->move(*PointArrive11);
        removeDockWidget(dock1);
        removeDockWidget(dock2);
        removeDockWidget(dock3);
        removeDockWidget(dock4);
        removeDockWidget(dock5);
        ui->TableauPrincipal->move(10,10);
        ui->TableauPrincipal->resize(this->width()-30, this->height()-70);
    }
}

void MainWindow::setMainWidget(){
    // C'est ici que je set ton widget dans mon UI
    //ui->gridLayout_2->addWidget(WIDGET);
}

