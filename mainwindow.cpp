#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked(bool)),this,SLOT(affiche_0()));
    connect(ui->pushButton_1,SIGNAL(clicked(bool)),this,SLOT(affiche_1()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(affiche_2()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(affiche_3()));
    connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(affiche_4()));
    connect(ui->pushButton_5,SIGNAL(clicked(bool)),this,SLOT(affiche_5()));
    connect(ui->pushButton_6,SIGNAL(clicked(bool)),this,SLOT(affiche_6()));
    connect(ui->pushButton_7,SIGNAL(clicked(bool)),this,SLOT(affiche_7()));
    connect(ui->pushButton_8,SIGNAL(clicked(bool)),this,SLOT(affiche_8()));
    connect(ui->pushButton_9,SIGNAL(clicked(bool)),this,SLOT(affiche_9()));
    connect(ui->pushButton_plus,SIGNAL(clicked(bool)),this,SLOT(affiche_plus()));
    connect(ui->pushButton_moins,SIGNAL(clicked(bool)),this,SLOT(affiche_moins()));
    connect(ui->pushButton_egal,SIGNAL(clicked(bool)),this,SLOT(affiche_egal()));
    connect(ui->pushButton_clear,SIGNAL(clicked(bool)),this,SLOT(clear()));
}

void MainWindow::affiche_0()
{
    QString n;
    n=QString("%1").arg(0);
    ui->textEdit->insertPlainText(n);
}

void MainWindow::affiche_1()
{
    QString n;
    n=QString("%1").arg(1);
    ui->textEdit->insertPlainText(n);
}

void MainWindow::affiche_2()
{
    QString n;
    n=QString("%1").arg(2);
    ui->textEdit->insertPlainText(n);
}

void MainWindow::affiche_3()
{
    QString n;
    n=QString("%1").arg(3);
    ui->textEdit->insertPlainText(n);
}

void MainWindow::affiche_4()
{
    QString n;
    n=QString("%1").arg(4);
    ui->textEdit->insertPlainText(n);
}

void MainWindow::affiche_5()
{
    QString n;
    n=QString("%1").arg(5);
    ui->textEdit->insertPlainText(n);
}

void MainWindow::affiche_6()
{
    QString n;
    n=QString("%1").arg(6);
    ui->textEdit->insertPlainText(n);
}
void MainWindow::affiche_7()
{
    QString n;
    n=QString("%1").arg(7);
    ui->textEdit->insertPlainText(n);
}

void MainWindow::affiche_8()
{
    QString n;
    n=QString("%1").arg(8);
    ui->textEdit->insertPlainText(n);
}

void MainWindow::affiche_9()
{
    QString n;
    n=QString("%1").arg(9);
    ui->textEdit->insertPlainText(n);
}

void MainWindow::affiche_plus()
{
    int i=ui->textEdit->toPlainText().toInt();
    ui->textEdit->clear();
}

void MainWindow::affiche_moins()
{
    int i=ui->textEdit->toPlainText().toInt();
    ui->textEdit->clear();
}

void MainWindow::affiche_egal()
{
    QString n;
    n=ui->textEdit->toPlainText();
    i=i+n.toFloat();
    qDebug()<<i;
  //ui->textEdit->insertPlainText(i);
    ui->textEdit->clear();
}

void MainWindow::clear()
{
    ui->textEdit->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}
