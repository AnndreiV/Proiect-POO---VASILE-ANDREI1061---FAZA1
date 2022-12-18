#include "BiletStandard.h"
#pragma warning(disable:4996)
int BiletStandard::nrBilete = 0;
BiletStandard::BiletStandard() {

	this->id = nrBilete;
	this->rand = "0";
	this->loc = "0";
	this->numeSpectator = new char[strlen("Necunoscut") + 1];
	strcpy(this->numeSpectator, "Necunoscut");
	this->statusLoc = false;
	this->numarTelefon = "Numar necunoscut";
}

BiletStandard::BiletStandard(const char* numeSpectator, string numarTelefon, string rand, string loc) {
	nrBilete++;
	this->rand = rand;
	this->loc = loc;
	this->id = nrBilete;
	this->numeSpectator = new char[strlen(numeSpectator) + 1];
	strcpy(this->numeSpectator, numeSpectator);
	this->statusLoc = true;
	this->numarTelefon = numarTelefon;
}

BiletStandard::BiletStandard(const BiletStandard& t) {
	nrBilete++;
	this->id = nrBilete;
	this->rand = t.rand;
	this->loc = t.loc;
	this->numeSpectator = new char[strlen(t.numeSpectator) + 1];
	strcpy(this->numeSpectator, t.numeSpectator);
	this->statusLoc = t.statusLoc;
	this->numarTelefon = t.numarTelefon;
}

BiletStandard::~BiletStandard() {
	if (this->numeSpectator != nullptr) {
		delete[]this->numeSpectator;
		this->numeSpectator = nullptr;
	}
}

string BiletStandard::getRand() {
	return this->rand;
}
string BiletStandard::getLoc() {
	return this->loc;
}
void  BiletStandard::setRand(string rand) {
	if (rand != "0") {
		this->rand = rand;
	}
}
void BiletStandard::setLoc(string loc) {
	if (loc != "0") {
		this->loc = loc;
	}
}

int BiletStandard::getId() {
	return this->id;
}
void BiletStandard::setId(int id) {
	if (id > 0)
		this->id = id;
}
char* BiletStandard::getNumeSpectator() {
	if (this->numeSpectator != nullptr) {
		char* copie = new char[strlen(this->numeSpectator) + 1];
		strcpy(copie, this->numeSpectator);
		return copie;
	}
	else return nullptr;
}
void BiletStandard::setNumeSpectator(const char* numeSpectator) {
	if (numeSpectator != nullptr) {
		if (this->numeSpectator != nullptr) {
			delete[]this->numeSpectator;
			this->numeSpectator = nullptr;
		}
		this->numeSpectator = new char[strlen(numeSpectator) + 1];
		strcpy(this->numeSpectator, numeSpectator);
	}
}

bool BiletStandard::getStatusLoc() {
	return this->statusLoc;
}
void BiletStandard::setStatusLoc(bool statusLoc) {
	this->statusLoc = statusLoc;
}
 int BiletStandard::getNrBilete() //aici nu a mers sa folosesc static int
 {
	return nrBilete;
}
string BiletStandard::getNumarTelefon() {
	return this->numarTelefon;
}
void BiletStandard::setNumarTelefon(string numarTelefon) {
	if (numarTelefon.size() == 10)
		this->numarTelefon = numarTelefon;
}

string BiletStandard::AflaNumarTelefon(int id) {
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

char* BiletStandard::AflaNumeSpectator(int id) {
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

BiletStandard&BiletStandard:: operator=(const BiletStandard& t) {
	this->rand = t.rand;
	this->loc = t.loc;
	this->id = t.id;
	this->numeSpectator = new char[strlen(t.numeSpectator) + 1];
	strcpy(this->numeSpectator, t.numeSpectator);
	this->statusLoc = t.statusLoc;
	this->numarTelefon = t.numarTelefon;

	return *this;
}

BiletStandard& BiletStandard::operator++() {
	nrBilete++;
	return *this;
}
BiletStandard& BiletStandard::operator++(int x) {
	BiletStandard copie = *this;
	nrBilete++;
	return copie;
}
//Operator !
bool BiletStandard::operator!() {
	if (this->id > this->nrBilete) {
		return 0;
	}
	else return 1;
}

ostream& operator<<(ostream& out, const BiletStandard t) {
	out << "------------DETALII BILET-------------" << endl;
	out << "ID: " << t.id << endl << "\t Nume spectator: " << t.numeSpectator << endl;
	out << "\t Rand: " << t.rand << "\tLoc: " << t.loc << endl;
	out << "\t Numar de telefon: " << t.numarTelefon;
	return out;
}
istream& operator>>(istream& in, BiletStandard& t) {
	cout << "------------CONFIGURARE BILET-------------" << endl;
	t.statusLoc = true;
	t.nrBilete++;
	t.id = t.nrBilete;

	cout << "Nume spectator: " << endl;
	char buffer[255];
	in.ignore();
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
