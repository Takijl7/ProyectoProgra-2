#pragma once
#include "ProductoDecorador.h"
#include "Ingrediente.h"

using namespace std;

class DecoratorSinSal : public ProductoDecorator
{
private:
	std::shared_ptr<Ingrediente> ingrediente;
public:
	DecoratorSinSal(shared_ptr<IProducto> p, shared_ptr<Ingrediente> i) : ProductoDecorator(p) , ingrediente(i){}

	double getCosto() const 
	{ 
		double costoBase = producto->getCosto() - ingrediente->getExtra();
	}
};