#pragma once
#include <string>
using namespace std;
class Ingrediente
{
public:
	Ingrediente(const string& nombre, double extra );
	string getNombre() const;
	double getExtra() const;
private:
	string nombre;
	double extra;
};

//Usando el PRINCIPIO DE RESPONSABILIDAD UNICA (SRP), que nos dice que, solo se debe tener una razon para cambiar
//En este caso, la clase Ingrediente se encarga de representar un ingrediente con su nombre y su costo adicional.
