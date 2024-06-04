#include "Joc.h"
#include "GraphicManager.h"
#include <fstream>
void Joc::inicialitza(const string& nomFitxer) {
    ifstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open()) {
        int tipusAux, fila, columna, gir;
        TipusFigura tipus;
        fitxer >> tipusAux;
        switch (tipusAux) {
        case 0: tipus = NO_FIGURA;
            break;
        case 1: tipus = FIGURA_O;
            break;
        case 2: tipus = FIGURA_I;
            break;
        case 3: tipus = FIGURA_T;
            break;
        case 4: tipus = FIGURA_L;
            break;
        case 5: tipus = FIGURA_J;
            break;
        case 6: tipus = FIGURA_Z;
            break;
        case 7: tipus = FIGURA_S;
            break;
        default:
            break;
        }
        fitxer >> fila;
        fitxer >> columna;
        fitxer >> gir;
        figuraActual.setTipus(tipus);
        figuraActual.setGir(gir);
        figuraActual.girar(GIR_HORARI, gir);
        figuraActual.setPosicio(columna - 1, fila - 1);
        int valorTauler;
        ColorFigura color;
        for (int i = 0; i < MAX_FILA; i++) {
            for (int j = 0; j < MAX_COL; j++) {
                fitxer >> valorTauler;
                switch (valorTauler) {
                case 0:
                    color = COLOR_NEGRE;
                    break;
                case 1:
                    color = COLOR_GROC;
                    break;
                case 2:
                    color = COLOR_BLAUCEL;
                    break;
                case 3:
                    color = COLOR_MAGENTA;
                    break;
                case 4:
                    color = COLOR_TARONJA;
                    break;
                case 5:
                    color = COLOR_BLAUFOSC;
                    break;
                case 6:
                    color = COLOR_VERMELL;
                    break;
                case 7:
                    color = COLOR_VERD;
                    break;
                default:
                    color = NO_COLOR;
                    break;
                }
                tauler.setValorCasella(color, j, i);

            }
        }
        fitxer.close();
    }
}
bool Joc::setFiguraActual(int colorFigura, int tipusFigura, int fila, int columna) {
    ColorFigura color;
    bool gameOver = false;
            switch (colorFigura) {
            case 0:
                color = COLOR_NEGRE;
                break;
            case 1:
                color = COLOR_GROC;
                break;
            case 2:
                color = COLOR_BLAUCEL;
                break;
            case 3:
                color = COLOR_MAGENTA;
                break;
            case 4:
                color = COLOR_TARONJA;
                break;
            case 5:
                color = COLOR_BLAUFOSC;
                break;
            case 6:
                color = COLOR_VERMELL;
                break;
            case 7:
                color = COLOR_VERD;
                break;
            default:
                color = NO_COLOR;
                break;
            }
            TipusFigura tipus;
            switch (tipusFigura) {
            case 0: tipus = NO_FIGURA;
                break;
            case 1: tipus = FIGURA_O;
                break;
            case 2: tipus = FIGURA_I;
                break;
            case 3: tipus = FIGURA_T;
                break;
            case 4: tipus = FIGURA_L;
                break;
            case 5: tipus = FIGURA_J;
                break;
            case 6: tipus = FIGURA_Z;
                break;
            case 7: tipus = FIGURA_S;
                break;
            default:
                break;
            }
            figuraActual.setColorFigura(color);
            figuraActual.setTipus(tipus);
            figuraActual.setPosicio(fila, columna);
            if (tauler.movimentValid(figuraActual)) {
                tauler.colocarFigura(figuraActual);
                gameOver = true;
            }
                    
            figuraActual.setGir(0);

            return gameOver;
}
bool Joc::giraFigura(DireccioGir direccio) {
    bool trobat = false;
    int nGirs = figuraActual.getGir();
    Figura figuraAux = figuraActual;
    figuraAux.girar(direccio, 1);
    tauler.esborraFigura(figuraActual);
    if (tauler.movimentValid(figuraAux)) {
        tauler.esborraFigura(figuraActual);
        figuraActual = figuraAux;
        figuraActual.setGir(nGirs + 1);
        
        trobat = true;
    }
    tauler.colocarFigura(figuraActual);
    tauler.setFiguraColocada(false);
    return trobat;
}

bool Joc::mouFigura(int dirX) {
    bool trobat = false;
    Figura figuraAux = figuraActual;
    if (dirX == 1) {
        figuraAux.moureDreta();
    }
    else if(dirX == -1){
        figuraAux.moureEsquerra();
    }
    tauler.esborraFigura(figuraActual);
    if (tauler.movimentValid(figuraAux)) {
        figuraActual = figuraAux;  
        trobat = true;
    }
    tauler.colocarFigura(figuraActual);
    tauler.setFiguraColocada(false);
    return trobat;
}
int Joc::baixaFigura() {
    int res =-1;
    Figura figuraAux = figuraActual;
    figuraAux.baixar();
    tauler.esborraFigura(figuraActual);
    if (tauler.movimentValid(figuraAux)) {        
        figuraActual = figuraAux;
        res = tauler.eliminarFilesCompletades();
    }
    tauler.colocarFigura(figuraActual);
    return res;
}
void Joc::escriuTauler(const string& nomFitxer) {

    
    int matriu[MAX_FILA][MAX_COL];
    for (int i = 0; i < MAX_FILA; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            matriu[i][j] = tauler.getValorCasella(j, i);
        }
    }
    if (!tauler.getFiguraColocada()) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (figuraActual.getValorCasella(j, i) != 0) {
                    matriu[i + figuraActual.getY() - 1][j + figuraActual.getX() - 1] = figuraActual.getColorFigura();

                }
            }
        }
        tauler.eliminarFilesCompletades();
    }
    ofstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open()) {
        for (int i = 0; i < MAX_FILA; i++) {
            for (int j = 0; j < MAX_COL; j++) {

                fitxer << matriu[i][j] << " ";
            }
            fitxer << "\n";
        }
    }
    fitxer.close();
}

void Joc::inicialitzaTauler() {
    for (int i = 0; i < N_FILES_TAULER; i++) {
        for (int j = 0; j < N_COL_TAULER; j++) {
            tauler.inicialitzaTauler();
        }
    }
}