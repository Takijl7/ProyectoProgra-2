#pragma once
#include "IEstrategiaPago.h"

class PagoDigital : public IEstrategiaPago {
public:
	const std::string getMensajePago() const override;
};
