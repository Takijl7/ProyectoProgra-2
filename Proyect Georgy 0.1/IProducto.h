#pragma once
#include <string>
class IProducto
{
public:
	virtual ~IProducto() = default;
	virtual float getCosto() = 0;
	virtal string getNombre() = 0;
};

