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
	vector<shared_ptr<Ingrediente>> extras;
	vector<string> quitados;

public:
	ProductoBase(const string& nombre, double precioBase, const string& descripcion, const char tam);

	string getNombre() const override;
	double getCosto() const override;
	string getDescripcion() const override;
	char getTamano() const override;

	//Implementación de IProductoIngredientes
	vector<shared_ptr<Ingrediente>> getIngredientes() const ;
	vector<shared_ptr<Ingrediente>> getExtras() const ;
	vector<string> getQuitados() const ;

	//Métodos para gestionar ingredientes
	void setIngrediente(const Ingrediente& victor) ;
	void quitarIngrediente(const string& nombre) ;
	void agregarIngredientes(const vector<Ingrediente>& victor);

	//Metodos para archivos, desarrollar en los hijos
	virtual void escribirBinario(std::ofstream& os) const = 0;
	virtual void leerBinario(std::ifstream& is) = 0;
};
