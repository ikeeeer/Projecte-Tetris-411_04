#include "Figura.h"

void Figura::moureEsquerra() {
    posicio_x--;
}
void Figura::moureDreta() {
    posicio_x++;
}
void Figura::baixar() {
    posicio_y++;
}
void Figura::obtenirPosicio(int& posicio_x2, int& posicio_y2) const {
    posicio_x2 = posicio_x;
    posicio_y2 = posicio_y;
}
void Figura::inicialitzarForma() {
    for (int i = 0; i < MAX_AMPLADA; ++i) {
        for (int j = 0; j < MAX_ALCADA; ++j) {
            forma[i][j] = 0;
        }
    }
    switch (tipus) {
    case FIGURA_O:
        forma[0][0] = 1;
        forma[0][1] = 1;
        forma[1][0] = 1;
        forma[1][1] = 1;
        color = COLOR_GROC;
        nc = 2;
        nf = 2;
        iRef = 0;
        jRef = 0;
        break;
    case FIGURA_I:
        forma[1][0] = 1;
        forma[1][1] = 1;
        forma[1][2] = 1;
        forma[1][3] = 1;
        color = COLOR_BLAUCEL;
        nc = 4;
        nf = 4;
        iRef = 1;
        jRef = 2;
        break;
    case FIGURA_T:
        forma[1][0] = 1;
        forma[1][1] = 1;
        forma[1][2] = 1;
        forma[0][1] = 1;
        iRef = 1;
        jRef = 1;
        nc = 3;
        nf = 3;
        color = COLOR_MAGENTA;
        break;
    case FIGURA_L:
        forma[1][0] = 1;
        forma[1][1] = 1;
        forma[1][2] = 1;
        forma[0][2] = 1;
        iRef = 1;
        jRef = 1;
        color = COLOR_TARONJA;
        nc = 3;
        nf = 3;
        break;
    case FIGURA_J:
        forma[1][0] = 1;
        forma[1][1] = 1;
        forma[1][2] = 1;
        forma[0][0] = 1;
        iRef = 1;
        jRef = 1;
        color = COLOR_BLAUFOSC;
        nc = 3;
        nf = 3;
        break;
    case FIGURA_Z:
        forma[1][2] = 1;
        forma[1][1] = 1;
        forma[0][1] = 1;
        forma[0][0] = 1;
        iRef = 1;
        jRef = 1;
        color = COLOR_VERMELL;
        nc = 3;
        nf = 3;
        break;
    case FIGURA_S:
        forma[1][0] = 1;
        forma[1][1] = 1;
        forma[0][1] = 1;
        forma[0][2] = 1;
        iRef = 1;
        jRef = 1;
        color = COLOR_VERD;
        nc = 3;
        nf = 3;
        break;
    default:
        break;
    }

    
    imin = 4; jmin = 4;
    imax = 0; jmax = 0;

    for (int i = 0; i < MAX_ALCADA; i++) {
        for (int j = 0; j < MAX_AMPLADA; j++) {
            if (forma[i][j] != 0) {
                if (i < imin) imin = i;
                if (j < jmin) jmin = j;
                if (i > imax) imax = i;
                if (j > jmax) jmax = j;
            }
        }
    }

}
void Figura::obtenirForma(int forma_actual[MAX_AMPLADA][MAX_ALCADA]) const {
    for (int i = 0; i < MAX_ALCADA; ++i) {
        for (int j = 0; j < MAX_AMPLADA; ++j) {
            forma_actual[i][j] = forma[i][j];
        }
    }
}
void Figura::girar(const DireccioGir direccio, int gir) {
    int transposada[MAX_ALCADA][MAX_AMPLADA];
    int girada[MAX_ALCADA][MAX_AMPLADA];
    for (int i = 0; i < MAX_AMPLADA; ++i) {
        for (int j = 0; j < MAX_ALCADA; ++j) {
            transposada[i][j] = 0;
            girada[i][j] = forma[i][j];;
        }
    }
    for (int k = 0; k < gir; k++) {
        for (int i = 0; i < nf; ++i) {
            for (int j = 0; j < nc; ++j) {
                transposada[i][j] = girada[j][i];
                girada[j][i] = 0;
            }
        }
        if (direccio == GIR_HORARI) {
            for (int i = 0; i < nf; ++i) {
                for (int j = 0; j < nc; ++j) {
                    girada[i][j] = transposada[i][nc - j - 1];
                }
            }
        }
        else if (direccio == GIR_ANTI_HORARI) {
            for (int i = 0; i < nf; ++i) {
                for (int j = 0; j < nc; ++j) {
                    girada[i][j] = transposada[nf - i - 1][j];
                }
            }
        }
    }
    for (int i = 0; i < MAX_ALCADA; ++i) {
        for (int j = 0; j < MAX_AMPLADA; ++j) {
            forma[i][j] = girada[i][j];
        }
    }
}