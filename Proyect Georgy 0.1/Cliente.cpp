#include "Cliente.h"
using namespace std;

Cliente::Cliente(string n) : nombre(n) , cantP(0) {}

const string Cliente::getNombre() const {
	return nombre;
}

const int Cliente::getCantP() const {
	return cantP;
}

void Cliente::setCantP(int p) {
	cantP = p;
}