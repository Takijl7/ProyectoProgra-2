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
	s << "\tFactura del Pedido\n\n";
	int d = 0;
	if (productos.empty()) throw PedidoVacioException();
	if (!mpago) throw NoMetodoDePagoException();
	else {
		s << mpago->getMensajePago();
	}
	double subt = ecalculo->calculoSubtotal(productos);
	if (cliente->getCantP() == 0) {
		d = 5;
	}
	else if (cliente->getCantP()>20){
		d = 10;
	}
	if (monto < ecalculo->calculoTotal(productos,d)) throw PInsuficuenteException(monto);
	cliente->setCantP(cliente->getCantP() + 1);

	s << "[Cliente] " << cliente->getNombre() << endl << endl;
	s << mostrarProductos() << endl;
	s << "[Calculo] Subtotal: " << subt << endl;
	s << "[Calculo] Descuento: -" << ecalculo->calculoDescuentos(subt,d) << endl;
	s << "[Calculo] Impuestos: +" << ecalculo->calculoImpuestos(subt, 13) << endl;
	s << "[Calculo] Total: " << ecalculo->calculoTotal(productos,d) << endl;
	s << "[Calculo] Vuelto: " << monto - ecalculo->calculoTotal(productos,d) << endl;
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

