#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void jogarAdivinhacao() {
    srand(time(0)); // Semente para gerar números aleatórios
    int numeroSecreto = rand() % 100 + 1; // Número aleatório entre 1 e 100
    int tentativa;
    int tentativas = 0;
    const int maxTentativas = 7;

    cout << "Bem-vindo ao jogo de Adivinhacao!" << endl;
    cout << "Tente adivinhar o numero secreto entre 1 e 100." << endl;

    while (tentativas < maxTentativas) {
        cout << "Tentativa " << tentativas + 1 << ": ";
        cin >> tentativa;
        tentativas++;

        if (tentativa < numeroSecreto) {
            cout << "Tente um numero maior." << endl;
        } else if (tentativa > numeroSecreto) {
            cout << "Tente um numero menor." << endl;
        } else {
            cout << "Parabens! Voce acertou o numero secreto " << numeroSecreto << " em " << tentativas << " tentativa(s)." << endl;
            return;
        }
    }

    cout << "Voce perdeu! O numero secreto era " << numeroSecreto << "." << endl;
}

int main() {
    jogarAdivinhacao();
    return 0;
}