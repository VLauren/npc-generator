#include "npcgenerator.h"

NpcGenerator::NpcGenerator()
{
    genders = 
    {
        "Hombre","Mujer"
    };
    
    races = 
    {
        "Humano", "Elfo"
    };

    ages = 
    {
        "Adulto", "Niño"
    };

    intelligences = 
    {
        "Normal", "Inteligente"
    };

    socialClasses = 
    {
        "Clase baja", "Clase media"
    };

    appearances = 
    {
        "Atractiva", "Pelo corto"
    };
    
    dressStyles = 
    {
        "Elegante", "Normal"
    };

    jobs = 
    {
        "Cocinero", "Cazador"
    };

    personalities = 
    {
        "Valiente", "Tímida"
    };
}

NpcData NpcGenerator::generate() const
{
    NpcData data;

    auto pick = [](const QStringList& list) -> QString
    {
        return list[0];
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
