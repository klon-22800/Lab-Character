#include <gtest/gtest.h>
#include <cstdio>
#include <functions/character_functions.h>
using namespace std;
using namespace rpg;
TEST(FunctionsTests, swap) {
    // Arrange
    CharacterList personList;
    auto person = make_shared<Assassin>();
    personList.add(person);
    auto a = personList[0];

    // Assert
    EXPECT_EQ(a, person);
}
//TEST(FunctionsTests, NewInsert) {
//    // Arrange
//    CharacterList personList;
//    Character person;
//    
//    
//    personList.add(person.create_person(Assassin));
//    personList.add(person.create_person(Assassin));
//    personList.add(person.create_person(Assassin));
//
//    int a = personList.size();
//
//    // Assert
//    EXPECT_EQ(a, 3);
//}
//
TEST(FunctionsTests, maxDamage) {
    // Arrange
    CharacterList personList;
    auto person = make_shared<Assassin>();
    auto person2 = make_shared<Berserk>();

    personList.add(person);
    personList.add(person);
    personList.insert(person2, 1);
    personList.add(person);
    personList.add(person);
    personList.add(person2);
    personList.delete_person(1);
    personList.print();
    auto a = personList[1];

    // Assert
    EXPECT_EQ(a, person);
}

TEST(FunctionsTests, AddingToStrangerPlace) {
    // Arrange
    CharacterList personList;
    auto ptr1 = make_shared<Assassin>();
    auto ptr2 = make_shared<Assassin>();
    auto ptr3 = make_shared<Assassin>();
    personList.add(ptr1);
    personList.add(ptr2);
    personList.insert(ptr3, 1);
    personList.delete_person(1);

    int a = personList.size();

    // Assert
    EXPECT_EQ(a, 2);
}
TEST(FunctionsTests, countOfPersonAfterDeleting) {
    // Arrange
    CharacterList personList;
    auto ptr = make_shared<Assassin>();
    personList.add(ptr);

    personList.delete_person(0);

    int a = personList.size();

    // Assert
    EXPECT_EQ(a, 0);
}

TEST(FunctionsTests, insertPersonToList) {
    // Arrange
    CharacterList personList;
    auto ptr = make_shared<Assassin>();
    auto ptr2 = make_shared<Berserk>();
    personList.add(ptr);
    personList.insert(ptr2, 0);

    int a = (*personList[0]).get_type();

    // Assert
    EXPECT_EQ(a, 2);
}

TEST(FunctionsTests, ListSize) {
    // Arrange
    CharacterList personList;
    auto ptr = make_shared<Assassin>();
    personList.add(ptr);
    personList.add(ptr);
    personList.add(ptr);
    personList.add(ptr);

    personList.add(ptr);
    personList.add(ptr);
    personList.add(ptr);
    personList.add(ptr);

    int a = personList.size();

    // Assert
    EXPECT_EQ(a, 8);
}