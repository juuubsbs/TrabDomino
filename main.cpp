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
    Lista<int> pecas;
    //LUE<int> jogador;

    pecas.inicializar();

    pecas.inserirInicio(4);
    pecas.inserirFinal(3);
    pecas.inserirFinal(21);
    pecas.inserirPosicao(17, 2);

    
    pecas.imprimir();
    std:: cout << " ";

    std:: cout << "aqui:" << pecas.descobrirIndice(56) << " ";

    //pecas.descobrirIndice(21);

    pecas.imprimir();



    return 0;
}