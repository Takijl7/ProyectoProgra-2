#include "DecoratorSinSal.h"
using namespace std;

DecoratorSinSal::DecoratorSinSal(shared_ptr<IProducto> p) : ProductoDecorator(p) {}

double DecoratorSinSal::getCosto() const {
	return producto->getCosto() + 200.0f;
}