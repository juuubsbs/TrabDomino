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

    void instanciar();

    void inserirInicio(T valor);

    bool inserirPosicao(T valor, int posicao);

    void inserirUltimo(T valor);

    void imprimir();

    bool removerInicio();

    bool removerPosicao(int posicao);

    bool removerFinal();
    
    bool contemItem(T valor);

    T obterItem(int posicao);

    int descobrirIndice(T valor);
};

template <typename T>
void LUE<T>:: instanciar(){
    comeco = nullptr;
    fim = nullptr;
    contador = -1;
}

template <typename T>
void LUE<T>:: inserirInicio(T valor){
    No<T> *novoNo = new No<T>;
    novoNo->dado = valor;
    novoNo->elo = nullptr;

    if(comeco == nullptr){
        comeco = novoNo;
        fim = novoNo;
        contador++;
        return;
    }
    novoNo->elo = comeco;//atualiza o endereço
    comeco = novoNo;//repassa os dados

    contador++;
}

template <typename T>
bool LUE<T>:: inserirPosicao(T valor, int posicao){
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

template <typename T>
void LUE<T>:: inserirUltimo(T valor){
    No<T> *novoNo = new No<T>;
    novoNo->dado = valor;
    novoNo->elo = nullptr;

    if(comeco == nullptr){
        comeco = novoNo;
        fim = novoNo;
        contador++;
        return;
    }

    fim->elo = novoNo; 
    fim = novoNo;
    
    contador++;
}

template <typename T>
void LUE<T>:: imprimir(){
    if(comeco == NULL) return;

    this->aux = this->comeco;

    while(this->aux != NULL){
        std:: cout << this->aux->dado << " ";
        this->aux = this->aux->elo;
    }
}

template <typename T>
bool LUE<T>:: removerInicio(){
    No<T> *aux1 = new No<T>;

    if(comeco == NULL) return false;

    aux1 = comeco;
    if(aux1 == fim){
        comeco = NULL;
        fim = NULL;
        contador--;

        delete aux1;
        return true;  
    }

    comeco = aux1->elo;
    contador--;
    delete aux1;

    return true;
}

template <typename T>
bool LUE<T>:: removerPosicao(int posicao){
    No<T> *aux1 = new No<T>;

    if(posicao < 0 || posicao > contador) return false;

    if(posicao == 0){
        removerInicio();
        return true;
    }
    if(posicao == contador){
        removerFinal();
        return true;
    }

    int i = 0;
    ant = aux1;
    aux1 = aux1->elo;
    prox = prox->elo;
    while(aux1->elo != NULL){
        if(posicao == i){
            std:: cout << "entrou aqui";
            ant->elo = prox;
            delete aux1;
            contador--;
            return true;
        }
        ant = aux1;
        aux1 = aux1->elo;
        prox = prox->elo;
    }
    return false;
}

template <typename T>
bool LUE<T>:: removerFinal(){
    No<T> *aux1 = new No<T>;

    if(fim == NULL) return false;

    aux1 = comeco;
    if(comeco == fim){
        comeco = NULL;
        fim = NULL;
        contador--;

        delete aux1;
        return true;
    }

    while(aux1->elo != NULL){
        ant = aux1;
        aux1 = aux1->elo;
        prox = prox->elo;

        if(aux1 == fim){
            fim = ant;
            fim->elo = NULL;
            contador--;

            delete aux1;
            return true;
        }
        return true;
    }
    return false;
}

template <typename T>
bool LUE<T>:: contemItem(T valor){
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

template <typename T>
T LUE<T>:: obterItem(int posicao){
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

template <typename T>
int LUE<T>:: descobrirIndice(T valor){
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
