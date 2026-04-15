#pragma once
#include <map>
#include <string>
#include <functional>
class GestorArchivos {
public:
	static void guardarEstadoBinario(const Pedido&, const std::string&);
	static void cargarEstadoBinario(Pedido&, const std::string&);
};
