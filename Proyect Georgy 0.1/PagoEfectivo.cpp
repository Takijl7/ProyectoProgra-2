#include "PagoEfectivo.h"
using namespace std;

const string PagoEfectivo::getMensajePago() const {
	return "\033[3;34m[Metodo de Pago]\033[0m Realizando Pago en Efectivo\n";
}