#pragma once

namespace Data {
    enum CharacterType
    {
        Knight,
        Assassin,
        Berserk

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
    enum GameStatus {
        gone,
        ended
    };

	class Character {
	public:
        void AssassinSkill();
        void KnightSkill();
        void BerserkSkill();


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
}



int sum_stub(int lhs, int rhs);

