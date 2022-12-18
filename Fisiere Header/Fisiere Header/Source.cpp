#include<iostream>
using namespace std;
#include "BiletVip.h"
//#include "InvitatiSpeciali.h"
#include "Locatie.h"
#include "DetaliiEveniment.h"

//Clasa se numeste BiletVIP pentru ca am avut alta incercare inainte si am facut o derivare. O sa o redenumesc daca nu e ok.
//Urmeaza sa fac validarile si interfata cu utilizatorul in faza 2, am vazut ca acolo este specificata. 
// Clasa InvitatiSpeciali nu este finalizata!

void afisareMeniu() {
	cout << endl << "**************MENIU**********" << endl;
	cout << "1.Adauga locatie" << endl;
	cout << "2.Vezi locatie!" << endl;
	cout << "3.Cumpara bilet  in zona standard!" << endl;
	cout << "4.Vezi bilet!" << endl;
	cout << "5.Exit." << endl;


}
int main() {
	cout << "Faza numarul 1 a proiectului. Interfata cu utilizatorul si validarile vor fi facute in faza 2 a proiectului." << endl;
	cout << "Pentru alte teste asupra proiectului va rog sa apelati in main! " << endl;
	cout << "Daca ma puteti ajuta cu alte indicatii sau aveti un sfat va rog sa ma anuntati! Multumesc mult! :) " << endl;
	Locatie LocatieTest;
	Locatie locatie("OriceLocatie", 3, 5, 20);
	

	cin >> LocatieTest;
	cout << LocatieTest << endl;
	cout << locatie;
	LocatieTest--; // scade numarul maxim de locuri
	cout << LocatieTest;
	if (LocatieTest == locatie)  // verifica daca toate atributele numerice sunt egale inre ele
		cout << "Locatii egale!" << endl;
	else
		cout << "Locatii diferite!" << endl;
	/////////////////////////////////////////////
	cin.ignore();
	BiletVip BiletTest;
	BiletVip bilet("Andrei Vasile", "0731609659", "2", "2");
	cin >> BiletTest;
	cout << BiletTest << endl;
	bilet++;
	cout << bilet.operator!();

	//////////////////////////////////////////
	cin.ignore();
	DetaliiEveniment eveniment("Eveniment", "15/33/33", "14:30", 40, locatie, bilet);
	DetaliiEveniment EvenimentTest("TEST", "15/33/33", "14:30", 40, locatie, bilet);
	DetaliiEveniment eveniment2;
	
	cin >> eveniment2;
	cout << eveniment2 << endl;
	cout << "Operator de inmultire a pretului + afisare" << endl;
	eveniment2.operator*(2);//Dubleaza pretul biletului
	cout << eveniment2;
	cout << "Operator de adunare a pretului + afisare" << endl;
	eveniment2.operator+(3);//Aduna valoarea 3 la pretul biletului.
	cout << eveniment2;

	cout << "****************************************" << endl;
	cout << "Adaugare bilet + afisare de matrice!" << endl;
	cout << "Se vor adauga datele obiectului 'bilet' din main. Rand:2 Loc: 2. " << endl;
	cout << "****************************************" << endl;


	EvenimentTest.setBilet();
	cout << EvenimentTest << endl;
	EvenimentTest.afiseazaMatrice();

	
	return 0;
}
