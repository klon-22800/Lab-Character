#include <functions/functions.h>
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
    Character_array[index] = person;
    _countOfPerson--;
}
int CharacterList::size() { //ÏÅÐÅÏÈÑÀÒÜ

    //for (int i = 0; i < CAPACITY; i++) {
    //    /*if ((Character_array[i].getType() == Assassin) ||
    //        (Character_array[i].getType() == Knight) ||
    //        (Character_array[i].getType() == Berserk)) {
    //        _countOfPerson++;
    //    } */  
    //}
    return _countOfPerson;
}
void CharacterList::insert(Character a, int index) {
    if (index < 0 || CAPACITY <= index) {
        throw out_of_range("[CharacterList::operator[]] Index is out of range.");
    }
    if (Character_array[index].getType() == NonType) {
        _countOfPerson++;
    }
    Character_array[index] = a;

}
Character CharacterList::operator[](const int index) const {
    if (index < 0 || CAPACITY <= index) {
        throw out_of_range("[CharacterList::operator[]] Index is out of range.");
    }

    return Character_array[index];
}

void CharacterList::add(const Character a) {

    if (_countOfPerson < CAPACITY && Character_array[_countOfPerson].getType() == NonType) {
        Character_array[_countOfPerson] = a;
        _countOfPerson++;
    }
    else {
        throw out_of_range("[CharacterList::operator[]] CAPACITY is reached or Element busy.");
    }
}



int CharacterList::index_of_max_damage() {
    int maxDamage = 0;

    for (int i = 0; i < CAPACITY; ++i) {
        if (Character_array[i].getDamage() > maxDamage) {
            maxDamage = Character_array[i].getDamage();
        }
    }
    return maxDamage;
}
