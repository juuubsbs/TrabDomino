#ifndef MAX_TAM
#define MAX_TAM 28 
#endif

#include <iostream>

// Definindo a estrutura para uma peça de dominó
struct Peca{
    int cima  = 0;  
    int baixo = 0; 
};

template <typename T>
struct Lista{
    Peca vetor[MAX_TAM];
    Peca *primeira;
    int ultimo;

    bool inicializar(int numJogadores){
        //ver se tem de 2 a 4 pessoas pra jogar 
        if (numJogadores < 2 || numJogadores > 4) {
            std:: cout << "Numero de jogadores incorreto!";
            return false; // só uma criatura não tem como jogar mais de 4 tambem não da 
        }
    
        // Criar todas as 28 peças de dominó cima e baixo
        int i = 0; // primeira casa do vetor 
        for (int cima = 0; cima <= 6; cima++) { //parte de cima começa 0 e pode ter ate 6 numeros mas so vira 1 depois q a barte de baxio vai do 0 a 6
            for (int baixo = cima; baixo <= 6; baixo++) {
                this->vetor[i].baixo = baixo;
                this->vetor[i].cima = cima;

                i++;
            }
        }

        ultimo = i - 1;
    
        return true;
    }

    bool receber(Lista<Peca> &pecas){
        Lista<Peca> novoPecas;
        //pra todos os jogadores receberem a mesma quantidade de peças
        int pecasPorJogador = 7; 
        // Distribui as peças para o jogador, já removendo a peça de "peças"
        for (int i = 0; i < pecasPorJogador; i++) {
            std:: cout << i;
            this->vetor[i] = pecas.vetor[i];

        }

        //nao tá deletando ainda mas eu só n tenho mais neuronios
        this->ultimo = 7 - 1;
        return true;
    }

    void mostrarPecas() {
        std:: cout << "Boneco tem: ";
        for (int i = 0; i <= ultimo; i++) {
            std:: cout << "[" << vetor[i].cima << "|" << vetor[i].baixo << "] ";
        }
        std:: cout << std:: endl;
    }
};