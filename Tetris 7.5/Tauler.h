#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler {
public:
    Tauler();

    bool movimentValid(const Figura& figura) const;
    void colocarFigura(const Figura& figura);
    int eliminarFilesCompletades();
    void setValorCasella(ColorFigura color, int x, int y) { m_tauler[y][x] = color; }
    ColorFigura getValorCasella(int x, int y) const { return m_tauler[y][x]; }
    bool getFiguraColocada() const { return figuraColocada; }
    void setFiguraColocada(bool colocat) { figuraColocada = colocat; }
private:
    ColorFigura m_tauler[MAX_FILA][MAX_COL];
    bool DinsDelTauler(const Figura& figura, int fila, int columna) const;
    bool CelaBuida(Figura figura, int fila, int columna) const;
    bool figuraColocada = false;
};

#endif