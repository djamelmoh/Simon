#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QList>
#include <QString>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    void changeTextBouton(int x,int y,QString text);
    void changeImageBouton(int x,int y,QString lienImageRessources);
    QPushButton * recuperationQPushButton(int x,int y);

public :
    void boutonClicked();

    ~Widget();

private:
    Ui::Widget *ui;

};

#endif // WIDGET_H
