#include <gtest/gtest.h>
#include <functions/character_functions.h>
using namespace std;
using namespace RPG;



TEST(FunctionsTests, CharacterParametersCalculation) {
    // Arrange
    Character person(100, 5, 10, ungod, selected, active, Knight, live);

    // Act
    person.PressActiveSkill();
    person.CharacterParametersCalculation();
    float a = person.getArmor();

    // Assert
    EXPECT_EQ(a, 10);
}

TEST(FunctionsTests, GetSetGodStatus) {
    // Arrange
    Character person;

    
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
    EXPECT_NEAR(a, 15, 0.05);
}


TEST(FunctionsTests, DamageTakenToGod) {
    // Arrange
    Character person(100, 5, 10, god, unselected, active, Assassin, live);

    // Act
    float a = person.DamageTaken(150);

    // Assert
    EXPECT_NEAR(a, 0, 0.05);
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

