#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
QString sequence="";
QString reponse="";
QString pseudo="";
int score=0;
int score1=0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Mise en place des attribus pour la connexion à la base de données
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../Base/qt.db"); // Nom de la base

    //Cacher l'interface du jeu jusqu'à la connection
    ui->Bleu->setVisible(false);
    ui->Jaune->setVisible(false);
    ui->Vert->setVisible(false);
    ui->Rouge->setVisible(false);
    ui->label_2->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->option->setVisible(false);
    ui->option_2->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->pseudo->setVisible(false);
    ui->score->setVisible(false);
    ui->progressBar->setVisible(false);

    //Création des timer
    tempo = new QTimer(this);
    connect(tempo,SIGNAL(timeout()),this,SLOT(generer_sequence()));

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(limite_temps()));

    temp02 = new QTimer(this);
    connect(temp02,SIGNAL(timeout()),this,SLOT(changement()));
}


void MainWindow::changement()
{
    ui->label->setStyleSheet("background-color: none;");
}

/*********************/
/*Écran de connection*/
/*********************/
void MainWindow::on_connection_clicked()
{
    //Vérification présence d'un pseudo
    if (ui->lineEdit->text()=="")
        //Si aucun pseudo présent afficher une boîte de dialogue
        QMessageBox::information(this,"Attention","Veuillez renseigner un Pseudo valide");
    else {
        //Rendre visible l'interface du jeu
        ui->Bleu->setVisible(true);
        ui->Jaune->setVisible(true);
        ui->Vert->setVisible(true);
        ui->Rouge->setVisible(true);
        ui->label_2->setVisible(true);
        ui->option->setVisible(true);
        ui->option_2->setVisible(true);
        ui->pushButton->setVisible(true);
        ui->pseudo->setVisible(true);
        ui->score->setVisible(true);

        //Cacher l'écran de connexion
        ui->connection->setVisible(false);
        ui->lineEdit->setVisible(false);

        //Récupérer le pseudo du joueur
        pseudo=ui->lineEdit->text();

        //Afficher le pseudo en bas à gauche de la fenêtre
        ui->pseudo->setText(pseudo);

        if(db.open()) {
            QSqlQuery requete;
            if(requete.exec("SELECT score FROM jeu WHERE Pseudo='"+pseudo+"';")) {
                requete.next();
                if(requete.isNull(0)){
                    requete.exec("INSERT INTO jeu (Pseudo, Score) VALUES ('"+pseudo+"', '0');");
                    score=0;
                    ui->score->setText("Score : " + QString::number(score));
                }
                else{
                    score= requete.value(0).toInt();
                    ui->score->setText("Meilleur Score : " + QString::number(score));
                }
            }
            db.close(); // Fermeture de la base de données
        }
        else {
            qDebug() << db.lastError();
        }
    }
}


/*****************/
/*Écran d'accueil*/
/*****************/

void MainWindow::on_pushButton_clicked()
{
    reponse="";
    sequence="";
    ui->pushButton->setVisible(false);
    ui->option->setVisible(false);
    ui->option_2->setVisible(false);
    ui->label_2->setText("");
    tempo->start(1000);
    ui->progressBar->setValue(0);
    timer->stop();
}
//Afficher les règles du jeu
void MainWindow::on_option_clicked()
{
    QMessageBox::information(this,"Règles","Cliquez sur le bouton \"démarrer\" au milieu de l'écran.Puis, une séquence de couleur va s'afficher en haut de l'écran. À l'aide des 4 boutons de couleur vous devez reproduire cette séquence dans un temps imparti.");
}


//Fonction gérant la limite de la barre de temps
void MainWindow::generer_sequence()
{
    if(sequence.length()<4){
        temp02->start(500);
        int c_aleatoire=qrand()%4;
        switch( c_aleatoire )
        {
        case 0:
            sequence=sequence+"R";ui->label->setStyleSheet("background-color: red;");break;
        case 1:
            sequence=sequence+"B";ui->label->setStyleSheet("background-color: rgb(0, 180, 255);");break;
        case 2:
            sequence=sequence+"J";ui->label->setStyleSheet("background-color: yellow;");break;
        case 3:
            sequence=sequence+"V";ui->label->setStyleSheet("background-color: rgb(127, 255, 54);");break;
        }
    }
    else{
        tempo->stop();
        ui->progressBar->setVisible(true);
        timer->start(1000);
        ui->label->setText("");
        ui->label->setStyleSheet("background-color: none;");
        ui->label_2->setText("A vous");
        ui->Bleu->setEnabled(true);
        ui->Rouge->setEnabled(true);
        ui->Jaune->setEnabled(true);
        ui->Vert->setEnabled(true);
    }
}

//Fonction gérant la limite de la barre de temps
void MainWindow::limite_temps()
{
    //Pour chaque fin de timer (1s) augmenter la valeur de la barre de 1
    ui->progressBar->setValue(ui->progressBar->value()+1);

    //Si 6 secondes se sont écoulées
    if(ui->progressBar->value()==6){
        //Arrêter le timer
        timer->stop();

        //Afficher "Perdu" dans le label du centre
        ui->label_2->setText("Perdu");
            {
                if(score1>score){
                 QMessageBox::information(this,"Félicitations","Vous avez battu votre propre record !");
            }

        score1=0;
        ui->score->setText("Score actuel : " + QString::number(score1));
}
        //Rendre Visible le bouton démarrer ainsi que le bouton indiquant les règles
        ui->pushButton->setVisible(true);
        ui->option->setVisible(true);
        ui->option_2->setVisible(true);
        //redésactiver les boutons de couleurs
        ui->Bleu->setEnabled(false);
        ui->Rouge->setEnabled(false);
        ui->Jaune->setEnabled(false);
        ui->Vert->setEnabled(false);
        ui->progressBar->setVisible(false);
    }
}

/*******************************/
/*Vérification du bouton cliqué*/
/*******************************/
void MainWindow::compare()
{
    if(sequence.length()==reponse.length()){
        timer->stop();
        ui->progressBar->setValue(0);
        ui->pushButton->setVisible(true);
        ui->option->setVisible(true);
        ui->option_2->setVisible(true);
        ui->Bleu->setEnabled(false);
        ui->Rouge->setEnabled(false);
        ui->Jaune->setEnabled(false);
        ui->Vert->setEnabled(false);
        ui->progressBar->setVisible(false);
        if(sequence==reponse)
        {
            ui->label_2->setText("Gagné");
            score1=score1+100;
            if(db.open()&&score1>score) {
                QSqlQuery requete;
                requete.exec("UPDATE jeu SET Score = '"+QString::number(score1)+"' WHERE Pseudo='"+pseudo+"';");
            }
            ui->score->setText("Score actuel : " + QString::number(score1));


        }
        else
        {
            ui->label_2->setText("Perdu");
            if(score1>score){
            QMessageBox::information(this,"Félicitations","Vous avez battu votre propre record !");
            }
            score1=0;
            ui->score->setText("Score actuel : " + QString::number(score1));
        }

    }
}

/*******************************/
/*Vérification du bouton cliqué*/
/*******************************/

void MainWindow::on_Bleu_clicked()
{
    reponse=reponse+"B";
    compare();
}

void MainWindow::on_Rouge_clicked()
{
    reponse=reponse+"R";
    compare();
}

void MainWindow::on_Jaune_clicked()
{
    reponse=reponse+"J";
    compare();
}

void MainWindow::on_Vert_clicked()
{
    reponse=reponse+"V";
    compare();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_option_2_clicked()
{
    QMessageBox::information(this,"Information","Nous sommes des étudiants en BTS Snir. Nous nous nommons Mohammedi Djamel et Dauvergne Florian. J'espere que vous vous amuserez bien avec ce jeu." );
}
