#pragma once
#include "IEstrategiaPago.h"

class PagoDigital : public IEstrategiaPago {
public:
	//void realizarPago() override;
	const std::string getMensajePago() const override;
};
