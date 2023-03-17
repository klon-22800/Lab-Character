#include <gtest/gtest.h>
#include <cstdio>
#include <functions/character_functions.h>
using namespace std;
using namespace rpg;
TEST(FunctionsTests, NewInsert) {
    // Arrange
    CharacterList personList;
    Character person;
    
    
    personList.add(person.create_person(Assassin));
    personList.add(person.create_person(Assassin));
    personList.add(person.create_person(Assassin));

    int a = personList.size();

    // Assert
    EXPECT_EQ(a, 3);
}

TEST(FunctionsTests, maxDamage) {
    // Arrange
    CharacterList personList;
    Character person;

    personList.add(person.create_person(Assassin));
    personList.add(person.create_person(Berserk));
    personList.add(person.create_person(Assassin));
    personList.add(person.create_person(Assassin));

    int a = personList.index_of_max_damage();

    // Assert
    EXPECT_EQ(a, 1);
}

TEST(FunctionsTests, AddingToStrangerPlace) {
    // Arrange
    CharacterList personList;
    Character person;
    const auto ptr1 = person.create_person(Assassin);
    const auto ptr2 = person.create_person(Assassin);
    const auto ptr3 = person.create_person(Assassin);
    personList.add(ptr1);
    personList.add(ptr2);
    personList.insert(ptr3, 1);
    personList.delete_person_from_list(1);

    int a = personList.size();

    // Assert
    EXPECT_EQ(a, 2);
}
TEST(FunctionsTests, countOfPersonAfterDeleting) {
    // Arrange
    CharacterList personList;
    Character person;
    const auto ptr = person.create_person(Assassin);
    personList.add(ptr);

    personList.delete_person_from_list(0);

    int a = personList.size();

    // Assert
    EXPECT_EQ(a, 0);
}
TEST(FunctionsTests, delete_person_from_list) {
    // Arrange
    CharacterList personList;
    Character person;
    const auto ptr1 = person.create_person(Assassin);
    const auto ptr2 = person.create_person(Assassin);
    const auto ptr3 = person.create_person(Assassin);
    personList.add(ptr1);
    personList.add(ptr2);
    personList.add(ptr3);
    
    personList.delete_person_from_list(1);

    CharacterType a = (*personList[1]).get_type();

    // Assert
    EXPECT_EQ(a, Assassin);
}
TEST(FunctionsTests, insertPersonToList) {
    // Arrange
    CharacterList personList;
    Character person;
    Character person2;
    const auto ptr = person.create_person(Assassin);
    const auto ptr2 = person2.create_person(Berserk);
    personList.add(ptr);
    personList.insert(ptr2, 0);

    CharacterType a = (*personList[0]).get_type();

    // Assert
    EXPECT_EQ(a, Berserk);
}

TEST(FunctionsTests, ListSize) {
    // Arrange
    CharacterList personList;
    Character person;
    personList.add(person.create_person(Assassin));
    personList.add(person.create_person(Assassin));
    personList.add(person.create_person(Assassin));
    personList.add(person.create_person(Assassin));
    personList.add(person.create_person(Assassin));
    personList.add(person.create_person(Assassin));
    personList.add(person.create_person(Assassin));
    personList.add(person.create_person(Assassin));
    

    int a = personList.size();


    // Assert
    EXPECT_EQ(a, 8);
}