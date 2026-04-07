#pragma once
#include <string>
using namespace std;
class Ingrediente
{
public:
	Ingrediente(string& nombre, double extra = 0.0);
	string getNombre() const;
	double getExtra() const;
	bool operator == (const Ingrediente& otro) const;
private:
	string nombre;
	double extra;
};