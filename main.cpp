/*
The MIT License (MIT)

Copyright (c) 2016 Wolfgang Almeida <wolfgang.almeida@yahoo.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

#define PEDRA 1
#define PAPEL 2
#define TESOURA 3

using namespace std;

/* Classe Principal do Programa, responsável por fazer
 * a jogada do computador e verificar se o jogador ganhou
 * ou perdeu.
 */

	/* Iniciar o jogo e fazer a comparação. */

class JogoPPT {
public:

/*private:
    static int SorteioCPU();
        void msgGanhou(string jogadaCPU, string jogadaJogador);
        void msgPerdeu(string jogadaCPU, string jogadaJogador);
        void msgEmpatou(string jogadaCPU, string jogadaJogador);
};

static int SorteioCPU();
    void msgGanhou(const std::string& jogadaCPU, const std::string& jogadaJogador);
    void msgPerdeu(const std::string& jogadaCPU, const std::string& jogadaJogador);
    void msgEmpatou(const std::string& jogadaCPU, const std::string& jogadaJogador);



int JogoPPT::SorteioCPU() {
    srand(time(NULL));
    return (rand() % 3) + 1;
}
*/
    void Jogar(int palpiteJogador) {
		int palpiteCPU = SorteioCPU();

    switch (palpiteCPU) {
    case PEDRA:
        if (palpiteJogador == PEDRA) {
            msgEmpatou("pedra", "pedra");
        }
        else if (palpiteJogador == PAPEL) {
            msgGanhou("pedra", "papel");
        }
        else if (palpiteJogador == TESOURA) {
            msgPerdeu("pedra", "tesoura");
        }
        break;

    case PAPEL:
        if (palpiteJogador == PEDRA) {
            msgPerdeu("papel", "pedra");
        }
        else if (palpiteJogador == PAPEL) {
            msgEmpatou("papel", "papel");
        }
        else if (palpiteJogador == TESOURA) {
            msgGanhou("papel", "tesoura");
        }
        break;

    case TESOURA:
        if (palpiteJogador == PEDRA) {
            msgGanhou("tesoura", "pedra");
        }
        else if (palpiteJogador == PAPEL) {
            msgPerdeu("tesoura", "papel");
        }
        else if (palpiteJogador == TESOURA) {
            msgEmpatou("tesoura", "tesoura");
        }
        break;
    }
}

	/* Mensagens para o usuário, indicando se perdeu ou ganhou e 
	 * mostrando a jogada do computador. */
	void msgGanhou(string jogadaCPU, string jogadaJogador) {
            cout << "Voce Ganhou!";
            cout << "Você jogou " << jogadaJogador << " e o computador jogou " << jogadaCPU << "." << endl;    
    }
    void msgPerdeu(string jogadaCPU, string jogadaJogador) {
            cout << "Voce Perdeu!";
            cout << "Você jogou " << jogadaJogador << " e o computador jogou " << jogadaCPU << "." << endl;
    }
    void msgEmpatou(string jogadaCPU, string jogadaJogador){
            cout << "Deu empate!";
            cout << "Voce jogou" << jogadaJogador << "e o computador jogou" << jogadaCPU << "." << endl;
    }
private:
	/* Método de sorteio do computador. */
	int SorteioCPU(void) {
		srand(time(NULL));
		return (rand() % 3) + 1;
    }
};
/* Método de inicialização do Jogo, pedindo um palpite ao 
 * usuário e iniciando o jogo.
 */ 
void IniciarJogo() {
        JogoPPT jogador;
        int palpiteJogador;

        cout << "1-PEDRA" << endl << "2-PAPEL" << endl << "3-TESOURA";
        cout << "Escolha seu destino";
        cin >> palpiteJogador;

        if (palpiteJogador != 1 && palpiteJogador != 2 && palpiteJogador != 3) {
		cout << "Saindo..." << endl;
		exit(0);
    }
	else {
		jogador.Jogar(palpiteJogador);
	}
}
/* Método principal do programa. */
int main(void) {
    string versao = "1.0";
	string escolha;

	cout << "==================================" << endl;
	cout << "Pedra Papel e Tesoura - Versão " << versao << endl;
	cout << "==================================" << endl << endl;

	while(true) {
		IniciarJogo();

		cout << endl << "Deseja jogar novamente? [S/n]: ";
		cin >> escolha;

		if (escolha == "n" || escolha == "N") {
			cout << "Saindo..." << endl;
			break;
		}

		cout << endl;
	}

	return 0;
    
}