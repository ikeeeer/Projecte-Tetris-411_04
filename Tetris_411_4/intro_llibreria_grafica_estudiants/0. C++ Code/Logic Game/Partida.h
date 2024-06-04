#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>
#include "InfoJoc.h"
#include "Joc.h"
#include "GraphicManager.h"
#include "obrirFigures.h"
#include "NodeMoviments.h"


using namespace std;

class Partida 
{
public:
    Partida();
    bool actualitza(int mode, double deltaTime);
    void inicialitzaPartida(const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
    bool creaNovaFigura();
    void guardaFiguraAlTauler();
    bool colisioBaix();
    void dibuixaFigura() const ;
    void fixaFigura();
    void inicialitzar();
    void inicialitzaFigures(const string& fitxerFigures);
    Figura& getPrimera();
    void inicialitzaMoviments(const string& fitxerMoviments);
    int getPrimerMoviment();
    void puntuacio(int nElim);
    double getVelocitat()const { return m_velocitat; }

private:

    TipusFigura converteixTipusFigura(int tipusAux);
    double m_velocitat;
    double m_temps;
    Joc m_joc;
    int m_puntuacio, m_nivell, nElim;
    string seqAparFig, seqMovFig;
    static const int MIDA = 4;
    IMAGE_NAME m_forma[MIDA][MIDA];
    int m_fila, m_columna;
    NodeFigura* primer;
    NodeMoviments* m_primer;


};

#endif 
