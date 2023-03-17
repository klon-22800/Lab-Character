#include <gtest/gtest.h>
#include <functions/character_functions.h>
using namespace std;
using namespace rpg;

TEST(FunctionsTests, TestOperatorComprasionFALSE) {
    // Arrange
    Character person;
    CharacterList list;
    const auto ptr1 = person.create_person(Assassin);
    const auto ptr2 = person.create_person(Berserk);
    list.add(ptr1);
    list.add(ptr2);
    bool a = *list[0] == *list[1];

    // Assert
    EXPECT_EQ(a, false);
}
TEST(FunctionsTests, TestOperatorComprasionTRUE) {
    // Arrange
    Character person;
    CharacterList list;
    const auto ptr1 = person.create_person(Assassin);
    const auto ptr2 = person.create_person(Assassin);
    list.add(ptr1);
    list.add(ptr2);
    bool a = *list[0] == *list[1];

    // Assert
    EXPECT_EQ(a, true);
}

TEST(FunctionsTests, create_person) {
    // Arrange
    Character person;
    const auto ptr = person.create_person(Assassin);
    auto a = (*ptr).get_type();

    // Assert
    EXPECT_EQ(a, Assassin);
}

TEST(FunctionsTests, character_parametr_calculation) {
    // Arrange
    Character person;
    const auto ptr = person.create_person(Assassin);

    // Act
    (*ptr).press_active_skill();
    (*ptr).character_parametr_calculation();
    float a = (*ptr).get_armor();

    // Assert
    EXPECT_EQ(a, 5);
}

TEST(FunctionsTests, Getset_god_status) {
    // Arrange
    Character person;
    const auto ptr = person.create_person(Assassin);

    
    // Act
    PersonGodStatus a = (*ptr).get_god_status();

    // Assert
    EXPECT_EQ(a, ungod);
}

TEST(FunctionsTests, Getset_type) {
    // Arrange
    Character person;
    const auto ptr = person.create_person(Assassin);

    CharacterType b = Assassin;
    (*ptr).set_type(b);
    // Act
    CharacterType a = (*ptr).get_type();

    // Assert
    EXPECT_EQ(a, Assassin);
}
TEST(FunctionsTests, Getset_live_statusPositive) {
    // Arrange
    Character person;
    const auto ptr = person.create_person(Assassin);

    
    (*ptr).set_hp(5);
    // Act
    PersonLiveStatus a = (*ptr).get_live_status();

    // Assert
    EXPECT_EQ(a, live);
}

TEST(FunctionsTests, Getset_live_statusNegative) {
    // Arrange
    Character person;
    const auto ptr = person.create_person(Assassin);

    (*ptr).set_hp(-5);
    // Act
    PersonLiveStatus a = (*ptr).get_live_status();

    // Assert
    EXPECT_EQ(a, dead);
}

TEST(FunctionsTests, hp_calculation) {
    // Arrange
    Character person;
    const auto ptr = person.create_person(Assassin);

    float b = 5;
    (*ptr).set_hp(b);
    // Act
    float a = (*ptr).hp_calculation(3);

    // Assert
    EXPECT_EQ(a, 2);
}

TEST(FunctionsTests, damage_given) {
    // Arrange
    Character person;
    const auto ptr = person.create_person(Assassin);

    float b = 5;
    (*ptr).set_damage(b);
    (*ptr).set_type(Berserk);
    (*ptr).set_passive_skill_status(active);
    // Act
    float a = (*ptr).damage_given();

    // Assert
    EXPECT_NEAR(a, 15, 0.05);
}


TEST(FunctionsTests, damage_takenToGod) {
    // Arrange
    
    Character person;
    const auto ptr = person.create_person(Assassin);
    (*ptr).set_active_skill_status(selected);
    (*ptr).character_parametr_calculation();

    // Act
    float a = (*ptr).damage_taken(150);

    // Assert
    EXPECT_NEAR(a, 0, 0.05);
}

TEST(FunctionsTests, damage_taken) {
    // Arrange
    Character person;
    const auto ptr = person.create_person(Assassin);

    // Act
    float a = (*ptr).damage_taken(15);

    // Assert
    EXPECT_NEAR(a, 10, 0.2);
}

TEST(FunctionsTests, Getset_armor) {
    // Arrange
    Character person;
    const auto ptr = person.create_person(Assassin);

    float b = 5;
    (*ptr).set_armor(b);
    // Act
    float a = (*ptr).get_armor();

    // Assert
    EXPECT_NEAR(a, 5, 0.2);
}
TEST(FunctionsTests, Getset_hp) {
    // Arrange
    Character person;
    const auto ptr = person.create_person(Assassin);

    float b = 5;
    (*ptr).set_hp(b);
    // Act
    float a = (*ptr).get_hp();

    // Assert
    EXPECT_NEAR(a, 5, 0.2);
}

TEST(FunctionsTests, Getset_damage) {
    // Arrange
    Character person;
    const auto ptr = person.create_person(Assassin);
    
    float b = 5;
    (*ptr).set_damage(b);
    // Act
    float a  = (*ptr).get_damage();

    // Assert
    EXPECT_NEAR(a, 5, 0.2);
}

