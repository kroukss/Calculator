#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int i=0;

private:
    Ui::MainWindow *ui;

private slots :
    void affiche_0();
    void affiche_1();
    void affiche_2();
    void affiche_3();
    void affiche_4();
    void affiche_5();
    void affiche_6();
    void affiche_7();
    void affiche_8();
    void affiche_9();
    void affiche_plus();
    void affiche_moins();
    void affiche_egal();
    void clear();
};

#endif // MAINWINDOW_H
