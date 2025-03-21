#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "whiteboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setPenBlue();
    void setPenRed();
    void setPenGreen();
    void clearScreen();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui;
    WhiteBoard *m_whiteboard; // Puntero al lienzo (WhiteBoard)
};

#endif // MAINWINDOW_H
