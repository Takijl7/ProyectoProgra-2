#pragma once
#include <string>
class Cliente
{
private:
	std::string nombre;
	unsigned int cantP;
public:
	Cliente(std::string);
	const std::string getNombre() const;
	const int getCantP() const;
	void setCantP(int);
};
