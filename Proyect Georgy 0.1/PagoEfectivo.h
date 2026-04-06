#pragma once
#include "IEstrategiaPago.h"

class PagoEfectivo : public IEstrategiaPago {
public:
	//void realizarPago() override;
	const std::string getMensajePago() const override;
};