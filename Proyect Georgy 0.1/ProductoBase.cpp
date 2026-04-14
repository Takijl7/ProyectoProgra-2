#include "ProductoBase.h"

ProductoBase::ProductoBase(const string& nombre, double precioBase, const string& descripcion, const string& categoria)
	: nombre(nombre), precioBase(precioBase), descripcion(descripcion), categoria(categoria) {}

string ProductoBase::getNombre() const { return nombre; }
double ProductoBase::getPrecioBase() const { return precioBase; }
double ProductoBase::getCosto() const { return precioBase; }
string ProductoBase::getDescripcion() const { return descripcion; }
string ProductoBase::getCategoria() const { return categoria; }

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
	for (const auto& nig : ingrediente)
	{
		if (*nig == victor)
		{
			return; 
		}
	}
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
