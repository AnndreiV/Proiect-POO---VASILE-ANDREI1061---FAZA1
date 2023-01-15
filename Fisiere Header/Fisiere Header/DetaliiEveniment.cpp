#include "DetaliiEveniment.h"
#include "Locatie.h"
#include "BiletVip.h"
#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;
DetaliiEveniment::DetaliiEveniment()
{
	this->denumire = nullptr;
	this->data = nullptr;
	this->ora = nullptr;
	this->pret = 0;
	this->matriceLocuri = nullptr;
	this->locatie = nullptr;
	this->bilete = nullptr;
	
	
}
DetaliiEveniment::DetaliiEveniment(const char* denumire, const char* data, const char* ora, float pret,  Locatie& locatie)
{
	this->denumire = new char[strlen(denumire) + 1];
	strcpy(this->denumire, denumire);
	this->data = new char[strlen(data) + 1];
	strcpy(this->data, data);
	this->ora = new char[strlen(ora) + 1];
	strcpy(this->ora, ora);
	this->pret = pret;
	this->locatie = new Locatie(locatie);
	this->matriceLocuri = new int* [locatie.getNrRanduri()];
	for (int i = 0; i < locatie.getNrRanduri(); i++) {
		this->matriceLocuri[i] = new int[locatie.getNrLocuri()];
	}

	for (int i = 0; i < locatie.getNrRanduri(); i++)
	{
		for (int j = 0; j < locatie.getNrLocuri(); j++)
		{
			this->matriceLocuri[i][j] = 0;
		}
	}
	
	

}
//Bilet constructor
DetaliiEveniment::DetaliiEveniment(const char* denumire, const char* data, const char* ora, float pret, Locatie& locatie, BiletVip& bilet)
{
	this->denumire = new char[strlen(denumire) + 1];
	strcpy(this->denumire, denumire);
	this->data = new char[strlen(data) + 1];
	strcpy(this->data, data);
	this->ora = new char[strlen(ora) + 1];
	strcpy(this->ora, ora);
	this->pret = pret;
	this->locatie = new Locatie(locatie);
	this->bilete = new BiletVip(bilet);
	this->matriceLocuri = new int* [locatie.getNrRanduri()];
	for (int i = 0; i < locatie.getNrRanduri(); i++) {
		this->matriceLocuri[i] = new int[locatie.getNrLocuri()];
	}

	for (int i = 0; i < locatie.getNrRanduri(); i++)
	{
		for (int j = 0; j < locatie.getNrLocuri(); j++)
		{
			this->matriceLocuri[i][j] = 0;
		}
	}



}

//end of bilet constructor
DetaliiEveniment::DetaliiEveniment( const DetaliiEveniment& t)
{
	if (t.denumire != nullptr) {
		this->denumire = new char[strlen(t.denumire) + 1];
		strcpy(this->denumire, t.denumire);
	}
	else
		this->denumire = nullptr;
	if (t.data != nullptr) {
		this->data = new char[strlen(t.data) + 1];
		strcpy(this->data, t.data);
	}
	else
		this->data = nullptr;
	if (t.ora != nullptr) {
		this->ora = new char[strlen(t.ora) + 1];
		strcpy(this->ora, t.ora);
	}
	else
		this->ora = nullptr;
	this->pret = t.pret;
	/// tryy
	if (t.matriceLocuri != nullptr)
	{
		this->matriceLocuri = new int* [t.locatie->getNrRanduri()];
		for (int i = 0; i < t.locatie->getNrRanduri(); i++) {
			this->matriceLocuri[i] = new int[t.locatie->getNrLocuri()];
		}

		for (int i = 0; i < t.locatie->getNrRanduri(); i++)
		{
			for (int j = 0; j < t.locatie->getNrLocuri(); j++)
			{
				this->matriceLocuri[i][j] = t.matriceLocuri[i][j];
			}
		}
	}
	else
		this->matriceLocuri = nullptr;
	if (t.locatie != nullptr)
	{
		this->locatie = new Locatie(*t.locatie);
		
	}
	else
		this->locatie = nullptr;
	if (t.bilete != nullptr) {
		this->bilete = new BiletVip(*t.bilete);

	}
	else
		this->bilete = nullptr;
}

DetaliiEveniment& DetaliiEveniment::operator=(const DetaliiEveniment& t)
{
	if (this != &t)
	{
		//Dezalocare:
		if (this->denumire != nullptr) {
			delete[]this->denumire;
			this->denumire = nullptr;
		}
		if (this->data != nullptr) {
			delete[]this->data;
			this->data = nullptr;
		}
		if (this->ora != nullptr) {
			delete[]this->ora;
			this->ora = nullptr;
		}
		if (this->bilete != nullptr)
			delete bilete;


		int x = 0;
		if (this->locatie != nullptr)
			 x = this->locatie->getNrRanduri();
		

		if (this->locatie != nullptr)
			delete locatie;
		if (this->matriceLocuri != nullptr) {
			for (int i = 0; i < x; i++)
			{
				delete[]matriceLocuri[i];
			}
			delete[] matriceLocuri;

		}
		if (t.denumire != nullptr) {
			this->denumire = new char[strlen(t.denumire) + 1];
			strcpy(this->denumire, t.denumire);
		}
		if (t.data != nullptr) {
			this->data = new char[strlen(t.data) + 1];
			strcpy(this->data, t.data);
		}
		if (t.ora != nullptr) {
			this->ora = new char[strlen(t.ora) + 1];
			strcpy(this->ora, t.ora);
		}
		this->pret = t.pret;
		//this->locatie = new Locatie(*t.locatie);
		//this->bilete = new BiletVip(*t.bilete);
		if (t.locatie != nullptr) /////
		{
			this->matriceLocuri = new int* [t.locatie->getNrRanduri()];
			for (int i = 0; i < t.locatie->getNrRanduri(); i++) {
				this->matriceLocuri[i] = new int[t.locatie->getNrLocuri()];
			}
			for (int i = 0; i < t.locatie->getNrRanduri(); i++)
			{
				for (int j = 0; j < t.locatie->getNrLocuri(); j++)
					this->matriceLocuri[i][j] = t.matriceLocuri[i][j];
			}
		}

	}
	return *this;
}

DetaliiEveniment::~DetaliiEveniment(){
	if (this->denumire != nullptr) {
		delete[]this->denumire;
		this->denumire = nullptr;
	}
	if (this->data != nullptr) {
		delete[]this->data;
		this->data = nullptr;
	}
	if (this->ora != nullptr) {
		delete[]this->ora;
		this->ora = nullptr;
	}
	if(this->locatie!=nullptr)////////////////////
	delete locatie;
	if (this->bilete != nullptr)
		delete bilete;
}

ostream& operator<<(ostream& out, const DetaliiEveniment t)
{
	out << "--------------------------------DETALII EVENIMENT-------------------------" << endl;
	if (t.denumire != nullptr) {
		out << "Nume eveniment: " << t.denumire << endl;
		if (t.data != nullptr && t.ora != nullptr)
			out << "Detalii eveniment: " << t.data << " " << t.ora << endl;
		if (t.pret != 0)
			out << "Pret bilet: " << t.pret << endl;
	}
	else
		out << "Nu avem detalii despre acest eveniment!" << endl;

	return out;
}
istream& operator>>(istream& in, DetaliiEveniment& t)
{
	char buffer1[100];
	char buffer2[100];
	char buffer3[100];
	cout << "----------------------PAGINA PENTRU ADAUGAREA UNUI NOU EVENIMENT---------------" << endl;
	cout << "Introduceti numele evenimentului:" << endl;
	//in >> buffer1;
	//in.getline(buffer1, 99);
	//in.ignore();
	in.getline(buffer1, 99);
	cout << "Introduceti data evenimentului sub formatul zz/ll/aaaa:";
	in >> buffer2;
	cout << "Introduceti ora evenimentului:" << endl;
	in >> buffer3;
	cout << "Introduceti pretul unui bilet: " << endl;
	in >> t.pret;
	if (t.denumire != NULL) {
		delete[]t.denumire;
		t.denumire = nullptr;
	}

	if (strlen(buffer1) > 1)
	{
		t.denumire = new char[strlen(buffer1) + 1];
		strcpy(t.denumire, buffer1);
	}
	else
	{
		t.denumire = new char[strlen("Necunoscut") + 1];
		strcpy(t.denumire, "Necunoscut");
	}



	if (t.data != NULL) {
		delete[]t.data;
		t.data = nullptr;

	}
	if (strlen(buffer2) > 1) {
		t.data = new char[strlen(buffer2) + 1];
		strcpy(t.data, buffer2);
	}
	else
	{
		t.data = new char[strlen("Necunoscuta") + 1];
		strcpy(t.data, "Necunoscuta");
	}

	if (t.ora != NULL) {
		delete[]t.ora;
		t.ora = nullptr;

	}
	if (strlen(buffer3) > 1) {
		t.ora = new char[strlen(buffer3) + 1];
		strcpy(t.ora, buffer3);
	}
	else
	{
		t.ora = new char[strlen("Necunoscuta") + 1];
		strcpy(t.ora, "Necunoscuta");
	}
	

	return in;
}

void DetaliiEveniment::setBilet()
{
	int rand = 0;
	int loc = 0;
	rand = stoi(bilete->getRand())-1;
	loc = stoi(bilete->getLoc())-1;
	//validarea pentru string o sa o fac in clasa biletvip :)
	if (rand < locatie->getNrRanduri() && loc < locatie->getNrLocuri())
	{
		if (matriceLocuri[rand][loc] == 0)
		{
			cout << "Locul ales de dvs. a fost rezervat!" << endl;
			matriceLocuri[rand][loc] = 1;
		}
		else
			if (matriceLocuri[rand][loc] == 1) {
				cout << "Locul ales de dvs. nu se poate rezerva deoarece este ocupat!" << endl;
			}
			
	}
	else
		cout << "Numarul randului sau al locului inexistent!" << endl;

}

void DetaliiEveniment::afiseazaMatrice() {
	if (this->matriceLocuri != nullptr) {
		cout << "Afisare grafica situatia locurilor in sala : (0 - Liber | 1 - Ocupat) " << endl;
		for (int i = 0; i < locatie->getNrRanduri(); i++) {
			for (int j = 0; j < locatie->getNrLocuri(); j++) {
				cout << matriceLocuri[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
		cout << "Nu putem afisa o situatie grafica asupra locurilor din sala! Ne cerem scuze!" << endl;
}


char* DetaliiEveniment::getDenumire() {
	char* copie = new char[strlen(this->denumire) + 1];
	strcpy(copie, this->denumire);
	return copie;
}
void DetaliiEveniment::setDenumire(const char* denumire) {
	if (this->denumire != nullptr) {
		delete[]this->denumire;
		this->denumire = nullptr;
	}
	if (strlen(denumire) > 0) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
	}
}

char* DetaliiEveniment::getData() {
	char* copie = new char[strlen(this->data) + 1];
	strcpy(copie, this->data);
	return copie;
}
void DetaliiEveniment::setData(const char* data) {
	if (this->data != nullptr) {
		delete[]this->data;
		this->data = nullptr;
	}
	if (strlen(data) > 0) {
		this->data = new char[strlen(data) + 1];
		strcpy(this->data, data);
	}
}

char* DetaliiEveniment::getOra() {
	char* copie = new char[strlen(this->ora) + 1];
	strcpy(copie, this->ora);
	return copie;
}
void DetaliiEveniment::setOra(const char* ora) {
	if (this->ora != nullptr) {
		delete[]this->ora;
		this->ora = nullptr;
	}
	if (strlen(ora) > 0) {
		this->ora = new char[strlen(ora) + 1];
		strcpy(this->ora, ora);
	}
}
float DetaliiEveniment::getPret() {
	return this->pret;
}

void DetaliiEveniment::setPret(float pret)
{
	if (pret > 0)
		this->pret = pret;
	else
		this->pret = 0;
}
DetaliiEveniment&DetaliiEveniment:: operator+(float x)
{
	this->pret += x;
	return *this;
}
DetaliiEveniment&DetaliiEveniment:: operator*(float x)
{
	this->pret *= x;
		return *this;

}

