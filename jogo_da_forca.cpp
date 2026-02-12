#include <iostream>
using namespace std;

bool letra_pertencente (char chute, string palavra) {
    int i;
    for (i=0; i < int(palavra.size()); i++) {
        if (chute == palavra[i]) {
            return true;
        } 
    }
    return false;

}

int main () {
char chute;
string palavra_secreta = "melancia";
bool nao_acertou = true;
bool nao_enforcou =  true;

while (nao_acertou && nao_enforcou) {
    cout << "qual seu chute: ";
    cin >> chute;
    if (letra_pertencente(chute,palavra_secreta)) {
        cout << "seu chute esta na palavra secreta\n";
    } else {
        cout << "seu chute nao esta na palavra secreta\n";
    }

    }

}