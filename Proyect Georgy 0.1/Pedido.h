#pragma once
#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include "IProducto.h"
#include "Cliente.h"
#include "IEstrategiaPago.h"
#include "EstrategiaCalculo.h"
#include "AppException.h"

class Pedido {
private:
	unsigned int codigo;
	static unsigned int generador_c;
	vector<shared_ptr<IProducto>> productos;
	shared_ptr<Cliente> cliente;
	shared_ptr<IEstrategiaPago> mpago;
	shared_ptr<EstrategiaCalculo> ecalculo;
public:
	Pedido(shared_ptr<Cliente>);

	void setMetodoPago(shared_ptr<IEstrategiaPago>);
	const string mostrarProductos() const;
	const string realizarPago(double);
	void agregaProducto(shared_ptr<IProducto>);

	const vector<shared_ptr<IProducto>>& getProductos() const;
	void limpiarProductos();
};