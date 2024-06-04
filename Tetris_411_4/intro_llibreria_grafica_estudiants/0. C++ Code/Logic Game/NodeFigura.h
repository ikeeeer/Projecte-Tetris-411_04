#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

class ObrirFigures {
public:
	Figura& getTipus();
	Figura& getFila();
	Figura& getColumna();
	Figura& getGir();
	ObrirFigures* getNext();
	void setTipus(const Figura& tipus);
	void setFila(const Figura& fila);
	void setColumna(const Figura& columna);
	void setGir(const Figura& gir);
	void setNext(ObrirFigures* next);

private:
	Figura tipusFigura, fila, columna, gir;
	ObrirFigures* m_nextFigura;
	
};

#endif