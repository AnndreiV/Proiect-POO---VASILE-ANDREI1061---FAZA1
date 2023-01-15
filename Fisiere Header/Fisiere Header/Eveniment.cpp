#include "Eveniment.h"
#pragma warning(disable:4996)
int Eveniment::nrFilm = 0;

Eveniment::Eveniment():nrMaximLocuri(100) 
{
	this->denumireFilm = new char[strlen("Necunoscut") + 1];
	strcpy(this->denumireFilm, "Necunoscut");
	this->data = new char[strlen("Data necunoscuta") + 1];
	strcpy(this->data, "Data necunoscuta");
	this->ora = new char[strlen("Ora necunoscuta") + 1];
	strcpy(this->ora, "Ora necunoscuta");
	this->nrRanduriBiletStandard = 0;
	this->nrLocuriBiletStandard = 0;
	this->nrRanduriBiletVIP = 0;
	this->nrLocuriBiletVIP = 0;

}

Eveniment::Eveniment(const char* denumireFilm, const char* data, const char* ora, int nrRanduriBiletStandard, int nrLocuriBiletStandard, int nrRanduriBiletVIP, int nrLocuriBiletVIP, int nrMaximLocuri) :nrMaximLocuri(nrMaximLocuri)
{
	nrFilm++;
	this->denumireFilm = new char[strlen(denumireFilm) + 1];
	strcpy(this->denumireFilm, denumireFilm);
	this->data = new char[strlen(data) + 1];
	strcpy(this->data, data);
	this->ora = new char[strlen(ora) + 1];
	strcpy(this->ora, ora);
	this->nrRanduriBiletStandard = nrRanduriBiletStandard;
	this->nrLocuriBiletStandard = nrLocuriBiletStandard;
	this->nrRanduriBiletVIP = nrRanduriBiletVIP;
	this->nrLocuriBiletVIP = nrLocuriBiletVIP;

}

Eveniment::Eveniment(const Eveniment& t) :nrMaximLocuri(t.nrMaximLocuri)
{
	nrFilm++;
	if (t.denumireFilm != nullptr) {
		this->denumireFilm = new char[strlen(t.denumireFilm) + 1];
		strcpy(this->denumireFilm, t.denumireFilm);
	}
	if (t.data != nullptr) {
		this->data = new char[strlen(t.data) + 1];
		strcpy(this->data, t.data);
	}
	if (t.ora != nullptr) {
		this->ora = new char[strlen(t.ora) + 1];
		strcpy(this->ora, t.ora);
	}
	this->nrRanduriBiletStandard = t.nrRanduriBiletStandard;
	this->nrLocuriBiletStandard = t.nrLocuriBiletStandard;
	this->nrRanduriBiletVIP = t.nrRanduriBiletVIP;
	this->nrLocuriBiletVIP = t.nrLocuriBiletVIP;

}
Eveniment& Eveniment::operator=(const Eveniment& t) {
	if (this != &t) {
		nrFilm++;
		if (this->denumireFilm != NULL) {
			delete[]this->denumireFilm;
			this->denumireFilm = nullptr;
		}
		if (this->data != NULL) {
			delete[]this->data;
			this->data = nullptr;
		}
		if (this->ora != NULL) {
			delete[]this->ora;
			this->ora = nullptr;
		}

		this->denumireFilm = new char[strlen(t.denumireFilm) + 1];
		strcpy(this->denumireFilm, t.denumireFilm);
		this->data = new char[strlen(t.data) + 1];
		strcpy(this->data, t.data);
		this->ora = new char[strlen(t.ora) + 1];
		strcpy(this->ora, t.ora);
		this->nrRanduriBiletStandard = t.nrRanduriBiletStandard;
		this->nrLocuriBiletStandard = t.nrLocuriBiletStandard;
		this->nrRanduriBiletVIP = t.nrRanduriBiletVIP;
		this->nrLocuriBiletVIP = t.nrLocuriBiletVIP;
		
	}
	return *this;
}
ostream& operator<<(ostream& out, const Eveniment t) {
	out << "----------DETALII EVENIMENT----------" << endl;
	if (t.denumireFilm != nullptr && t.data != nullptr && t.ora != nullptr)
		out << "Evenimentul " << t.denumireFilm << " va avea loc pe data de  " << t.data << " la ora " << t.ora << "." << endl;
	out << "Numarul locurilor de care dispune sala este " << t.nrMaximLocuri << " organizate pe 2 zone, STANDARD si VIP." << endl;
	out << "Zona standard dispune de " << t.nrRanduriBiletStandard << " randuri care insumeaza " << t.nrLocuriBiletStandard* t.nrRanduriBiletStandard << " locuri." << endl;
	out << "Zona VIP dispune de " << t.nrRanduriBiletVIP << " randuri care insumeaza " << t.nrLocuriBiletVIP* t.nrRanduriBiletVIP << " locuri." << endl;

	return out;
}

istream& operator>>(istream& in, Eveniment& t) {
	char buffer1[99];
	char buffer2[99];
	char buffer3[99];
	cout << "Introduceti numele evenimentului:" << endl;
	//in >> buffer1;
	//in.getline(buffer1, 99);
	//in.ignore();
	in.getline(buffer1, 99);
	cout << "Introduceti data evenimentului sub formatul zz/ll/aaaa:";
	in >> buffer2;
	cout << "Introduceti ora evenimentului:" << endl;
	in >> buffer3;
	cout << "Numarul maxim de locuri este: " << t.nrMaximLocuri << endl;
	cout << "Introduceti numarul de randuri alocate biletelor standard: ";
	in >> t.nrRanduriBiletStandard;
	cout << "Introduceti numarul de locuri pe rand pentru biletele standard: ";
	in >> t.nrLocuriBiletStandard;
	cout << "Introduceti numarul de randuri alocate biletelor VIP: ";
	in >> t.nrRanduriBiletVIP;
	cout << "Introduceti numarul de locuri pe rand pentru biletele VIP: ";
	int numarLocuriVip = 0;
	in >> numarLocuriVip;
	if (numarLocuriVip + t.nrLocuriBiletStandard > t.nrMaximLocuri) {
		cout << "Ai depasit numarul maxim de locuri! S-au alocat toate biletele ramase libere zonei VIP" << endl;
		t.nrLocuriBiletVIP = t.nrMaximLocuri - t.nrLocuriBiletStandard;
	}
	else {
		t.nrLocuriBiletVIP = numarLocuriVip;
	}

	if (t.denumireFilm != NULL) {
		delete[]t.denumireFilm;
		t.denumireFilm = nullptr;
	}

	if (strlen(buffer1) > 1)
	{
		t.denumireFilm = new char[strlen(buffer1) + 1];
		strcpy(t.denumireFilm, buffer1);
	}
	else
	{
		t.denumireFilm = new char[strlen("Necunoscut") + 1];
		strcpy(t.denumireFilm, "Necunoscut");
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

char* Eveniment::getDenumireFilm() {
	char* copie = new char[strlen(this->denumireFilm) + 1];
	strcpy(copie, this->denumireFilm);
	return copie;
}
void Eveniment::setDenumireFilm(const char* denumireFilm) {
	if (this->denumireFilm != nullptr) {
		delete[]this->denumireFilm;
		this->denumireFilm = nullptr;
	}
	if (strlen(denumireFilm) > 0) {
		this->denumireFilm = new char[strlen(denumireFilm) + 1];
		strcpy(this->denumireFilm, denumireFilm);
	}
}

char* Eveniment::getData() {
	char* copie = new char[strlen(this->data) + 1];
	strcpy(copie, this->data);
	return copie;
}
void Eveniment::setData(const char* data) {
	if (this->data != nullptr) {
		delete[]this->data;
		this->data = nullptr;
	}
	if (strlen(data) > 0) {
		this->data = new char[strlen(data) + 1];
		strcpy(this->data, data);
	}
}

char* Eveniment::getOra() {
	char* copie = new char[strlen(this->ora) + 1];
	strcpy(copie, this->ora);
	return copie;
}
void Eveniment::setOra(const char* ora) {
	if (this->ora != nullptr) {
		delete[]this->ora;
		this->ora = nullptr;
	}
	if (strlen(ora) > 0) {
		this->ora = new char[strlen(ora) + 1];
		strcpy(this->ora, ora);
	}
}
int Eveniment:: getNrRanduriBiletStandard() {
	return this->nrRanduriBiletStandard;
}
void Eveniment::setNrRanduriBiletStandard(int nrRanduriBiletStandard) {
	if (nrRanduriBiletStandard > 0)
		this->nrRanduriBiletStandard = nrRanduriBiletStandard;
}

int Eveniment:: getNrRanduriBiletVIP() {
	return this->nrRanduriBiletVIP;
}
void Eveniment::setNrRanduriBiletVIP(int nrRanduriBiletVIP) {
	if (nrRanduriBiletVIP > 0)
		this->nrRanduriBiletVIP = nrRanduriBiletVIP;
}

int Eveniment::getNrLocuriBiletStandard() {
	return this->nrLocuriBiletStandard;
}
void Eveniment::setNrLocuriBiletStandard(int nrLocuriBiletStandard) {
	if (nrLocuriBiletStandard > 0) {
		this->nrLocuriBiletStandard = nrLocuriBiletStandard;
	}
}
int Eveniment::getNrLocuriBiletVIP() {
	return this->nrLocuriBiletVIP;
}
void Eveniment::setNrLocuriBiletVIP(int nrLocuriBiletVIP) {
	if (nrLocuriBiletVIP > 0) {
		this->nrLocuriBiletVIP = nrLocuriBiletVIP;
	}
}
int Eveniment::getNrMaximLocuri() {
	return this->nrMaximLocuri;

}
//Operatori
string Eveniment::operator>(const Eveniment& t) {
	if (this->nrRanduriBiletStandard > t.nrRanduriBiletStandard && this->nrLocuriBiletStandard > t.nrLocuriBiletVIP) {
		return "Primul eveniment are o capacitate mai mare!";
	}
	else 
		if (this->nrRanduriBiletStandard == t.nrRanduriBiletStandard && this->nrLocuriBiletStandard == t.nrLocuriBiletVIP)
		return "Evenimentele au o capacitate egala";
	else
		return "Al doilea eveniment are o capacitate mai mare!";
}
bool Eveniment::operator>=(const Eveniment& t)
{
	if (this->nrRanduriBiletStandard >= t.nrRanduriBiletStandard && this->nrLocuriBiletStandard >= t.nrLocuriBiletVIP) {
		return true;
	}
	else
		return false;
}

int Eveniment::nrTotalLocuri() {
	return nrRanduriBiletStandard * nrLocuriBiletStandard + nrRanduriBiletVIP * nrLocuriBiletVIP;
}


Eveniment::~Eveniment() {
	if (this->denumireFilm != nullptr) {
		delete[]this->denumireFilm;
		this->denumireFilm = nullptr;
	}
	if (this->data != nullptr) {
		delete[]this->data;
		this->data = nullptr;
	}
	if (this->ora != nullptr) {
		delete[]this->ora;
		this->ora = nullptr;
	}
}
