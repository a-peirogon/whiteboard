#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Establecer el tamaño de la ventana (ancho x alto)
    w.resize(800, 600); // 800x600 píxeles

    // Mostrar la ventana
    w.show();

    return a.exec();
}
