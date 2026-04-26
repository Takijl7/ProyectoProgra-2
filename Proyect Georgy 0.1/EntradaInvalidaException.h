#pragma once
#include "AppException.h"
#include <string>

class EntradaInvalidaException : public AppException {
public:
	EntradaInvalidaException() : AppException("ERROR: Entrada Invalida") {}
};
