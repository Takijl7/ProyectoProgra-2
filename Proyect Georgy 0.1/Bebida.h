#pragma once
#include "ProductoBase.h"

enum class TipoBebida { ALCOHOLICA, NATURAL, GASEOSA };

class Bebida : public ProductoBase
{
private:
	TipoBebida tipo;
public:
	Bebida(string nom, double precio, string desc, char tam, TipoBebida t);

	TipoBebida getTipo() const;
};

