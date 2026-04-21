#pragma once
#include <string>
class Cliente
{
private:
	std::string nombre;
public:
	Cliente(std::string);
	const std::string getNombre() const;
};
