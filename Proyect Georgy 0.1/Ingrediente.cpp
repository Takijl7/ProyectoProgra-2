#include "Ingrediente.h"

Ingrediente::Ingrediente(string& nombre, double extra) : nombre(nombre), extra(extra) {}

string Ingrediente::getNombre() const { return nombre; }
double Ingrediente::getExtra() const { return extra; }

bool Ingrediente::operator == (const Ingrediente& otro) const {
	return nombre == otro.nombre;
}