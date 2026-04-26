#pragma once
#include <string>
#include <stdexcept>

//Esta clase nos ayuda para errores genericos, sus hijos serian errores especificos
class AppException : public std::runtime_error
{
public:
	AppException(const std::string& mensaje) : runtime_error(mensaje){}
};
