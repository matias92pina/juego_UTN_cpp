#include "Mago.h"
#include<iostream>

Mago::Mago()
{
	life = 100;
	max_life = 100;
	armor = 4;
	basic_attack = 15;
	mana = 150;
	type = "Mago";
}

Mago::~Mago()
{
	std::cout << "Eliminado" << std::endl;
}

int Mago::heal_mana()
{
	{
		if (mana < 150)
			mana += 30;
		if (mana >= 100)
			mana = 150;
		return mana;
	}
}
