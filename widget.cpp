#include "widget.h"
#include "ui_widget.h"
#include <vector>

using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QHBoxLayout *layout = new QHBoxLayout(this);
    QSignalMapper* mapper = new QSignalMapper();
    magicNr = rand() % 10;

    for (int i = 0; i < 10; i ++) {
        buttons[i] = new QPushButton(QString::number(i));
        mapper->setMapping(buttons[i], i);
        //Setter dei til disabled ; check for om det funker
        buttons[i]->setDisabled(true);
        connect(buttons[i], SIGNAL(clicked()), mapper, SLOT(map()));
        layout->addWidget(buttons[i]);
    }

    nyttSpill = new QPushButton("Start nytt spill");
    mapper->setMapping(nyttSpill, "Start nytt spill");
    connect(nyttSpill, SIGNAL(clicked()), mapper, SLOT(map()));
    layout->addWidget(nyttSpill);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressed(int) {

}

void Widget::keyPressed(QString) {
    magicNr = rand() % 10;

    for (QPushButton b : buttons) {
        b.setEnabled(true);
        b.setStyleSheet("* { background-color: white }");
    }
}
