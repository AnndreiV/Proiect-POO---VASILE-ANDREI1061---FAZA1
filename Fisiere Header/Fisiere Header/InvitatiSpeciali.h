#pragma once
#include <iostream>
using namespace std;
class InvitatiSpeciali
{
private:
	string nume;
	int varsta;
	int dimVector;
	int* noteRecenzii;
	float oreAcoperite;
public:
	InvitatiSpeciali();
	InvitatiSpeciali(string nume, int varsta, int* noteRecenzii, int dimVector, float oreAcoperite);
	InvitatiSpeciali(string nume, int varsta, float oreAcoperite);

	InvitatiSpeciali(const InvitatiSpeciali& t);
	~InvitatiSpeciali();
	InvitatiSpeciali& operator=(const InvitatiSpeciali &t);
	friend ostream& operator<<(ostream& out, InvitatiSpeciali t);
	friend istream& operator>>(istream& in, InvitatiSpeciali& t);
	
	string getNume();
	int getVarsta();
	int getDimVector();
	int* getNoteRecenzii();
	float getOreAcoperite();
	void setNume(string nume);
	void setVarsta(int varsta);
	void setDimVector(int dimVector);
	void setNoteRecenzii(int* noteRecenzii, int dimVector);
	void setOreAcoperite(float oreAcoperite);


};

