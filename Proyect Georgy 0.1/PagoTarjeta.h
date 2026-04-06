#pragma once
#include "IEstrategiaPago.h"

class PagoTarjeta : public IEstrategiaPago {
public:
	//void realizarPago() override;
	const std::string getMensajePago() const override;
};