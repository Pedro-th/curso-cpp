#include <iostream>
using namespace std;

int main () {
    int numeroSecreto=42;
    int chute,tentativas=0;
    double pontuacao = 1000;
    
    cout << "********************************* \n";
    cout << "* Bem vindo ao jogo de advinhar * \n";
    cout << "********************************* \n";
    
    cout << "qual seu chute: ";
    cin >> chute;

    if (chute == numeroSecreto) {
        cout << "acertou com 1 tentativa e " << pontuacao << " pontos";
    } else if (chute > numeroSecreto) {
        cout << "o numero secreto eh menor\n";
        tentativas++;
    } else {
        cout << "o numero secreto eh maior\n";
        tentativas++;
    }
    double penalizacao = abs(chute-numeroSecreto)/2.0;
    pontuacao -= penalizacao;

    while (chute != numeroSecreto) {   
    tentativas++;
    cout << "qual seu chute: ";
    cin >> chute;
    penalizacao = abs(chute-numeroSecreto)/2.0;
    if (chute == numeroSecreto) {
        cout.precision(2);
        cout << fixed;
        cout << "acertou com: " << tentativas << " tentativas e " << pontuacao << " pontos" ;
    } else if (chute > numeroSecreto) {
        cout << "o numero secreto eh menor\n";
        pontuacao -= penalizacao;
    } else {
        cout << "o numero secreto eh maior\n";
        pontuacao -= penalizacao;
    }

  }

}
