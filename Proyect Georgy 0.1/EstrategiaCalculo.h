#pragma once
#include <vector>
#include <memory>
#include "IProducto.h"

//PATRON DELEGATE: Esta clase solo calcula el total

class EstrategiaCalculo {
private:
	float calculoSubtotal(std::vector<std::shared_ptr<IProducto>>);
	float calculoImpuestos(float subt, int imp = 13);
	float calculoDescuentos(float subt, int desc);
public:
	float calculoTotal(std::vector<std::shared_ptr<IProducto>>);
};
