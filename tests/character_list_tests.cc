#include <gtest/gtest.h>
#include <cstdio>
#include <functions/functions.h>
using namespace std;
using namespace RPG;



TEST(FunctionsTests, maxDamage) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    Character person1(100, 10, 100, ungod, selected, active, Assassin, live);

    personList.add(person);
    personList.add(person1);

    float a = personList.index_of_max_damage();

    // Assert
    EXPECT_EQ(a, 100);
}

TEST(FunctionsTests, AddingToStrangerPlace) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    personList.add(person);
    personList.add(person);
    personList.insert(person, 1);
    personList.deletePersonFromList(1);

    int a = personList.size();

    // Assert
    EXPECT_EQ(a, 1);
}
TEST(FunctionsTests, countOfPersonAfterDeleting) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    personList.add(person);

    personList.deletePersonFromList(0);

    int a = personList.size();

    // Assert
    EXPECT_EQ(a, 0);
}
TEST(FunctionsTests, deletePersonFromList) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    personList.add(person);

    personList.deletePersonFromList(0);

    CharacterType a = personList[0].getType();

    // Assert
    EXPECT_EQ(a, NonType);
}
TEST(FunctionsTests, insertPersonToList) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    Character personTEST(100, 10, 15, ungod, selected, active, Berserk, live);
    personList.add(person);
    personList.insert(personTEST, 0);

    CharacterType a = personList[0].getType();

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

    CharacterType a = personList[6].getType();

    // Assert
    EXPECT_EQ(a, Berserk);
}

TEST(FunctionsTests, AddPersonToVoidList) {
    // Arrange
    CharacterList personList;
    personList.size();
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    personList.insert(person, 5);
    CharacterType a = personList[5].getType();

    // Assert
    EXPECT_EQ(a, Assassin);
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