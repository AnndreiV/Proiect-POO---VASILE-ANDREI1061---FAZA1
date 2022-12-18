#pragma once
#include<iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

class Locatie
{
private:
		char* denumireLocatie;
		int nrRanduri;
		int nrLocuri;
		int nrMaximLocuri;

public:
	Locatie();
	Locatie(const char*, int nrRanduri, int nrLocuri, int nrMaximLocuri);
	Locatie(const char*, int nrRanduri, int nrLocuri);
	Locatie(const Locatie& t);
	~Locatie();
	Locatie& operator=(const Locatie& t);
	friend ostream& operator<<(ostream& out, const Locatie t);
	friend istream& operator>>(istream& in, Locatie& t);
	void setDenumireLocatie(const char* denumireLocatie);
	char* getDenumireLocatie();
	void setNrRanduri(int nrRanduri);
	int getNrRanduri();
	void setNrLocuri(int nrLocuri);
	int getNrLocuri();
	void setNrMaximLocuri(int nrMaximLocuri);
	int getNrMaximLocuri();
	Locatie& operator--();
	Locatie& operator--(int x);
	bool operator==(Locatie& t);
	friend class DetaliiEveniment;
};

