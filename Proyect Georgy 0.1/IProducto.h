#pragma once
#ifndef IPRODUCTO_H
#define IPRODUCTO_H

#include <string>
#include <vector>
#include <memory>

using namespace std;
// PRINCIPIO DE SEGREGACIÓN DE INTERFAZ (ISP):
// Creamos contratos pequeños (IEntidad, IProductor) en lugar de uno gigante.
// SOLID (I): Las clases no deben ser forzadas a implementar métodos que no usan.

class IProducto
{
public:
    virtual ~IProducto() = default;
    virtual string getNombre() const = 0;
    virtual double getCosto() const = 0;
    virtual string getDescripcion() const = 0;
    virtual char getTamano() const = 0;
};
#endif