#include <iostream>
#include <memory>
#include <vector>
#include "Menu.h"
#include "Pedido.h"
#include "Cliente.h"
#include "Ingrediente.h"
#include "Comida.h"
#include "Bebida.h"
#include "Postre.h"
#include "DecoratorExtraQueso.h"
#include "DecoratorCambiarTamano.h"
#include "PagoEfectivo.h" 
#include "PagoTarjeta.h"
#include "PagoDigital.h"
#include "EntradaInvalidaException.h"
#include "PedidoVacioException.h"

using namespace std;

void crearMenu(shared_ptr<Menu>& m) {
    // --- PRODUCTO 1: BURRITO ---
    auto p1 = make_shared<Comida>("Burrito de Carne", 3000, "Burrito de carne de 15cm con queso y frijoles", 'G', false);
    vector<Ingrediente> ingsBurrito = {
        {"Tortilla", 0.0},
        {"Queso", 0.0},
        {"Frijoles", 0.0},
        {"Carne Mechada", 0.0}
    };
    p1->agregarIngredientes(ingsBurrito);

    // --- PRODUCTO 2: HAMBURGUESA ---
    auto p2 = make_shared<Comida>("Hamburguesa", 3500, "Hamburguesa Clasica", 'G', false);
    vector<Ingrediente> ingsBurger = {
        {"Pan", 0.0},
        {"Carne", 0.0},
        {"Lechuga", 0.0},
        {"Tomate", 0.0}
    };
    auto p3 = make_shared<Bebida>("Refresco Natural", 1000, "Frutas de temporada", 'M', TipoBebida::NATURAL);

    auto p4 = make_shared<Postre>("Tiramisú", 2000, "Recuien Hecho", 'G');
    // Agregamos al menú
    m->agregarProducto(p1);
    m->agregarProducto(p2);
    m->agregarProducto(p3);
    m->agregarProducto(p4);
}

int main() {
    try {
        shared_ptr<Menu> menu = make_shared<Menu>();
        crearMenu(menu);
        cout << menu->mostrarProductos();
        cout << "Que desea ordenar?" << endl;
    }
    catch (const exception& error) {
        std::cerr << "Error inesperado: " << error.what() << "\n";
    }
};

