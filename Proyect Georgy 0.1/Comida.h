#pragma once
#include "ProductoBase.h"

class Comida : public ProductoBase {
private:
	bool esVegano;
public:
	Comida(std::string nom, double precio, std::string desc, char tam, bool vegano);

	bool getEsVegano() const;
	string getDescripcion() const override;
};

