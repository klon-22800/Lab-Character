#include <functions/character_functions.h>
#include <ctime>   
#include <stdexcept>

using namespace rpg;
using namespace std;



void Character::press_active_skill()
{
    _active_skill_status = selected;
}

void Character::character_parametr_calculation() {
    switch (_type) {
    case Knight:
        if (_active_skill_status == selected)
        {
            _armor += 5;
            _damage -= 10;
        }
        break;
    case Assassin:
        if (_active_skill_status == selected)
        {
            _god_status = god;
        }
        break;
    case Berserk:
        if (_active_skill_status == selected)
        {
            _damage += 10;
            _triple_damage_chance_berserk += 0.2;
            _armor -= 10;
        }
        break;
    }
}

float Character::hp_calculation(float damageFromOpponent)
{
    _hp -= damageFromOpponent;
    return _hp;

}

float Character::damage_given() {
    float totalDamage = _damage;
    float damageToOpponent = _damage;
    passive_skill_chance();
    switch (_type) {
    case Knight:
        break;
    case Assassin:
        if (_passive_skill_status == active) {
            totalDamage += _damage;
        }
        damageToOpponent = totalDamage;
        break;
    case Berserk:
        if (_passive_skill_status == active) {
            damageToOpponent = damageToOpponent * 3;
        }
        break;
    }
    return damageToOpponent;
}
void Character::passive_skill_chance() {
    srand(time(NULL));
    int chance = rand() % 100 + 1;
    switch (_type)
    {
    case Knight:
        if (_reduce_damage_chance_knight > chance)
        {
            _passive_skill_status = active;
        }
        
        break;
    case Assassin:
        if (_double_attack_chance_assassin > chance)
        {
            _passive_skill_status = active;
        }
        break;
    case Berserk:
        if (_triple_damage_chance_berserk > chance)
        {
            _passive_skill_status = active;
        }
        break;

    }

}
float Character::damage_taken(float damage_given) {
    passive_skill_chance();
    float damageFromOpponent = damage_given - _armor;
    switch (_type) {
    case Knight:
        if (_passive_skill_status == active) {
            damageFromOpponent = damageFromOpponent / 2;
        }
        break;
    case Assassin:
        if (_god_status == god) {
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
    _god_status = godStatus;
    _active_skill_status = activeSkillStatus;
    _passive_skill_status = passiveSkillStatus;
    _type = type;
    _live_status = liveStatus;
}
 Character::Character() {
    _hp = 100;
    _armor = 5;
    _damage = 15;
    _god_status = ungod;
    _active_skill_status = unselected;
    _passive_skill_status = unactive;
    _type = NonType;
    _live_status = live;
} 





void Character::set_passive_skill_status(PassiveSkillStatus a) {
    _passive_skill_status = a;
}

void Character::set_active_skill_status(ActiveSkillStatus a) {
    _active_skill_status = a;
}
void Character::set_type(CharacterType a)
{
    _type = a;
}
CharacterType Character::get_type() {
    return _type;
}
void Character::set_damage(float a)
{

    _damage = a;
}

PersonGodStatus Character::get_god_status() {
    return _god_status;
}
void Character::set_god_status(PersonGodStatus a)
{

    _god_status = a;
}

float Character::get_damage() {
    return _damage;
}
void Character::set_armor(float a)
{

    _armor = a;
}
float Character::get_armor() {
    return _armor;
}

void Character::set_hp(float a)
{

    _hp = a;
}
float Character::get_hp() {
    return _hp;
}

void Character::set_live_status(PersonLiveStatus a)
{

    _live_status = a;
}
PersonLiveStatus Character::get_live_status() {
    if (_hp <= 0) {
        return dead;
    }
    else {
        return live;
    }
}