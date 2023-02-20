#include <functions/functions.h>
#include <iostream>
#include <ctime>    
using namespace Data;


void Character::setType(CharacterType a)
{
    _type = a;
}
CharacterType Character::getType() {
    return _type;
}
void Character::setDamage(float a)
{

    _damage = a;
}

PersonGodStatus Character::getGodStatus() {
    return _godStatus;
}
void Character::setGodStatus(PersonGodStatus a)
{

    _godStatus = a;
}

float Character::getDamage() {
    return _damage;
}
void Character::setArmor(float a)
{

    _armor = a;
}
float Character::getArmor() {
    return _armor;
}

void Character::setHP(float a)
{

    _hp = a;
}
float Character::getHP() {
    return _hp;
}

void Character::setLiveStatus(PersonLiveStatus a)
{

    _liveStatus = a;
}
PersonLiveStatus Character::getLiveStatus() {
    if (_hp <= 0) {
        return dead;
    }
    else {
        return live;
    }
}

void Character::AssassinSkill()
{
    _activeSkillStatus = selected;
}
void Character::KnightSkill()
{
    _activeSkillStatus = selected;
}
void Character::BerserkSkill()
{
    _activeSkillStatus = selected;
}


void Character::CharacterParametersCalculation() {
    switch (_type) {
    case Knight:
        if (_activeSkillStatus == selected)
        {
            _armor += 5;
            _damage -= 10;
        }
        break;
    case Assassin:
        if (_activeSkillStatus == selected)
        {
            _godStatus == god;
        }
        break;
    case Berserk:
        if (_activeSkillStatus == selected)
        {
            _damage += 10;
            _tripleDamgeChanceBerserk += 0.2;
            _armor -= 10;
        }
        break;
    }
}

float Character::HPCalculation(float damageFromOpponent)
{
    _hp -= damageFromOpponent;
    return _hp;

}

float Character::DamageGiven() {
    float damageToOpponent = _damage;
    //PassiveSkillChance(person);
    switch (_type) {
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
void Character::PassiveSkillChance() {
    srand(time(NULL));
    int chance = rand() % 10000;
    switch (_type)
    {
    case Knight:
        if (_reduceDamageChanceKnight > chance)
        {
            _passiveSkillStatus = active;
        }
        break;
    case Assassin:
        if (_doubleAttackChanceAssassin > chance)
        {
            _passiveSkillStatus = active;
        }
        break;
    case Berserk:
        if (_tripleDamgeChanceBerserk > chance)
        {
            _passiveSkillStatus = active;

        }
        break;

    }

}
float Character::DamageTaken(float damageGiven) {
    PassiveSkillChance();
    float damageFromOpponent = damageGiven - _armor;
    switch (_type) {
    case Knight:
        if (_passiveSkillStatus == active) {
            damageFromOpponent = damageFromOpponent / 2;
        }
        break;
    case Assassin:
        if (_godStatus == god) {
            damageFromOpponent = 0;
        }
        break;
    case Berserk:
        break;
    }

    return damageFromOpponent;
}
int sum_stub(int lhs, int rhs) {
        return lhs + rhs;
    }

