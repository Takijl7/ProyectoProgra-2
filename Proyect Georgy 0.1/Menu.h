#pragma once
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include "IProducto.h"
class Menu
{
private:
	std::vector<std::shared_ptr<IProducto>> productos;
public:
	void agregarProducto(std::shared_ptr<IProducto> p);
	const string mostrarProductos() const;

	//Metodos para los archivos
	const vector<shared_ptr<IProducto>>& getProductos() const;
	void limpiarProductos();
};
