#pragma once
#include "ProductoDecorador.h"
class DecoratorSinSal :
    public ProductoDecorator
{
    DecoratorSinSal(std::shared_ptr<IProducto>);
    double getCosto() const override;
};

