#pragma once
#include <iostream>;
#include <memory>
#include<vector>
using namespace std;

namespace rpg {
    enum PersonGodStatus {
        god,
        ungod
    };
    enum ActiveSkillStatus {
        selected,
        unselected
    };
    enum PassiveSkillStatus {
        active,
        unactive
    };
    enum PersonLiveStatus {
        live,
        dead
    };
    enum GameStatus {
        gone,
        ended
    };
    class Character;

    using CharacterPtr = std::shared_ptr<Character>;

    class Character {
    public:
       
        bool operator==(const Character& rhs);
       
        virtual int get_type() = 0;
        virtual void print() const = 0;
        virtual unique_ptr<Character> clone() const = 0;
        virtual void character_parametr_calculation() = 0;
        virtual float damage_given() = 0;
        virtual float damage_taken(float damage_given) = 0;
        virtual void passive_skill_chance() = 0;


        
        void set_god_status(PersonGodStatus a);
        void press_active_skill();
        float hp_calculation(float damageFromOpponent);
        
        void set_damage(float a);
        float get_damage();

        void set_armor(float a);
        float get_armor();

        void set_hp(float a);
        float get_hp();

        void set_active_skill_status(ActiveSkillStatus a);
        void set_passive_skill_status(PassiveSkillStatus a);

        void set_live_status(PersonLiveStatus a);
        PersonLiveStatus get_live_status();

        
        
    protected:
        ActiveSkillStatus _active_skill_status;
        PassiveSkillStatus _passive_skill_status;
        PersonLiveStatus _live_status;

        float _hp;
        float _armor;
        float _damage;
        PersonGodStatus _god_status = ungod;
        Character() = default;

    };

    std::ostream& operator<<(std::ostream& stream, Character& person);

    class Assassin : public Character {
    public:
        Assassin() {
            _hp = 100;
			_armor = 5;
			_damage = 25;
			_god_status = ungod;
			_active_skill_status = unselected;
			_passive_skill_status = unactive;
			_live_status = live;
        }
        Assassin(float hp,float armor,float damage,PersonGodStatus god_status,ActiveSkillStatus active_skill_status,
            PassiveSkillStatus passive_skill_status, PersonLiveStatus live_status) {
            _hp = hp;
            _armor = armor;
            _damage = damage;
            _god_status = god_status;
            _active_skill_status = active_skill_status;
            _passive_skill_status = passive_skill_status;
            _live_status = live_status;
        }
        int get_type() override {
            return 1;
        }
        void print() const override;
        unique_ptr<Character> clone() const  override;
        void character_parametr_calculation() override;
        float damage_given() override;
        float damage_taken(float damage_given) override;
        void passive_skill_chance() override;
        
        PersonGodStatus get_god_status();
    private:
        
        float _double_attack_chance_assassin = 50;

    };
    class Berserk : public Character {
    public:
        Berserk() {
            _hp = 200;
            _armor = 1;
            _damage = 35;
            _active_skill_status = unselected;
            _passive_skill_status = unactive;
            _live_status = live;
        }
        Berserk(float hp, float armor, float damage, ActiveSkillStatus active_skill_status,
            PassiveSkillStatus passive_skill_status, PersonLiveStatus live_status) {
            _hp = hp;
            _armor = armor;
            _damage = damage;
            _active_skill_status = active_skill_status;
            _passive_skill_status = passive_skill_status;
            _live_status = live_status;
        }
        int get_type() override {
            return 2;
        }
        void print() const override;
        unique_ptr<Character> clone() const  override;
        void character_parametr_calculation() override;
        float damage_given() override;
        float damage_taken(float damage_given) override;
        void passive_skill_chance() override;
    private:
        float _triple_damage_chance_berserk = 50;
    };
    class Knight : public Character {
    public:
        Knight() {
            _hp = 150;
            _armor = 7;
            _damage = 30;
            _active_skill_status = unselected;
            _passive_skill_status = unactive;
            _live_status = live;
        }
        Knight(float hp, float armor, float damage, ActiveSkillStatus active_skill_status,
            PassiveSkillStatus passive_skill_status, PersonLiveStatus live_status) {
            _hp = hp;
            _armor = armor;
            _damage = damage;
            _active_skill_status = active_skill_status;
            _passive_skill_status = passive_skill_status;
            _live_status = live_status;
        }
        int get_type() override {
            return 3;
        }
        unique_ptr<Character> clone() const  override;
        void print() const override;
        void character_parametr_calculation() override;
        float damage_given() override;
        float damage_taken(float damage_given) override;
        void passive_skill_chance() override;
    private:
        float _reduce_damage_chance_knight = 50;
    };


    class CharacterList {
    public:
        void swap(CharacterList& OtherList) noexcept;
        
        CharacterList() = default;
        CharacterList(const CharacterList& OtherList);
        CharacterPtr operator[](const int index) const;
        CharacterList& operator=(CharacterList rhs);

        int size();

        void print();

        void add(CharacterPtr person);
        int index_of_max_damage();
        void insert(CharacterPtr a, int index);
        void delete_person(int index);
        
    private:
        std::vector<CharacterPtr> _character_array;  
    };
}