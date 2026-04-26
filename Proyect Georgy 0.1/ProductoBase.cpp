#include "ProductoBase.h"
#include "DecoratorExtraQueso.h"
#include "DecoratorCambiarTamano.h"
#include "DecoratorSinSal.h"

ProductoBase::ProductoBase(const string& nom, double base, const string& descrip, const char tam)
	: nombre(nom), precioBase(base), descripcion(descrip) , tamano(tam){}

string ProductoBase::getNombre() const { return nombre; }
double ProductoBase::getCosto() const { return precioBase; }
string ProductoBase::getDescripcion() const { return descripcion; }
char ProductoBase::getTamano() const { return tamano; }

void ProductoBase::setIngrediente(const Ingrediente& victor) {
	ingrediente.push_back(make_shared<Ingrediente>(victor));
}
void ProductoBase::quitarIngrediente(shared_ptr<Ingrediente> ingre) {
	if (!ingre) return;
	quitados.push_back(ingre->getNombre());
	ingrediente.erase(
		std::remove_if(ingrediente.begin(), ingrediente.end(),
			[&](shared_ptr<Ingrediente> p) { return p->getNombre() == ingre->getNombre(); }),
		ingrediente.end()
	);
}
void ProductoBase::agregarIngredientes(const vector<Ingrediente>& vIngredientes) {
	for (const auto& ing : vIngredientes) {
		this->setIngrediente(ing);
	}
}
const vector<shared_ptr<Ingrediente>>& ProductoBase::getIngredientes() const {
	return ingrediente;
}
const vector<string> ProductoBase::getQuitados() const {
	return quitados;
}