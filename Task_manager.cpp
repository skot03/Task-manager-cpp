#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Task.h"
#include "Task_container.h"
#include <locale.h>
#include "TaskException.h"
#include "function.h"
using namespace std;
/**
 * @file main.cpp
 * @brief Program do zarządzania zadaniami
 * @version 0.1
 * @date 2024-01-20
 * @author Paweł Skotnicki
 */

 /**
  * @brief Główna funkcja programu
  *
  * @param argc Liczba argumentów
  * @param argv Tablica argumentów
  * @return int Kod zakończenia programu
  */
int main(int argc, char* argv[])
{
	
	setlocale(LC_CTYPE, "Polish");
	print(argv[1], argc);
	Task_container taskContainer;
	int choice,taskIndex;
	display_menu(argv[1], argc);

	while (1) {
		cin >> choice;
		cin_check();
		cin.ignore();

		switch (choice) {
		case 1:
		{/**
			 * @brief Dodaje nowy task do kontenera.
			 * 
			 * @param name Nazwa taska.
			 * @param description Opis taska.
			 */
			string name, description;
			cout << "Podaj nazwe taska: ";
			getline(cin, name);

			cout << "Podaj opis taska: ";
			getline(cin, description);

			taskContainer.add_task(name, description);
		}
		break;
		case 2:
			/**
			 * @brief Ustawia status taska na zrobiony.
			 *
			 * @param taskIndex Indeks taska w kontenerze.
			 */
			cout << "Podaj indeks taska, ktory chcesz odznaczyc jako zrobiony: ";
			cin >> taskIndex;
			cin_check();

			taskContainer.set_task(taskIndex);
			break;
		case 3:
			
			
			cout << "Podaj indeks taska, ktory chcesz usunac: ";
			cin >> taskIndex;
			cin_check();
			try {
				/**
				 * @brief Usuwa task z kontenera.
				 *
				 * @param taskIndex Indeks taska w kontenerze.
				 * @throw VectorIndexException Jeśli indeks jest poza zakresem.
				 */
				taskContainer.remove_task(taskIndex); 
			}
			catch (VectorIndexException& e) { 
				cout << "Wyjatek: " << e.what() << endl;
				cout << "Niepoprawny indeks: " << e.get_index() << endl; 
			}
			break;
		case 4:
			/**
			 * @brief Dodaje opis do taska.
			 *
			 * @param taskIndex Indeks taska w kontenerze.
			 */
			cout << "Podaj indeks taska, ktoremu chcesz dodac opis: ";
			cin >> taskIndex;
			cin_check();
			cin.ignore(); 
            taskContainer.add_description(taskIndex);

			break;
		case 5:
			/**
			 * @brief Czyści ekran.
			 *
			 */
			taskContainer.clear_screen();
			display_menu(argv[1], argc);

			break;
		case 6:
			/**
			 * @brief Pokazuje wszystkie taski w kontenerze.
			 *
			 */
			taskContainer.show_tasks();
			break;
		case 7: 
			/**
			 * @brief Ustawia wszystkie taski na zrobione.
			 *
			 */
			taskContainer.set_task_done(); 
			break;
		case 8:
			/**
			 * @brief Pokazuje liczbę tasków w kontenerze.
			 *
			 */
			taskContainer.tasks_conter();
				break;
		default:
			cout << "Niepoprawny wybor.\n";
			break;
		}
	}

	return 0;
}