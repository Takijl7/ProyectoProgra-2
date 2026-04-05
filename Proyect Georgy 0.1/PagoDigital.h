#pragma once
#include "IEstrategiaPago.h"

class PagoEfectivo : public IEstrategiaPago {
public:
	void ejecutarPago() override;
	const std::string getMensajePago() const override;
};
