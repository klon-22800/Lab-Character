#include <gtest/gtest.h>
#include <functions/functions.h>
using namespace RPG;
TEST(FunctionsTests, AddingToStrangerPlace) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    personList.add(person, 0);
    personList.add(person, 0);
    personList.add(person, 0);
    personList.add(person, 0);
    personList.add(person, 0);
    personList.add(person, 0);
    personList.add(person, 0);
    personList.add(person, 0);
    personList.add(person, 0);
    personList.add(person, 0);
    CharacterType a = personList[9].getType();


    // Assert
    EXPECT_EQ(a, Assassin);
}
TEST(FunctionsTests, countOfPersonAfterDeleting) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    personList.add(person, 0);

    personList.deletePersonFromList(0);

    int a = personList.size();

    // Assert
    EXPECT_EQ(a, 0);
}
TEST(FunctionsTests, deletePersonFromList) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    personList.add(person, 0);
    
    personList.deletePersonFromList(0);

    CharacterType a = personList[0].getType();

    // Assert
    EXPECT_EQ(a, NonType);
}
TEST(FunctionsTests, replacePersonToList) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    Character personTEST(100, 10, 15, ungod, selected, active, Berserk, live);
    personList.add(person, 0);
    personList.replace(personTEST, 0);

    CharacterType a = personList[0].getType();

    // Assert
    EXPECT_EQ(a, Berserk);
}

TEST(FunctionsTests, AddPersonToNOTVoidList) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    Character personTEST(100, 10, 15, ungod, selected, active, Berserk, live);
    personList.add(person, 0);
    personList.add(person, 1);
    personList.add(person, 2);
    personList.add(person, 3);
    personList.add(person, 4);
    personList.add(person, 5);
    personList.add(personTEST, 5);

    CharacterType a = personList[6].getType();

    // Assert
    EXPECT_EQ(a, Assassin);
}

TEST(FunctionsTests, AddPersonToVoidList) {
    // Arrange
    CharacterList personList;
    personList.size();
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    personList.add(person, 5);
    CharacterType a = personList[5].getType();

    // Assert
    EXPECT_EQ(a, Assassin);
}

TEST(FunctionsTests, ListSize) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);    
    personList.add(person, 0);
    personList.add(person, 0);
    personList.add(person, 0);
    personList.add(person, 0);
    personList.add(person, 0);
    personList.add(person, 0);
    personList.add(person, 0);
    personList.add(person, 0);
    personList.add(person, 0);
   
    int a = personList.size();
    

    // Assert
    EXPECT_EQ(a, 9);
}
TEST(FunctionsTests, maxDamage) {
    // Arrange
    CharacterList personList;
    Character person(100, 10, 15, ungod, selected, active, Assassin, live);
    Character person1(100, 10, 100, ungod, selected, active, Assassin, live);

    personList.add(person, 1);
    personList.add(person1, 2);

    float a = personList.index_of_max_damage();

    // Assert
    EXPECT_EQ(a, 100);
}

TEST(FunctionsTests, CharacterParametersCalculation) {
    // Arrange
    Character person(100, 5, 10, ungod, selected, active, Knight, live);

    
    // Act
    person.setActiveSkillStatus(selected);
    person.CharacterParametersCalculation();
    float a = person.getArmor();

    // Assert
    EXPECT_EQ(a, 10);
}

TEST(FunctionsTests, GetSetGodStatus) {
    // Arrange
    Character person;

    /*PersonGodStatus b = god;
    person.setGodStatus(b);*/
    // Act
    PersonGodStatus a = person.getGodStatus();

    // Assert
    EXPECT_EQ(a, ungod);
}

TEST(FunctionsTests, GetSetType) {
    // Arrange
    Character person;

    CharacterType b = Assassin;
    person.setType(b);
    // Act
    CharacterType a = person.getType();

    // Assert
    EXPECT_EQ(a, Assassin);
}
TEST(FunctionsTests, GetSetLiveStatusPositive) {
    // Arrange
    Character person;

    
    person.setHP(5);
    // Act
    PersonLiveStatus a = person.getLiveStatus();

    // Assert
    EXPECT_EQ(a, live);
}

TEST(FunctionsTests, GetSetLiveStatusNegative) {
    // Arrange
    Character person;


    person.setHP(-5);
    // Act
    PersonLiveStatus a = person.getLiveStatus();

    // Assert
    EXPECT_EQ(a, dead);
}

TEST(FunctionsTests, HPCalculation) {
    // Arrange
    Character person;

    float b = 5;
    person.setHP(b);
    // Act
    float a = person.HPCalculation(3);

    // Assert
    EXPECT_EQ(a, 2);
}

TEST(FunctionsTests, DamageGiven) {
    // Arrange
    Character person;

    float b = 5;
    person.setDamage(b);
    CharacterType t = Berserk;
    person.setType(t);
    // Act
    float a = person.DamageGiven();

    // Assert
    EXPECT_NEAR(a, 15, 0.2);
}

TEST(FunctionsTests, GetSetArmor) {
    // Arrange
    Character person;

    float b = 5;
    person.setArmor(b);
    // Act
    float a = person.getArmor();

    // Assert
    EXPECT_NEAR(a, 5, 0.2);
}
TEST(FunctionsTests, GetSetHP) {
    // Arrange
    Character person;

    float b = 5;
    person.setHP(b);
    // Act
    float a = person.getHP();

    // Assert
    EXPECT_NEAR(a, 5, 0.2);
}

TEST(FunctionsTests, GetSetDamage) {
    // Arrange
    Character person;
    
    float b = 5;
    person.setDamage(b);
    // Act
    float a  = person.getDamage();

    // Assert
    EXPECT_NEAR(a, 5, 0.2);
}

TEST(FunctionsTests, SumStubTest1) {
    // Arrange
    int lhs = 2;
    int rhs = 3;
    
    // Act
    int r = sum_stub(lhs, rhs);
    
    // Assert
    EXPECT_EQ(r, 5);
}

TEST(FunctionsTests, SumStubTest2) {
    // Arrange
    int lhs = -1;
    int rhs = 3;
    
    // Act
    int r = sum_stub(lhs, rhs);
    
    // Assert
    EXPECT_EQ(r, 2);
}
