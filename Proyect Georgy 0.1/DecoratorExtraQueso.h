#pragma once
#include "ProductoDecorador.h"
class DecoratorExtraQueso :
    public ProductoDecorator
{
public: 
    DecoratorExtraQueso(std::shared_ptr<IProducto>);
    double getCosto() const override;
};