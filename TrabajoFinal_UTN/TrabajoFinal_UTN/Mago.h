#pragma once
#include "Guerrero.h"

class Mago : public Guerrero {
public:
	Mago();
	~Mago();
	int heal_mana();
};
