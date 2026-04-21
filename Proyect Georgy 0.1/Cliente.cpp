#include "Cliente.h"
using namespace std;

Cliente::Cliente(string n) : nombre(n) {}

const string Cliente::getNombre() const {
	return nombre;
}