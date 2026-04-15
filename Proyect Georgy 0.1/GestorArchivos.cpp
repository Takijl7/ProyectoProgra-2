#include "GestorArchivos.h"
#include "Pedido.h"
#include "ProductoBase.h"
#include <fstream>

using namespace std;

namespace {
	std::map<int, function<shared_ptr<ProductoBase>()>> cocina = {
		{1, []() { return make_shared<ProductoBase>("",0.0,"","");}} //Cuando se agreguen tipos lo vamos cambiando
	};
}

void GestorArchivos::guardarEstadoBinario(const Pedido& pedido, const string& ruta) {
	ofstream archivo(ruta, ios::binary);
	if (!archivo) return;

	const auto& productos = pedido.getProductos();
	size_t total_memoria = productos.size();
	archivo.write(reinterpret_cast<const char*>(&total_memoria), sizeof(total_memoria));

	for (const auto& e : productos) {
		auto pBase = dynamic_pointer_cast<ProductoBase>(e);
		if (pBase) {
			pBase->escribirBinario(archivo);
		}
	}
}

void GestorArchivos::cargarEstadoBinario(Menu& menu, const string ruta) {
	ifstream archivo(ruta, ios::binary);
	if (!archivo) return;

	menu.limpiarProductos();

	size_t total_memoria = 0;
	archivo.read(reinterpret_cast<char*>(&total_memoria), sizeof(total_memoria));

	for (size_t i = 0;i < total, ++i) {
		int tipo = 0;
		archivo.read(reinterpret_cast<char*>(&tipo), sizeof(tipo));

		if (!archivo) break;
		if (cocina.count(tipo)) {
			auto nuevoProducto = cocina[tipo]();
			nuevoProducto->leerBinario(archivo);
			
		}
	}
}