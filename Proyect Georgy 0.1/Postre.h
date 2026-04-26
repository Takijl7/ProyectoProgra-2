#pragma once
#include "ProductoBase.h"

class Postre : public ProductoBase {
public:
    Postre(string nom, double precio, string desc, char tam);
    void escribirBinario(std::ofstream& os) const override;
    void leerBinario(std::ifstream& is) override;
};

