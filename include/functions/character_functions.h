#pragma once
using namespace std;
namespace rpg {
    enum CharacterType
    {
        Knight,
        Assassin,
        Berserk,
        NonType

    };
    enum PersonGodStatus {
        god,
        ungod
    };
    enum ActiveSkillStatus {
        selected,
        unselected
    };
    enum PassiveSkillStatus {
        active,
        unactive
    };
    enum PersonLiveStatus {
        live,
        dead
    };
    //enum GameStatus {
    //    gone,
    //    ended
    //};
    class Character {
    public:
        Character(float hp, float armor, float damage,
            PersonGodStatus godStatus, ActiveSkillStatus activeSkillStatus, PassiveSkillStatus passiveSkillStatus,
            CharacterType type, PersonLiveStatus liveStatus);
        Character();
        
       /* void AssassinSkill();
        void KnightSkill();
        void BerserkSkill();*/
        void press_active_skill();

        float hp_calculation(float damageFromOpponent);
        void character_parametr_calculation();
        void passive_skill_chance();

        float damage_taken(float damage_given);
        float damage_given();

        CharacterType get_type();
        void set_type(CharacterType a);

        void set_damage(float a);
        float get_damage();

        void set_armor(float a);
        float get_armor();

        void set_hp(float a);
        float get_hp();

        void set_active_skill_status(ActiveSkillStatus a);
        void set_passive_skill_status(PassiveSkillStatus a);

        void set_live_status(PersonLiveStatus a);
        PersonLiveStatus get_live_status();

        void set_god_status(PersonGodStatus a);
        PersonGodStatus get_god_status();
    private:

        PersonGodStatus _god_status;
        ActiveSkillStatus _active_skill_status;
        PassiveSkillStatus _passive_skill_status;

        CharacterType _type;
        PersonLiveStatus _live_status;
        float _reduce_damage_chance_knight = 50;
        float _double_attack_chance_assassin = 50;
        float _triple_damage_chance_berserk = 50;
        float _hp;
        float _armor;
        float _damage;

    };

    class CharacterList {
    public:
        
        int size();
        CharacterList();
        Character operator[](const int index) const;
        void add(Character a);
        int index_of_max_damage();
        void insert(Character a, int index);
        void delete_person_from_list(int index);
    private:
        int _countOfPerson = 0;
        static const int CAPACITY = 10;
        Character _ñharacter_array[CAPACITY];
       // int _size;
        
        
    };
}


