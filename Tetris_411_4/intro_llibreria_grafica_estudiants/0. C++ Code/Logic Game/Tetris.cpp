#include "Tetris.h"

// Library effective with Windows
#include <windows.h>



using namespace std;

int Tetris::getOpcioMenu() {
	int mode = 0;
	cout << "------------------------TETRIS---------------------------------------" << endl;
	cout << "---------------------------------------------------------------------" << endl << endl;
	cout << "Tria un mode:" << endl;
	cout << "1. Clàssic" << endl;
	cout << "2. Mode test" << endl;
	cout << "3. Mostra puntuacions" << endl;
	cout << "4. Sortir" << endl;
	cin >> mode;
	while ((mode > 4) || (mode < 1)) {
		cout << "Prem una de les opcions" << endl;
		cin >> mode;
	}
	return mode;

}

int Tetris::jugar(Screen& pantalla, TipusMode mode) {

	bool final = false;
	bool continuar = true;

	//Mostrem la finestra grafica
	pantalla.show();

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;
	if (mode == CLASSICMODE) {
		m_partida.inicialitzar();
		do
		{
			LAST = NOW;
			NOW = SDL_GetPerformanceCounter();
			deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

			// Captura tots els events de ratolí i teclat de l'ultim cicle
			pantalla.processEvents();

			continuar = m_partida.actualitza(mode, deltaTime);

			// Actualitza la pantalla
			pantalla.update();

			if (Keyboard_GetKeyTrg(KEYBOARD_ESCAPE)) final = true;

		} while (!final && continuar);
		// Sortim del bucle si pressionem ESC
	}
	else {
		string fitxerInicial, fitxerFigura, fitxerMoviments;
		cout << "Fitxer incial: ";
		cin >> fitxerInicial;
		cout << endl << "Fitxer figures: ";
		cin >> fitxerFigura;
		cout << endl << "Fitxer moviments: ";
		cin >> fitxerMoviments;
		m_partida.inicialitzaPartida(fitxerInicial, fitxerFigura, fitxerMoviments);
		do
		{
			LAST = NOW;
			NOW = SDL_GetPerformanceCounter();
			deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

			// 
			// 
			// Captura tots els events de ratolí i teclat de l'ultim cicle
			//pantalla.processEvents();

			continuar = m_partida.actualitza(mode, deltaTime);
			Sleep(500);
			// Actualitza la pantalla
			pantalla.update();

			if (Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
				final = true;

		} while (!final && continuar);

	}
	return 10; //puntuacio
}