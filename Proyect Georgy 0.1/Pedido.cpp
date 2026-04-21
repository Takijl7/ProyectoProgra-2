#include "Pedido.h"
using namespace std;

unsigned int Pedido::generador_c = 0;

Pedido::Pedido(shared_ptr<Cliente> c) : cliente(c), mpago(nullptr) {
	codigo = ++generador_c;
}
void Pedido::setMetodoPago(std::shared_ptr<IEstrategiaPago> metodo) {
	mpago = metodo;
}
const string Pedido::realizarPago(double monto) {
	
}
void Pedido::agregaProducto(shared_ptr<IProducto> p) {
	productos.push_back(p);
}

