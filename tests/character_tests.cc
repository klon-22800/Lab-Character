#include <gtest/gtest.h>
#include <functions/character_functions.h>
using namespace std;
using namespace rpg;



TEST(FunctionsTests, character_parametr_calculation) {
    // Arrange
    Character person(100, 5, 10, ungod, selected, active, Knight, live);

    // Act
    person.press_active_skill();
    person.character_parametr_calculation();
    float a = person.get_armor();

    // Assert
    EXPECT_EQ(a, 10);
}

TEST(FunctionsTests, Getset_god_status) {
    // Arrange
    Character person;

    
    // Act
    PersonGodStatus a = person.get_god_status();

    // Assert
    EXPECT_EQ(a, ungod);
}

TEST(FunctionsTests, Getset_type) {
    // Arrange
    Character person;

    CharacterType b = Assassin;
    person.set_type(b);
    // Act
    CharacterType a = person.get_type();

    // Assert
    EXPECT_EQ(a, Assassin);
}
TEST(FunctionsTests, Getset_live_statusPositive) {
    // Arrange
    Character person;

    
    person.set_hp(5);
    // Act
    PersonLiveStatus a = person.get_live_status();

    // Assert
    EXPECT_EQ(a, live);
}

TEST(FunctionsTests, Getset_live_statusNegative) {
    // Arrange
    Character person;

    person.set_hp(-5);
    // Act
    PersonLiveStatus a = person.get_live_status();

    // Assert
    EXPECT_EQ(a, dead);
}

TEST(FunctionsTests, hp_calculation) {
    // Arrange
    Character person;

    float b = 5;
    person.set_hp(b);
    // Act
    float a = person.hp_calculation(3);

    // Assert
    EXPECT_EQ(a, 2);
}

TEST(FunctionsTests, damage_given) {
    // Arrange
    Character person;

    float b = 5;
    person.set_damage(b);
    person.set_type(Berserk);
    person.set_passive_skill_status(active);
    // Act
    float a = person.damage_given();

    // Assert
    EXPECT_NEAR(a, 15, 0.05);
}


TEST(FunctionsTests, damage_takenToGod) {
    // Arrange
    Character person(100, 5, 10, god, unselected, active, Assassin, live);

    // Act
    float a = person.damage_taken(150);

    // Assert
    EXPECT_NEAR(a, 0, 0.05);
}

TEST(FunctionsTests, damage_taken) {
    // Arrange
    Character person(100, 5, 10, ungod, unselected, active, Knight, live);

    // Act
    float a = person.damage_taken(15);

    // Assert
    EXPECT_NEAR(a, 5, 0.2);
}

TEST(FunctionsTests, Getset_armor) {
    // Arrange
    Character person;

    float b = 5;
    person.set_armor(b);
    // Act
    float a = person.get_armor();

    // Assert
    EXPECT_NEAR(a, 5, 0.2);
}
TEST(FunctionsTests, Getset_hp) {
    // Arrange
    Character person;

    float b = 5;
    person.set_hp(b);
    // Act
    float a = person.get_hp();

    // Assert
    EXPECT_NEAR(a, 5, 0.2);
}

TEST(FunctionsTests, Getset_damage) {
    // Arrange
    Character person;
    
    float b = 5;
    person.set_damage(b);
    // Act
    float a  = person.get_damage();

    // Assert
    EXPECT_NEAR(a, 5, 0.2);
}

