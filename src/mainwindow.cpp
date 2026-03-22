#include "mainwindow.h"
#include "npcgenerator.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <qnamespace.h>

MainWindow::MainWindow(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("Generador de NPC");
    // resize(350, 500);
    resize(500, 700);

    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* title = new QLabel("Generador de NPC", this);
    title->setAlignment(Qt::AlignCenter);
    QFont titleFont = title->font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    title->setFont(titleFont);

    layout->addWidget(title);
    layout->addSpacing(20);

    // helper lambda to create a row
    auto createRow = [this](const QString& labelText, QLabel*& valueLabel) -> QHBoxLayout*
    {
        QHBoxLayout* row = new QHBoxLayout();
        QLabel *name = new QLabel(labelText + ":", this);
        name->setTextInteractionFlags(Qt::TextSelectableByMouse);
        name->setMinimumWidth(100);
        valueLabel = new QLabel("???", this);
        valueLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
        row->addWidget(name);
        row->addWidget(valueLabel, 1);
        return row;
    };

    layout->addLayout(createRow("Genero", genderLabel));
    layout->addLayout(createRow("Raza", raceLabel));
    layout->addLayout(createRow("Edad", ageLabel));
    layout->addLayout(createRow("Inteligencia", intelligenceLabel));
    layout->addLayout(createRow("Clase social", socialClassLabel));
    layout->addLayout(createRow("Apariencia", appearanceLabel));
    layout->addLayout(createRow("Estilo", dressStyleLabel));
    layout->addLayout(createRow("Trabajo", jobLabel));
    layout->addLayout(createRow("Personalidad", personalityLabel));

    layout->addStretch();

    QPushButton* button = new QPushButton("Generar NPC", this);
    layout->addWidget(button);

    // ------------------------

    // NpcData data;
    // data.gender = "Hombre";
    // data.race = "Humano";
    // data.age = "Adulto";
    // data.intelligence = "Normal";
    // data.socialClass = "Clase media";
    // data.appearance = "Atletica";
    // data.dressStyle = "Elegante";
    // data.job = "Panadero";
    // data.personality = "Leal, Valuente, Honesto, Curioso";

    NpcGenerator* generator = new NpcGenerator();

    displayNPC(generator->generate());
}

void MainWindow::displayNPC(const NpcData& data)
{
    genderLabel->setText(data.gender);
    raceLabel->setText(data.race);
    ageLabel->setText(data.age);
    intelligenceLabel->setText(data.intelligence);
    socialClassLabel->setText(data.socialClass);
    appearanceLabel->setText(data.appearance);
    dressStyleLabel->setText(data.dressStyle);
    jobLabel->setText(data.job);
    personalityLabel->setText(data.personality);
}
