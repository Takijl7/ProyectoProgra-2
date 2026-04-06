#pragma once
#include <memory>
#include <vector>
#include <string>
#include "IProducto.h"
#include "Cliente.h"
#include "IEstrategiaPago.h"

class Pedido {
private:
	unsigned int codigo;
	static unsigned int generador_c;
	std::vector<std::shared_ptr<IProducto>> productos;
	std::shared_ptr<Cliente> cliente;
	std::shared_ptr<IEstrategiaPago> mpago;
public:
	Pedido(std::shared_ptr<Cliente>);

	void setMetodoPago(std::shared_ptr<IEstrategiaPago>);
	const std::string realizarPago(float);
	void agregaProducto(std::shared_ptr<IProducto>);
};