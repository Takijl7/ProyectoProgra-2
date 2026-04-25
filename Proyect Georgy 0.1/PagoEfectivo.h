#pragma once
#include "IEstrategiaPago.h"

class PagoEfectivo : public IEstrategiaPago {
public:
	const std::string getMensajePago() const override;
};