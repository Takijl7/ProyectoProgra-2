#pragma once
#include <fstream>
#include "IProducto.h"
#include "Ingrediente.h"


class ProductoBase : public IProducto
{
protected:
	string nombre;
	double precioBase;
	string descripcion;
	char tamano;
	vector<shared_ptr<Ingrediente>> ingrediente;
	vector<string> quitados;

public:
	ProductoBase(const string& nombre, double precioBase, const string& descripcion, const char tam);

	string getNombre() const override;
	double getCosto() const override;
	string getDescripcion() const override;
	char getTamano() const override;
	void setIngrediente(const Ingrediente& victor);
	void quitarIngrediente(shared_ptr<Ingrediente>);
	void agregarIngredientes(const vector<Ingrediente>& vIngredientes);

	const vector<shared_ptr<Ingrediente>>& getIngredientes() const;
	const vector<string> getQuitados() const;
	virtual void escribirBinario(std::ofstream& os) const = 0;
	virtual void leerBinario(std::ifstream& is) = 0;
};
