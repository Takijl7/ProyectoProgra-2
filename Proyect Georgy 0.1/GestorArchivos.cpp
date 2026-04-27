#include "GestorArchivos.h"
#include "Menu.h"
#include "Pedido.h"
#include "Bebida.h"
#include "Comida.h"
#include "Postre.h"
#include "DecoratorExtraQueso.h"
#include "DecoratorCambiarTamano.h"
#include "DecoratorSinSal.h"
#include "NoFileException.h"
#include <fstream>
using namespace std;

namespace {
    map<int, function<shared_ptr<ProductoBase>()>> cocina = {
        {1, []() { return make_shared<Bebida>("", 0.0, "", ' ', TipoBebida::NATURAL); }},
        {2, []() { return make_shared<Comida>("", 0.0, "", ' ', false); }},
        {3, []() { return make_shared<Postre>("", 0.0, "", ' '); }}
    };

    shared_ptr<IProducto> leerProducto(ifstream& is) {
        int tipo = 0;
        is.read(reinterpret_cast<char*>(&tipo), sizeof(tipo));
        if (!is) return nullptr;
        if (tipo == 4) {
            size_t tam;
            is.read(reinterpret_cast<char*>(&tam), sizeof(tam));
            string nombre(tam, ' ');
            is.read(&nombre[0], tam);
            double extra;
            is.read(reinterpret_cast<char*>(&extra), sizeof(extra));
            auto ing = make_shared<Ingrediente>(nombre, extra);
            auto interno = leerProducto(is);
            return make_shared<DecoratorExtraQueso>(interno, ing);
        }
        if (tipo == 5) {
            char tamano;
            is.read(&tamano, sizeof(tamano));
            auto interno = leerProducto(is);
            return make_shared<DecoratorCambiarTamano>(interno, tamano);
        }
        if (tipo == 6) {
            size_t tam;
            is.read(reinterpret_cast<char*>(&tam), sizeof(tam));
            string nombre(tam, ' ');
            is.read(&nombre[0], tam);
            double extra;
            is.read(reinterpret_cast<char*>(&extra), sizeof(extra));
            auto ing = make_shared<Ingrediente>(nombre, extra);
            auto interno = leerProducto(is);
            return make_shared<DecoratorSinSal>(interno, ing);
        }
        if (cocina.count(tipo)) {
            auto producto = cocina[tipo]();
            producto->leerBinario(is);
            return producto;
        }
        return nullptr;
    }

    void guardarProducto(ofstream& os, const shared_ptr<IProducto>& e) {
        auto pDeco = dynamic_pointer_cast<ProductoDecorator>(e);
        if (pDeco) {
            if (dynamic_pointer_cast<DecoratorExtraQueso>(e)) {
                int tipo = 4;
                os.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));
                auto ing = dynamic_pointer_cast<DecoratorExtraQueso>(e)->getIngrediente();
                size_t tamNombre = ing->getNombre().size();
                os.write(reinterpret_cast<const char*>(&tamNombre), sizeof(tamNombre));
                os.write(ing->getNombre().c_str(), tamNombre);
                double extra = ing->getExtra();
                os.write(reinterpret_cast<const char*>(&extra), sizeof(extra));
            }
            else if (dynamic_pointer_cast<DecoratorCambiarTamano>(e)) {
                int tipo = 5;
                os.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));
                char t = dynamic_pointer_cast<DecoratorCambiarTamano>(e)->getTamano();
                os.write(&t, sizeof(t));
            }
            else if (dynamic_pointer_cast<DecoratorSinSal>(e)) {
                int tipo = 6;
                os.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));
                auto ing = dynamic_pointer_cast<DecoratorSinSal>(e)->getIngrediente();
                size_t tamNombre = ing->getNombre().size();
                os.write(reinterpret_cast<const char*>(&tamNombre), sizeof(tamNombre));
                os.write(ing->getNombre().c_str(), tamNombre);
                double extra = ing->getExtra();
                os.write(reinterpret_cast<const char*>(&extra), sizeof(extra));
            }
            guardarProducto(os, pDeco->getProductoInterno());
            return;
        }
        auto pBase = dynamic_pointer_cast<ProductoBase>(e);
        if (pBase) pBase->escribirBinario(os);
    }
}

void GestorArchivos::guardarEstadoBinario(const Pedido& pedido, const string& ruta) {
    ofstream archivo(ruta, ios::binary);
    if (!archivo) throw NoFileException(ruta);
    const auto& productos = pedido.getProductos();
    size_t total = productos.size();
    archivo.write(reinterpret_cast<const char*>(&total), sizeof(total));
    for (const auto& e : productos)
        guardarProducto(archivo, e);
}

void GestorArchivos::cargarEstadoBinario(Pedido& pedido, const string& ruta) {
    ifstream archivo(ruta, ios::binary);
    if (!archivo) throw NoFileException(ruta);
    pedido.limpiarProductos();
    size_t total = 0;
    archivo.read(reinterpret_cast<char*>(&total), sizeof(total));
    for (size_t i = 0; i < total; ++i) {
        auto producto = leerProducto(archivo);
        if (producto) pedido.agregaProducto(producto);
    }
}
