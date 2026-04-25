#include "ProductoDecorador.h"
using namespace std;

ProductoDecorator::ProductoDecorator(std::shared_ptr<IProducto> p) :producto(p) {}

string ProductoDecorator::getNombre() const { return producto->getNombre(); }
double ProductoDecorator::getPrecioBase() const { return producto->getPrecioBase(); }
double ProductoDecorator::getCosto() const { return producto->getCosto(); }
string ProductoDecorator::getDescripcion() const { return producto->getDescripcion(); }
string ProductoDecorator::getCategoria() const { return producto->getCategoria(); }

vector<shared_ptr<Ingrediente>> ProductoDecorator::getIngredientes() const { return producto->getIngredientes(); }
vector<shared_ptr<Ingrediente>> ProductoDecorator::getExtras() const { return producto->getExtras(); }
vector<string> ProductoDecorator::getQuitados() const { return producto->getQuitados(); }

void ProductoDecorator::setIngrediente(const Ingrediente& ing) { producto->setIngrediente(ing); }
void ProductoDecorator::quitarIngrediente(const string& nombre) { producto->quitarIngrediente(nombre); }