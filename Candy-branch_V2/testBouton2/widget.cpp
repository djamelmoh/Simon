#include "widget.h"
#include "ui_widget.h"
#include <QGridLayout>
#include <QObjectList>
#include <QLayoutItem>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QGridLayout *mylayout =new QGridLayout();
    for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {

                QPushButton* unBouton = new QPushButton();
                unBouton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

                mylayout->addWidget(unBouton,i,j);
            }
        }

    this->setLayout(mylayout);
    this->changeImageBouton(1,1,"://img/rouge.jpg");
    this->changeImageBouton(1,2,"://img/bleu.jpg");
    this->changeImageBouton(2,1,"://img/vert.png");
    this->changeImageBouton(2,2,"://img/jaune.jpg");

    QPushButton *Rouge = this->recuperationQPushButton(1,1);
    QPushButton *Bleu = this->recuperationQPushButton(1,2);
    QPushButton *Vert = this->recuperationQPushButton(2,1);
    QPushButton *Jaune = this->recuperationQPushButton(2,2);

    QObject::connect(Rouge,&QPushButton::clicked, this,&Widget::boutonClicked);
    QObject::connect(Bleu,&QPushButton::clicked, this,&Widget::boutonClicked);
    QObject::connect(Vert,&QPushButton::clicked, this,&Widget::boutonClicked);
    QObject::connect(Jaune,&QPushButton::clicked, this,&Widget::boutonClicked);



}
QPushButton * Widget::recuperationQPushButton(int x,int y)
{
    QLayoutItem* item = this->layout()->itemAt( (x-1) + (y-1) * 2);
    QWidget* widget = item->widget();
    QPushButton* button = dynamic_cast<QPushButton*>(widget);
    return button;
}

void Widget::boutonClicked()
{
//    QString piece;
//        QObject* button = QObject::sender();
//        if (button == ui->pushButton)
//        {
//            piece = ui->label->text();
//        }
//        else if (button == ui->pushButton_2)
//        {
//            piece = ui->label_2->text();
//        }
//        else
//        {
//            piece = ui->label_3->text();
//        }

//        qDebug() << "Starting to play:" << piece;
}

void Widget::changeImageBouton(int x,int y,QString lienImageRessources)
{
    QPushButton * monBtn;
    monBtn = recuperationQPushButton( x, y);
    QPixmap pixmap(lienImageRessources);
    QIcon iconBack(pixmap);
    monBtn->setIcon(iconBack);
    monBtn->setIconSize(QSize(90, 90));
}

Widget::~Widget()
{
    delete ui;
}
