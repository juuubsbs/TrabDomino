#include <iostream>
#include "ListaVetorial.hpp"
#include "LUE.hpp"

struct Peca{
    int cima;
    int baixo;

    Peca() : cima(-1), baixo(-1) {}
    Peca(int c, int b) : cima(c), baixo(b) {} // Construtor necessário

    void inverter() {
        int temp = cima;
        cima = baixo;
        baixo = temp;
    }

    bool ehDupla() const {
        return cima == baixo;
    }
};

std::ostream& operator<<(std::ostream &os, const Peca &valor){
    os << "[" << valor.cima << "|" << valor.baixo << "]";
    return os; // Retorno necessário
}

bool operator==(const Peca &peca1, const Peca &peca2){
    return (peca1.cima == peca2.cima && peca1.baixo == peca2.baixo) ||
           (peca1.cima == peca2.baixo && peca1.baixo == peca2.cima);
    // Retorno necessário (a lógica já estava aqui)
}

bool operator!=(const Peca &peca1, const Peca &peca2){
    return !(peca1 == peca2); // Retorno necessário
}


// --- Funções do Jogo Adaptadas para Usar Assinaturas Originais (T valor) ---

LUE<Peca> criarMonte() {
    LUE<Peca> monte;
    monte.instanciar();
    for (int i = 0; i <= 6; ++i) {
        for (int j = i; j <= 6; ++j) {
            Peca p(i, j);
            monte.inserirUltimo(p); // Passa Peca por valor
        }
    }
    return monte;
}

void distribuirPecas(LUE<Peca>& monte, Lista<Peca>& maoJogador, int numPecas) {
    for (int i = 0; i < numPecas; ++i) {
        if (monte.tamanho == 0) break;
        Peca pecaComprada = monte.obterItem(0);
        monte.removerInicio();
        maoJogador.inserirFinal(pecaComprada); // Passa Peca por valor
    }
}

void imprimirMao(const Lista<Peca>& mao, int jogador) {
    //cores
    std:: string codigo;
    if((jogador / 2) != 0){
        codigo = "\e[0;36m";//azul ciano
    }
    else codigo = "\e[0;33m";//amarelo

    std::cout << codigo << "Jogador " << jogador << " Mao: ";
    for (int i = 0; i <= mao.ultimo; ++i) {
        std::cout << "(" << i << ")" << mao.obterItem(i) << " ";
    }
    std::cout << "\e[0m" << std::endl;
}

void imprimirMesa(const LUE<Peca>& mesa) {
    std::cout << "Mesa: ";
    if (mesa.tamanho == 0) {
        std::cout << "\e[0;31m(vazia)\e[0m";
    } else {
        mesa.imprimir(); // LUE.imprimir (já tem \n no final)
    }
    std::cout << "------------------------------------" << std::endl;
}

bool comprarPeca(LUE<Peca>& monte, Lista<Peca>& mao) {
    if (monte.tamanho == 0) {
        std::cout << "Monte vazio!" << std::endl;
        return false;
    }
    Peca pecaComprada = monte.obterItem(0);
    monte.removerInicio();
    mao.inserirFinal(pecaComprada); // Passa Peca por valor
    std::cout << "Comprou a peca: " << pecaComprada << std::endl;
    return true;
}

bool podeJogar(Peca peca, const LUE<Peca>& mesa, int& lado, bool& inverte) {
    lado = -1;
    inverte = false;

    if (mesa.tamanho == 0) {
        lado = 0;
        return true;
    }

    Peca pontaEsquerda = mesa.obterItem(0);
    Peca pontaDireita = mesa.obterItem(mesa.contador); // Usa contador para índice do último

    if (peca.cima == pontaEsquerda.cima) {
        lado = 0; inverte = true; return true;
    }
    if (peca.baixo == pontaEsquerda.cima) {
        lado = 0; inverte = false; return true;
    }
    if (peca.cima == pontaDireita.baixo) {
        lado = 1; inverte = false; return true;
    }
    if (peca.baixo == pontaDireita.baixo) {
        lado = 1; inverte = true; return true;
    }

    return false;
}


// --- Função Principal (main) Usando Assinaturas Originais ---
int main() {
    LUE<Peca> monte;
    Lista<Peca> maoJogador1;
    Lista<Peca> maoJogador2;
    LUE<Peca> mesa;
    int numPecas;
    int rodada;

    // 1. Inicializar
    monte.instanciar();
    maoJogador1.inicializar();
    maoJogador2.inicializar();
    mesa.instanciar();
    numPecas = 7;
    rodada = 0;

    // 2. Criar monte
    monte = criarMonte();

    // 3. Distribuir peças
    distribuirPecas(monte, maoJogador1, numPecas);
    distribuirPecas(monte, maoJogador2, numPecas);

    std::cout << "\e[0;35m--- Distribuicao Inicial ---\e[0m" << std::endl;
    imprimirMao(maoJogador1, 1);
    imprimirMao(maoJogador2, 2);
    std::cout << "\e[0;35m----------------------------\e[0m" << std::endl;

    int jogadorAtual = 1;
    bool alguemGanhou = false;
    bool primeiroMovimentoFeito = false;

    // 4. Determinar quem começa com [6|6]
    Peca seisSeis(6, 6);
    int indiceSeisSeis1 = maoJogador1.descobrirIndice(seisSeis); // Passa Peca por valor
    int indiceSeisSeis2 = maoJogador2.descobrirIndice(seisSeis); // Passa Peca por valor

    if (indiceSeisSeis1 != -1) {
        std::cout << "Jogador 1 tem [6|6] e comeca." << std::endl;
        maoJogador1.removerPosicao(indiceSeisSeis1);
        mesa.inserirInicio(seisSeis); // Passa Peca por valor
        jogadorAtual = 2;
        primeiroMovimentoFeito = true;
        rodada++;
    } else if (indiceSeisSeis2 != -1) {
        std::cout << "Jogador 2 tem [6|6] e comeca." << std::endl;
        maoJogador2.removerPosicao(indiceSeisSeis2);
        mesa.inserirInicio(seisSeis); // Passa Peca por valor
        jogadorAtual = 1;
        primeiroMovimentoFeito = true;
        rodada++;
    } else {
        std::cout << "Ninguem tem [6|6]. Jogador 1 comeca." << std::endl;
        jogadorAtual = 1;
        primeiroMovimentoFeito = false;
        rodada++;
    }

    if (primeiroMovimentoFeito) {
         std::cout << "\n--- Apos primeira jogada ([6|6]) ---" << std::endl;
         imprimirMesa(mesa);
         imprimirMao(maoJogador1, 1);
         imprimirMao(maoJogador2, 2);
         std::cout << "------------------------------------" << std::endl;
    }

    bool passouTurno[2] = {false, false};

    // 5. Loop principal
    while (!alguemGanhou) {
        Lista<Peca>& maoAtual = (jogadorAtual == 1) ? maoJogador1 : maoJogador2;

        //cores
        std:: cout << "\n\e[0;35mRodada " << rodada << "\e[0m";
        std:: string codigo;
        if((jogadorAtual / 2) != 0){
            codigo = "\e[0;36m";//azul ciano
        }
        else codigo = "\e[0;33m";//amarelo

        std::cout << codigo << "\n=== Vez do Jogador " << jogadorAtual << " ===\e[0m" << std::endl;
        imprimirMesa(mesa);
        imprimirMao(maoAtual, jogadorAtual);

        // 6. Tentar encontrar jogada
        int indiceJogavel = -1;
        int ladoJogada = -1;
        bool invertePeca = false;

        for (int i = 0; i <= maoAtual.ultimo; ++i) {
            Peca pecaTeste = maoAtual.obterItem(i);
            if (podeJogar(pecaTeste, mesa, ladoJogada, invertePeca)) {
                indiceJogavel = i;
                break;
            }
        }

        // 7. Realizar jogada ou comprar/passar
        if (indiceJogavel != -1) {
             passouTurno[jogadorAtual - 1] = false;
            Peca pecaParaJogar = maoAtual.obterItem(indiceJogavel);
            std::cout << "Jogador " << jogadorAtual << " joga " << pecaParaJogar << std::endl;
            maoAtual.removerPosicao(indiceJogavel);
            if (invertePeca) {
                pecaParaJogar.inverter();
            }
            if (mesa.tamanho == 0 || ladoJogada == 0) {
                 mesa.inserirInicio(pecaParaJogar); // Passa Peca por valor
            } else {
                mesa.inserirUltimo(pecaParaJogar); // Passa Peca por valor
            }
        } else {
            std::cout << "Jogador " << jogadorAtual << " nao tem pecas para jogar." << std::endl;
            if (monte.tamanho > 0) {
                comprarPeca(monte, maoAtual);
                passouTurno[jogadorAtual - 1] = false;
            } else {
                std::cout << "Monte vazio. Jogador " << jogadorAtual << " passa a vez." << std::endl;
                passouTurno[jogadorAtual - 1] = true;
                 if(passouTurno[0] && passouTurno[1]) {
                     std::cout << "\nJOGO TRANCADO! (Ambos passaram sem pecas no monte)" << std::endl;
                     std::cout << "Resultado: Jogo Trancado." << std::endl;
                     imprimirMao(maoJogador1, 1);
                     imprimirMao(maoJogador2, 2);
                     alguemGanhou = true;
                 }
            }
        }

        // 8. Verificar vitória
        if (!alguemGanhou && maoAtual.tamanho == 0) {
            alguemGanhou = true;
            std::cout << "\n\e[0;32m!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
            std::cout << "         Jogador " << jogadorAtual << " VENCEU!" << std::endl;
            std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\e[0m" << std::endl;
            imprimirMesa(mesa);
            imprimirMao(maoJogador1, 1);
            imprimirMao(maoJogador2, 2);
        } else if (!alguemGanhou) {
            // 9. Passar a vez
            jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
            std:: cout << "Pressione qualquer tecla para continuar...";
            std:: cin.get();
            std::cout << std::string(50, '\n');//printa muitos \n
            rodada++;
        }
    } // Fim do while

    return 0;
}