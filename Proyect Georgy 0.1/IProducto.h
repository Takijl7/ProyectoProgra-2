#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Ingredientes.h"
using namespace std;
// PRINCIPIO DE SEGREGACIÓN DE INTERFAZ (ISP):
// Creamos contratos pequeños (IEntidad, IProductor) en lugar de uno gigante.
// SOLID (I): Las clases no deben ser forzadas a implementar métodos que no usan.
class IProducto 
{
public:
    virtual ~IProducto() = default;

    virtual string getNombre()      const = 0;
    virtual double getPrecioBase()  const = 0;
    virtual double getCosto() const = 0;
    virtual string getDescripcion() const = 0;
    virtual string getCategoria()   const = 0;

    virtual vector<Ingrediente> getIngredientes() const = 0;
    virtual vector<Ingrediente> getExtras()       const = 0;
    virtual vector<string> getQuitados()     const = 0;
};

