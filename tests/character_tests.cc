#include <gtest/gtest.h>
#include <functions/character_functions.h>
using namespace std;
using namespace rpg;


TEST(FunctionsTests, Operator_Comparison) {
    // Arrange
    auto person = make_shared<Assassin>();
    auto person2 = make_shared<Assassin>();


    float b = *person == *person2;

    
    // Assert
    EXPECT_EQ(b, true);
}


TEST(FunctionsTests, character_parametr_calculation) {
    // Arrange
    auto ptr = make_shared<Assassin>();

    // Act
    (*ptr).press_active_skill();
    (*ptr).character_parametr_calculation();
    float a = (*ptr).get_armor();

    // Assert
    EXPECT_EQ(a, 5);
}

TEST(FunctionsTests, Getset_god_status) {
    // Arrange
    auto ptr = make_shared<Assassin>();

    
    // Act
    PersonGodStatus a = (*ptr).get_god_status();

    // Assert
    EXPECT_EQ(a, ungod);
}


TEST(FunctionsTests, Getset_live_statusPositive) {
    // Arrange
    auto ptr = make_shared<Assassin>();

    
    (*ptr).set_hp(5);
    // Act
    PersonLiveStatus a = ptr->get_live_status();

    // Assert
    EXPECT_EQ(a, live);
}

TEST(FunctionsTests, hp_calculation) {
    // Arrange
    auto ptr = make_shared<Assassin>();

    float b = 5;
    ptr->set_hp(b);
    // Act
    float a = ptr->hp_calculation(3);

    // Assert
    EXPECT_EQ(a, 2);
}

TEST(FunctionsTests, damage_given) {
    // Arrange
    auto ptr = make_shared<Assassin>();

    float b = 5;
    (*ptr).set_damage(b);
    (*ptr).set_passive_skill_status(active);
    // Act
    float a = (*ptr).damage_given();

    // Assert
    EXPECT_NEAR(a, 10, 0.0001);
}


TEST(FunctionsTests, damage_takenToGod) {
    // Arrange
    
    auto ptr = make_shared<Assassin>();
    (*ptr).set_active_skill_status(selected);
    (*ptr).character_parametr_calculation();

    // Act
    float a = (*ptr).damage_taken(150);

    // Assert
    EXPECT_NEAR(a, 0, 0.05);
}

TEST(FunctionsTests, damage_taken) {
    // Arrange
    auto ptr = make_shared<Assassin>();

    // Act
    float a = (*ptr).damage_taken(15);

    // Assert
    EXPECT_NEAR(a, 10, 0.2);
}

TEST(FunctionsTests, Getset_armor) {
    // Arrange
    auto ptr = make_shared<Assassin>();

    float b = 5;
    (*ptr).set_armor(b);
    // Act
    float a = (*ptr).get_armor();

    // Assert
    EXPECT_NEAR(a, 5, 0.2);
}
TEST(FunctionsTests, Getset_hp) {
    // Arrange
    auto ptr = make_shared<Assassin>();

    float b = 5;
    (*ptr).set_hp(b);
    // Act
    float a = (*ptr).get_hp();

    // Assert
    EXPECT_NEAR(a, 5, 0.2);
}

TEST(FunctionsTests, Getset_damage) {
    // Arrange
    auto ptr = make_shared<Assassin>();
    
    float b = 5;
    (*ptr).set_damage(b);
    // Act
    float a  = (*ptr).get_damage();

    // Assert
    EXPECT_NEAR(a, 5, 0.2);
}

