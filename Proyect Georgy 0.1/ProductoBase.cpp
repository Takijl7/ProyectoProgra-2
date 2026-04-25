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

vector<shared_ptr<Ingrediente>> ProductoBase::getIngredientes() const { return ingrediente; }
vector<shared_ptr<Ingrediente>> ProductoBase::getExtras() const { return extras; }
vector<string> ProductoBase::getQuitados() const { return quitados; }

void ProductoBase::agregarIngredientes(const vector<Ingrediente>& victor) 
{
	ingrediente.clear();

	for (const auto& nig : victor) 
	{
		ingrediente.push_back(make_shared<Ingrediente>(nig));
	}
}

void ProductoBase::setIngrediente(const Ingrediente& victor) 
{
	ingrediente.push_back(make_shared<Ingrediente>(victor));
}

void ProductoBase::quitarIngrediente(const string& nombre) 
{
	for (size_t i = 0; i < ingrediente.size(); ++i) 
	{
		if (ingrediente[i]->getNombre() == nombre) 
		{
			ingrediente.erase(ingrediente.begin() + i);
			quitados.push_back(nombre);
			return;
		}
	}
}

void ProductoBase::escribirBinario(std::ofstream& os) const {
	 
}
void ProductoBase::leerBinario(std::ifstream& is) {

}