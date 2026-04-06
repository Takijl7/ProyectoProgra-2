#pragma once
#include <vector>
#include <memory>
#include "IProducto.h"

//PATRON DELEGATE: Esta clase solo calcula el total

class EstrategiaCalculo {
public:
	float calculoTotal(std::vector<std::shared_ptr<IProducto>>);
};
