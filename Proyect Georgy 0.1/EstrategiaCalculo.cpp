#include "EstrategiaCalculo.h"
using namespace std;

float EstrategiaCalculo::calculoSubtotal(std::vector<std::shared_ptr<IProducto>> productos) {
	float suma = 0.0;
	for (auto& p : productos) {
		(float) suma += p->getCosto();
	}
	return suma;
}

float EstrategiaCalculo::calculoImpuestos(float subt, int imp) {
	return (float) subt * (imp / 100);
}

float EstrategiaCalculo(std::vector<std::shared_ptr<IProducto>> productos) {
	float subt = calculoSubtotal(productos);
	return subt + calculoImpuestos(subt);
}