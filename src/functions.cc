#include <functions/functions.h>
#include <iostream>
#include <ctime>    

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
class BattleField
{
public:
    void MakeStep(Character personX, Character personY, int step)
    {
        step = 1;
        Character attacker;
        Character defender;
        GameStatus gameStatus = gone;
        float damageGiven;
        float damageTaken;
        while (gameStatus == gone) {
            if (step % 2 == 1) {
                attacker = personX;
                defender = personY;
            }
            else {
                attacker = personY;
                defender = personX;
            }
            attacker.CharacterParametersCalculation(attacker);
            defender.CharacterParametersCalculation(defender);
            damageGiven = attacker.DamageGiven(attacker);
            damageTaken = defender.DamageTaken(defender, damageGiven);
            defender.HPCalculation(defender, damageTaken);
            if (defender.LiveStatusCalculation(defender) == dead) {
                gameStatus = ended;
            }
        }
    
    
    
    
    }
private:
    int step;
};


class Character 
{
public:
    void PassiveSkillChance(Character person) {
        srand(time(NULL));
        int chance = rand() % 10000;
        switch (person.type)
        {
        case Knight:
            if (person.reduceDamageChanceKnight > chance)
            {
                person.passiveSkillStatus = active;
            }
            break;
        case Assassin:
            if (person.doubleAttackChanceAssassin > chance)
            {
                person.passiveSkillStatus = active;
            }
            break;
        case Berserk:
            if (person.tripleDamgeChanceBerserk > chance)
            {
                person.passiveSkillStatus = active;
                
            }
            break;

        }


    }
    float DamageGiven(Character person) 
    {
        float damageToOpponent = person.damage;
        PassiveSkillChance(person);
        switch (person.type) {
        case Knight:
            break;
        case Assassin:

            break;
        case Berserk:
            damageToOpponent = damageToOpponent * 3;
            break;
        }
        return damageToOpponent;
    }
    float DamageTaken(Character personX, float damageGiven){
        PassiveSkillChance(personX);
        float damageFromOpponent = damageGiven - personX.armor;
        switch (personX.type) {
        case Knight:
            if (personX.passiveSkillStatus == active) {
                damageFromOpponent = damageFromOpponent / 2;
            }
            break;
        case Assassin:
            if (personX.godStatus == god) {
                damageFromOpponent = 0;
            }
            break;
        case Berserk:
            break;
        }
        
        return damageFromOpponent;
    }
    float HPCalculation(Character person, float damageFromOpponent)
    {
        person.hp -= damageFromOpponent;
        return person.hp;

    }
    PersonLiveStatus LiveStatusCalculation(Character person) {
        if (person.hp <= 0) {
            return dead;
        }
        else {
            return live;
        }
    }
    void CharacterParametersCalculation(Character person) {
        switch (person.type) {
        case Knight:
            if (person.activeSkillStatus == selected)
            {
                person.armor += 5;
                person.damage -= 10;
            }
            break;
        case Assassin:
            if (person.activeSkillStatus == selected)
            {
                person.godStatus == god;
            }
            break;
        case Berserk: 
            if (person.activeSkillStatus == selected)
            {
                person.damage += 10;
                person.tripleDamgeChanceBerserk += 0.2;
                person.armor -= 10;
            }
            break;
        }
    }
    void AssassinSkill(Character person)
    {
        person.activeSkillStatus = selected;    
    }
    void KnightSkill(Character person)
    {
        person.activeSkillStatus = selected;
    }
    void BerserkSkill(Character person)
    {
        person.activeSkillStatus = selected;
    }
    
private:
    PersonLiveStatus liveStatus;
    PersonGodStatus godStatus; 
    ActiveSkillStatus activeSkillStatus;
    PassiveSkillStatus passiveSkillStatus;
    float reduceDamageChanceKnight = 50;
    float doubleAttackChanceAssassin = 50;
    float tripleDamgeChanceBerserk = 50;
    float hp;
    float armor;
    float damage;
    CharacterType type;


};


int sum_stub(int lhs, int rhs) {
    return lhs + rhs;
}
