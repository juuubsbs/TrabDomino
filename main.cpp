#include <iostream>
#include "ListaVetorial.cpp"
#include "LUE.hpp"

struct Peca{
    int cima;
    int baixo;

    //default
    Peca() : cima(0), baixo(0) {}

    Peca(int c, int b) : cima(c), baixo(b) {}
};

//aqui é pra definição de como os operadores irão lidar com Pecas
std:: ostream &operator<<(std:: ostream &os, Peca &valor){
    os << "[" << valor.cima << "|" << valor.baixo << "]";
    return os;
}
bool operator==(Peca &peca1, Peca &peca2){
    return (peca1.cima == peca2.cima && peca1.baixo == peca2.baixo);
}

//estes são por desencargo de consciencia, mas a principio não vao ser usados
bool operator!=(Peca &peca1, Peca &peca2){
    return !(peca1 == peca2);
}



struct Jogador{

};

void IniciaListaDePeca(LUE<Peca> & l){


}
//vai precisar de uma adaptação pra utilizar os simbolos de >, < e = que estão na biblioteca LUE.hpp 


int main(){
    LUE<Peca> pecas;
    //LUE<int> jogador;
    Peca oi(2,3);

    

    pecas.instanciar();

    pecas.inserirInicio(oi);

    oi.baixo = 9;
    oi.cima = 1;
    pecas.inserirInicio(oi);

    oi.baixo = 5;
    oi.cima = 12;
    pecas.inserirPosicao(oi, 1);

    pecas.imprimir();
    pecas.obterItem(1);
    pecas.imprimir();


    return 0;
}