#pragma once
#include<iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;
class BiletStandard
{
private:
	int id;
	char* numeSpectator;
	bool statusLoc;
	string rand;
	string loc;
	static int nrBilete;
	string numarTelefon;
public:
	BiletStandard();
	BiletStandard(const char* numeSpectator, string numarTelefon, string rand, string loc);
	BiletStandard(const BiletStandard& t);
	~BiletStandard();
	string getRand();
	string getLoc();
	void setRand(string rand);
	void setLoc(string loc);
	int getId();
	void setId(int id);
	char* getNumeSpectator();
	void setNumeSpectator(const char* numeSpectator);
	bool getStatusLoc();
	void setStatusLoc(bool statusLoc);
	static int getNrBilete();
	string getNumarTelefon();
	void setNumarTelefon(string numarTelefon);
	string AflaNumarTelefon(int id);
	char* AflaNumeSpectator(int id);
	BiletStandard& operator=(const BiletStandard& t);
	friend ostream& operator<<(ostream& out, BiletStandard t);
	friend istream& operator>>(istream& in, BiletStandard& t);
	BiletStandard& operator++();
	BiletStandard& operator++(int x);

	bool operator!();
};

