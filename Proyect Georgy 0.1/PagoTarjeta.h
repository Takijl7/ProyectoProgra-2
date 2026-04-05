#pragma once
#include "IEstrategiaPago.h"

class PagoTarjeta : public IEstrategiaPago {
public:
	void ejecutarPago() override;
	const std::string getMensajePago() const override;
};