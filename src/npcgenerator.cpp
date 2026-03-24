#include "npcgenerator.h"
#include <QRandomGenerator>

NpcGenerator::NpcGenerator()
{
    genders = 
    {
        {"Hombre", 0.5f},
        {"Mujer", 0.5f}
    };
    
    races = 
    {
        {"Humano", 0.9f},
        {"Elfo", 0.1f}
    };

    ages = 
    {
        {"Adulto", 0.5f},
        {"Niño", 0.5f},
    };

    intelligences = 
    {
        {"Normal", 0.5f},
        {"Inteligente", 0.5f},
    };

    socialClasses = 
    {
        {"Clase baja", 0.5f},
        {"Clase media", 0.5f},
    };

    appearances = 
    {
        {"Atractiva", 0.5f},
        {"Pelo corto", 0.5f},
    };
    
    dressStyles = 
    {
        {"Elegante", 0.5f},
        {"Normal", 0.5f},
    };

    jobs = 
    {
        {"Cocinero", 0.5f},
        {"Cazador", 0.5f},
    };

    personalities = 
    {
        {"Valiente", 0.5f},
        {"Tímida", 0.5f},
    };
}

NpcData NpcGenerator::generate() const
{
    NpcData data;

    auto pick = [](const QVector<WeightedOption>& options) -> QString
    {
        float roll = QRandomGenerator::global()->generateDouble();

        float cumulative = 0;
        for(const auto &option : options)
        {
            cumulative += option.weight;
            if(cumulative > roll)
                return option.value;
        }

        return options.last().value;
    };

    data.gender = pick(genders);
    data.race = pick(races);
    data.age = pick(ages);
    data.intelligence = pick(intelligences);
    data.socialClass = pick(socialClasses);
    data.appearance = pick(appearances);
    data.dressStyle = pick(dressStyles);
    data.job = pick(jobs);
    data.personality = pick(personalities);

    return data;
}
