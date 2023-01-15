#pragma once
#include <iostream>
#include <string>
using namespace std;
class Eveniment
{
private:
	char* denumireFilm;
	char* data;
	char* ora;
	int nrRanduriBiletStandard;
	int nrLocuriBiletStandard;
	int nrRanduriBiletVIP;
	int nrLocuriBiletVIP;
	const int nrMaximLocuri;
	static int nrFilm;
public:
	Eveniment();
	Eveniment(const char* denumireFilm, const char* data, const char* ora, int nrRanduriBiletStandard, int nrLocuriBiletStandard, int nrRanduriBiletVIP, int nrLocuriBiletVIP, int nrMaximLocuri);
	Eveniment(const Eveniment& t);
	Eveniment& operator=(const Eveniment& t);
	friend ostream& operator<<(ostream& out, const Eveniment t);
	friend istream& operator>>(istream& in, Eveniment& t);
	char* getDenumireFilm();
	void setDenumireFilm(const char* denumireFilm);
	char* getData();
	void setData(const char* data);
	char* getOra();
	void setOra(const char* ora);
	int getNrRanduriBiletStandard();
	void setNrRanduriBiletStandard(int nrRanduriBiletStandard);
	int getNrRanduriBiletVIP();
	void setNrRanduriBiletVIP(int nrRanduriBiletVIP);
	int getNrLocuriBiletStandard();
	void setNrLocuriBiletStandard(int nrLocuriBiletStandard);
	int getNrLocuriBiletVIP();
	void setNrLocuriBiletVIP(int nrLocuriBiletVIP);
	int getNrMaximLocuri();
	string operator>(const Eveniment& t);
	bool operator>=(const Eveniment& t);
	int nrTotalLocuri();
	static int numarFilm(int id);
	////////////////////////NU UITAAA
	~Eveniment();



};

