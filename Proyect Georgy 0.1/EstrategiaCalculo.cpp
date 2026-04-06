#include "EstrategiaCalculo.h"
using namespace std;

float EstrategiaCalculo::calculoTotal(std::vector<std::shared_ptr<IProducto>> productos) {
	float suma = 0.0;
	for (auto& p : productos) {
		suma += p->getCosto();
	}
	return suma;
}