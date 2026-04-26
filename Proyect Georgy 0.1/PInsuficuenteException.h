#pragma once
#include "AppException.h"
#include <string>

class PInsuficuenteException : public AppException {
public:
	PInsuficuenteException(double montom) : AppException("ERROR: Monto Insufuciente   Monto Dispensado " + std::to_string(montom)) {}
};
