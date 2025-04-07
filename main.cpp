#include <iostream>
#include "ListaVetorial2.cpp"
#include "LUE.hpp"

int main(){
    
    Lista<Peca> pecas;
    Lista<Peca> jogador1;
    Lista<Peca> jogador2;
    //Lista<Peca> jogador3;
    //Lista<Peca> jogador4;


    pecas.inicializar(2);

    pecas.mostrarPecas();

    jogador1.receber(pecas);
    //pecas.distribuir(jogador3);
    //pecas.distribuir(jogador4);

    jogador1.mostrarPecas();
    std:: cout << "agora vem as pecas dnv: " << std:: endl;
    pecas.mostrarPecas();

    //funcionandinho






    return 0;
}