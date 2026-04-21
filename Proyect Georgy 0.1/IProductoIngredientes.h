#pragma once
#include <vector>
#include <memory>
#include "Ingrediente.h"

class IProductoIngredientes
{
public:
	virtual vector<shared_ptr<Ingrediente>> getIngredientes() const = 0;
	virtual vector<shared_ptr<Ingrediente>> getExtras() const = 0;
	virtual vector<string> getQuitados() const = 0;

	virtual void setIngrediente(const Ingrediente& ing) = 0;
	virtual void quitarIngrediente(const string& nombre) = 0;
};

//Implemnta el PRINCIPIO DE SEGREGACION DE INTERFAZ (ISP)
//Esto permite que las clases que no necesitan gestionar ingredientes no estén obligadas a implementar métodos relacionados con ellos, 
