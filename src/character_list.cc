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
    if (_�haracter_array[index].get_type() == NonType) {
        throw out_of_range("[CharacterList::operator[]] Index is void");
    }
    else {
        Character person;
        _�haracter_array[index] = person;
        for (int i = index; i != CAPACITY - 1; i++) {
            _�haracter_array[i] = _�haracter_array[i + 1];
        }
        // _�haracter_array[CAPACITY - 1] = person;
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
    if (_�haracter_array[index].get_type() == NonType) {
        throw out_of_range("[CharacterList::operator[]] Index is void, nothing is happend");
    }
    else {
        for (int i = _countOfPerson - 1; i != index; i--) {
            _�haracter_array[i + 1] = _�haracter_array[i];

        }
        _�haracter_array[index] = a;
        _countOfPerson++;
    }

    
}
Character CharacterList::operator[](const int index) const {
    if (index < 0 || CAPACITY <= index) {
        throw out_of_range("[CharacterList::operator[]] Index is out of range.");
    }

    return _�haracter_array[index];
}

void CharacterList::add(const Character a) {
    int i = 0;
    if (_countOfPerson < CAPACITY && _�haracter_array[_countOfPerson].get_type() == NonType) {
        _�haracter_array[_countOfPerson] = a;
        _countOfPerson++;
    }
    else {
        
        for (i = 0; i < CAPACITY; i++) {
            if (_�haracter_array[i].get_type() == NonType) {
                _�haracter_array[i] = a;
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
        if (_�haracter_array[i].get_damage() > maxDamage) {
            maxDamage = _�haracter_array[i].get_damage();
            index = i;
        }
    }
    return index;
}
