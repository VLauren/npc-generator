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
        {"Balfo", 0.005f},
        {"Bárbaro", 0.01f},
        {"Elfo", 0.12f},
        {"Elno (bello: elfo+humano)", 0.03f},
        {"Enablin (enano+goblin)", 0.04f},
        {"Enano", 0.15f},
        {"Enomo (genio: enano+gnomo)", 0.02f},
        {"Gnomo", 0.20f},
        {"Gnoblin (gremlin: gnomo+goblin)", 0.005f},
        {"Goblin", 0.02f},
        {"Humano", 0.33f},
        {"Huro (humano+barbaro)", 0.03f},
        {"Falso niño (Mediano)", 0.04f}
    };

    ages = 
    {
        {"Bebé (0-2 años)", 0.04f},
        {"Niño pequeño (2-5 años)", 0.06f},
        {"Niño mediano (6-8 años)", 0.08f},
        {"Niño mayor (9-11 años)", 0.07f},
        {"Adolescente (12-14 años)", 0.09f},
        {"Adulto (15-24 años)", 0.09f},
        {"Adultez avanzada (25-34 años)", 0.11f},
        {"Mediana edad (35-44 años)", 0.12f},
        {"Mediana edad avanzada (45-54 años)", 0.15f},
        {"Edad avanzada (55-64 años)", 0.09f},
        {"Vejez (65-74 años)", 0.06f},
        {"Vejez avanzada (75-84 años)", 0.03f},
        {"Gran anciano (85+ años)", 0.01f}
    };

    intelligences = 
    {
        {"Muy poca inteligencia", 0.03f},
        {"Poca inteligencia", 0.10f},
        {"Normal", 0.67f},
        {"Inteligente", 0.15f},
        {"Muy inteligente", 0.05f}
    };

    socialClasses = 
    {
        {"Clase bajísima (pobreza)", 0.099f},
        {"Clase baja", 0.19f},
        {"Clase media", 0.50f},
        {"Clase media-alta", 0.15f},
        {"Clase alta (nobleza)", 0.05f},
        {"Clase altísima (clero)", 0.01f},
        {"Clase selecta (realeza)", 0.001f}
    };

    appearances = 
    {
        "Alta", "Atlética", "Atractiva", "Baja", "Barbuda",
        "Calva", "Con pecas", "Cuidada/Sin barba", "Delgada", "Descuidada",
        "Enjoyada (Muchas joyas)", "Guapa", "Intimidante", "Muchas cicatrices",
        "Mucho maquillaje", "Muchos lunares", "Musculada", "Manos grandes",
        "Manos pequeñas", "Pelo color diferente (Natural)", "Pelo corto",
        "Pelo largo", "Pelo teñido", "Peso de más", "Poco atractiva", "Salvaje"
    };

    dressStyles = 
    {
        "A la moda", "Colorida", "Combate", "Combinada", "Descuidada",
        "Elegante", "Normal", "Extravagante", "Formal", "Harapienta",
        "Laboral", "Llamativa", "Lujosa", "Modesta", "Mucha ropa",
        "Pasada de moda", "Poca ropa", "Provocativa", "Salvaje", "Sencilla", "Sobria"
    };

    jobs = 
    {
        "Abogado", "Actor", "Agente de sanidad alimentaria", "Agricultor",
        "Aguador (También hace de Bombero)", "Albañil", "Alcantarillero", "Alquimista",
        "Árbitro", "Arquitecto", "Artesano de alcohol", "Artesano de cieno",
        "Artesano de instrumentos", "Artesano de pieles", "Asesor", "Atleta",
        "Bailarín", "Banquero", "Barrendero", "Bolista (Jugador de bolos)",
        "Boticario", "Burócrata", "Camarero", "Camello", "Cantante",
        "Carnicero", "Carpintero", "Catador de comida", "Cazador", "Ceramista",
        "Científico", "Cocinero", "Comercial", "Combatiente de una orden",
        "Contable", "Curandero", "Curtidor (Quién trabaja el cuero)",
        "Crítico de arte", "Crítico de cocina", "Decorador", "Dependiente",
        "Desollador (Quién quita/trabaja la piel de animales)", "Detective",
        "Dibujante", "Director de orquesta", "Director de teatro", "Diseñador",
        "Domador", "Entrenador personal", "Erudito", "Escalador", "Escritor",
        "Explorador", "Flautista", "Florista", "Forense", "Frutero",
        "Ganadero", "Golfista (Jugador de mini-golf)", "Guardacostas",
        "Guardaespaldas", "Guardia", "Guardia secreta", "Guardián de zoológico",
        "Guía de arte", "Guía espiritual", "Guitarrista", "Granjero", "Heladero",
        "Herrero", "Herrero mágico", "Humorista", "Influencer", "Inquisidor",
        "Inventor", "Jardinero", "Joyero", "Juez", "Jugador de Béisbol",
        "Jugador de Juegos de mesa (Legal)", "Párelista (Jugador de Párel)",
        "Leñador", "Limpiador", "Maestro de artes marciales", "Maestro de armas",
        "Maestro de magia", "Maestro de yoga", "Manitas (Arregla/monta cosas simples)",
        "Martillo de Tántalo (Martillo)", "Masajista", "Mecenas (Productor de arte)",
        "Mediador", "Mensajero", "Minero", "Modelo", "Modista",
        "Montador (Estructuras de corta duración)", "Nadador", "Novicio",
        "Nutricionista", "Oboísta (Quién toca el oboe)",
        "Operario de demoliciones (Destructor)", "Panadero", "Peluquero",
        "Periodista", "Pescadero", "Pescador", "Pintor", "Poeta",
        "Porteador (Persona que lleva palanquín)", "Portero (Vigilante de puerta)",
        "Profesor elemental (Escuela)", "Profesor laboral", "Profesor superior (Universidad)",
        "Profesor de arte", "Psicólogo", "Psiquiatra", "Recepcionista", "Recolector",
        "Repostero", "Sacerdote", "Secretario", "Sepulturero", "Sirviente",
        "Escudo de Tántalo (Escudo)", "Tabernero", "Tejedor", "Tendero",
        "Tenista", "Traceurs/traceuses (Deportista de Parkour)", "Trabajador de industria",
        "Transportista", "Trompetista", "Vendedor de objetos mágicos",
        "Vigilante de muralla", "Vigilante de seguridad", "Violinista"
    };

    illegalJobs = 
    {
        "Apostador (Ilegal)",
        "Bandido",
        "Científico ilegal",
        "Espía",
        "Estafador",
        "Herrero clandestino",
        "Ladrón",
        "Líder de mafia (Ilegal)",
        "Líder espiritual (Ilegal)",
        "Mafioso (Ilegal)",
        "Prostituto (Ilegal)",
        "Proxeneta (Ilegal)",
        "Sectario (Ilegal)",
        "Sicario (Ilegal)",
        "Traficante de órganos (Ilegal)",
        "Vendedor clandestino (Ilegal)"
    };

    personalities = 
    {
        "Abierta", "Aburrida", "Acogedora", "Acomplejada", "Activa",
        "Adicta", "Adorable", "Agresiva", "Ahorradora", "Alegre",
        "Amable", "Amargada", "Ambiciosa", "Amigable", "Analista",
        "Ansiosa", "Apasionada", "Artística", "Asexual", "Asustadiza",
        "Atrevida", "Autoculpabilizadora (se echa las culpas)", "Avara",
        "Bocazas", "Bondadosa", "Borde", "Burlona", "Cálida", "Callada",
        "Cantarina (habla cantando)", "Cariñosa", "Cauta", "Celosa",
        "Cerrada", "Charlatana", "Chismosa (gusto por hablar o escuchar de otros)",
        "Cobarde", "Coqueta (le gusta verse bien)", "Coleccionista",
        "Competitiva", "Confiable", "Confusa", "Consejera", "Considerada",
        "Conspiradora", "Constante", "Controladora", "Cooperativa", "Corrupta",
        "Creativa", "Creída (habla mucho y bien de sí misma)", "Cuidadosa",
        "Curiosa", "Dependiente", "Depresiva", "Desarraigada (no le importa su familia o nación)",
        "Desconfiada", "Descuidada", "Deshonesta", "Desquiciada",
        "Despilfarradora (Gastona)", "Despreocupada", "Desordenada",
        "Diferente/Inadaptada", "Diplomática", "Disruptiva", "Divertida",
        "Dominante", "Dulce", "Dura", "Empática", "Envidiosa", "Egocéntrica",
        "Egoísta", "Emocional", "Escrupulosa", "Espabilada", "Especista (Racista)",
        "Estricta", "Eufórica", "Exigente", "Extremista", "Fatalista", "Fiel",
        "Fuerte", "Fría", "Ganadora", "Generosa", "Gregaria (Hogareña)",
        "Halagadora", "Habladora", "Hipócrita", "Honesta", "Humilde",
        "Impaciente", "Impetuosa", "Implacable", "Impulsiva", "Impuntual",
        "Incauta", "Inconformista", "Inconsciente", "Inculta", "Independiente",
        "Individualista", "Inflexible", "Inquieta", "Inmadura", "Inocente",
        "Insegura", "Intensa", "Intimidante", "Intolerante", "Irascible",
        "Irracional", "Irrespetuosa", "Justiciera", "Juzgadora", "Ladronzuela",
        "Leal", "Líder", "Ligona", "Limpia", "Mal hablada (Soez)",
        "Manipuladora", "Mentirosa", "Negociadora", "Obsesiva", "Olvidadiza",
        "Optimista", "Pacifista", "Patriota", "Peleona", "Peligrosa",
        "Pensativa", "Perceptiva", "Perdedora", "Perezosa", "Perfeccionista",
        "Pesada/Insistente", "Pesimista", "Picaresca",
        "Postureta (lo más importante es parecer interesante)", "Pragmática",
        "Prepotente (Engreída)", "Presuntuosa", "Protectora", "Quejica",
        "Racional", "Reflexiva", "Religiosa", "Rencorosa", "Reservada",
        "Respetuosa", "Responsable", "Restrictiva", "Retadora", "Revolucionaria",
        "Ruidosa", "Sabia", "Sádica", "Salvaje", "Santurrona (Demasiado buena)",
        "Seductora", "Segura", "Sensible", "Seria", "Servicial", "Silenciosa",
        "Sincera", "Sinvergüenza", "Soberbia", "Sobreprotectora", "Sociable",
        "Solidaria", "Solitaria", "Sumisa", "Superficial", "Supersticiosa",
        "Tacaña (no quiere gastar dinero)", "Tímida", "Tolerante", "Traicionera",
        "Tramposa", "Tranquila", "Traviesa", "Triste", "Trivial", "Valiente",
        "Viciosa", "Vividora", "Voluble (influenciable por la opinión del resto)",
        "Vulnerable"
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

    float illegalChance = 
        static_cast<float>(illegalJobs.size()) / (jobs.size() + illegalJobs.size());
    if(QRandomGenerator::global()->generateDouble() < illegalChance)
        data.job = pick(illegalJobs) + ", " + pick(jobs);
    else
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
