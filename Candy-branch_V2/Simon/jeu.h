#ifndef JEU_H
#define JEU_H

#include <QWidget>

namespace Ui {
class Jeu;
}

class Jeu : public QWidget
{
    Q_OBJECT
    
public:
    explicit Jeu(QWidget *parent = 0,int choix=0);
    ~Jeu();
    
private slots:
    void on_pushButton_clicked();

    void on_label_linkHovered(const QString &link);

private:
    Ui::Jeu *ui;
};

#endif // JEU_H
