#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget window;

    window.setWindowTitle("Guess the number game");
    window.resize(300, 50);
    window.show();

    return app.exec();
}
