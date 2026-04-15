#pragma once
#include <string>
//Esta clase es la interfaz para quien quiera realizar el pago del pedido
//Patron DELEGATE : Se delega el trabajo de realizar el pago
class IEstrategiaPago {
public:
	virtual ~IEstrategiaPago() = default;
	virtual void realizarPago() = 0;
	virtual const std::string getMensajePago() = 0;
};
