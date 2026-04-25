#pragma once
#include <vector>
#include <memory>
#include "IProducto.h"

//PATRON DELEGATE: Esta clase solo calcula el total

class EstrategiaCalculo {
private:
	double calculoSubtotal(const std::vector<std::shared_ptr<IProducto>>&);
	double calculoImpuestos(double subt, int imp = 13);
	double calculoDescuentos(double subt, int desc);
public:
	double calculoTotal(const std::vector<std::shared_ptr<IProducto>>&);
};
