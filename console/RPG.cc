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

void active_skill_print(int type){
	switch (type) {
	case 0: {
		cout << "Will take 0 damage\n";
	}
		  break;
	case 1: {
		cout << "Increases armor by 1, reduces damage by 3\n";

	}
		  break;
	case 2: {
		cout << "Increases damage by 10, increases triple damage chance by 10 %, reduces armor by 10\n";
	}
		  break;
	}
}

void passive_skill_print(int type) {
	switch (type) {
	case 0: {
		cout << "Increases damage X2\n";
	}
		  break;
	case 1: {
		cout << "Reduce damage /2\\n";

	}
		  break;
	case 2: {
		cout << "Increases damage X3\n";
	}
		  break;
	}
}

void Battle(Character& playerA, Character& playerB) {
	int step = 0;
	
	bool playerA_attack = false;
	bool playerB_attack = false;

	float playerA_damage = 0;
	float playerB_damage = 0;

	float playerA_damage_take = 0;
	float playerB_damage_take = 0;

	float playerA_present_health = playerA.get_hp();
	float playerB_present_health = playerB.get_hp();

	int typeA = playerA.get_type();
	int typeB = playerB.get_type();

	cout << "HP 1 player " << playerA_present_health << "\n";
	cout << "HP 2 player " << playerB_present_health << "\n\n";

	while (playerA.get_hp() > 0 && playerB.get_hp() > 0) {
		cout << "Step: " << step << "\n";
		
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
			active_skill_print(typeA);
		}
		if (playerB_attack == false) {
			playerB.press_active_skill();
			cout << "Player B choose the skill  " << "\n";
			active_skill_print(typeB);
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
		cout << "Player A take: " << playerA_damage_take << " damage\n";
		playerB_damage_take = playerB.damage_taken(playerA_damage);
		cout << "Player B take: " << playerB_damage_take << " damage\n";
		
		playerA_present_health = playerA.hp_calculation(playerA_damage_take);
		playerB_present_health = playerB.hp_calculation(playerB_damage_take);


		cout <<"HP 1 player " << playerA_present_health << "\n";
		cout << "HP 2 player " << playerB_present_health << "\n\n\n";
		step++;
	}

	if (playerA_present_health > playerB_present_health) {
		cout << "PLAYER A WIN!!!!\n";
	}
	else if (playerA_present_health < playerB_present_health) {
		cout << "PLAYER B WIN!!!!\n";
	}
	else if (playerA_present_health == playerB_present_health) {
		cout << "DRAW\n";
	}
}




int main() {
	int choice = 1;
	CharacterList list;
	Character person;
	while (choice != 0) {
		cout << "1 - Add element\n2 - Insert element by index\n3 - Delete element by index\n4 - Print all eleement\n5 - Print person with max damage\n6 - Start the fight\n7 - Close\n";
		cin >> choice;
		system("cls");
		switch (choice) {
		case 1: {
			int type = 0;
			cout << "Choose person\n0 - Assassin\n1 - Knight\n2 - Berserk";
			cin >> type;
			if (type < 0 || type>2) {
				cout << "[{INCORRECT TYPE}]\n";
				break;
			}
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
			int type = 0;
			int index = -1;
			cout << "Choose person\n0 - Assassin\n1 - Knight\n2 - Berserk";
			cin >> type;
			if (type < 0 || type>2) {
				cout << "[{INCORRECT TYPE}]\n";
				break;
			}
			cout << "Choose index: ";
			cin >> index;
			if ((index<0 || index> list.size()) || (type<0 || type >2)) {
				cout << "[{INCORRECT INDEX}]\n";
				break;
			}
			switch (type) {
			case 0: {
				list.insert(person.create_person(Assassin), index);
				list.print();
			}
				  break;
			case 1: {
				list.insert(person.create_person(Knight), index);
				list.print();
			}
				  break;
			case 2: {
				list.insert(person.create_person(Berserk), index);
				list.print();
			}
				  break;
			}

		}
			  break;
		case 3: {
			int index_delete = -1;
			cout << "Enter index for delete";
			cin >> index_delete;
			if (index_delete < 0 || index_delete >= list.size()) {
				cout << "\n\t[{INCORRECT INDEX}]\n";
			}
			else {
				list.delete_person_from_list(index_delete);
			}
			list.print();
		}
			  break;
		case 4: {
			list.print();
		}
			  break;
		case 5: {
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
		case 6: {
			int indexA = -1;
			int indexB = -1;
			cout << "Choose first person from the list: ";
			cin >> indexA;
			cout << "Choose second person from the list: ";
			cin >> indexB;
			if (indexA == indexB) {
				cout << "[{INCORRECT INDEX}]\n";
			}
			else {
				if ((indexA >= 0 && indexA < list.size()) && (indexB >= 0 && indexB < list.size())) {
					Battle(*list[indexA], *list[indexB]);
				}
				else {
					cout << "[{INCORRECT INDEX}]\n";
				}
			}
		}
			  break;
		case 7:
			return 0;
		}
		
	}
}
