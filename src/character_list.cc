#include <functions/character_functions.h>
#include <iostream>
#include <ctime>   
#include <stdexcept>

using namespace rpg;
using namespace std;



CharacterList::CharacterList() {
    _character_array = new Character * [0];
    _size = 0;
}
void CharacterList::delete_person_from_list(int index) {
    auto copy = new Character* [_size - 1];
    for (int i = 0; i < _size - 1; ++i) {
        if (index > i)
            copy[i] = _character_array[i];
        else
            copy[i] = _character_array[i + 1];
    }
    delete[] _character_array;
    _character_array = copy;
    _size--;
}

int CharacterList::size() { 

    return _size;
}

void CharacterList::insert(Character* person, int index) {
    auto copy = new Character* [_size + 1];
    for (int i = 0; i < _size; i++) {
        if (i < index)
            copy[i] = _character_array[i];
        else
            copy[i + 1] = _character_array[i];
    }
    copy[index] = person;
    delete[] _character_array;
    _character_array = copy;
    _size++;    
}
Character* CharacterList::operator[](const int index) const {
    if (index < 0 || _size <= index) {
        throw out_of_range("[CharacterList::operator[]] Index is out of range.");
    }

    return _character_array[index];
}

void CharacterList::add(Character* person) {
    auto copy = new Character* [_size + 1];
    for (int i = 0; i < _size; ++i) {
        copy[i] = _character_array[i];
    }   
    copy[_size] = person;
    delete[] _character_array;
    _character_array = copy;
    _size++;
}

int CharacterList::index_of_max_damage() {
    int maxDamage = 0;
    int index = 0;
    for (int i = 0; i < _size; ++i) {
        if ((*_character_array[i]).get_damage() > maxDamage) {
            maxDamage = (*_character_array[i]).get_damage();
            index = i;
        }
    }
    return index;
}

CharacterList::~CharacterList() {
    for (int i = 0; i < _size; ++i) {
        delete _character_array[i];
    }
    delete[] _character_array;
}


void CharacterList::swap(CharacterList& OtherList) {
    std::swap(this->_character_array, OtherList._character_array);
    std::swap(this->_size, OtherList._size);
}


CharacterList::CharacterList(const CharacterList& OtherList) :
    _character_array(new Character*[OtherList._size]),
    _size(OtherList._size)
{
    for (int i = 0; i < _size; ++i) {
        _character_array[i] = OtherList[i]->clone();
    }
}