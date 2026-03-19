#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("Generador de NPC");
    resize(350, 500);
}
