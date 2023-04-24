#include <functions/character_functions.h>
#include <iostream>
#include <ctime>   
#include <stdexcept>

using namespace rpg;
using namespace std;


CharacterList& CharacterList::operator=(CharacterList rhs) {
    CharacterList copy(rhs);
    swap(copy);
    return *this;
}

void CharacterList::swap(CharacterList& OtherList) noexcept  {
    std::swap(this->_character_array, OtherList._character_array);
    
}

CharacterList::CharacterList(const CharacterList& OtherList){
    for (int i = 0; i < size(); ++i) {
        _character_array.push_back(OtherList[i]->clone());
    }
}

void CharacterList::print() {
    for (int i = 0; i < size(); i++) {
        std::cout<<"Index: " << i;
        _character_array[i]->print();
    }
}

void CharacterList::delete_person(int index) {
    auto iter = _character_array.cbegin();
    _character_array.erase(iter + index);
}

int CharacterList::size() { 
    return _character_array.size();
}

void CharacterList::insert(CharacterPtr person, int index) {
    auto iter = _character_array.cbegin();
    _character_array.emplace(iter+index, person);    
}

CharacterPtr CharacterList::operator[](const int index) const {
    if (index < 0) {
        throw out_of_range("[CharacterList::operator[]] Index is out of range.");
    }
    return _character_array[index];
}

void CharacterList::add(CharacterPtr person) {
    _character_array.push_back(person);
}

int CharacterList::index_of_max_damage() {
    int maxDamage = 0;
    int index = 0;
    for (int i = 0; i < size(); ++i) {
        if ((*_character_array[i]).get_damage() > maxDamage) {
            maxDamage = (*_character_array[i]).get_damage();
            index = i;
        }
    }
    return index;
}