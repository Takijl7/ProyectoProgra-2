#include "DecoratorExtraQueso.h"
using namespace std;

DecoratorExtraQueso::DecoratorExtraQueso(shared_ptr<IProducto> p) :producto(p) {}

double DecoratorExtraQueso::getCosto() const {
	Ingrediente ing("Queso-Extra", 600);
	producto->setIngrediente(ing);
	return producto->getCosto() + 600;
}