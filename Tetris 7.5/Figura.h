#ifndef FIGURA_H
#define FIGURA_H

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;


typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    Figura(TipusFigura tipus, ColorFigura color) :tipus(tipus), color(color), posicio_x(0), posicio_y(0) {
        inicialitzarForma();
    }
    Figura(TipusFigura tipus, int gira, int x, int y) :tipus(tipus), gir(gira), posicio_x(x), posicio_y(y) {
        inicialitzarForma();
    }
    void moureEsquerra();
    void moureDreta();
    void baixar();
    void obtenirForma(int forma_actual[MAX_AMPLADA][MAX_ALCADA]) const;
    void obtenirPosicio(int& posicio_x, int& posicio_y) const;
    void girar(const DireccioGir direccio, int gir);
    TipusFigura getTipusFigura() const { return tipus; }
    int getX() const { return posicio_x; }
    int getY() const { return posicio_y; }
    int getNc() const { return nc; }
    int getNf() const { return nf; }
    int getIRef() const { return iRef; }
    int getJRef() const { return jRef; }
    int getIMin() const { return imin; }
    int getJMin() const { return jmin; }
    int getIMax() const { return imax; }
    int getJMax() const { return jmax; }
    int getValorCasella(int x, int y) const { return forma[y][x]; }
    int getGir() const { return gir; }
    void setTipus(TipusFigura t) { tipus = t; inicialitzarForma(); }
    void setGir(int g) { gir = g;}
    void setPosicio(int x, int y) { posicio_x = x; posicio_y = y; }
    ColorFigura getColorFigura() const { return color; }


private:
    TipusFigura tipus;
    ColorFigura color;
    int gir;
    void inicialitzarForma();
    int posicio_x;
    int posicio_y;
    int forma[MAX_AMPLADA][MAX_ALCADA];
    int nf, nc;
    int iRef, jRef;
    int imin, imax, jmin, jmax;
};


#endif