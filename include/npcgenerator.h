#ifndef NPCGENERATOR_H
#define NPCGENERATOR_H

#include "mainwindow.h"

struct WeightedOption
{
    QString value;
    float weight;
};

class NpcGenerator 
{
public:
    NpcGenerator();
    NpcData generate() const;

private:
    QVector<WeightedOption> genders;
    QVector<WeightedOption> races;
    QVector<WeightedOption> ages;
    QVector<WeightedOption> intelligences;
    QVector<WeightedOption> socialClasses;
    QVector<WeightedOption> appearances;
    QVector<WeightedOption> dressStyles;
    QVector<WeightedOption> jobs;
    QVector<WeightedOption> personalities;
};

#endif
