#include "Bebida.h"
#include <fstream>

Bebida::Bebida(string nom, double precio, string desc, char tam, TipoBebida t)
    : ProductoBase(nom, precio, desc, tam), tipo(t) {}

TipoBebida Bebida::getTipo() const {
    return tipo;
}

void Bebida::escribirBinario(std::ofstream& os) const {
    int tipoP = 1;
    os.write(reinterpret_cast<const char*>(&tipoP), sizeof(tipoP));

    size_t tamNombre = nombre.size();
    os.write(reinterpret_cast<const char*>(&tamNombre), sizeof(tamNombre));
    os.write(nombre.c_str(), tamNombre);

    os.write(reinterpret_cast<const char*>(&precioBase), sizeof(precioBase));

    size_t tamDescrp = descripcion.size();
    os.write(reinterpret_cast<const char*>(&tamDescrp), sizeof(tamDescrp));
    os.write(descripcion.c_str(), tamDescrp);

    os.write(&tamano, sizeof(tamano));

    int tipoInt = static_cast<int>(tipo);
    os.write(reinterpret_cast<const char*>(&tipoInt), sizeof(tipoInt));

}
void Bebida::leerBinario(std::ifstream& is) {
    size_t tam;
    is.read(reinterpret_cast<char*>(&tam), sizeof(tam));

    nombre.resize(tam);
    is.read(&nombre[0], tam);

    is.read(reinterpret_cast<char*>(&precioBase), sizeof(precioBase));

    size_t tamD;
    is.read(reinterpret_cast<char*>(&tamD), sizeof(tamD));

    descripcion.resize(tamD);
    is.read(&descripcion[0], tamD);

    is.read(&tamano, sizeof(tamano));

    int tipoInt;
    is.read(reinterpret_cast<char*>(&tipoInt), sizeof(tipoInt));

    tipo = static_cast<TipoBebida>(tipoInt);
}