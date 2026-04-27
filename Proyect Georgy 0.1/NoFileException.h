#pragma once
#include "AppException.h"
#include <string>

class NoFileException : public AppException {
public:
	NoFileException(const std::string& ruta) : AppException("ERROR: Archivo no encontrado\nNombre de archivo inexistente: " + ruta) {}
};

