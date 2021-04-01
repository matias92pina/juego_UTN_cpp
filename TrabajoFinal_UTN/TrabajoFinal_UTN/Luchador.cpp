#include "Luchador.h"
#include<iostream>

Luchador::Luchador()
{
	life = 110;
	max_life = 110;
	armor = 6;
	basic_attack = 15;
	mana = 90;
	type = "Luchador";
}

Luchador::~Luchador()
{
	std::cout << "Eliminado" << std::endl;
}
