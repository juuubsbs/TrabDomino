#ifndef MAX_TAM
#define  MAX_TAM 28
#endif


#include <iostream>

template <typename T>
struct Lista{
    T vetor[MAX_TAM];
    int ultimo;
    int aux;
    int inicio;

    void inicializar();

    bool inserirInicio(T valor);

    bool inserirPosicao(T valor, int posicao);

    bool inserirFinal(T valor);

    bool removerPosicao(int posicao);

    bool removerInicio();
    
    bool removerFinal();

    T obterItem(int posicao);

    bool contemItem(T valor);

    int descobrirIndice(T valor);

    void imprimir();
};

//implementação

template <typename T>
void Lista<T>:: inicializar(){
    inicio = 0;
    ultimo = -1;
    aux = 0;
}

template <typename T>
bool Lista<T>:: inserirInicio(T valor){
    if( ultimo == MAX_TAM-1) return false;
    
    if(ultimo == -1){
        vetor[0] = valor;
        ultimo++;
        return true;
    }
    else{
        int i = ultimo;
        while( i >= inicio ){
            vetor[i+1] = vetor[i];
            i--;
        }
        ultimo++;
        vetor[0] = valor;
        return true;
    }
    return false;
}

template <typename T>
bool Lista<T>:: inserirPosicao(T valor, int posicao){
    if(ultimo == MAX_TAM-1 || posicao < 0 || posicao > ultimo+1) return false;

    if(posicao == inicio){
        inserirInicio(valor);
        return true;
    }
    else{
        int i = posicao;
        while( i <= ultimo ){
            vetor[i+1] = vetor[i];
            i++;
        }
        ultimo++;
        vetor[posicao] = valor;
    }
    return true;
}

template <typename T>
bool Lista<T>:: inserirFinal(T valor){
    if( ultimo == MAX_TAM-1) return false;

    vetor[ultimo+1] = valor;
    ultimo++;
    return true;

}

template <typename T>
bool Lista<T>:: removerPosicao(int posicao){

    if(posicao < 0 || posicao > ultimo) return false;

    for( int i = posicao; i < ultimo; i++ ){
        vetor[i] = vetor[i+1];
    }
    ultimo--;
    return true;  
}

template <typename T>
bool Lista<T>:: removerInicio(){
    //lista vazia
    if(ultimo == -1) return false;

    for( int i = inicio; i < ultimo; i++ ){
        vetor[i] = vetor[i+1];
    }
    ultimo--;
    return true;
} 

template <typename T>
bool Lista<T>:: removerFinal(){
    //lista vazia
    if(ultimo == -1) return false;

    ultimo--;
    return true;
}

template <typename T>
T Lista<T>:: obterItem(int posicao){
    if(posicao < 0 || posicao > ultimo) return false;

    return vetor[posicao];
}

template <typename T>
bool Lista<T>:: contemItem(T valor){
    int i = inicio;
        while( i <= ultimo ){
            if(vetor[i] == valor) return true;
            i++;
        }
        return false;
}

template <typename T>
int Lista<T>:: descobrirIndice(T valor){
    int i = inicio;
        while( i <= ultimo ){
            if(vetor[i] == valor) return i;
            i++;
        }
        return -1;
}

template <typename T>
void Lista<T>:: imprimir(){
    for(int i = 0; i <= ultimo; i++ ){
        std:: cout << vetor[i] << " ";
    }
}








