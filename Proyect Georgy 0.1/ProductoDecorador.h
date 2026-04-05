#pragma once
#include "IProducto.h"
class ProductoDecorator :
    public IProducto
{
protected:
    std::shared_ptr<IProducto> producto;
public:
    ProductoDecorator(std::shared_ptr<IProducto> p);
    virtual ~ProductoDecorator() = default;
};

