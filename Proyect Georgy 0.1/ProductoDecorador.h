#pragma once
#include <memory>
#include "IProducto.h"
#include "IProductoIngredientes.h"
class ProductoDecorator :
    public IProducto
{
protected:
    std::shared_ptr<IProducto> producto;
public:
    ProductoDecorator(std::shared_ptr<IProducto>);
    virtual ~ProductoDecorator() = default;

    virtual string getNombre() const override;
    virtual double getPrecioBase() const override;
    virtual double getCosto() const override;
    virtual string getDescripcion() const override;
    virtual string getCategoria() const override;

    virtual vector<shared_ptr<Ingrediente>> getIngredientes() const override;
    virtual vector<shared_ptr<Ingrediente>> getExtras() const override;
    virtual vector<string> getQuitados() const override;

    virtual void setIngrediente(const Ingrediente& ing) override;
    virtual void quitarIngrediente(const string& nombre) override;
};

