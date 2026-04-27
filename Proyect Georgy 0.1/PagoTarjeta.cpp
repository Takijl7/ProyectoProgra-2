#include "PagoTarjeta.h"
using namespace std;

const string PagoTarjeta::getMensajePago() const {
	return "\033[3;34m[Metodo de Pago]\033[0m Realizando Pago con Tarjeta\n";
}
