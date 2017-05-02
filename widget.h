#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QPushButton *knapp0, *knapp1, *knapp2, *knapp3, *knapp4, *knapp5, *knapp6, *knapp7, *knapp8, *knapp9, *nyttSpill;
    QPushButton* buttons[10];
    int magicNr;

public slots:
    void keyPressed(int);
    void keyPressed(QString);
};

#endif // WIDGET_H
