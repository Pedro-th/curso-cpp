#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
string palavra_secreta = " ";
//dicionario em c++
map<char,bool> chutou;
//vetor dinamico
vector<char> chutes_errados;


void salva_arquivo (vector <string> nova_lista) {
    ofstream arquivo;
    arquivo.open("tripulantes.txt");
    if (arquivo.is_open()) {
        arquivo << nova_lista.size() << endl;
        for (string palavra : nova_lista) {
            arquivo << palavra << endl;
        } 
        arquivo.close();
        
    }
    else {
            cout << "não foi possivel acessar o banco de palavras";
        }
}

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

vector <string> ler_arquivo() {
    int i;
    ifstream arquivo("tripulantes.txt");
    int quantidade_de_palavras;
    arquivo >> quantidade_de_palavras;
    vector<string> tripulantes;

    for (i=0; i < quantidade_de_palavras; i++) {
        string palavra_lida;
        arquivo >> palavra_lida;
        tripulantes.push_back(palavra_lida);
    }
    arquivo.close();
    return tripulantes;
}

void sorteia_palavra () {
    vector <string> palavras = ler_arquivo();
    srand(time(NULL));
    int indice_sorteio = rand() % palavras.size();
    palavra_secreta = palavras[indice_sorteio];
}

void adiciona_palavra () {
    cout << "digite um novo tripulante: ";
    string novo_tripulante;
    cin >> novo_tripulante;
    vector <string> lista_palavras = ler_arquivo();
    lista_palavras.push_back(novo_tripulante);
    salva_arquivo(lista_palavras);
}





int main () {
    cout << "*******************************\n";
    cout << "******* advinhe o tripulante *********\n";
    cout << "*******************************\n";

char chute;

ler_arquivo ();
sorteia_palavra();
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
        cout << "vc deseja adicionar uma nova palavra ao ao banco?(s/n) :";
        char escolha;
        cin >> escolha;
        if (escolha == 's') {
            adiciona_palavra();
        }
    }


}