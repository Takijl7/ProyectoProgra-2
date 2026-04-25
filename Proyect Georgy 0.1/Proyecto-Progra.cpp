#include <iostream>
#include <memory>
#include <vector>
#include "Pedido.h"
#include "Menu.h"
#include "ProductoBase.h"
using namespace std;

void crearMenu(shared_ptr<Menu>& m) {
    Ingrediente ing1("Tortilla", 0.0);
    Ingrediente ing2("Queso", 0.0);
    Ingrediente ing3("Frijoles", 0.0);
    Ingrediente ing4("Carne Mechada", 0.0);
    shared_ptr<ProductoBase> p1 = make_shared<ProductoBase>("Burrito de Carne", 3000, "Burrito de carne de 15cm con queso y frijoles", "Comida");


    p1->setIngrediente(ing1);
    p1->setIngrediente(ing2);
    p1->setIngrediente(ing3);
    p1->setIngrediente(ing4);

    Ingrediente ing5("Pan", 0.0);
    Ingrediente ing6("Carne", 0.0);
    Ingrediente ing7("Lechuga", 0.0);
    Ingrediente ing8("Tomate", 0.0);
    shared_ptr<ProductoBase> p2 = make_shared<ProductoBase>("Hamburgesa", 3500, "Hamburguesa Clasica", "Comida");

    p2->setIngrediente(ing5);
    p2->setIngrediente(ing6);
    p2->setIngrediente(ing7);
    p2->setIngrediente(ing8);

    m->agregarProducto(p1);
    m->agregarProducto(p2);
}


int main()
{
    shared_ptr<Menu> menu = make_shared<Menu>();
    crearMenu(menu);
    cout << menu->mostrarProductos();

    cout << "Que desea ordenar?" << endl;
    cin>>op
}

