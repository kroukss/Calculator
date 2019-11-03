#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class Calculatrice;
}

class Calculatrice : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculatrice(QWidget *parent = 0);
    ~Calculatrice();
    char virg=46;
     double pnum;

private:
    Ui::Calculatrice *ui;


private slots :
    void affiche_nombre();
    void affiche_dialog();
    void operation();
    void virgule();
    void egal();
    void plusmoins_percent();
    void clear();
};

#endif // MAINWINDOW_H
