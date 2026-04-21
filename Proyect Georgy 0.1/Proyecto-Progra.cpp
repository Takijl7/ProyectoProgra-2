#include <iostream>
#include <memory>
#include <vector>
#include "Pedido.h"
#include "Menu.h"
#include "ProductoBase.h"
using namespace std;

int main()
{
    shared_ptr<Menu> Menu = make_shared<Menu>;

    shared_ptr<ProductoBase> p1 = make_shared<ProductoBase>;
    Menu->agregarProducto(p1);
}

