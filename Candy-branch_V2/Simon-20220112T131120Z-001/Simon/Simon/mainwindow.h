#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <QtDebug>
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void generer_sequence();
    void limite_temps();
    void changement();


private slots:
    void compare();

    void on_Bleu_clicked();

    void on_Rouge_clicked();

    void on_Jaune_clicked();

    void on_Vert_clicked();

    void on_pushButton_clicked();

    void on_option_clicked();

    void on_connection_clicked();

    void on_option_2_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *tempo;
    QTimer *timer;
    QTimer *temp02;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
