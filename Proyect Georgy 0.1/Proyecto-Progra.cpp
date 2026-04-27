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
#include "GestorArchivos.h"

using namespace std;

int main() {
    try {
        shared_ptr<Menu> menu = make_shared<Menu>();
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

        auto p4 = make_shared<Postre>("Tiramisú", 2000, "Recien Hecho", 'G');
        // Agregamos al menú
        menu->agregarProducto(p1);
        menu->agregarProducto(p2);
        menu->agregarProducto(p3);
        menu->agregarProducto(p4);


        cout << "\033[3;34m[Sistema]\033[0m Iniciando Simulacion\n\n\tBienvenido\n\n";

        cout << "\033[3;34m[Sistema]\033[0m Generado cliente\n\n";
        shared_ptr<Cliente> cliente = make_shared<Cliente>("Pedro");

        cout << endl << menu->mostrarProductos() << endl;

        shared_ptr<Pedido> pedido = make_shared<Pedido>(cliente);

        cout << "\033[3;34m[Sistema]\033[0m Agregando Burrito de Carne al pedido\n";
        pedido->agregaProducto(p1);

        cout << "\033[3;34m[Sistema]\033[0m Agregando Extra Queso a la hamburguesa\n";
        shared_ptr<DecoratorExtraQueso> pD2 = make_shared<DecoratorExtraQueso>(p2, make_shared<Ingrediente>("Queso", 300));

        cout << "\033[3;34m[Sistema]\033[0m Agregando Hamburguesa al pedido (Decorada)\n";
        pedido->agregaProducto(pD2);

        cout << "\033[3;34m[Sistema]\033[0m Cambiando el tamano de Refresco Natural a Grande\n";
        shared_ptr<DecoratorCambiarTamano> pD1 = make_shared<DecoratorCambiarTamano>(p3, 'G');

        cout << "\033[3;34m[Sistema]\033[0m Agregando Refresco Natural al pedido (Decorada)\n";
        pedido->agregaProducto(pD1);

        cout << pedido->mostrarProductos();

        cout << "\033[3;34m[Sistema]\033[0m Asignando metodo de pago\n";
        shared_ptr<IEstrategiaPago> mpago = make_shared<PagoDigital>();
        pedido->setMetodoPago(mpago);

        cout << "\033[3;34m[Usuario]\033[0m Monto Dispensado: 10000\n";
        cout << "\033[3;34m[Cliente]\033[0m Descuento Asignado por ser Cliente Nuevo (5%)\n\n";
        cout << pedido->realizarPago(10000.0);

        cout << endl << endl << "\033[3;34m[Sistema]\033[0m Guardando este pedido\n";
        GestorArchivos::guardarEstadoBinario(*pedido, "pedido.dat");

        cout << endl << endl << "\033[3;34m[Sistema]\033[0m Alterando este pedido para demostrar persistencia de datos\n";
        cout << "\033[3;34m[Sistema]\033[0m Agregando Tiramisu al pedido\n";
        pedido->agregaProducto(p4);
        cout << "\033[3;34m[Sistema]\033[0m Asignando metodo de pago\n";
        shared_ptr<IEstrategiaPago> mpago2 = make_shared<PagoEfectivo>();
        pedido->setMetodoPago(mpago2);
        cout << "\033[3;34m[Usuario]\033[0m Monto Dispensado: 12000\n";
        cout << "\033[3;34m[Cliente]\033[0m No se asigna descuento al no ser cliente nuevo\n\n";
        cout << pedido->realizarPago(12000.0);

        cout << endl << endl << "\033[3;34m[Sistema]\033[0m Cargando Pedido anterior\n";
        GestorArchivos::cargarEstadoBinario(*pedido, "pedido.dat");

        cout << "\033[3;34m[Cliente]\033[0m Monto Dispensado: 10000\n\n";
        cout << pedido->realizarPago(10000.0);
    }
    catch (const exception& error) {
        std::cerr << "Error inesperado: " << error.what() << "\n";
    }
    cout << endl << "\tMuchas gracias por preferirnos!\n\tVuelva pronto\n";
};

