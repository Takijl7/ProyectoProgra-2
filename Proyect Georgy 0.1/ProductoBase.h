#pragma once
#include "IProducto.h"


class ProductoBase : public IProducto 
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

	vector<shared_ptr<Ingrediente>> getIngredientes() const override;
	vector<shared_ptr<Ingrediente>> getExtras() const override;
	vector<string> getQuitados() const override;

	void setIngrediente(const Ingrediente& victor) override;
	void quitarIngrediente(const string& nombre) override;

	void agregarIngredientes(const vector<Ingrediente>& victor);
};


//AGREGAR NO ES LO MISMO QUE SETEAR, SET ES PAA
