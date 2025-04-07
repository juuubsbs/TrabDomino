#include <iostream>
//#include "ListaVetorial2.cpp"
#include "LUE.hpp"

struct Peca{
    int cima;
    int baixo;
};

struct Jogador{

};

void IniciaListaDePeca(LUE<Peca> & l){

}


int main(){
    LUE<int> pecas;
    //LUE<Jogador> jogadores;

    pecas.instanciar();

    pecas.inserir(8);
    pecas.inserir(3);
    pecas.inserir(1);
    pecas.inserir(7);

    pecas.descobrirIndice(10);

    pecas.imprimir();



    return 0;
}