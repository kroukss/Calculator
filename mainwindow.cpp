#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDialog"
#include "dialog.h"
#include "math.h"

Calculatrice::Calculatrice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculatrice)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked(bool)),this,SLOT(affiche_nombre()));
    connect(ui->pushButton_1,SIGNAL(clicked(bool)),this,SLOT(affiche_nombre()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(affiche_nombre()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(affiche_nombre()));
    connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(affiche_nombre()));
    connect(ui->pushButton_5,SIGNAL(clicked(bool)),this,SLOT(affiche_nombre()));
    connect(ui->pushButton_6,SIGNAL(clicked(bool)),this,SLOT(affiche_nombre()));
    connect(ui->pushButton_7,SIGNAL(clicked(bool)),this,SLOT(affiche_nombre()));
    connect(ui->pushButton_8,SIGNAL(clicked(bool)),this,SLOT(affiche_nombre()));
    connect(ui->pushButton_9,SIGNAL(clicked(bool)),this,SLOT(affiche_nombre()));

    connect(ui->pushButton_plus,SIGNAL(clicked(bool)),this,SLOT(operation()));
    connect(ui->pushButton_moins,SIGNAL(clicked(bool)),this,SLOT(operation()));
    connect(ui->pushButton_division,SIGNAL(clicked(bool)),this,SLOT(operation()));
    connect(ui->pushButton_multiplication,SIGNAL(clicked(bool)),this,SLOT(operation()));
    connect(ui->pushButton_pow,SIGNAL(clicked(bool)),this,SLOT(operation()));
    connect(ui->pushButton_racine,SIGNAL(clicked(bool)),this,SLOT(operation()));

    connect(ui->pushButton_egal,SIGNAL(clicked(bool)),this,SLOT(egal()));
    connect(ui->pushButton_virgule,SIGNAL(clicked(bool)),this,SLOT(virgule()));
    connect(ui->pushButton_clear,SIGNAL(clicked(bool)),this,SLOT(clear()));

    connect(ui->pushButton_plusmoins,SIGNAL(clicked(bool)),this,SLOT(plusmoins_percent()));
    connect(ui->pushButton_percent,SIGNAL(clicked(bool)),this,SLOT(plusmoins_percent()));

    connect(ui->action_About,SIGNAL(clicked(bool)),this,SLOT(affiche_dialog()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_moins->setCheckable(true);
    ui->pushButton_multiplication->setCheckable(true);
    ui->pushButton_division->setCheckable(true);
    ui->pushButton_pow->setCheckable(true);
    ui->pushButton_racine->setCheckable(true);
}

void Calculatrice::affiche_dialog()
{
    QDialog *dialog=new QDialog(this);
    dialog->show();

}

void Calculatrice::affiche_nombre()
{
    QPushButton * button = (QPushButton *) sender();
    double num;
    QString n;

    num= button->text().toDouble();
    n=QString::number(num,'g',15);
    ui->textEdit->insertPlainText(n);
}


void Calculatrice::plusmoins_percent()
{
    QPushButton * button = (QPushButton *)sender();
    double num;
    QString n;

    if(button->text() == "+/-")
    {
        num=ui->textEdit->toPlainText().toDouble();
        num=num* -1;
        n=QString::number(num,'g',15);
        ui->textEdit->clear();
        ui->textEdit->insertPlainText(n);
    }

    if(button->text() == "%")
    {
        num=ui->textEdit->toPlainText().toDouble();
        num=num* 0.01;
        n=QString::number(num,'g',15);
        ui->textEdit->clear();
        ui->textEdit->insertPlainText(n);
    }
}

void Calculatrice::operation()
{
   QPushButton * button = (QPushButton *)sender();

   pnum=ui->textEdit->toPlainText().toDouble();
   button->setChecked(true);
   ui->textEdit->clear();
}

void Calculatrice::virgule()
{
    QString n;
    n=QString("%1").arg(virg);
    ui->textEdit->insertPlainText(n);
}

void Calculatrice::egal()
{
    QString nouvn;
    double num,nums;

    nums=ui->textEdit->toPlainText().toDouble();
    ui->textEdit->clear();

    if(ui->pushButton_plus->isChecked())
    {
       num = pnum + nums;
       nouvn=nouvn.number(num);
       ui->textEdit->clear();
       ui->textEdit->insertPlainText(nouvn);
       ui->pushButton_plus->setChecked(false);
    }

    if(ui->pushButton_moins->isChecked())
    {
        num = pnum - nums;
        nouvn=nouvn.number(num);
        ui->textEdit->clear();
        ui->textEdit->insertPlainText(nouvn);
        ui->pushButton_moins->setChecked(false);
    }

    if(ui->pushButton_multiplication->isChecked())
    {
        num = pnum * nums;
        nouvn=nouvn.number(num);
        ui->textEdit->clear();
        ui->textEdit->insertPlainText(nouvn);
        ui->pushButton_multiplication->setChecked(false);
    }

    if(ui->pushButton_division->isChecked())
    {
        num = pnum / nums;
        nouvn=nouvn.number(num);
        ui->textEdit->clear();
        ui->textEdit->insertPlainText(nouvn);
        ui->pushButton_division->setChecked(false);
    }

    if(ui->pushButton_pow->isChecked())
    {
        num = pow(pnum,nums);
        nouvn=nouvn.number(num);
        ui->textEdit->clear();
        ui->textEdit->insertPlainText(nouvn);
        ui->pushButton_pow->setChecked(false);
    }

    if(ui->pushButton_racine->isChecked())
    {
        num = sqrt(nums);
        nouvn=nouvn.number(num);
        ui->textEdit->clear();
        ui->textEdit->insertPlainText(nouvn);
        ui->pushButton_racine->setChecked(false);
    }
}

void Calculatrice::clear()
{
    ui->textEdit->clear();
}

Calculatrice::~Calculatrice()
{
    delete ui;
}
