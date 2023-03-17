#include <functions/character_functions.h>
#include <ctime>   
#include <stdexcept>
#include <iostream>


using namespace rpg;
using namespace std;


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

		}
			  break;

		}
	}
}
