#include "Comida.h"

Comida::Comida(std::string nom, double precio, std::string desc, char tam, bool vegano)
	: ProductoBase(nom, precio, desc, tam), esVegano(vegano) {}


bool Comida::getEsVegano() const { return esVegano; }

string Comida::getDescripcion() const {
    return descripcion + (esVegano ? "(Vegano)" : "");
}

void Comida::escribirBinario(std::ofstream& os) const {
    int tipo = 2;
    os.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));

    size_t tamNombre = nombre.size();
    os.write(reinterpret_cast<const char*>(&tamNombre), sizeof(tamNombre));
    os.write(nombre.c_str(), tamNombre);

    os.write(reinterpret_cast<const char*>(&precioBase), sizeof(precioBase));

    size_t tamDescrp = descripcion.size();
    os.write(reinterpret_cast<const char*>(&tamDescrp), sizeof(tamDescrp));
    os.write(descripcion.c_str(), tamDescrp);

    os.write(&tamano, sizeof(tamano));

    os.write(reinterpret_cast<const char*>(&esVegano), sizeof(esVegano));
}
void Comida::leerBinario(std::ifstream& is) {
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

    is.read(reinterpret_cast<char*>(&esVegano), sizeof(esVegano));
}
