#include<iostream>
using namespace std;
#include "BiletVip.h"
#include "Locatie.h"
#include "DetaliiEveniment.h"



void afisareMeniu() {
	cout << endl << "**************MENIU**********" << endl;
	cout << "1.Adauga locatie" << endl;
	cout << "2.Vezi locatie!" << endl;
	cout << "3.Editeaza locatie!" << endl;
	cout << "4.Cumpara bilet!" << endl;
	cout << "5.Vezi bilet!" << endl;
	cout << "6. Verifica existenta biletului!" << endl;
	cout << "7.Eveniment." << endl;
	cout << "8. Exit." << endl;


}
int main() {
	Locatie Locatie1;
	BiletVip Bilet1;
	DetaliiEveniment Eveniment1;
	int optiune = 0;
	
	do {
		afisareMeniu();
		cout << "Introduceti optiunea: " << endl;
		cin >> optiune;
		system("cls");
		switch (optiune) 
		{
		case 1: 
			cin.ignore();
			cin >> Locatie1;
			cout << endl << "Locatie adaugata cu succes!" << endl;
			break;
		
		case 2: 
			system("cls");
			cout << Locatie1 << endl;
			break;
		
		case 3: 
			cout << "Editam locatia: " << Locatie1.getDenumireLocatie() << endl;
			cout << "Numarul maxim de locuri anterior: " << Locatie1.getNrMaximLocuri() << endl;
			Locatie1--;
			cout << "Numarul maxim de locuri a devenit: " << Locatie1.getNrMaximLocuri() << " pentru locatia: " << Locatie1.getDenumireLocatie() << endl;
			break;
		

		case 4: 
			system("cls");
			cin.ignore();
			cin >> Bilet1;
			cout << "Bilet inregistrat cu succes!" << endl;
			break;
		
		case 5: 
			cout << Bilet1;
			break;
		
		case 6: 
			system("cls");
			if (Bilet1.operator!() == 1)
				cout << "Biletul exista in baza de date!" << endl;
			else
				cout << "Biletul nu exista in baza de date!" << endl;
			break;
		
		case 7: 
			system("cls");
			cin.ignore();
			DetaliiEveniment EvenimentTest("TEST", "15/33/33", "14:30", 40, Locatie1, Bilet1);
			cin >> EvenimentTest;
			cout << endl << "Evenimentul a fost adaugat cu succes!" << endl;
			EvenimentTest.setBilet();
			cout << "Detalii eveniment: " << endl;
			cout << EvenimentTest << endl;
			EvenimentTest.afiseazaMatrice();

			bool optiune2;
			cout << "Vrei sa modifici pretul biletelor pentru acest eveniment? (1/0)" << endl;
			cin >> optiune2;
			if (optiune2 == 0)
				break;
			else if (optiune2 == 1)
			{
				int optiune3;
				cout << "1. Dubleaza pretul curent al biletului: " << endl;
				cout << "2. Adauga 5 lei la pretul curent al biletului: " << endl;
				cout << "Introduceti optiunea: " << endl;
				cin >> optiune3;
				if (optiune3 == 1) {
					EvenimentTest.operator*(2);
					cout << "Pretul biletului a fost dublat cu succes!" << endl;
				}
				else if (optiune3 == 2) {
					EvenimentTest.operator+(5);
					cout << "Pretul biletului a fost modificat cu succes!" << endl;

				}
				cout << endl << EvenimentTest << endl;
			}

			break;
		

		}

	} while (optiune != 8);


	return 0;
}
