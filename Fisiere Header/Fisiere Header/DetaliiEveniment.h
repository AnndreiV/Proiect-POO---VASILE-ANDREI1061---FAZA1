#pragma once
#include <iostream>
#include <string>
#include "Locatie.h"
#include "BiletVip.h"
using namespace std;
class DetaliiEveniment
{
private:
	char* denumire;
	char* data;
	char* ora;
	float pret;
	int** matriceLocuri;
	Locatie* locatie;
	BiletVip* bilete;
	
	
public:
	DetaliiEveniment();
	DetaliiEveniment(const char* denumire, const char* data, const char* ora, float pret,  Locatie& locatie);
	DetaliiEveniment(const char* denumire, const char* data, const char* ora, float pret, Locatie& locatie, BiletVip& bilet);

	DetaliiEveniment(const DetaliiEveniment& t);
	DetaliiEveniment& operator=(const DetaliiEveniment& t);
	~DetaliiEveniment();
	friend ostream& operator<<(ostream& out, DetaliiEveniment t);
	friend istream& operator>>(istream& out, DetaliiEveniment& t);
	void setBilet();
	void afiseazaMatrice();
	char* getDenumire();
	void setDenumire(const char* denumire);
	char* getData();
	void setData(const char* data);
	char* getOra();
	void setOra(const char* ora);
	float getPret();
	void setPret(float pret);
	DetaliiEveniment& operator+(float x);
	DetaliiEveniment& operator*(float x);


};

