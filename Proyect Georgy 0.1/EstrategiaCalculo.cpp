#include "EstrategiaCalculo.h"
using namespace std;

double EstrategiaCalculo::calculoSubtotal(const std::vector<std::shared_ptr<IProducto>>& productos) {
	double suma = 0.0;
	for (const auto& p : productos) {
		suma += p->getCosto();
	}
	return suma;
}

double EstrategiaCalculo::calculoImpuestos(double subt, int imp) {
	return (double) subt * (imp / 100.0f);
}

double EstrategiaCalculo::calculoImpuestos(double subt, int desc) {

}

double EstrategiaCalculo::EstrategiaCalculo(const std::vector<std::shared_ptr<IProducto>>& productos) {
	double subt = calculoSubtotal(productos);
	return subt + calculoImpuestos(subt,13);
}