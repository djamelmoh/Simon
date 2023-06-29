/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Bleu;
    QPushButton *Rouge;
    QPushButton *Jaune;
    QPushButton *Vert;
    QPushButton *pushButton;
    QLabel *label;
    QProgressBar *progressBar;
    QLabel *label_2;
    QToolButton *option;
    QLineEdit *lineEdit;
    QPushButton *connection;
    QLabel *pseudo;
    QLabel *score;
    QToolButton *option_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(500, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(500, 550));
        MainWindow->setMaximumSize(QSize(500, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Bleu = new QPushButton(centralWidget);
        Bleu->setObjectName(QStringLiteral("Bleu"));
        Bleu->setEnabled(false);
        Bleu->setGeometry(QRect(20, 140, 200, 160));
        Bleu->setSizeIncrement(QSize(90, 100));
        Bleu->setBaseSize(QSize(90, 100));
        Bleu->setStyleSheet(QLatin1String("background-color: rgb(0, 180, 255);\n"
""));
        Bleu->setIconSize(QSize(100, 80));
        Rouge = new QPushButton(centralWidget);
        Rouge->setObjectName(QStringLiteral("Rouge"));
        Rouge->setEnabled(false);
        Rouge->setGeometry(QRect(270, 140, 200, 160));
        Rouge->setStyleSheet(QStringLiteral("background-color: red;"));
        Rouge->setIconSize(QSize(100, 80));
        Jaune = new QPushButton(centralWidget);
        Jaune->setObjectName(QStringLiteral("Jaune"));
        Jaune->setEnabled(false);
        Jaune->setGeometry(QRect(20, 320, 200, 160));
        Jaune->setStyleSheet(QStringLiteral("background-color: yellow;"));
        Jaune->setCheckable(false);
        Jaune->setAutoRepeatDelay(300);
        Jaune->setDefault(false);
        Jaune->setFlat(false);
        Vert = new QPushButton(centralWidget);
        Vert->setObjectName(QStringLiteral("Vert"));
        Vert->setEnabled(false);
        Vert->setGeometry(QRect(270, 320, 200, 160));
        Vert->setStyleSheet(QStringLiteral("background-color: rgb(127, 255, 54);"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 80, 151, 51));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 501, 71));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("background-color: none;"));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label->setMargin(20);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setGeometry(QRect(17, 520, 471, 23));
        sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy);
        progressBar->setMaximum(6);
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 501, 71));
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral(""));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setMargin(20);
        option = new QToolButton(centralWidget);
        option->setObjectName(QStringLiteral("option"));
        option->setGeometry(QRect(0, 0, 91, 41));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(190, 260, 113, 20));
        connection = new QPushButton(centralWidget);
        connection->setObjectName(QStringLiteral("connection"));
        connection->setGeometry(QRect(200, 300, 75, 23));
        pseudo = new QLabel(centralWidget);
        pseudo->setObjectName(QStringLiteral("pseudo"));
        pseudo->setGeometry(QRect(30, 570, 131, 16));
        score = new QLabel(centralWidget);
        score->setObjectName(QStringLiteral("score"));
        score->setEnabled(true);
        score->setGeometry(QRect(320, 570, 171, 20));
        option_2 = new QToolButton(centralWidget);
        option_2->setObjectName(QStringLiteral("option_2"));
        option_2->setGeometry(QRect(460, 0, 31, 31));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Bleu->setText(QString());
        Rouge->setText(QString());
        Jaune->setText(QString());
        Vert->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Demarrer", 0));
        label->setText(QString());
        progressBar->setFormat(QApplication::translate("MainWindow", "%v", 0));
        label_2->setText(QApplication::translate("MainWindow", "Simon", 0));
        option->setText(QApplication::translate("MainWindow", "Comment jouer ?", 0));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Votre Pseudo", 0));
        connection->setText(QApplication::translate("MainWindow", "Connexion", 0));
        pseudo->setText(QApplication::translate("MainWindow", "Pseudo", 0));
        score->setText(QApplication::translate("MainWindow", "Score :", 0));
        option_2->setText(QApplication::translate("MainWindow", "?", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
