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

    pecas.inserirInicio(4);
    pecas.inserirInicio(3);
    //pecas.inserirUltimo(3);
    pecas.inserirPosicao(5, 1);
    pecas.inserirUltimo(9);
    pecas.inserirPosicao(20, 0);


    
    pecas.imprimir();



    return 0;
}