#include "ProductoDecorador.h"

ProductoDecorator::ProductoDecorador(std::shared_ptr<IProducto> p) : producto(p){}

string ProductoDecorator::getNombre() const {
	return producto->getNombre();
}