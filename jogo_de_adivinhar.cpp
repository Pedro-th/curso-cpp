#include <iostream>
using namespace std;

int main () {
    int numeroSecreto=42;
    int chute=0,tentativas=0,numero_de_tentativas=0;
    double pontuacao = 1000;
    char dificuldade;
    bool naoAcertou = true;
    cout << "********************************* \n";
    cout << "* Bem vindo ao jogo de advinhar * \n";
    cout << "********************************* \n";
    cout << "qual nivel de difculdade vc quer (f/m/d): ";
    cin >> dificuldade;
    
    if (dificuldade == 'f') {
        numero_de_tentativas = 15;
    } else if (dificuldade == 'm') {
        numero_de_tentativas = 10;
    } else {
        numero_de_tentativas = 5;
    }

    double penalizacao = abs(chute-numeroSecreto)/2.0;
    

    for (tentativas = 1; tentativas <= numero_de_tentativas && naoAcertou; tentativas++) { 
     
    cout << "tentativa "<< tentativas << " qual seu chute: ";
    cin >> chute;
    
    penalizacao = abs(chute-numeroSecreto)/2.0;

   
    if (chute == numeroSecreto) {
        cout.precision(2);
        cout << fixed;
        cout << "acertou com: " << tentativas << " tentativas e " << pontuacao << " pontos" ;
        naoAcertou = false;

    }  else if (tentativas == numero_de_tentativas) {
        cout << "vc perdeu, tente novamente";
    } else if (chute > numeroSecreto) {
        cout << "o numero secreto eh menor\n";
        pontuacao -= penalizacao;
    } else if (chute < numeroSecreto) {
        cout << "o numero secreto eh maior\n";
        pontuacao -= penalizacao;
   }

   }
}