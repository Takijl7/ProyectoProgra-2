#include "Menu.h"
using namespace std;

void Menu::agregarProducto(shared_ptr<IProducto> p) {
	productos.push_back(p);
}

const string Menu::mostrarProductos() const {
	stringstream s;
	s << "\tMenu" << endl;
	for (auto& e : productos)
		s << e->getNombre() << endl;
	return s.str();
}
const vector<shared_ptr<IProducto>> Menu::getProductos() {
	return productos;
}
void Menu::limpiarProductos() {
	productos.clear();
}