c#pragma once
#include "IProducto.h"
#include "IProductoIngredientes.h"

class ProductoBase : public IProducto, public IProductoIngredientes
{
protected:
	string nombre;
	double precioBase;
	string descripcion;
	string categoria;

	vector<shared_ptr<Ingrediente>> ingrediente;
	vector<shared_ptr<Ingrediente>> extras;
	vector<string> quitados;
public:
	ProductoBase(const string& nombre, double precioBase, const string& descripcion, const string& categoria);

	string getNombre() const override;
	double getPrecioBase() const override;
	double getCosto() const override;
	string getDescripcion() const override;
	string getCategoria() const override;

	//Implementación de IProductoIngredientes
	vector<shared_ptr<Ingrediente>> getIngredientes() const override;
	vector<shared_ptr<Ingrediente>> getExtras() const override;
	vector<string> getQuitados() const override;

	//Métodos para gestionar ingredientes
	void setIngrediente(const Ingrediente& victor) override;
	void quitarIngrediente(const string& nombre) override;
	void agregarIngredientes(const vector<Ingrediente>& victor);

	//Metodos para archivos, desarrollar en los hijos
	virtual void escribirBinario(std::ofstream& os) const = 0;
	virtual void leerBinario(std::ifstream& is) = 0;
};
