#ifndef TETRIS_H
#define TETRIS_H

#include <iostream>
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#include <conio.h>      /* getch */ 

#include "./Partida.h"
#include "./InfoJoc.h"

class Tetris
{
public:
	Tetris() {};
	int getOpcioMenu();
	int jugar( Screen &pantalla,  TipusMode mode);

private:
	Partida m_partida;
};
#endif