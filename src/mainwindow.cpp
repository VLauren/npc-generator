#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("Generador de NPC");
    // resize(350, 500);
    resize(500, 700);

    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* title = new QLabel("Generator de NPC", this);
    title->setAlignment(Qt::AlignCenter);
    QFont titleFont = title->font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    title->setFont(titleFont);

    layout->addWidget(title);
    layout->addSpacing(20);

    QLabel* placeholder = new QLabel("Pulsa el boton para generar", this);
    placeholder->setAlignment(Qt::AlignCenter);
    layout->addWidget(placeholder);

    layout->addStretch();

    QPushButton* button = new QPushButton("Generar NPC", this);
    layout->addWidget(button);
}
