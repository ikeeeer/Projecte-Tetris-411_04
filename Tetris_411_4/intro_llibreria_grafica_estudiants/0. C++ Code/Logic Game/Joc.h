#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>
using namespace std;

class Joc
{
public:
	Joc() : figuraActual(FIGURA_I, COLOR_BLAUCEL) {}
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);
	bool setFiguraActual(int colorFigura, int tipusFigura, int fila, int columna);
	//int getPosicioIJFigura(int i, int j) const { return figuraActual.getValorCasella(i, j); }
	ColorFigura getColorFigura() const { return figuraActual.getColorFigura(); }
	void inicialitzaTauler();
	ColorFigura getPosTauler(int i, int j) const { return tauler.getValorCasella(j, i); }
	int getPosX()const { return figuraActual.getX(); }
	int getPosY()const { return figuraActual.getY(); }

private:
	Tauler tauler;
	Figura figuraActual;
};

#endif