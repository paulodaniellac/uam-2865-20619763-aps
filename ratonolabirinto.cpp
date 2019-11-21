#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>

using namespace std;

const int ELEMENTOALEATORIO[5] = { 1,2,3,4,5 };

void mostrarLabirinto(char lab[7][7]) {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cout << " " << lab[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

bool navegar(char labirinto[7][7], int x, int y, string passagem, bool &queijo, bool entrada, bool caminho, bool parede, bool espaco) {
	if (queijo == true) {
		return true;
	}
	else if (labirinto[x][y] == 'Q') {
		labirinto[x][y] = 'X';
		queijo = true;
		return true;
	}
	else if (labirinto[x][y] == 'E') {
		entrada = true;
		return false;
	}
	else if (labirinto[x][y] == '*') {
		caminho = true;
		return false;
	}
	else if (labirinto[x][y] == '#') {
		parede = true;
		return false;
	}
	else {
		labirinto[x][y] = 'R';
		mostrarLabirinto(labirinto);
		labirinto[x][y] = '*';
		if ((passagem != "descer") && queijo == false && navegar(labirinto, x + 1, y, "subir", queijo, entrada, caminho, parede, espaco)) {
			labirinto[x][y] = 'R';
			mostrarLabirinto(labirinto);
			labirinto[x][y] = ' ';
			return true;
		}
		else if ((passagem != "direita") && queijo == false && navegar(labirinto, x, y + 1, "esquerda", queijo, entrada, caminho, parede, espaco)) {
			labirinto[x][y] = 'R';
			mostrarLabirinto(labirinto);
			labirinto[x][y] = ' ';
			return true;
		}
		else if ((passagem != "subir") && queijo == false && navegar(labirinto, x - 1, y, "descer", queijo, entrada, caminho, parede, espaco)) {
			labirinto[x][y] = 'R';
			mostrarLabirinto(labirinto);
			labirinto[x][y] = ' ';
			return true;
		}
		else if ((passagem != "esquerda") && queijo == false && navegar(labirinto, x, y - 1, "direita", queijo, entrada, caminho, parede, espaco)) {
			labirinto[x][y] = 'R';
			mostrarLabirinto(labirinto);
			labirinto[x][y] = ' ';
			return true;
		}
		else {
			labirinto[x][y] = 'R';
			mostrarLabirinto(labirinto);
			labirinto[x][y] = ' ';
			return false;
		}

	}
}

int elementoAleatorio() {
	return ELEMENTOALEATORIO[rand() % 5];
}

int main()
{
	clock_t tempoInicial;
	double duracao;

	srand(time(0));
	char labirinto[7][7] = {
		{ '#','#','#','#','#','#','#' },
		{ '#',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#' }
	};

	int xEntrada = elementoAleatorio();
	int yEntrada = elementoAleatorio();

	labirinto[xEntrada][yEntrada] = 'R';
	labirinto[elementoAleatorio()][elementoAleatorio()] = 'Q';
	labirinto[elementoAleatorio()][elementoAleatorio()] = '#';

	bool temQueijo = false;

	tempoInicial = clock();

	navegar(labirinto, xEntrada, yEntrada, "entrada", temQueijo, false, false, false, false);

	duracao = (clock() - tempoInicial) / (double)CLOCKS_PER_SEC;

	cout << "Tempo decorrido: " << duracao << "s \n";

	return 0;
}