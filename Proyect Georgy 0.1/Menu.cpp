#include "Menu.h"
using namespace std;

void Menu::agregarProducto(shared_ptr<IProducto> p) {
	productos.push_back(p);
}

const string Menu::mostrarProductos() const {
	stringstream s;
	s << "\tMenu" << endl;
	for (auto& e : productos) {
		s << e->getNombre() << endl;
		s << "\t" << e->getDescripcion() << endl;
	}
	return s.str();
}
const vector<shared_ptr<IProducto>>& Menu::getProductos() const {
	return productos;
}
void Menu::limpiarProductos() {
	productos.clear();
}