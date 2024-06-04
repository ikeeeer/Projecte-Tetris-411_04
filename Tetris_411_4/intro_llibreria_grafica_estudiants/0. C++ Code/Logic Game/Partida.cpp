#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"
#include <iostream>
#include <fstream>

using namespace std;

Partida::Partida()
{
}
void Partida::inicialitzar() {
	m_temps = 0;
	m_fila = 1;
	m_columna = 5;
	m_puntuacio = 0;
	m_nivell = 1;
	creaNovaFigura();
	m_joc.inicialitzaTauler();
	nElim = 0;
	m_velocitat = 1.0;
}
void Partida::inicialitzaFigures(const string& fitxerFigures) {
	ifstream fitxer;
	NodeFigura* nodeAnterior;
	NodeFigura* nodeSeguent = NULL;

	fitxer.open(fitxerFigures);
	if (fitxer.is_open()) {

		primer = new NodeFigura();

		int tipus, fila, columna, gir;

		fitxer >> tipus;
		fitxer >> fila;
		fitxer >> columna;
		fitxer >> gir;

		Figura* f = new Figura(converteixTipusFigura(tipus), gir, columna - 1, fila - 1);

		primer->setFigura(*f);


		nodeAnterior = primer;

		while (!fitxer.eof()) {
			// construir el nodeFigura seguent

			nodeSeguent = new NodeFigura();
			// llegir seguent figura
			fitxer >> tipus;
			fitxer >> fila;
			fitxer >> columna;
			fitxer >> gir;

			// figura llegida al node
			f = new Figura(converteixTipusFigura(tipus), gir, columna - 1, fila - 1);
			// actualitza la figura al node
			nodeSeguent->setFigura(*f);
			//node anterior apunta al node actual
			nodeAnterior->setNext(nodeSeguent);
			nodeAnterior = nodeSeguent;

		}
		nodeSeguent->setNext(NULL);
		fitxer.close();
	}

}

TipusFigura Partida::converteixTipusFigura(int tipusAux) {
	TipusFigura tipus;

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
	return tipus;
}
void Partida::inicialitzaMoviments(const string& fitxerMoviments) {
	ifstream fitxer;
	fitxer.open(fitxerMoviments);
	if (fitxer.is_open()) {

		m_primer = new NodeMoviments();

		int valor;

		fitxer >> valor;

		m_primer->setValor(valor);

		NodeMoviments* nodeAnterior;
		NodeMoviments* nodeSeguent;


		nodeAnterior = m_primer;
		nodeSeguent = new NodeMoviments();

		while (fitxer >> valor) {

			nodeSeguent = new NodeMoviments();


			nodeSeguent->setValor(valor);
			nodeAnterior->setNext(nodeSeguent);
			nodeAnterior = nodeSeguent;
		}
		nodeSeguent->setNext(m_primer);
		fitxer.close();
	}
}
int Partida::getPrimerMoviment() {
	int valor = 0;
	if (m_primer != NULL) {
		valor = m_primer->getValor();
		NodeMoviments* next = m_primer->getNext();
		m_primer = next;
	}
	return valor;
}
void Partida::inicialitzaPartida(const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments) {
	m_joc.inicialitza(fitxerInicial);
	m_columna = m_joc.getPosX() + 1;
	m_fila = m_joc.getPosY() + 1;
	inicialitzaFigures(fitxerFigures);
	inicialitzaMoviments(fitxerMoviments);
}
bool Partida::creaNovaFigura() {
	int colorFigura = rand() % (GRAFIC_QUADRAT_VERD - GRAFIC_QUADRAT_GROC) + GRAFIC_QUADRAT_GROC;
	int tipusFigura = rand() % 7 + 1;
	return(m_joc.setFiguraActual(colorFigura, tipusFigura, m_fila - 1, m_columna - 1));
}

Figura& Partida::getPrimera() {
	Figura f;
	if (primer != NULL) {
		f = primer->getFigura();
		NodeFigura* next = primer->getNext();
		primer = next;
	}
	return f;
}
void Partida::puntuacio(int nElim)
{
	switch (nElim) //Sumem puntuacions segons el número de files eliminades. Com que "PlaySound()" només pot treballar amb una pista a la vegada, no podem afegir efectes a la partida.
	{
	case 0:
		m_puntuacio += 10;
		break;
	case 1:
		m_puntuacio += 110;
		break;
	case 2:
		m_puntuacio += 260;
		break;
	case 3:
		m_puntuacio += 385;
		break;
	case 4:
		m_puntuacio += 510;
		break;
	}

	if (m_puntuacio < 100)
	{
		m_nivell = 1;
	}
	else if (m_puntuacio < 200)
	{
		m_nivell = 2;
		m_velocitat = 0.90;
	}
	else if (m_puntuacio < 300)
	{
		m_nivell = 3;
		m_velocitat = 0.80;
	}
	else if (m_puntuacio < 400)
	{
		m_nivell = 4;
		m_velocitat = 0.70;
	}
	else if (m_puntuacio < 500)
	{
		m_nivell = 5;
		m_velocitat = 0.60;
	}
	else if (m_puntuacio < 1000)
	{
		m_nivell = 6;
		m_velocitat = 0.50;
	}
	else if (m_puntuacio < 2000)
	{
		m_nivell = 7;
		m_velocitat = 0.40;
	}
	else if (m_puntuacio < 3000)
	{
		m_nivell = 8;
		m_velocitat = 0.30;
	}
	else if (m_puntuacio < 4000)
	{
		m_nivell = 9;
		m_velocitat = 0.25;
	}
	else if (m_puntuacio < 10000)
	{
		m_nivell = 10;
		m_velocitat = 0.20;
	}
	else if (m_puntuacio < 11000)
	{
		m_nivell = 11;
		m_velocitat = 0.15;
	}
	else if (m_puntuacio < 12000)
	{
		{
			m_nivell = 11;
			m_velocitat = 0.10;
		}
	}
}

bool Partida::actualitza(int mode, double deltaTime)
{
	bool gameOver = true;
	bool primeraAparicio = false;
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
	string msg = "Fila: " + to_string(m_fila) + ", Columna: " + to_string(m_columna);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER - 100, POS_Y_TAULER - 50, 1.0, msg);

	m_temps += deltaTime;
	if (m_temps > 0.5 * getVelocitat())
	{
		if (m_joc.getPosY() == 1) //Si s'ha generat una nova figura després de baixar.
			puntuacio(nElim);
		nElim = m_joc.baixaFigura();
		if (m_fila < N_FILES_TAULER - 1 && (nElim != -1)) {
			m_fila++;
		}
		else {
			if (mode == CLASSICMODE) {
				m_fila = 1;
				m_columna = 5;
				if (!creaNovaFigura()) {
					gameOver = false;
				}
				else
					primeraAparicio = true;

			}
			else {
				Figura figAux = getPrimera();
				if (!figAux.esFiguraBuida()) {
					m_fila = figAux.getY() + 1;
					m_columna = figAux.getX() + 1;
					m_joc.setFiguraActual(figAux.getColorFigura(), figAux.getTipusFigura(), figAux.getY(), figAux.getX());
					primeraAparicio = true;
				}
				else gameOver = false;
			}
		}
		m_temps = 0;
	}
	if (!primeraAparicio) {
		if (mode == CLASSICMODE) {
			if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT)) {
				if (m_joc.mouFigura(1))
					m_columna++;

			}
			if (Keyboard_GetKeyTrg(KEYBOARD_LEFT)) {

				if (m_joc.mouFigura(-1))
					m_columna--;

			}
			if (Keyboard_GetKeyTrg(KEYBOARD_UP)) {
				m_joc.giraFigura(GIR_HORARI);
			}
			if (Keyboard_GetKeyTrg(KEYBOARD_DOWN)) {
				m_joc.giraFigura(GIR_ANTI_HORARI);
			}
			if (Keyboard_GetKeyTrg(KEYBOARD_SPACE)) {
				int posFila = m_fila;
				bool trobat = false;
				for (int i = m_fila; i < N_FILES_TAULER - 1 && !trobat; i++) {
					if (m_joc.baixaFigura() != -1) {
						posFila++;
					}
					else
						trobat = true;
				}
				m_fila = posFila;
				nElim = m_joc.baixaFigura();
				if (m_joc.getPosY() == 1)
					puntuacio(nElim);
			}
			string msg2 = "Level: " + to_string(m_nivell) + " Score: " + to_string(m_puntuacio);
			GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER + 225, POS_Y_TAULER - 50, 1, msg2);
		}
		else {
			// mode test
			//if (m_temps > 0.5) {
			int valor = getPrimerMoviment();
			switch (valor) {
			case 0:

				if (m_joc.mouFigura(-1))
					m_columna--;

				break;
			case 1:
				if (m_joc.mouFigura(1))
					m_columna++;
				break;
			case 2:
				m_joc.giraFigura(GIR_HORARI);
				break;
			case 3:
				m_joc.giraFigura(GIR_ANTI_HORARI);
				break;
			case 4:
				m_joc.baixaFigura();
				break;
			case 5:
				int posFila = m_fila;
				bool trobat = false;
				for (int i = m_fila; i < N_FILES_TAULER - 1 && !trobat; i++) {
					if (m_joc.baixaFigura() != -1) {
						posFila++;
					}
					else
						trobat = true;
				}
				m_fila = posFila;
				break;
			}
		}
	}


	dibuixaFigura();

	return gameOver;

}
void Partida::dibuixaFigura() const {
	for (int i = 1; i <= N_FILES_TAULER; i++) {
		for (int j = 1; j <= N_COL_TAULER; j++) {
			if (m_joc.getPosTauler(i - 1, j - 1) != COLOR_NEGRE) {
				IMAGE_NAME colorReal;
				switch (m_joc.getPosTauler(i - 1, j - 1)) {
				case COLOR_GROC: colorReal = GRAFIC_QUADRAT_GROC; break;
				case COLOR_BLAUCEL: colorReal = GRAFIC_QUADRAT_BLAUCEL; break;
				case COLOR_MAGENTA: colorReal = GRAFIC_QUADRAT_MAGENTA; break;
				case COLOR_TARONJA: colorReal = GRAFIC_QUADRAT_TARONJA; break;
				case COLOR_BLAUFOSC: colorReal = GRAFIC_QUADRAT_BLAUFOSC; break;
				case COLOR_VERMELL: colorReal = GRAFIC_QUADRAT_VERMELL; break;
				case COLOR_VERD: colorReal = GRAFIC_QUADRAT_VERD; break;
				}
				GraphicManager::getInstance()->drawSprite(colorReal, POS_X_TAULER + (j)*MIDA_QUADRAT, POS_Y_TAULER + (i - 1) * MIDA_QUADRAT, false);
			}
		}
	}
}
