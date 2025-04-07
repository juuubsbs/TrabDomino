#include <iostream>

using namespace std;

#ifndef MAX_TAM
#define MAX_TAM 28 
#endif

// Definindo a estrutura para uma peça de dominó
struct Peca{
    int cima  = 0;  
    int baixo = 0; 
};

template <typename T>
struct Lista{
    T vetor[MAX_TAM];
    Peca primeira;
    Peca ultima;
};


bool inicializar(Lista<Peca> &lista, int numJogadores){
    //ver se tem de 2 a 4 pessoas pra jogar 
    if (numJogadores < 2 || numJogadores > 4) {
        return false; // só uma criatura não tem como jogar mais de 4 tambem não da 
    }

    // Criar todas as 28 peças de dominó cima e baixo
    int index = 0; // primeira casa do vetor 
    for (int cima = 0; cima <= 6; cima++) { //parte de cima começa 0 e pode ter ate 6 numeros mas so vira 1 depois q a barte de baxio vai do 0 a 6
        for (int baixo = cima; baixo <= 6; baixo++) { 
            lista.vetor[index] = Peca(cima, baixo);  
            index++;
        }
    }

    lista.ultimo = index - 1;  //voltando pra casa 27 

    return true;
}

bool distribuir(Lista<Peca> &lista, int numJogadores, Lista<Peca> &jogadores){
    if (numJogadores < 2 || numJogadores > 4){
        return false;
    }
    //pra todos os jogadores receberem a mesma quantidade de peças
    int pecasPorJogador = 7; 
    int index = 0;
    // Distribui as peças para os jogadores
    for (int i = 0; i < numJogadores; i++) {
        for (int j = 0; j < pecasPorJogador; j++) {
            jogadores[i].vetor[j] = lista.vetor[index++];
        }
        //pois inicializa de 0->27
        jogadores[i].ultimo = pecasPorJogador - 1;
    }

    return true;
}

bool inserirMesa(Lista<Peca> &mesa, Peca peca, Lista<Peca> &jogadores, int jogadorAtual) {
    // Se a mesa está vazia, qualquer peça pode ser inserida
    if (mesa.primeira.baixo == NULL && mesa.primeira.cima == NULL){  //tive que pega com nossa amiga IA essa parte 

        // Remove a peça da mão do jogador
        auto &jogador = jogadores[jogadorAtual];

        for (int i = 0; i <= jogador.ultimo; i++) {
            if (jogador.vetor[i].cima == peca.cima && jogador.vetor[i].baixo == peca.baixo) {
                for (int j = i; j < jogador.ultimo; j++) {
                    jogador.vetor[j] = jogador.vetor[j + 1];
                }
                jogador.ultimo--;
                break;
            }
        }
        return true;
    }

    // Verifica se a peça pode ser inserida (tem que ser compatível com uma das extremidades da mesa)
    if (peca.cima == mesa.ultima.baixo || peca.baixo == mesa.ultima.baixo || peca.cima == mesa.primeira.baixo || peca.baixo == mesa.primeira.baixo) {
        mesa.ultima = peca;
          // coloca a peca na mesa 
        // Remove a peça da mão do jogador
        auto& jogador = jogadores[jogadorAtual];
        for (int i = 0; i <= jogador.ultimo; i++) {
            if (jogador.vetor[i].cima == peca.cima && jogador.vetor[i].baixo == peca.baixo) {
                for (int j = i; j < jogador.ultimo; j++) {
                    jogador.vetor[j] = jogador.vetor[j + 1];
                }
                jogador.ultimo--;
                break;
            }
        }
        return true;
    }

    return false;  
}

// Função para exibir o estado da mesa
void mostrarMesa(Lista<Peca>& mesa) {
    cout << "Mesa: ";
    for (auto &peca : mesa) {
        cout << "[" << peca.cima << "|" << peca.baixo << "] ";
    }
    cout << endl;
}

// Função para mostrar as peças de um jogador
void mostrarJogador(const Lista<Peca> jogador) {
    cout << "Boneco tem: ";
    for (int i = 0; i <= jogador.ultimo; i++) {
        cout << "[" << jogador.vetor[i].cima << "|" << jogador.vetor[i].baixo << "] ";
    }
    cout << endl;
}

int main() {
    Lista <Peca> listaDePecas;
    Lista <Peca> jogadores[4];  // tem q ter de 2 a 4 pessoas pra funfa
    Lista <Peca> mesa; 

    int numJogadores;
    cout << "Digite o número de jogadores (2 a 4): ";
    cin >> numJogadores;

    // Inicializa as peças e distribui entre os jogadores
    if (!inicializar(listaDePecas, numJogadores)) {
        cout << "Número de jogadores inválido!" << endl;
        return 0;
    }

    if (!distribuir(listaDePecas, numJogadores, jogadores)) {
        cout << "Erro ao distribuir as peças!" << endl;
        return 0;
    }

    // Exibe as peças dos jogadores
    for (int i = 0; i < numJogadores; i++) {
        cout << "Jogador " << i + 1 << ":\n";
        mostrarJogador(jogadores[i]);
    }

    // Exemplo de inserção de peça na mesa
    cout << "Jogador 1 joga a peça [6|6]" << endl;
    inserirMesa(mesa, Peca(6, 6), jogadores, 0);
    mostrarMesa(mesa);

    // Exemplo de mais uma jogada
    cout << "Jogador 2 joga a peça [6|5]" << endl;
    inserirMesa(mesa, Peca(6, 5), jogadores, 1);
    mostrarMesa(mesa);



    return 0;
}
