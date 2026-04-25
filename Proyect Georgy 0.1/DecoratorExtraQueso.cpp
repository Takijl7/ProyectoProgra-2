#include "DecoratorExtraQueso.h"
using namespace std;

DecoratorExtraQueso::DecoratorExtraQueso(std::shared_ptr<IProducto> p) :ProductoDecorator(p) {}

double DecoratorExtraQueso::getCosto() const {
	Ingrediente ing("Queso-Extra", 600);
	producto->setIngrediente(ing);
	return producto->getCosto() + 600;
}