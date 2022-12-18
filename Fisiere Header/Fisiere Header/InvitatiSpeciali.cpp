#include "InvitatiSpeciali.h"
#pragma warning(disable:4996)
InvitatiSpeciali::InvitatiSpeciali() {
	this->nume = "Inexistent";
	this->varsta = 0;
	this->dimVector = 0;
	this->noteRecenzii = nullptr;
	this->oreAcoperite = 0;
}
InvitatiSpeciali::InvitatiSpeciali(string nume, int varsta, int* noteRecenzii, int dimVector, float oreAcoperite)
{
	this->nume = nume;
	this->varsta = varsta;
	this->dimVector = dimVector;
	this->noteRecenzii = new int[dimVector];
	for (int i = 0; i < dimVector; i++) {
		this->noteRecenzii[i] = noteRecenzii[i];
	}
	this->oreAcoperite = oreAcoperite;
}
InvitatiSpeciali::InvitatiSpeciali(string nume, int varsta, float oreAcoperite) {
	this->nume = nume;
	this->varsta = varsta;
	this->oreAcoperite = oreAcoperite;
}
InvitatiSpeciali::InvitatiSpeciali(const InvitatiSpeciali& t)
{
	this->nume = t.nume;
	this->varsta = t.varsta;
	this->dimVector = t.dimVector;
	this->noteRecenzii = new int[t.dimVector];
	for (int i = 0; i < t.dimVector; i++) {
		this->noteRecenzii[i] = t.noteRecenzii[i];
	}
	this->oreAcoperite = t.oreAcoperite;
}
InvitatiSpeciali::~InvitatiSpeciali()
{
	if (this->noteRecenzii != nullptr) {
		delete[]this->noteRecenzii;
		this->noteRecenzii = nullptr;
	}

}

string InvitatiSpeciali::getNume() {
	return this->nume;
}
int InvitatiSpeciali::getVarsta() {
	return this->varsta;
}
int InvitatiSpeciali::getDimVector() {
	return this->dimVector;
}
int* InvitatiSpeciali::getNoteRecenzii() {
	if (this->noteRecenzii != nullptr) {
		int* copie = new int[this->dimVector];
		for (int i = 0; i < this->dimVector; i++) {
			copie[i] = this->noteRecenzii[i];
		}
		return copie;
	}
	else
		return nullptr;
}
float InvitatiSpeciali::getOreAcoperite() {
	return this->oreAcoperite;
}

void InvitatiSpeciali::setNume(string nume)
{	
	if (nume != "") {
		this->nume = nume;
	}

}
void InvitatiSpeciali::setVarsta(int varsta) {
	if (varsta > 0) {
		this->varsta = varsta;
	}
}
void InvitatiSpeciali::setDimVector(int dimVector) {
	if (dimVector > 0) {
		this->dimVector = dimVector;
	}
}
void InvitatiSpeciali::setNoteRecenzii(int* noteRecenzii, int dimVector) {
	if (noteRecenzii != nullptr&&dimVector>0) {
		if (this->noteRecenzii != nullptr) {
			delete[]this->noteRecenzii;
			this->noteRecenzii = nullptr;
		}
		this->dimVector = dimVector;
		this->noteRecenzii = new int[dimVector];
		for (int i = 0; i < dimVector; i++) {
			this->noteRecenzii[i] = noteRecenzii[i];
		}
		
	}
}
void InvitatiSpeciali::setOreAcoperite(float oreAcoperite) {
	if (oreAcoperite > 0) {
		this->oreAcoperite = oreAcoperite;
	}
}
InvitatiSpeciali& InvitatiSpeciali:: operator=(const InvitatiSpeciali& t) {
	if (this != &t) {
		this->nume = t.nume;
		this->varsta = t.varsta;
		this->oreAcoperite = t.oreAcoperite;
		this->dimVector = t.dimVector;
		if (this->noteRecenzii != nullptr) {
			delete[]this->noteRecenzii;
			this->noteRecenzii = nullptr;
		}
		for (int i = 0; i < t.dimVector; i++) {
			this->noteRecenzii[i] = t.noteRecenzii[i];
		}

	}
	return *this;

}

ostream& operator<<(ostream& out, InvitatiSpeciali t) {
	out << "Numele invitatului de astazi este: " << t.nume << endl;
	out << "Acesta are o varsta de " << t.varsta << " ani si ne este alaturi in seara asta pentru aproximativ " << t.oreAcoperite << " ore!" << endl;
	if (t.dimVector > 0 && t.noteRecenzii != nullptr) {
		out << "Acesta a primit urmatoarele recenzii sub forma de note la evenimentele trecute: " << endl;
		for (int i = 0; i < t.dimVector; i++) {
			out << t.noteRecenzii[i] << " ";
		}
	}
	return out;
}
istream& operator>>(istream& in, InvitatiSpeciali& t) {
	cout << "Introduceti numele invitatului special: " << endl;
	in >> t.nume;
	cout << "Introduceti varsta invitatului special: " << endl;
	in >> t.varsta;
	cout << "Cate ore o sa ne fie alaturi?" << endl;
	in >> t.oreAcoperite;
	cout << "Acesta are recenzii pe care le putem arata publicului?(1/0) " << endl;
	bool x;
	in >> x;
	if (x == 1) {
		cout << "Introduceti numarul de recenzii pe care doriti sa le evidentiati: " << endl;
		in >> t.dimVector;
		cout << "Introduceti recenziile in ordinea dorita: " << endl;
		if (t.noteRecenzii != nullptr) {
			delete[]t.noteRecenzii;
			t.noteRecenzii = nullptr;
		}
		t.noteRecenzii = new int[t.dimVector];
		for (int i = 0; i < t.dimVector; i++) {
			in >> t.noteRecenzii[i];
		}
	}
	else 
		if (x == 0) {
		cout << "La revedere!" << endl;
	}
		else {
			cout << "Nu ai introdus 1 pentru DA sau 0 pentru NU." << endl;
		}
	return in;
}