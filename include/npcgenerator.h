#ifndef NPCGENERATOR_H
#define NPCGENERATOR_H

#include "mainwindow.h"

class NpcGenerator 
{
public:
    NpcGenerator();
    NpcData generate() const;

private:
    QStringList genders;
    QStringList races;
    QStringList ages;
    QStringList intelligences;
    QStringList socialClasses;
    QStringList appearances;
    QStringList dressStyles;
    QStringList jobs;
    QStringList personalities;
};

#endif
