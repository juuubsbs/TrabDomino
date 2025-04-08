template<typename T>
struct No{
    T dado;
    No *elo; // nó seguinte a ele
}; 

//refazer inserir e refazer remover, precisa dos tres 

template<typename T>
struct LUE{
    No<T> *comeco;
    No<T> *fim;
    No<T> *ant;    //posição a ser escolhida
    No<T> *prox;   //posição a ser escolhida
    No<T> *aux;    //posição a ser escolhida
    int contador;

    void instanciar(){
        comeco = nullptr;
        fim = nullptr;
        contador = -1;
    }

    void inserirInicio(T valor){

        No<T> *novoNo = new No<T>;
        novoNo->dado = valor;
        novoNo->elo = nullptr;

        if(comeco == nullptr){
            comeco = novoNo;
            fim = novoNo;
            return;
        }
        novoNo->elo = comeco;//atualiza o endereço
        comeco = novoNo;//repassa os dados


        contador++;
    }

    bool inserirPosicao(T valor, int posicao){
        if(posicao < 0 || posicao > contador + 1) return false;
        No<T> *novoNo = new No<T>;
        novoNo->dado = valor;
        novoNo->elo = nullptr;

        
        if(posicao == 0){
            inserirInicio(valor);
            return true;
        }

        if(posicao == contador){
            inserirUltimo(valor);
            return true;
        }

        ant = comeco; 
        prox = ant->elo;
        int i = 0;
        while(i <= posicao){
            if(i == posicao-1){
                ant->elo = novoNo;
                novoNo->elo = prox;
                break;
            }
            i++;
            ant = prox; 
            prox = ant->elo;
        }
        contador++;
        return true;
    }

    void inserirUltimo(T valor){

        No<T> *novoNo = new No<T>;
        novoNo->dado = valor;
        novoNo->elo = nullptr;

        if(comeco == nullptr){
            comeco = novoNo;
            fim = novoNo;
            return;
        }

        fim->elo = novoNo; 
        fim = novoNo;
        
        contador++;

    }

    void inserir(T valor){
        No<T> *novoNo = new No<T>;
        novoNo->dado = valor;
        novoNo->elo = nullptr;

        //caso seja o primeiro da lista
        if(comeco == nullptr){
            comeco = novoNo;
            fim = novoNo;
        }
        //caso seja o menor de todos
        else if(valor < comeco->dado){
            novoNo->elo = comeco;//atualiza o endereço
            comeco = novoNo;//repassa os dados

        }
        //caso seja o maior de todos
        else if(valor > fim->dado){
            fim->elo = novoNo; 
            fim = novoNo;
        }
        //caso seja no meio
        else{
            ant = comeco; 
            prox = ant->elo;

            while(prox != NULL){
                if(ant->dado < valor && valor < prox->dado){
                    ant->elo = novoNo;
                    novoNo->elo = prox;
                    break;
                }
                ant = prox; 
                prox = ant->elo;
            }
        }
        contador++;
    }

    void imprimir(){
        this->aux = this->comeco;

        while(this->aux != NULL){
            std:: cout << this->aux->dado << " ";
            this->aux = this->aux->elo;
        }

    }

    bool retirar(T valor){
        //achar o valor
        No <T> *aux1 = comeco;
        while(aux1 != NULL){ // passa pela lista
            if(aux1->dado == valor){ // tenta achar o valor
                if(aux1 == comeco){
                    // unico valor na lista
                    if(aux1 == fim){ 
                        comeco = NULL;
                        fim = NULL;
                    }
                    //retirar no começo
                    else {
                        comeco = aux1->elo;
                    }
                    delete aux1;
                    contador--;
                }
                //retirar no final
                else if(aux1 == fim){
                    fim = ant;
                    fim->elo = NULL;
                    delete aux1;
                    contador--;
                }
                //retirar no meio
                else{
                    ant->elo = prox;
                    delete aux1;
                    contador--;
                }
                return true;
            }
            ant = aux1;         //avança uma casa
            aux1 = aux1->elo;
            prox = aux1->elo;
        }
        return false;
    }
    
    bool contemItem(T valor){

        No<T> *aux1 = comeco;

        while(aux1 != NULL){
            if(aux1->dado == valor){
                return true;
            }
            else{
                aux1 = aux1->elo;
            }
        }
        return false;

    }

    T obterItem(int posicao){

        No<T> *aux1 = comeco;
        int i = 0;

        while(aux1 != NULL){
            //regrede uma no main
            if(i == posicao){
                return aux1->dado;
            }
            else{
                aux1 = aux1->elo;
                i++;
            }
        } 

        return (T)NULL;
    }

    int descobrirIndice(T valor){

        No<T> *aux1 = comeco;
        int i = 0;

        while( aux1 != NULL){
            if(aux1->dado == valor){
                std:: cout << "o i:" << i;
                std:: cout << "o valor:" << aux1->dado;
                return i;
            }
            else{
                i++;
                aux1 = aux1->elo;
            }
        }
        return -1;
    }
};