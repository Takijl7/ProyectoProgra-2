#pragma once
#include "ProductoDecorador.h"
#include <memory>
#include <cctype>

//Decorador de tamano 

class DecoratorCambiarTamano : public ProductoDecorator
{
private:
	char tamano;
public:
	DecoratorCambiarTamano(std::shared_ptr<IProducto> p, char t) : ProductoDecorator(p) { tamano = (char)toupper(t); }

	char getTamano() const override { return tamano; }

	double getCosto() const override
	{
		if (tamano == 'G') return producto->getCosto() * 1.10;
		if (tamano == 'P') return producto->getCosto() * 0.85;
		return producto->getCosto();
	}
	string getNombre() const override
	{
		string t = (tamano == 'G') ? "Grande" : (tamano == 'P' ? "Pequeño" : "Normal");
		return producto->getNombre() + " " + t;
	}
};