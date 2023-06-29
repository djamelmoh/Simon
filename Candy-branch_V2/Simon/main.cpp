#include "jeu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int choix=0;
    Jeu w(0,choix);
    w.show();
    return a.exec();
}
