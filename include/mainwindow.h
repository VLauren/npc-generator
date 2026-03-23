#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QLabel;

struct NpcData
{
    QString gender;
    QString race;
    QString age;
    QString intelligence;
    QString socialClass;
    QString appearance;
    QString dressStyle;
    QString job;
    QString personality;
};

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void setupUI();
    void generateAndDisplay();
    void displayNPC(const NpcData& data);
    
    QLabel* genderLabel;
    QLabel* raceLabel;
    QLabel* ageLabel;
    QLabel* intelligenceLabel;
    QLabel* socialClassLabel;
    QLabel* appearanceLabel;
    QLabel* dressStyleLabel;
    QLabel* jobLabel;
    QLabel* personalityLabel;
};

#endif
