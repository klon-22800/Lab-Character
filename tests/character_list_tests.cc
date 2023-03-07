#include <gtest/gtest.h>
#include <cstdio>
#include <functions/character_functions.h>
using namespace std;
using namespace rpg;
TEST(FunctionsTests, NewInsert) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Berserk, live);
    Character person1(100, 10, 100, ungod, selected, active, Assassin, live);
    
    personList.add(person);
    personList.add(person);
    personList.add(person);
    personList.insert(person1, 1);

    int a = personList.size();

    // Assert
    EXPECT_EQ(a, 4);
}

TEST(FunctionsTests, ReachingCapacity) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    Character person1(100, 10, 100, ungod, selected, active, Assassin, live);

    personList.add(person);
    personList.add(person);
    personList.add(person);
    personList.add(person);
    personList.add(person);

    personList.add(person);
    personList.add(person);
    personList.add(person);
    personList.add(person);
    personList.add(person);

    personList.add(person1);

    int a = personList.size();

    // Assert
    EXPECT_EQ(a, 10);
}

TEST(FunctionsTests, maxDamage) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    Character person1(100, 10, 100, ungod, selected, active, Assassin, live);

    personList.add(person);
    personList.add(person1);
    personList.add(person);
    personList.add(person);

    int a = personList.index_of_max_damage();

    // Assert
    EXPECT_EQ(a, 1);
}

TEST(FunctionsTests, AddingToStrangerPlace) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    personList.add(person);
    personList.add(person);
    personList.insert(person, 1);
    personList.delete_person_from_list(1);

    int a = personList.size();

    // Assert
    EXPECT_EQ(a, 2);
}
TEST(FunctionsTests, countOfPersonAfterDeleting) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    personList.add(person);

    personList.delete_person_from_list(0);

    int a = personList.size();

    // Assert
    EXPECT_EQ(a, 0);
}
TEST(FunctionsTests, delete_person_from_list) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    personList.add(person);
    personList.add(person);
    personList.add(person);
    
    personList.delete_person_from_list(1);

    CharacterType a = personList[1].get_type();

    // Assert
    EXPECT_EQ(a, Assassin);
}
TEST(FunctionsTests, insertPersonToList) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    Character personTEST(100, 10, 15, ungod, selected, active, Berserk, live);
    personList.add(person);
    personList.insert(personTEST, 0);

    CharacterType a = personList[0].get_type();

    // Assert
    EXPECT_EQ(a, Berserk);
}

TEST(FunctionsTests, AddPersonToNOTVoidList) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    Character personTEST(100, 10, 15, ungod, selected, active, Berserk, live);
    personList.add(person);
    personList.add(person);
    personList.add(person);
    personList.add(person);
    personList.add(person);
    personList.add(person);
    personList.add(personTEST);

    CharacterType a = personList[6].get_type();

    // Assert
    EXPECT_EQ(a, Berserk);
}

TEST(FunctionsTests, InsertPersonToVoidList) {
    // Arrange
    CharacterList personList;
    personList.size();
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    personList.insert(person, 5);
    CharacterType a = personList[5].get_type();

    // Assert
    EXPECT_EQ(a, NonType);
}

TEST(FunctionsTests, ListSize) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    personList.add(person);
    personList.add(person);
    personList.add(person);
    personList.add(person);
    personList.add(person);
    personList.add(person);
    personList.add(person);
    personList.add(person);

    int a = personList.size();


    // Assert
    EXPECT_EQ(a, 8);
}