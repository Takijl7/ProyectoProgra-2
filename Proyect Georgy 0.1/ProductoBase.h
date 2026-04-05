#pragma once
#include "IProducto.h"

class ProductoBase : public IProducto 
{
protected:
	std::string nombre;
	double precioBase;
	std::string descripcion;
	std::string categoria;

public:
	ProductoBase(const std::string& nombre, double precioBase, const std::string& descripcion, const std::string& categoria);

	std::string getNombre() const override;
	double getPrecioBase() const override;
	double getCosto() const override;
	std::string getDescripcion() const override;
	std::string getCategoria() const override;

	std::vector<shared_ptr<Ingrediente>> getIngredientes() const override;
	std::vector<shared_ptr<Ingrediente>> getExtras() const override;
	std::vector<string> getQuitados() const override;

	void agregarIngrediente(const Ingrediente& ing);
	void quitarIngrediente(const string& nombre);
};
