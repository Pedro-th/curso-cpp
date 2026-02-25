#include <iostream>
#include <map>
#include <vector>
using namespace std;
string palavra_secreta = "melancia";
//dicionario em c++
map<char,bool> chutou;
//vetor dinamico
vector<char> chutes_errados;

bool letra_pertencente (char chute, string palavra) {
    int i;
    for (i=0; i < int(palavra.size()); i++) {
        if (chute == palavra[i]) {
            return true;
        } 
    }
    return false;

}
//função que continua o jogo se o chute está na palavra secreta
bool nao_acertou () {
    for (char letra : palavra_secreta) {
        if (!chutou[letra]) {
            return true;
        }
    }
    return false;
}
//fução que delimita o numero de tentativas pra 5, assim como no jogo da forca
bool nao_enforcou () {
    return chutes_errados.size() < 5;
}



int main () {
    cout << "*******************************\n";
    cout << "******* jogo da forca *********\n";
    cout << "*******************************\n";

char chute;

while (nao_acertou() && nao_enforcou()) {
    cout << "chutes errados: ";
    for (char letra : chutes_errados) {
        cout << letra << " ";
    } 
    cout << endl;
    //esse for intera a letra atraves da palavra secreta
    for (char letra : palavra_secreta) {
        if (chutou[letra]) {
            cout << letra << " ";
        } else {
            cout << "_ ";
        }
    }
    
    cout <<"\n qual seu chute: ";
    cin >> chute;
    
    chutou[chute] = true;

    if (letra_pertencente(chute,palavra_secreta)) {
        cout << "seu chute esta na palavra secreta\n";
    } else {
        cout << "seu chute nao esta na palavra secreta\n";
        chutes_errados.push_back(chute);

    }

    }
    cout << "fim de jogo" << endl;
    if (nao_acertou()) {
        cout << "vc perdeu, tente novamente";
    } else {
        cout << "parabens, vc ganhou";
    }


}