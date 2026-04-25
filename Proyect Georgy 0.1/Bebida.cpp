#include "Bebida.h"
#include <fstream>

Bebida::Bebida(string nom, double precio, string desc, char tam, TipoBebida t)
    : ProductoBase(nom, precio, desc, tam), tipo(t) {}

TipoBebida Bebida::getTipo() const {
    return tipo;
}