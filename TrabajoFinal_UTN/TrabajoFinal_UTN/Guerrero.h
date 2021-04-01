#pragma once
#include <ctime>
#include <iostream>
using namespace std;

class Guerrero {

protected:
	int life; //Vida b�sica con la que inicia el guerrero
	int armor; //Armadura b�sica con la que inicia el guerrero
	int mana; //Mana b�sica con la que inicia el guerrero
	int basic_attack; //Ataque b�sico con el que inicia el guerrero
	bool isAlive = true; //Est� vivo?
	int max_life;
	string type;
	
public:
	Guerrero();
	~Guerrero();
	virtual int attack(); //Para atacar
	virtual int defense_basic();

	virtual int take_damage(int recibido, int armadura); //Recibe da�o //Recibir por par�metro el da�o que emite recibimos de attack
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