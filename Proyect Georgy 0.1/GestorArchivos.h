#pragma once
#include <map>
#include <string>
#include <functional>
#include "Pedido.h"

class GestorArchivos {
public:
	static void guardarEstadoBinario(const Pedido& pedido, const std::string&);
	static void cargarEstadoBinario(Pedido& menu, const std::string&);
};
