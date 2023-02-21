#include <functions/functions.h>
#include <iostream>
#include <ctime>   
#include <stdexcept>
using namespace RPG;
using namespace std;

CharacterList::CharacterList() : _size(CAPACITY) {}

void CharacterList::deletePersonFromList(int index) {
    if (index < 0 || CAPACITY <= index) {
        throw out_of_range("[FunctionList::operator[]] Index is out of range.");
    }
    Character person;
    Character_array[index] = person;
    _countOfPerson--;
}
int CharacterList::size()  { //ÏÅÐÅÏÈÑÀÒÜ
    
    //for (int i = 0; i < CAPACITY; i++) {
    //    /*if ((Character_array[i].getType() == Assassin) ||
    //        (Character_array[i].getType() == Knight) ||
    //        (Character_array[i].getType() == Berserk)) {
    //        _countOfPerson++;
    //    } */  
    //}
    return _countOfPerson;
}
void CharacterList::replace(Character a, int index) {
    if (index < 0 || CAPACITY <= index) {
        throw out_of_range("[CharacterList::operator[]] Index is out of range.");
    }
    Character_array[index] = a;

}
Character CharacterList::operator[](const int index) const {
    if (index < 0 || CAPACITY <= index) {
        throw out_of_range("[CharacterList::operator[]] Index is out of range.");
    }

    return Character_array[index];
}

void CharacterList::add(const Character a, int index) {
    if (index >= CAPACITY || _countOfPerson >= CAPACITY) {
        throw runtime_error("[CharacterList::add] Capacity is reached.");
    }
    if (Character_array[index].getType() == NonType) {
        Character_array[index] = a;
        _countOfPerson++;
      
    }
    else {
        int n = size();
        int i = n - 1;
        while(i!=index-1) {
            Character_array[i+1] = Character_array[i];
            i--;
        }
        Character_array[index] = a;
        _countOfPerson++;
    }
}

int CharacterList::index_of_max_damage() {
    int maxDamage = 0; 
    
    for (int i = 0; i < _size; ++i) {
        if (Character_array[i].getDamage() > maxDamage) {
            maxDamage = Character_array[i].getDamage();
        }
    }
    return maxDamage;
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
            _godStatus = god;
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
 Character::Character(float hp, float armor, float damage,
    PersonGodStatus godStatus, ActiveSkillStatus activeSkillStatus, PassiveSkillStatus passiveSkillStatus,
    CharacterType type, PersonLiveStatus liveStatus) {
    _hp = hp;
    _armor = armor;
    _damage = damage;
    _godStatus = godStatus;
    _activeSkillStatus = activeSkillStatus;
    _passiveSkillStatus = passiveSkillStatus;
    _type = type;
    _liveStatus = liveStatus;
}
 Character::Character() {
    _hp = 100;
    _armor = 5;
    _damage = 15;
    _godStatus = ungod;
    _activeSkillStatus = unselected;
    _passiveSkillStatus = unactive;
    _type = NonType;
    _liveStatus = live;
} 




int sum_stub(int lhs, int rhs) {
        return lhs + rhs;
    }



void Character::setActiveSkillStatus(ActiveSkillStatus a) {
    _activeSkillStatus = a;
}
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