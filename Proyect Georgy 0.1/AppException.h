#pragma once
#include <string>
#include <stdexcept>

class AppException : public std::runtime_error
{
public:
	AppException(const std::string& mensaje) : runtime_error(mensaje){}
};
