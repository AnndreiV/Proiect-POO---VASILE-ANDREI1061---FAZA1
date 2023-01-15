#include "BiletVip.h"
#include<iostream>
#include<string>
#pragma warning(disable:4996)
int BiletVip::nrBilete = 0;
BiletVip::BiletVip() {

	this->id = nrBilete;
	this->rand = "0";
	this->loc = "0";
	this->numeSpectator = new char[strlen("Necunoscut") + 1];
	strcpy(this->numeSpectator, "Necunoscut");
	this->statusLoc = false;
	this->numarTelefon = "Numar necunoscut";
}

BiletVip::BiletVip(const char* numeSpectator, string numarTelefon, string rand, string loc) {
	nrBilete++;
	this->rand = rand;
	this->loc = loc;
	this->id = nrBilete;
	this->numeSpectator = new char[strlen(numeSpectator) + 1];
	strcpy(this->numeSpectator, numeSpectator);
	this->statusLoc = true;
	this->numarTelefon = numarTelefon;
}

BiletVip::BiletVip(const BiletVip& t) {
	nrBilete++;
	this->id = nrBilete;
	this->rand = t.rand;
	this->loc = t.loc;
	
		this->numeSpectator = new char[strlen(t.numeSpectator) + 1];
		strcpy(this->numeSpectator, t.numeSpectator);
	this->statusLoc = t.statusLoc;
	this->numarTelefon = t.numarTelefon;

}

BiletVip::~BiletVip() {
	if (this->numeSpectator != nullptr) {
		delete[]this->numeSpectator;
		this->numeSpectator = nullptr;
	}
}

string BiletVip::getRand() {
	return this->rand;
}
string BiletVip::getLoc() {
	return this->loc;
}
void  BiletVip::setRand(string rand) {
	if (rand != "0") {
		this->rand = rand;
	}
}
void BiletVip::setLoc(string loc) {
	if (loc != "0") {
		this->loc = loc;
	}
}

int BiletVip::getId() {
	return this->id;
}
void BiletVip::setId(int id) {
	if (id > 0)
		this->id = id;
}
char* BiletVip::getNumeSpectator() {
	if (this->numeSpectator != nullptr) {
		char* copie = new char[strlen(this->numeSpectator) + 1];
		strcpy(copie, this->numeSpectator);
		return copie;
	}
	else return nullptr;
}
void BiletVip::setNumeSpectator(const char* numeSpectator) {
	if (numeSpectator != nullptr) {
		if (this->numeSpectator != nullptr) {
			delete[]this->numeSpectator;
			this->numeSpectator = nullptr;
		}
		this->numeSpectator = new char[strlen(numeSpectator) + 1];
		strcpy(this->numeSpectator, numeSpectator);
	}
}

bool BiletVip::getStatusLoc() {
	return this->statusLoc;
}
void BiletVip::setStatusLoc(bool statusLoc) {
	this->statusLoc = statusLoc;
}
int BiletVip::getNrBilete() //aici nu a mers sa folosesc static int
{
	return nrBilete;
}
string BiletVip::getNumarTelefon() {
	return this->numarTelefon;
}
void BiletVip::setNumarTelefon(string numarTelefon) {
	if (numarTelefon.size() == 10)
		this->numarTelefon = numarTelefon;
}

string BiletVip::AflaNumarTelefon(int id) {
	if (id > 0) {
		if (this->id == id)
		{
			return this->numarTelefon;
		}
	}
	else {


		return "Nu ai introdus un ID valid.";
	}
}

char* BiletVip::AflaNumeSpectator(int id) {
	if (id > 0) {
		if (this->id == id)
		{
			if (this->numeSpectator != nullptr) {
				char* copie = new char[strlen(this->numeSpectator) + 1];
				strcpy(copie, this->numeSpectator);
				return copie;
			}
		}
		else
			return nullptr;
	}
	else return nullptr;
}

BiletVip& BiletVip:: operator=(const BiletVip& t) {
	this->rand = t.rand;
	this->loc = t.loc;
	this->id = t.id;
	this->numeSpectator = new char[strlen(t.numeSpectator) + 1];
	strcpy(this->numeSpectator, t.numeSpectator);
	this->statusLoc = t.statusLoc;
	this->numarTelefon = t.numarTelefon;

	return *this;
}

BiletVip& BiletVip::operator++() {
	nrBilete++;
	return *this;
}
BiletVip& BiletVip::operator++(int x) {
	BiletVip copie = *this;
	nrBilete++;
	return copie;
}

//Operator !
bool BiletVip::operator!() {
	if (this->id > this->nrBilete) {
		return 0;
	}
	else return 1;
}

ostream& operator<<(ostream& out, const BiletVip t) {
	out << "------------DETALII BILET-------------" << endl;
	out << "ID: " << t.id << endl << "\t Nume spectator: " << t.numeSpectator << endl;
	out << "\t Rand: " << t.rand << "\tLoc: " << t.loc << endl;
	out << "\t Numar de telefon: " << t.numarTelefon;
	return out;
}
istream& operator>>(istream& in, BiletVip& t) {
	cout << "------------CONFIGURARE BILET-------------" << endl;
	t.statusLoc = true;
	t.nrBilete++;
	t.id = t.nrBilete;

	cout << "Nume spectator: " << endl;
	char buffer[255];
	//in.ignore();
	in.getline(buffer, 50);
	if (t.numeSpectator != nullptr) {
		delete[]t.numeSpectator;
		t.numeSpectator = nullptr;
	}
	if (strlen(buffer) > 2) {
		t.numeSpectator = new char[strlen(buffer) + 1];
		strcpy(t.numeSpectator, buffer);
	}
	cout << "Rand: " << endl;
	in >> t.rand;
	cout << "Loc: " << endl;
	in >> t.loc;
	cout << "Numar telefon: " << endl;
	in >> t.numarTelefon;


	return in;
}
