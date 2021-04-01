#include "Guerrero.h"
#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;

Guerrero::Guerrero()
{
	life = 70;
	armor = 2;
	mana = 100;
	basic_attack = 10;
	isAlive = true;
	max_life = 100;
}

Guerrero::~Guerrero()
{
	cout << "Eliminado" << endl;
}

int Guerrero::attack()
{
	int dado1 = rand() % 12 + 1;
	int dado2 = rand() % 12 + 1;
	int danyo = dado1 + dado2 + basic_attack;
	cout << "Ataca con: " << danyo << endl;

	return danyo;
}

int Guerrero::defense_basic()
{
	int dado1 = rand() % 4 + 1;
	int dado2 = rand() % 4 + 1;
	int defensa = dado1 + dado2 + armor;

	return defensa;
}

int Guerrero::take_damage(int recibido, int armadura)
{
	int damage = recibido - armadura * (recibido * 0.10); //Por cada punto de armadura, recibo -10% del daño
	cout << "\nDanyo recibido: " << damage << endl;
	if (damage >= 0)
		life -= damage;
	else
		life = life; //Si damage es menor a 0, no hay daño.

	return life;
}

void Guerrero::death()
{
	if (isAlive==false)
		cout << "Personaje eliminado" << endl;
}

int Guerrero::getArmor()
{
	return armor;
}

int Guerrero::getLife()
{
	return life;
}


int Guerrero::mode_defense()
{
	int dado1 = rand() % 4 + 1;
	int dado2 = rand() % 4 + 1;
	int defensa = (dado1 + dado2 + armor) * 2;

	return defensa;
}

int Guerrero::spell()
{
	int selec;
	if (mana >= 30)
	{
		cout << "Selecciona el hechizo a utilizar:\n\tIgnorar armadura [30 mana] (1)\tCurar [30 mana] (2)\tCurar mana [0 mana] (3)." << endl;
		cin >> selec;
		while (selec != 1 && selec != 2 && selec != 3)
		{
			cout << "Selecciona el hechizo a utilizar:\n\tIgnorar armadura [30 mana] (1)\tCurar [30 mana] (2)\tCurar mana [0 mana] (3)." << endl;
			cin >> selec;
		}
		mana -= 30;
		return selec;
	}
	else if (mana < 30)
	{
		cout << "Selecciona el hechizo a utilizar:\n\tIgnorar armadura (insuficiente) (1)\tCurar (insuficiente) (2)\tCurar mana(3)." << endl;
		do
		{
			cout << "\tCurar (3)" << endl;
			cin >> selec;
		} while (selec != 3);
		return selec;
	}

}



int Guerrero::heal_mana()
{
	if (mana < 100)
		mana += 30;
	if (mana >= 100)
		mana = 100;
	return mana;
}

int Guerrero::getMana()
{
	return mana;
}

string Guerrero::getType()
{
	return type;
}

void Guerrero::mostrar()
{
	cout << "TIPO: " << type << endl;
	cout << "VIDA: " << life << endl;
	cout << "MANA: " << mana << endl;
}

int Guerrero::heal()
{
	if (life < max_life)
		life += 20;
	if (life > max_life)
		life = max_life;
	return life;

}

