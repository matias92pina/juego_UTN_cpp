#include <iostream>
#include <ctime>
#include "Guerrero.h"
#include "Luchador.h"
#include "Mago.h"
#include "Tirador.h"
#include <map>

using namespace std;

int mayor;
bool defendiendo1 = false;
bool defendiendo2 = false;
int who_start();

void mostrar(map<int, Guerrero*>player);

int cantidad_guerreros(map<int, Guerrero*>player);

void rondas(map<int, Guerrero*>player, map<int, Guerrero*>player2);

int main()
{
	srand(time(NULL));

	map<int, Guerrero*> Player1;
	map<int, Guerrero*> Player2;
	int num;
	int cant = 3;

	//armando ejércitos
	for (int i = 0; i < cant; ++i)
	{
		num = rand() % 3;
		switch (num)
		{
		case 0:
			Player1[i] = new Luchador();
			break;
		case 1:
			Player1[i] = new Tirador();
			break;
		case 2:
			Player1[i] = new Mago();
			break;
		}
	}

	for (int i = 0; i < cant; i++)
	{
		num = rand() % 3;
		switch (num)
		{
		case 0:
			Player2[i] = new Luchador();
			break;
		case 1:
			Player2[i] = new Tirador();
			break;
		case 2:
			Player2[i] = new Mago();
			break;
		}
	}

	int n_rondas = 1;
	do
	{
		cout << "\n\t\t###RONDA###: " << n_rondas << endl;
		cout << "\n\t***JUGADOR 1***" << endl;
		rondas(Player1, Player2);
		
		cout << "\n\t***JUGADOR 2***" << endl;
		rondas(Player2, Player1);
		
		n_rondas++;

	} while (cantidad_guerreros(Player1) > 0 && cantidad_guerreros(Player2) >0);

	if (cantidad_guerreros(Player1) > cantidad_guerreros(Player2))
		cout << "\n\t\t++++FIN DEL JUEGO++++\n\t\tJUGADOR 1 GANADOR!!" << endl;
	else if(cantidad_guerreros(Player1) < cantidad_guerreros(Player2))
		cout << "\n\t\t++++FIN DEL JUEGO++++\n\t\tJUGADOR 2 GANADOR!!" << endl;
	else
	{
		cout << "\n\t\t++++FIN DEL JUEGO++++\n\t\tEMPATE!" << endl;
	}


	//Comienzo de ronda
	//bool defendiendo1 = false;
	//bool defendiendo2 = false;
	//
	////Selecciona guerrero
	//int select_warrior;
	//int selec_opponent;
	//mostrar(Player1);

	//cout << "Elige uno de tus campeones: ";
	//cin >> select_warrior;
	//int accion1=0;

	//while (accion1 != 1 && accion1 != 2 && accion1 != 3)
	//{
	//	cout << "\nJugador 1: \n\tAtaca (1) \tDefiende (2) \tLanza hechizo (3)" << endl;
	//	cin >> accion1;
	//}
	//if (accion1 == 1)
	//{
	//	cout << "\nSelecciona un rival: " << endl;
	//	mostrar(Player2);
	//	cin >> selec_opponent;
	//	if (defendiendo2 == true)
	//	{
	//		Player2[selec_opponent]->take_damage(Player1[select_warrior]->attack(), Player2[selec_opponent]->mode_defense());
	//		defendiendo2 = false;
	//		if (Player2[selec_opponent]->getLife() <= 0)
	//		{
	//			cout << "Guerrero: " << Player2.find(selec_opponent)->first << " eliminado" << endl;
	//			map<int, Guerrero*>::iterator e = Player2.find(selec_opponent);
	//			delete Player2[selec_opponent];
	//			Player2.erase(e);
	//		}
	//	}
	//	else if (defendiendo2 == false)
	//		Player2[selec_opponent]->take_damage(Player1[select_warrior]->attack(), Player2[selec_opponent]->defense_basic());
	//}
	//else if (accion1 == 2)
	//	defendiendo1 = true;
	//else
	//{
	//	int spell = Player1[select_warrior]->spell();
	//	cout << "\nSelecciona un rival: " << endl;
	//	mostrar(Player2);
	//	cin >> selec_opponent;
	//	if (spell == 1)
	//	{
	//		Player2[selec_opponent]->take_damage(Player1[select_warrior]->attack(), 0);
	//		if (Player2[selec_opponent]->getLife() <= 0)
	//		{
	//			cout << "Guerrero: " << Player2.find(selec_opponent)->first << " eliminado" << endl;
	//			map<int, Guerrero*>::iterator e = Player2.find(selec_opponent);
	//			delete Player2[selec_opponent];
	//			Player2.erase(e);
	//		}
	//	}
	//	else if (spell == 2)
	//		Player1[select_warrior]->heal();
	//	else
	//	{
	//		Player1[select_warrior]->heal_mana();
	//	}
	//}

}

int who_start()
{
	int p1;
	int p2;
	do
	{
		p1 = rand() % 6 + 1;
		cout << "Dado de jugador 1: " << p1 << endl;
		p2 = rand() % 6 + 1;
		cout << "Dado de jugador 2: " << p2 << endl;
	} while (p1 == p2);

	if (p1 > p2)
	{
		mayor = 1;
	}
	else if (p2 > p1)
	{
		mayor = 2;
	}
	return mayor;
}

//void armar(map<int, Guerrero*>player)
//{
//	int num;
//	int cant = 3;
//	for (int i = 0; i < cant; ++i)
//	{
//		num = rand() % 3;
//		switch (num)
//		{
//		case 0:
//			player[i] = new Luchador();
//			break;
//		case 1:
//			player[i] = new Tirador();
//			break;
//		case 2:
//			player[i] = new Mago();
//			break;
//		}
//	}
//}

void mostrar(map<int, Guerrero*>player)
{
	for (map<int, Guerrero*>::iterator it = player.begin(); it != player.end(); it++)
	{
		cout << "[" << it->first << "]" << "\nTIPO: " << it->second->getType() << "\nVIDA: " << it->second->getLife() << "\nMANA: " << it->second->getMana() << endl;
	}
}

int cantidad_guerreros(map<int, Guerrero*>player)
{
	int contador = 0;
	for (map<int, Guerrero*>::iterator it = player.begin(); it != player.end(); it++)
	{
		contador += 1;
	}
	return contador;
}

void rondas(map<int, Guerrero*>player, map<int, Guerrero*>player2)
{
	//Selecciona guerrero
	int select_warrior;
	int selec_opponent;
	mostrar(player);

	cout << "Elige uno de tus guerreros: ";
	cin >> select_warrior;
	int accion1 = 0;

	while (accion1 != 1 && accion1 != 2 && accion1 != 3)
	{
		cout << "\nJugador: \n\tAtaca (1) \tDefiende (2) \tLanza hechizo (3)" << endl;
		cin >> accion1;
	}
	if (accion1 == 1)
	{
		cout << "\nSelecciona un guerrero rival: " << endl;
		mostrar(player2);
		cin >> selec_opponent;
		if (defendiendo2 == true)
		{
			player2[selec_opponent]->take_damage(player[select_warrior]->attack(), player2[selec_opponent]->mode_defense());
			defendiendo2 = false;
			if (player2[selec_opponent]->getLife() <= 0)
			{
				cout << "Guerrero: " << player2.find(selec_opponent)->first << " eliminado" << endl;
				map<int, Guerrero*>::iterator e = player2.find(selec_opponent);
				//delete player2[selec_opponent];Tira error en la función "mostrar"
				player2.erase(e);
				
				

			}
		}
		else if (defendiendo2 == false)
		{
			player2[selec_opponent]->take_damage(player[select_warrior]->attack(), player2[selec_opponent]->defense_basic());
			if (player2[selec_opponent]->getLife() <= 0)
			{
				cout << "Guerrero: " << player2.find(selec_opponent)->first << " eliminado." << endl;
				map<int, Guerrero*>::iterator e = player2.find(selec_opponent);
				//delete player2[selec_opponent];Tira error en la función "mostrar"
				player2.erase(e);

			}
		}

	}
	else if (accion1 == 2)
		defendiendo1 = true;
	else
	{
		int spell = player[select_warrior]->spell();
		cout << "\nSelecciona un guerrero rival: " << endl;
		mostrar(player2);
		cin >> selec_opponent;
		if (spell == 1)
		{
			player2[selec_opponent]->take_damage(player[select_warrior]->attack(), 0);
			if (player2[selec_opponent]->getLife() <= 0)
			{
				cout << "Guerrero: " << player2.find(selec_opponent)->first << " eliminado" << endl;
				map<int, Guerrero*>::iterator e = player2.find(selec_opponent);
				//delete player2[selec_opponent]; Tira error en la función "mostrar"
				player2.erase(e);

			}
		}
		else if (spell == 2)
			player[select_warrior]->heal();
		else
		{
			player[select_warrior]->heal_mana();
		}
	}
}


