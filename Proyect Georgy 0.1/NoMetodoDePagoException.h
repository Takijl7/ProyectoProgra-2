#pragma once
#include "AppException.h"

class NoMetodoDePagoException : public AppException {
public:
	NoMetodoDePagoException() : AppException("ERROR; No existe Metodo de Pago seleccionado") {}
};
