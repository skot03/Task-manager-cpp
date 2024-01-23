#pragma once
#include <iostream>



using namespace std;

template <typename T>
void print(T value, int argc) {
	if (argc != 2) {
		cout << "Z³a liczba argumentów" << endl;
		exit(5);
	}

	cout << "Menad¿er tasków dla " << value << endl;
}
template<typename T>
void display_menu(T value, int argc) {
	if (argc != 2) {
		cout << "Z³a liczba argumentów" << endl;
		exit(5);
	}
	cout << "Program do zarzadzania zadaniami \n";
	cout << "1."<<value<< " Dodaj nowego taska \n";
	cout << "2." << value << "  Odznacz taska jako zrobionego \n";
	cout << "3." << value << "  Usun taska z listy taskow \n";
	cout << "4." << value << "  Dodaj opis do taska \n";
	cout << "5." << value << "  Wyczysc ekran \n";
	cout << "6." << value << " Wypisz taski \n";
	cout << "7" << value << " .Zaznacz wszystkie taski jako zrobione \n";
	cout << "8" << value << " .Wyswietl liczbe zrobionych taskow\n";
	cout  << value << " Wybierz odpowiednia opcje:\n";
}
void cin_check() {
	if (cin.fail()) {

		cout << "Poda³eœ z³y parametr";
		exit(6);
	}
}