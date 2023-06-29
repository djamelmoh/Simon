#include "jeu.h"
#include "ui_jeu.h"
#include <QLabel>
#include <QProgressBar>
Jeu::Jeu(QWidget *parent, int choix) :
    QWidget(parent),
    ui(new Ui::Jeu)
{
    ui->setupUi(this);
    QLabel *label=new QLabel(this);
    QProgressBar *barre=new QProgressBar(this);
    barre->format();
    switch(choix){
    default:label->setText("Niveau Libre");break;
    case 1:label->setText("Niveau 1");break;
    case 2:label->setText("Niveau 2");break;
    case 3:label->setText("Niveau 3");break;
    }
}

Jeu::~Jeu()
{
    delete ui;
}
