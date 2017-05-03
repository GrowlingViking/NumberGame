#include "widget.h"
#include "ui_widget.h"
#include <vector>

using namespace std;

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
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

void Widget::keyPressed(int i) {
    if (i == magicNr) {
        buttons[i]->setStyleSheet(" * { background-color: green }");
        QMessageBox *mBox = new QMessageBox();
        mBox->about(this, "Congrats!", "You picked the right number!");
    } else if (i < magicNr) {
        for (int j = 0; j <= i; j ++) {
            buttons[j]->setStyleSheet(" * { background-color: red }");
        }
    } else {
        for (int k = 9; k >= i; k --) {
            buttons[k]->setStyleSheet(" * { background-color: red }");
        }
    }
}

void Widget::keyPressed(QString) {
    magicNr = rand() % 10;

    for (int i = 0; i < 10; i ++) {
        buttons[i]->setEnabled(true);
        buttons[i]->setStyleSheet("* { background-color: white }");
    }
}
