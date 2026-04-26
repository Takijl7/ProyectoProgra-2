#include "Pedido.h"
using namespace std;

unsigned int Pedido::generador_c = 0;

Pedido::Pedido(shared_ptr<Cliente> c) : cliente(c), mpago(nullptr),
ecalculo(make_shared<EstrategiaCalculo>())
{
	codigo = ++generador_c;
}
void Pedido::setMetodoPago(std::shared_ptr<IEstrategiaPago> metodo) {
	mpago = metodo;
}
const string Pedido::mostrarProductos() const {
	stringstream s;
	s << "\tProductos" << endl;
	for (auto& e : productos) {
		s << e->getNombre() << endl;
	}
	return s.str();
}
const string Pedido::realizarPago(double monto) {
	stringstream s;
	double subt = ecalculo->calculoSubtotal(productos);
	if (monto < ecalculo->calculoTotal(productos)) {
		throw PInsuficuenteException(monto);
	}
	if (!mpago) {
		throw NoMetodoDePagoException();
	}
	s << "\tFactura del Pedido\n\n";
	s << mostrarProductos() << endl;
	s << "Subtotal: " << subt << endl;
	s << "Descuento: -" << ecalculo->calculoDescuentos(subt,0) << endl;
	s << "Impuestos: +" << ecalculo->calculoImpuestos(subt, 13) << endl;
	s << "Total: " << ecalculo->calculoTotal(productos);
	s << mpago->getMensajePago() << endl;
	return s.str();
}
void Pedido::agregaProducto(shared_ptr<IProducto> p) {
	productos.push_back(p);
}
const vector<shared_ptr<IProducto>>& Pedido::getProductos() const {
	return productos;
}
void Pedido::limpiarProductos() {
	productos.clear();
}

