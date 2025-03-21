#include "mainwindow.h"
#include "ui_mainwindow.h" // Incluye la interfaz generada por el archivo .ui
#include "whiteboard.h"
#include <QKeyEvent>  // Para manejar eventos de teclado

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow) // Inicializa la interfaz de usuario
{
    ui->setupUi(this); // Configura la interfaz

    // Obtener el lienzo (WhiteBoard) desde el contenedor
    m_whiteboard = ui->whiteboard;

    // Conectar acciones de los botones de colores
    connect(ui->btnBlue, &QPushButton::clicked, this, &MainWindow::setPenBlue);
    connect(ui->btnRed, &QPushButton::clicked, this, &MainWindow::setPenRed);
    connect(ui->btnGreen, &QPushButton::clicked, this, &MainWindow::setPenGreen);
}

MainWindow::~MainWindow()
{
    delete ui; // Liberar la memoria de la interfaz de usuario
}

void MainWindow::setPenBlue() { m_whiteboard->setPenColor(Qt::blue); }
void MainWindow::setPenRed() { m_whiteboard->setPenColor(Qt::red); }
void MainWindow::setPenGreen() { m_whiteboard->setPenColor(Qt::green); }
void MainWindow::clearScreen() { m_whiteboard->clear(); }

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_0) {
        QApplication::quit();
    } else {
        QMainWindow::keyPressEvent(event);
    }
}
