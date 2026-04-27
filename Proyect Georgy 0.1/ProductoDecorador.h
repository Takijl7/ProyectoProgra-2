#pragma once
#include <memory>
#include "IProducto.h"

class ProductoDecorator : public IProducto
{
protected:
    std::shared_ptr<IProducto> producto;
public:
    ProductoDecorator(std::shared_ptr<IProducto> p) : producto(p) {}

    std::shared_ptr<IProducto> getProductoInterno() const { return producto; }
    string getNombre() const override { return producto->getNombre(); }
    double getCosto() const override { return producto->getCosto(); }
    string getDescripcion() const override { return producto->getDescripcion(); }
    char getTamano() const override { return producto->getTamano(); }
};

