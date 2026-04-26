#pragma once

#include "AppException.h"
#include <string>

class PedidoVacioException : public AppException {
public:
	PedidoVacioException() : AppException("ERROR: Ningun producto seleccionado") {}
};
