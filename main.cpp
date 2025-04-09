#include <iostream>
#include "ListaVetorial.cpp"
#include "LUE.hpp"

struct Peca{
    int cima;
    int baixo;
};

struct Jogador{

};

void IniciaListaDePeca(LUE<Peca> & l){


}
//vai precisar de uma adaptação pra utilizar os simbolos de >, < e = que estão na biblioteca LUE.hpp 


int main(){
    LUE<int> pecas;
    //LUE<int> jogador;

    pecas.instanciar();

    pecas.inserirUltimo(3);
    pecas.inserirUltimo(6); 
    pecas.imprimir();
    pecas.removerPosicao(0);
    pecas.imprimir();


    return 0;
}