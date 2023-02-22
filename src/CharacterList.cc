#include <functions/character_functions.h>
#include <iostream>
#include <ctime>   
#include <stdexcept>

using namespace RPG;
using namespace std;


//CharacterList::CharacterList() : _size(CAPACITY) {}
CharacterList::CharacterList() {}

void CharacterList::deletePersonFromList(int index) {
    if (index < 0 || CAPACITY <= index) {
        throw out_of_range("[FunctionList::operator[]] Index is out of range.");
    }
    Character person;
    _ñharacter_array[index] = person;
    _countOfPerson--;
}
int CharacterList::size() { 

    return _countOfPerson;
}
void CharacterList::insert(Character a, int index) {
    if (index < 0 || CAPACITY <= index) {
        throw out_of_range("[CharacterList::operator[]] Index is out of range.");
    }
    if (_ñharacter_array[index].getType() == NonType) {
        _countOfPerson++;
    }
    _ñharacter_array[index] = a;

}
Character CharacterList::operator[](const int index) const {
    if (index < 0 || CAPACITY <= index) {
        throw out_of_range("[CharacterList::operator[]] Index is out of range.");
    }

    return _ñharacter_array[index];
}

void CharacterList::add(const Character a) {
    int i = 0;
    if (_countOfPerson < CAPACITY && _ñharacter_array[_countOfPerson].getType() == NonType) {
        _ñharacter_array[_countOfPerson] = a;
        _countOfPerson++;
    }
    else {
        
        for (i = 0; i < CAPACITY; i++) {
            if (_ñharacter_array[i].getType() == NonType) {
                _ñharacter_array[i] = a;
                _countOfPerson++;
                break;
            }
        }
    }
    if (i == CAPACITY) {
        throw out_of_range("[CharacterList::operator[]] CAPACITY is reached");
    }
    
}



int CharacterList::index_of_max_damage() {
    int maxDamage = 0;

    for (int i = 0; i < CAPACITY; ++i) {
        if (_ñharacter_array[i].getDamage() > maxDamage) {
            maxDamage = _ñharacter_array[i].getDamage();
        }
    }
    return maxDamage;
}
