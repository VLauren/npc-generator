#include "npcgenerator.h"
#include <QRandomGenerator>

NpcGenerator::NpcGenerator()
{
    genders = 
    {
        "Hombre", "Mujer"
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
        "Atractiva",
        "Pelo corto"
    };
    
    dressStyles = 
    {
        "Elegante",
        "Normal"
    };

    jobs = 
    {
        "Cocinero",
        "Cazador"
    };

    personalities = 
    {
        "Abierta", "Aburrida", "Acogedora", "Acomplejada", "Activa",
        "Adicta", "Adorable", "Agresiva",
        "Valiente",
        "Tímida"
    };
}

NpcData NpcGenerator::generate() const
{
    NpcData data;

    // Pick random string from list method
    auto pick = [](const QStringList& options) -> QString
    {
        int index = QRandomGenerator::global()->bounded(options.size());
        return options[index];
    };

    // Pick random string from weighted list method
    auto weightedPick = [](const QVector<WeightedOption>& options) -> QString
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
    data.race = weightedPick(races);
    data.age = weightedPick(ages);
    data.intelligence = weightedPick(intelligences);
    data.socialClass = weightedPick(socialClasses);
    data.appearance = pick(appearances);
    data.dressStyle = pick(dressStyles);
    data.job = pick(jobs);

    QStringList pickedPersonalities;
    QStringList pool = personalities; // Create a copy
    for (int i = 0; i < 4; i++)
    {
        int index =  QRandomGenerator::global()->bounded(pool.size());
        pickedPersonalities.append(pool.takeAt(index));
    }
    data.personality = pickedPersonalities.join(", ");

    return data;
}
