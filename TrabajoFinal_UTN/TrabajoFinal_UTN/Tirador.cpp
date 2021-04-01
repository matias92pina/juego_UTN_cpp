#include "Tirador.h"
#include<iostream>

Tirador::Tirador()
{
	life = 10;
	max_life = 100;
	mana = 100;
	basic_attack = 25;
	armor = 4;
	type = "Tirador";
}

Tirador::~Tirador()
{
	std::cout << "Eliminado" << std::endl;
}
