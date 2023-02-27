#pragma once
using namespace std;
namespace RPG {
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
        void PressActiveSkill();

        float HPCalculation(float damageFromOpponent);
        void CharacterParametersCalculation();
        void PassiveSkillChance();

        float DamageTaken(float damageGiven);
        float DamageGiven();

        CharacterType getType();
        void setType(CharacterType a);

        void setDamage(float a);
        float getDamage();

        void setArmor(float a);
        float getArmor();

        void setHP(float a);
        float getHP();

        void setActiveSkillStatus(ActiveSkillStatus a);
        void setPassiveSkillStatus(PassiveSkillStatus a);

        void setLiveStatus(PersonLiveStatus a);
        PersonLiveStatus getLiveStatus();

        void setGodStatus(PersonGodStatus a);
        PersonGodStatus getGodStatus();
    private:

        PersonGodStatus _godStatus;
        ActiveSkillStatus _activeSkillStatus;
        PassiveSkillStatus _passiveSkillStatus;

        CharacterType _type;
        PersonLiveStatus _liveStatus;
        float _reduceDamageChanceKnight = 50;
        float _doubleAttackChanceAssassin = 50;
        float _tripleDamgeChanceBerserk = 50;
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
        void deletePersonFromList(int index);
    private:
        int _countOfPerson = 0;
        static const int CAPACITY = 10;
        Character _ñharacter_array[CAPACITY];
       // int _size;
        
        
    };
}


