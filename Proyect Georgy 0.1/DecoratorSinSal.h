#pragma once
#include "ProductoDecorador.h"
#include "Ingrediente.h"

//Aunque diga extra sal, este decorador sirve para quitar todo tipo de ingrediente

using namespace std;

class DecoratorSinSal : public ProductoDecorator
{
private:
	std::shared_ptr<Ingrediente> ingrediente;
public:
	DecoratorSinSal(shared_ptr<IProducto> p, shared_ptr<Ingrediente> i) : ProductoDecorator(p) , ingrediente(i){}

	double getCosto() const 
	{ 
		return producto->getCosto() - ingrediente->getExtra();
	}

	string getNombre() const override
	{
		return producto->getNombre() + " Sin " + ingrediente->getNombre();
	}

	std::shared_ptr<Ingrediente> getIngrediente() const { return ingrediente; }
};