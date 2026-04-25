#include "Ingrediente.h"

Ingrediente::Ingrediente(const string& nombre, double extra) : nombre(nombre), extra(extra) {}

string Ingrediente::getNombre() const { return nombre; }
double Ingrediente::getExtra() const { return extra; }

