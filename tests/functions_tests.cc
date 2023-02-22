#include <gtest/gtest.h>
#include <functions/functions.h>
using namespace std;
using namespace RPG;

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
    person.setType(Berserk);
    person.setPassiveSkillStatus(active);
    // Act
    float a = person.DamageGiven();

    // Assert
    EXPECT_NEAR(a, 15, 0.2);
}

TEST(FunctionsTests, DamageTaken) {
    // Arrange
    Character person(100, 5, 10, ungod, unselected, active, Knight, live);

    // Act
    float a = person.DamageTaken(15);

    // Assert
    EXPECT_NEAR(a, 5, 0.2);
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
