#include <functions/character_functions.h>
#include <ctime>   
#include <iostream>
#include <stdexcept>

using namespace rpg;
using namespace std;




bool Character::operator==(const Character& rhs) {
	if (_hp == rhs._hp && _armor == rhs._armor && _damage == rhs._damage
		&& _active_skill_status == rhs._active_skill_status && _passive_skill_status == rhs._passive_skill_status
		&& _live_status == rhs._live_status) {
		return true;
	}
	else {
		return false;
	}

}

ostream& rpg::operator<<(ostream& stream, Character& person) {
	stream << "\tHP: " << person.get_hp() << "\tArmor: " << person.get_armor() << "\tDamage: " << person.get_damage() << "\n";
	return stream;
}



void Assassin::print() const {
	std::cout << "  Type: " << "Assassin" << "\tHP: " << _hp << "\tArmor: " << _armor << "\tDamage: " << _damage << "\n";
}
void Berserk::print() const {
	std::cout << "  Type: " << "Berserk" << "\t\tHP: " << _hp << "\tArmor: " << _armor << "\tDamage: " << _damage << "\n";
}
void Knight::print() const {
	std::cout << "  Type: " << "Knight" << "\t\tHP: " << _hp << "\tArmor: " << _armor << "\tDamage: " << _damage << "\n";
}


unique_ptr<Character> Assassin::clone() const {
	return  make_unique<Assassin>(_hp, _armor, _damage, _god_status, _active_skill_status, _passive_skill_status, _live_status);
}
unique_ptr<Character> Berserk::clone() const {
	return  make_unique<Berserk>(_hp, _armor, _damage, _active_skill_status, _passive_skill_status, _live_status);
}
unique_ptr<Character> Knight::clone() const {
	return  make_unique<Knight>(_hp, _armor, _damage, _active_skill_status, _passive_skill_status, _live_status);
}



void Character::press_active_skill()
{
	_active_skill_status = selected;
}

void Assassin::character_parametr_calculation() {
	if (_active_skill_status == selected) {
		_god_status = god;
	}
}
void Berserk::character_parametr_calculation() {
	if (_active_skill_status == selected) {
		_damage += 10;
		_triple_damage_chance_berserk += 0.1;
		_armor -= 10;
	}
}
void Knight::character_parametr_calculation() {
	if (_active_skill_status == selected) {
		_armor += 1;
		_damage -= 3;;
	}
}

float Character::hp_calculation(float damageFromOpponent)
{
	if (damageFromOpponent >= 0) {
		_hp -= damageFromOpponent;
		return _hp;
	}
	return _hp;

}

float Assassin::damage_given() {
	float totalDamage = _damage;
	float damageToOpponent = _damage;
	passive_skill_chance();
	if (_passive_skill_status == active) {
		totalDamage += _damage;
	}
	damageToOpponent = totalDamage;
	return damageToOpponent;
}
float Berserk::damage_given() {
	float totalDamage = _damage;
	float damageToOpponent = _damage;
	passive_skill_chance();
	if (_passive_skill_status == active) {
		damageToOpponent = damageToOpponent * 3;
	}
	return damageToOpponent;
}

float Knight::damage_given() {
	return _damage;
}

 

void Assassin::passive_skill_chance() {
	srand(time(NULL));
	int chance = rand() % 100 + 1;
	if (_double_attack_chance_assassin > chance)
	{
		_passive_skill_status = active;
	}

}
void Berserk::passive_skill_chance() {
	srand(time(NULL));
	int chance = rand() % 100 + 1;
	if (_triple_damage_chance_berserk > chance)
	{
		_passive_skill_status = active;
	}
}
void Knight::passive_skill_chance() {
	srand(time(NULL));
	int chance = rand() % 100 + 1;
	if (_reduce_damage_chance_knight > chance)
	{
		_passive_skill_status = active;
	}
}


float Assassin::damage_taken(float damage_given) {
	passive_skill_chance();
	if (damage_given == 0) {
		return 0;
	}
	float damage_from_opponent = damage_given - _armor;
	if (_god_status == god) {
		damage_from_opponent = 0;
	}
	if (damage_from_opponent > 0) {
		return damage_from_opponent;
	}
	else {
		return 0;
	}
}

float Knight::damage_taken(float damage_given) {
	passive_skill_chance();
	if (damage_given == 0) {
		return 0;
	}
	float damage_from_opponent = damage_given - _armor;
	if (_passive_skill_status == active) {
		damage_from_opponent = damage_from_opponent / 2;
	}
	if (damage_from_opponent > 0) {
		return damage_from_opponent;
	}
	else {
		return 0;
	}
}
float Berserk::damage_taken(float damage_given) {
	passive_skill_chance();
	if (damage_given == 0) {
		return 0;
	}
	float damage_from_opponent = damage_given - _armor;
	if (damage_from_opponent > 0) {
		return damage_from_opponent;
	}
	else {
		return 0;
	}
}

void Character::set_passive_skill_status(PassiveSkillStatus a) {
    _passive_skill_status = a;
}

void Character::set_active_skill_status(ActiveSkillStatus a) {
    _active_skill_status = a;
}

void Character::set_damage(float a)
{

    _damage = a;
}

PersonGodStatus Assassin::get_god_status() {
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
