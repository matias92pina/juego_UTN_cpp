#pragma once
#include <ctime>
#include <iostream>
using namespace std;

class Guerrero {

protected:
	int life; //Vida básica con la que inicia el guerrero
	int armor; //Armadura básica con la que inicia el guerrero
	int mana; //Mana básica con la que inicia el guerrero
	int basic_attack; //Ataque básico con el que inicia el guerrero
	bool isAlive = true; //Está vivo?
	int max_life;
	string type;
	
public:
	Guerrero();
	~Guerrero();
	virtual int attack(); //Para atacar
	virtual int defense_basic();

	virtual int take_damage(int recibido, int armadura); //Recibe daño //Recibir por parámetro el daño que emite recibimos de attack
	virtual void death();
	virtual int getArmor();
	virtual int getLife();
	


	virtual int mode_defense();
	virtual int spell();


	virtual int heal();
	virtual int heal_mana();
	virtual int getMana();
	virtual string getType();

	virtual void mostrar();
};