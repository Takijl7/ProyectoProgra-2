#include "Comida.h"

Comida::Comida(std::string nom, double precio, std::string desc, char tam, bool vegano)
	: ProductoBase(nom, precio, desc, tam), esVegano(vegano) {}


bool Comida::getEsVegano() const { return esVegano; }

string Comida::getDescripcion() const {
    return descripcion + (esVegano ? "(Vegano)" : "");
}

