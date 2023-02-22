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
    _�haracter_array[index] = person;
    _countOfPerson--;
}
int CharacterList::size() { 

    return _countOfPerson;
}
void CharacterList::insert(Character a, int index) {
    if (index < 0 || CAPACITY <= index) {
        throw out_of_range("[CharacterList::operator[]] Index is out of range.");
    }
    if (_�haracter_array[index].getType() == NonType) {
        _countOfPerson++;
    }
    _�haracter_array[index] = a;

}
Character CharacterList::operator[](const int index) const {
    if (index < 0 || CAPACITY <= index) {
        throw out_of_range("[CharacterList::operator[]] Index is out of range.");
    }

    return _�haracter_array[index];
}

void CharacterList::add(const Character a) {
    int i = 0;
    if (_countOfPerson < CAPACITY && _�haracter_array[_countOfPerson].getType() == NonType) {
        _�haracter_array[_countOfPerson] = a;
        _countOfPerson++;
    }
    else {
        
        for (i = 0; i < CAPACITY; i++) {
            if (_�haracter_array[i].getType() == NonType) {
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

    for (int i = 0; i < CAPACITY; ++i) {
        if (_�haracter_array[i].getDamage() > maxDamage) {
            maxDamage = _�haracter_array[i].getDamage();
        }
    }
    return maxDamage;
}
