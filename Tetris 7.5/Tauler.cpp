#include "Tauler.h"
Tauler::Tauler() {
    for (int i = 0; i < MAX_FILA; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            m_tauler[i][j] = COLOR_NEGRE;
        }
    }
    figuraColocada = false;
}
bool Tauler::movimentValid(const Figura& figura) const {
    bool trobat = true;
    int forma[MAX_ALCADA][MAX_AMPLADA];
    int posicio_x, posicio_y;
    figura.obtenirPosicio(posicio_x, posicio_y);
    figura.obtenirForma(forma);
    for (int i = 0; i < figura.getNf() && trobat; i++) {
        for (int j = 0; j < figura.getNc() && trobat; j++) {
            if (forma[i][j] == 1) {
                int fila = posicio_y + i ;              
                int columna = posicio_x + j ;
                if (!DinsDelTauler(figura, fila-1, columna-1) || !CelaBuida(figura, fila -1, columna-1)) {
                    trobat = false;
                }
            }
        }
    }
    return trobat;
}
void Tauler::colocarFigura(const Figura& figura) {

    for (int i = 0; i < figura.getNf(); i++) {
        for (int j = 0; j < figura.getNc(); j++) {
            if (figura.getValorCasella(j, i) != 0) {
                m_tauler[i + figura.getY() - 1][j + figura.getX() - 1] = figura.getColorFigura();

            }
        }
    }
    figuraColocada = true;
    
    /* int posicio_x, posicio_y;
    int forma[MAX_ALCADA][MAX_AMPLADA];
    figura.obtenirPosicio(posicio_x, posicio_y);
    figura.obtenirForma(forma);
    for (int i = 0; i < MAX_ALCADA; i++) {
        for (int j = 0; j < MAX_AMPLADA; j++) {
            int fila = posicio_y + j - figura.getJRef();
            int columna = posicio_x + i - figura.getIRef();
            if (forma[j][i] == 1) {
                m_tauler[fila][columna] = figura.getColorFigura();
            }
        }
    } */
}
int Tauler::eliminarFilesCompletades() {
    bool fila_completada = true;
    int comptFiles = 0;
    for (int i = MAX_FILA - 1; i >= 0; i--) {
        fila_completada = true;
        int j = 0;
       while(j < MAX_COL && fila_completada){
            if (m_tauler[i][j] == COLOR_NEGRE) {
                fila_completada = false;
            }
            else {
                j++;
            }
        }
        if (fila_completada) {
            for (int k = i; k > 0; k--) {
                for (int p = 0; p < MAX_COL; p++) {
                    m_tauler[k][p] = m_tauler[k - 1][p];
                }
            }
            for (int m = 0; m < MAX_COL; m++) {
                m_tauler[0][m] = COLOR_NEGRE;
            }
            comptFiles++;
        }
    }
    return comptFiles;
}
bool Tauler::DinsDelTauler(const Figura& figura, int fila, int columna) const {
    bool trobat = false;
    
    //if (fila+jmin >= 0 && fila+jmax-1 < MAX_FILA && columna+imin >= 0 && columna+imax-1 < MAX_COL)
        //trobat = true;
    //if (fila + figura.getJMin() >= 0 && fila  +figura.getJMax() - 1 < MAX_FILA && columna + figura.getIMin() >= 0 && columna  + figura.getIMax() - 1 < MAX_COL)
            //trobat = true;
    if (fila >= 0 && fila < MAX_FILA && columna >= 0 && columna < MAX_COL)
        trobat = true;
    return trobat;
}
bool Tauler::CelaBuida(Figura figura, int fila, int columna) const {
    
    return (m_tauler[fila][columna] == COLOR_NEGRE);
 
}