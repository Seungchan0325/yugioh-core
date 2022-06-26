#include "common.h"
#include <string>
#include <set>

namespace yugioh_core
{

struct StaticCardBase {
    std::wstring card_name;
    std::wstring card_description;
};

struct StaticMonsterCardBase : public StaticCardBase {
    enum Primary{
        NORMAL,
        EFFECT,
        PENDULUM,
    };

    enum CardType {
        MONSTER,
        RITUAL,
        FUSION,
        SYNCHRO,
        XYZ,
        LINK,
    };

    enum Secondary {
        SPECIAL_SUMMON,
        TUNNER,
    };

    enum Ability {
        FLIP,
        TOON,
        SPIRIT,
        UNION,
        GEMINI,
    };

    enum Type {
        AQUA,
        BEAST,
        BEAST_WORRIOR,
        CREATOR_GOD,
        CYBERSE,
        DINOSAUR,
        DIVINE_BEAST,
        DRAGON,
        FAIRY,
        FIEND,
        FISH,
        INSECT,
        MACHINE,
        PLANT,
        PSYCHIC,
        PYRO,
        REPTILE,
        ROCK,
        SEA_SERPENT,
        SPELL_CASTER,
        THUNDER,
        WARRIOR,
        WINGED_BEAST,
        WYRM,
        ZOMBIE,
    };

    enum Attribute {
        DARK,
        DIVINE,
        EARTH,
        FIRE,
        LIGHT,
        WATER,
        WIND,
    };

    uint32_t level_rank_link;
    uint32_t attack_point;
    uint32_t defense_point;
    Primary primary;
    CardType card_type;
    std::set<Secondary> secondaries;
    std::set<Ability> abilities;
    Type type;
    Attribute attribute;
};

struct StaticMonsterCard : public StaticMonsterCardBase {
    StaticMonsterCard() {
        card_type = CardType::MONSTER;
    }
}

struct StaticRitualMonsterCard : public StaticMonsterCardBase {
    StaticRitualMonsterCard() {
        card_type = CardType::RITUAL;
    }
}

struct StaticFusionMonsterCard : public StaticMonsterCardBase {
    StaticFusionMonsterCard() {
        card_type = CardType::FUSION;
    }
}

struct StaticSynchroMonsterCard : public StaticMonsterCardBase {
    StaticSynchroMonsterCard() {
        card_type = CardType::SYNCHRO;
    }
}

struct StaticXyzMonsterCard : public StaticMonsterCardBase {
    StaticXyzMonsterCard() {
        card_type = CardType::XYZ;
    }
}

struct StaticLinkMonsterCard : public StaticMonsterCardBase {
    enum LinkMarkerDirection {
        BOTTOM,
        BOTTOM_LEFT,
        LEFT,
        TOP_LEFT,
        TOP,
        TOP_RIGHT,
        RIGHT,
        BOTTOM_RIGHT,
    };

    StaticLinkMonsterCard() {
        card_type = CardType::LINK;
        defense_point = 0;
    }

    std::set<LinkMarkerDirection> link_markers_direction;
}

struct StaticSpellCard :  public StaticCardBase {
    enum Type {
        CONTINOUSE,
        EQUIP,
        FIELD,
        NORMAL,
        QUICK_PLAY,
        RITUAL,
    };

    Type type;
}

struct StaticTrapCard : public StaticCardBase {
    enum Type {
        CONTINOUSE,
        COUNTER,
        NORMAL,
    };

    Type type;
}

}