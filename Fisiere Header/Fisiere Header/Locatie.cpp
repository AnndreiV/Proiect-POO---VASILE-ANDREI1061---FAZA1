#include "Locatie.h"
#pragma warning(disable:4996)
#include <iostream>
#include <string>
Locatie::Locatie() 
{
	this->denumireLocatie = new char[strlen("Necunoscuta") + 1];
	strcpy(this->denumireLocatie, "Necunoscuta");
	this->nrRanduri = 0;
	this->nrLocuri = 0;
	this->nrMaximLocuri = 0;

}
Locatie::Locatie(const char* denumireLocatie, int nrRanduri, int nrLocuri, int nrMaximLocuri) 
{
	if (denumireLocatie != nullptr) {
		this->denumireLocatie = new char[strlen(denumireLocatie) + 1];
		strcpy(this->denumireLocatie, denumireLocatie);
	}
	else {
		this->denumireLocatie = new char[strlen("NESPECIFICATA") + 1];
		strcpy(this->denumireLocatie, "NESPECIFICATA");
	}
	if (nrRanduri >= 0) {
		this->nrRanduri = nrRanduri;
	}
	else
		this->nrRanduri = 0;
	if (nrLocuri > 0) {
		this->nrLocuri = nrLocuri;
	}
	else
		this->nrLocuri = 0;
	if (nrMaximLocuri >= 0) {
		this->nrMaximLocuri = nrMaximLocuri;
	}
	else
		this->nrMaximLocuri = nrRanduri * nrLocuri;
}

Locatie::Locatie(const char* denumireLocatie, int nrRanduri, int nrLocuri)
{
	if (denumireLocatie != nullptr) {
		this->denumireLocatie = new char[strlen(denumireLocatie) + 1];
		strcpy(this->denumireLocatie, denumireLocatie);
	}
	else {
		this->denumireLocatie = new char[strlen("NESPECIFICATA") + 1];
		strcpy(this->denumireLocatie, "NESPECIFICATA");
	}
	if (nrRanduri >= 0) {
		this->nrRanduri = nrRanduri;
	}
	else
		this->nrRanduri = 0;
	if (nrLocuri > 0) {
		this->nrLocuri = nrLocuri;
	}
	else
		this->nrLocuri = 0;
}

Locatie::Locatie(const Locatie& t)
{
	if (t.denumireLocatie != nullptr) {
		this->denumireLocatie = new char[strlen(t.denumireLocatie) + 1];
		strcpy(this->denumireLocatie, t.denumireLocatie);
	}
	else {
		this->denumireLocatie = new char[strlen("NESPECIFICATA") + 1];
		strcpy(this->denumireLocatie, "NESPECIFICATA");
	}
	if (t.nrRanduri >= 0) {
		this->nrRanduri = t.nrRanduri;
	}
	else
		this->nrRanduri = 0;
	if (t.nrLocuri > 0) {
		this->nrLocuri = t.nrLocuri;
	}
	else
		this->nrLocuri = 0;
	if (t.nrMaximLocuri >= 0) {
		this->nrMaximLocuri = t.nrMaximLocuri;
	}
	else
		this->nrMaximLocuri = t.nrRanduri * t.nrLocuri;
}
Locatie::~Locatie()
{
	if (this->denumireLocatie != nullptr) {
		delete[]this->denumireLocatie;
		this->denumireLocatie = nullptr;
	}
}
Locatie& Locatie::operator=(const Locatie& t)
{
	if (this != &t)
	{
		if (this->denumireLocatie != nullptr) {
			delete[]this->denumireLocatie;
			this->denumireLocatie = nullptr;
		}
		if (t.denumireLocatie != nullptr) 
		{
			this->denumireLocatie = new char[strlen(t.denumireLocatie) + 1];
			strcpy(this->denumireLocatie, t.denumireLocatie);
		}
		this->nrLocuri = t.nrLocuri;
		this->nrRanduri = t.nrRanduri;
		this->nrMaximLocuri = t.nrMaximLocuri;
	}
	return *this;
}
ostream& operator<<(ostream& out, const Locatie t)
{
	out << "----------DETALII LOCATIE EVENIMENT----------" << endl;
	if (t.denumireLocatie != nullptr) 
	{
		out << "Zona/locatia " << t.denumireLocatie << " dispune de urmatoarele caracteristici:" << endl;
		out << "Numar maxim de locuri: " << t.nrMaximLocuri << endl;
		out << "Numar de randuri: " << t.nrRanduri << endl;
		out << "Numar de locuri: " << t.nrLocuri << endl;
	}
	else
		out << "Numele nu este specificat, nu putem sa oferim date despre o zona necunoscuta!" << endl;
	return out;
}

istream& operator >>(istream& in, Locatie& t)
{	
	char buffer[100];
	cout << "Introduceti denumirea locatiei: " << endl;
	//in.ignore();
	in.getline(buffer, 99);
	if (strlen(buffer) > 2) {
		if (t.denumireLocatie != nullptr) {
			delete[]t.denumireLocatie;
		}
		t.denumireLocatie = new char[strlen(buffer) + 1];
		strcpy(t.denumireLocatie, buffer);
	}
	else {
		cout << "Nu ai introdus un nume valid. Limita inferioara este de 2 caractere! " << endl;
		cout << "S-a autoasignat un nume: INVALIDNAME" << endl;
		if (t.denumireLocatie != nullptr)
		{
			delete[]t.denumireLocatie;
		}
		t.denumireLocatie = new char[strlen("INVALIDNAME") + 1];
		strcpy(t.denumireLocatie, "INVALIDNAME");

	}
	cout << "Introduceti numarul maxim de locuri: " << endl;
	int nrMax = 0;
	in >> nrMax;
	if (nrMax > 0)
		t.nrMaximLocuri = nrMax;
	else
	{
		cout << "Nu ai introdus un numar maxim de locuri valid." << endl;
		t.nrMaximLocuri = 0;
		t.nrRanduri = 0;
		t.nrLocuri = 0;
	}
	
	int nrRand = 0;
	cout << "Introduceti numarul de randuri: " << endl;
	in >> nrRand;
	if (nrRand >= 0 && nrRand < t.nrMaximLocuri)
		t.nrRanduri = nrRand;
	else {
		cout << "Nu ai introdus corect numarul de randuri!" << endl;
		t.nrRanduri = 0;
		
	}
	int nrLoc = 0;
	cout << "Introduceti numarul de locuri:" << endl;
	in >> nrLoc;
	if (nrLoc > 0 && nrLoc < t.nrMaximLocuri)
		t.nrLocuri = nrLoc;
	else {
		cout << "Nu ai introdus corect numarul de locuri!" << endl;
		t.nrLocuri = 0;
	}
	return in;

	
}
void Locatie::setDenumireLocatie(const char* denumireLocatie)
{
	if (denumireLocatie != nullptr) {
		if (this->denumireLocatie != nullptr) {
			delete[]this->denumireLocatie;
			this->denumireLocatie = nullptr;
		}
		this->denumireLocatie = new char[strlen(denumireLocatie) + 1];
		strcpy(this->denumireLocatie, denumireLocatie);
	}
	
}
char* Locatie::getDenumireLocatie()
{
	if (this->denumireLocatie != nullptr) {
		char* copie = new char[strlen(this->denumireLocatie) + 1];
		strcpy(copie, this->denumireLocatie);
		return copie;
	}
	else
		return nullptr;

}
void Locatie:: setNrRanduri(int nrRanduri)
{
	if (nrRanduri >= 0) {
		this->nrRanduri = nrRanduri;
	}
}

int Locatie:: getNrRanduri()
{
	return this->nrRanduri;
}
void Locatie::setNrLocuri(int nrLocuri)
{
	if (nrLocuri > 0) {
		this->nrLocuri = nrLocuri;
	}
}
int Locatie::getNrLocuri()
{
	return this->nrLocuri;
}

void Locatie::setNrMaximLocuri(int nrMaximLocuri)
{
	if (nrMaximLocuri > 0) {
		this->nrMaximLocuri = nrMaximLocuri;
	}
}
int Locatie::getNrMaximLocuri()
{
	return this->nrMaximLocuri;
}

Locatie&Locatie:: operator--()
{
	this->nrMaximLocuri--;
	return *this;
}

Locatie& Locatie::operator--(int x) {
	Locatie copie = *this;
	this->nrMaximLocuri--;
	return copie;
}
bool Locatie::operator==(Locatie& t) {
	if (this->nrLocuri == t.nrLocuri && this->nrRanduri == t.nrRanduri && this->nrMaximLocuri == t.nrMaximLocuri) {
		return true;
	}
	else
		return false;
}




