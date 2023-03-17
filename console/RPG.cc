#include <functions/character_functions.h>
#include <ctime>   
#include <stdexcept>
#include <iostream>
#include <chrono>
#include <thread>


using namespace rpg;
using namespace std;

bool attack_or_skill() {
	int probability_skill_or_attack = 50;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	srand(time(NULL));
	int choice = rand() % 100 + 1;
	if (choice > probability_skill_or_attack) {
		return true;
	}
	else {
		return false;
	}
}

void parametrs_null(Character& a, Character& b) {
	a.set_active_skill_status(unselected);
	b.set_active_skill_status(unselected);

	a.set_passive_skill_status(unactive);
	b.set_passive_skill_status(unactive);

	a.set_god_status(ungod);
	b.set_god_status(ungod);
}

void Battle(Character& playerA, Character& playerB) {
	
	bool playerA_attack = false;
	bool playerB_attack = false;

	float playerA_damage = 0;
	float playerB_damage = 0;

	float playerA_damage_take = 0;
	float playerB_damage_take = 0;

	float playerA_present_health = playerA.get_hp();
	float playerB_present_health = playerB.get_hp();

	while (playerA.get_hp() > 0 && playerB.get_hp() > 0) {
		
		parametrs_null(playerA, playerB);
		playerA_attack = false;
		playerA_attack = false;

		playerA_damage = 0;
		playerB_damage = 0;



		playerA_attack = attack_or_skill();
		playerB_attack = attack_or_skill();


		if (playerA_attack == false) {
			playerA.press_active_skill();
			cout << "Player A choose the skill" << "\n";
		}
		if (playerB_attack == false) {
			playerB.press_active_skill();
			cout << "Player B choose the skill  " << "\n\n";
		}
		
		

		playerA.character_parametr_calculation();
		playerB.character_parametr_calculation();

		if (playerA_attack == true) {
			playerA_damage = playerA.damage_given();
			cout << "Player A choose the atack, damage: " << playerA_damage<<"\n";
		}
		if (playerB_attack == true) {
			playerB_damage = playerB.damage_given();
			cout << "Player B choose the atack, damage: " << playerB_damage << "\n\n";
		}

		playerA_damage_take = playerA.damage_taken(playerB_damage);
		playerB_damage_take = playerB.damage_taken(playerA_damage);
		
		playerA_present_health = playerA.hp_calculation(playerA_damage_take);
		playerB_present_health = playerB.hp_calculation(playerB_damage_take);


		cout <<"HP 1 player" << playerA_present_health << "\n";
		cout << "HP 2 player" << playerB_present_health << "\n\n";
	}
}




int main() {
	int choice = 1;
	CharacterList list;
	Character person;
	while (choice != 0) {
		cout << "1 - Add element by index\n2 - Delete element by index\n3 - Print all eleement\n4 - Print person with max damage\n5 - Start the fight";
		cin >> choice;
		system("cls");
		switch (choice) {
		case 1: {
			int type = 0;
			cout << "Choose person\n0 - Assassin\n1 - Knight\n2 - Berserk";
			cin >> type;
			switch (type) {
			case 0: {
				list.add(person.create_person(Assassin));
				list.print();
			}
				  break;
			case 1: {
				list.add(person.create_person(Knight));
				list.print();
			}
				  break;
			case 2: {
				list.add(person.create_person(Berserk));
				list.print();
			}
				  break;
			}
		}
			  break;
		case 2: {
			int index_delete = -1;
			cout << "Enter index for delete";
			cin >> index_delete;
			if (index_delete < 0 || index_delete >= list.size()) {
				cout << "\n\t[{UNCORRECT INDEX}]\n";
			}
			else {
				list.delete_person_from_list(index_delete);
			}
			list.print();
		}
			  break;
		case 3: {
			list.print();
		}
			  break;
		case 4: {
			if (list.size() <= 0) {
				cout << "\n\t[{LIST IS VOID}]\n\n";
			}
			else {
				int index_of_max_damage = list.index_of_max_damage();
				cout << "Max damage person is: ";
				(*list[index_of_max_damage]).print();
			}
			
		}
			  break;
		case 5: {
			int indexA = -1;
			int indexB = -1;
			cout << "Choose first person from the list";
			cin >> indexA;
			cout << "Choose second person from the list";
			cin >> indexB;
			Battle(*list[indexA], *list[indexB]);

		}
			  break;

		}
	}
}
