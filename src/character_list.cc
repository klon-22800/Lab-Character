#include <functions/character_functions.h>
#include <iostream>
#include <ctime>   
#include <stdexcept>

using namespace rpg;
using namespace std;


//CharacterList::CharacterList() : _size(CAPACITY) {}
CharacterList::CharacterList() {}

void CharacterList::delete_person_from_list(int index) {
    if (index < 0 || CAPACITY <= index) {
        throw out_of_range("[FunctionList::operator[]] Index is out of range.");
    }
    if (_ñharacter_array[index].get_type() == NonType) {
        throw out_of_range("[CharacterList::operator[]] Index is void");
    }
    else {
        Character person;
        _ñharacter_array[index] = person;
        for (int i = index; i != CAPACITY - 1; i++) {
            _ñharacter_array[i] = _ñharacter_array[i + 1];
        }
        // _ñharacter_array[CAPACITY - 1] = person;
        _countOfPerson--;
    }
}
int CharacterList::size() { 

    return _countOfPerson;
}
void CharacterList::insert(Character a, int index) {
    if (index < 0 || CAPACITY <= index) {
        throw out_of_range("[CharacterList::operator[]] Index is out of range.");
    }
    if (_ñharacter_array[index].get_type() == NonType) {
        throw out_of_range("[CharacterList::operator[]] Index is void, nothing is happend");
    }
    else {
        for (int i = _countOfPerson - 1; i != index; i--) {
            _ñharacter_array[i + 1] = _ñharacter_array[i];

        }
        _ñharacter_array[index] = a;
        _countOfPerson++;
    }

    
}
Character CharacterList::operator[](const int index) const {
    if (index < 0 || CAPACITY <= index) {
        throw out_of_range("[CharacterList::operator[]] Index is out of range.");
    }

    return _ñharacter_array[index];
}

void CharacterList::add(const Character a) {
    int i = 0;
    if (_countOfPerson < CAPACITY && _ñharacter_array[_countOfPerson].get_type() == NonType) {
        _ñharacter_array[_countOfPerson] = a;
        _countOfPerson++;
    }
    else {
        
        for (i = 0; i < CAPACITY; i++) {
            if (_ñharacter_array[i].get_type() == NonType) {
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
    int index = 0;
    for (int i = 0; i < CAPACITY; ++i) {
        if (_ñharacter_array[i].get_damage() > maxDamage) {
            maxDamage = _ñharacter_array[i].get_damage();
            index = i;
        }
    }
    return index;
}
