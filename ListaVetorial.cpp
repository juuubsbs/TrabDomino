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

    void inicializar(){
        inicio = 0;
        ultimo = -1;
        aux = 0;
    }

    bool inserirInicio(T valor){
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

    bool inserirPosicao(T valor, int posicao){
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

    bool inserirFinal(T valor){
        if( ultimo == MAX_TAM-1) return false;

        vetor[ultimo+1] = valor;
        ultimo++;
        return true;

    }

    bool removerPosicao(int posicao){

        if(posicao < 0 || posicao > ultimo) return false;

        for( int i = posicao; i < ultimo; i++ ){
            vetor[i] = vetor[i+1];
        }
        ultimo--;
        return true;  
    }

    bool removerInicio(){
        //lista vazia
        if(ultimo == -1) return false;

        for( int i = inicio; i < ultimo; i++ ){
            vetor[i] = vetor[i+1];
        }
        ultimo--;
        return true;
    } 
    
    bool removerFinal(){
        //lista vazia
        if(ultimo == -1) return false;

        ultimo--;
        return true;
    }

    T obterItem(int posicao){
        if(posicao < 0 || posicao > ultimo) return false;

        return vetor[posicao];
    }

    bool contemItem(T valor){
        int i = inicio;
            while( i <= ultimo ){
                if(vetor[i] == valor) return true;
                i++;
            }
            return false;
    }

    int descobrirIndice(T valor){
        int i = inicio;
            while( i <= ultimo ){
                if(vetor[i] == valor) return i;
                i++;
            }
            return -1;
    }

    void imprimir(){
        for(int i = 0; i <= ultimo; i++ ){
            std:: cout << vetor[i] << " ";
        }
    }


};
