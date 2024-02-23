#include <iostream>
#include <cstdlib>
#include <ctime> 

#define PEDRA 1
#define PAPEL 2
#define TESOURA 3

using namespace std;

class JogoPPT {
public:
    void Jogar(int palpiteJogador);
private:
    int SorteioCPU(); 
    void msgGanhou(const string& jogadaCPU, const string& jogadaJogador);
    void msgPerdeu(const string& jogadaCPU, const string& jogadaJogador);
    void msgEmpatou(const string& jogadaCPU, const string& jogadaJogador);
};

int JogoPPT::SorteioCPU() {
    srand(time(NULL));
    return (rand() % 3) + 1;
}

void JogoPPT::Jogar(int palpiteJogador) {
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

void JogoPPT::msgGanhou(const string& jogadaCPU, const string& jogadaJogador) {
    cout << "Voce ganhou!" << endl;
    cout << "Voce jogou " << jogadaJogador << " e o computador jogou " << jogadaCPU << "." << endl;
}

void JogoPPT::msgPerdeu(const string& jogadaCPU, const string& jogadaJogador) {
    cout << "Voce perdeu!" << endl;
    cout << "Voce jogou " << jogadaJogador << " e o computador jogou " << jogadaCPU << "." << endl;
}

void JogoPPT::msgEmpatou(const string& jogadaCPU, const string& jogadaJogador) {
    cout << "O jogo empatou!" << endl;
    cout << "Voce jogou " << jogadaJogador << " e o computador jogou " << jogadaCPU << "." << endl;
}

void IniciarJogo() {
    JogoPPT jogador;
    int palpiteJogador;

    cout << "1 - PEDRA" << endl << "2 - PAPEL" << endl << "3 - TESOURA" << endl;
    cout << "Escolha seu destino: ";
    cin >> palpiteJogador;

    if (palpiteJogador != 1 && palpiteJogador != 2 && palpiteJogador != 3) {
        cout << "Escolha inválida! Saindo..." << endl;
        exit(0);
    } else {
        jogador.Jogar(palpiteJogador);
    }
}

int main() {
    string versao = "1.0";
    string escolha;

    cout << "==================================" << endl;
    cout << "Pedra, Papel e Tesoura - Versao " << versao << endl;
    cout << "==================================" << endl << endl;

    while (true) {
        IniciarJogo();

        /*cout << endl << "Deseja jogar novamente? [S/n]: ";
        cin >> escolha;*/

        if (escolha == "n" || escolha == "N") {
            cout << "Saindo..." << endl;
            break;
        }

        cout << endl;
    }

    return 0;
    
}