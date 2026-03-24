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
    QStringList genders;
    QVector<WeightedOption> races;
    QVector<WeightedOption> ages;
    QVector<WeightedOption> intelligences;
    QVector<WeightedOption> socialClasses;
    QStringList appearances;
    QStringList dressStyles;
    QStringList jobs;
    QStringList illegalJobs;
    QStringList personalities;
};

#endif
