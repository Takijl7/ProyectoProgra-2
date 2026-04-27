#pragma once
#include "ProductoDecorador.h"
#include "ingrediente.h"
#include <memory>

class DecoratorExtraQueso : public ProductoDecorator 
{
private:
	std::shared_ptr<Ingrediente> ingrediente;
public:
	DecoratorExtraQueso(std::shared_ptr<IProducto> p) : ProductoDecorator(p) , ingrediente(make_shared<Ingrediente>("Queso", 300)) {}

	double getCosto() const override
	{
		return producto->getCosto() + ingrediente->getExtra();
	}

	string getNombre() const override
	{
		return producto->getNombre() + " " + "Extra de " + ingrediente->getNombre();
	}
};