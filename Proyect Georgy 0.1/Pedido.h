#pragma once
#include <memory>
#include <vector>
#include "IProducto.h"
#include "Cliente.h"

class Pedido {
private:
	unsigned int codigo;
	static unsigned int generador_c;
	std::vector<std::shared_ptr<IProducto>> productos;
	std::shared_ptr<Cliente> cliente;
public:
	Pedido()
};