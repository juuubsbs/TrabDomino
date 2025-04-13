template<typename T>
struct No{
    T dado;
    No *elo; // nó seguinte a ele

    //construtor de No
    No() : dado(), elo(nullptr) {}
    No(T &valor) : dado(valor), elo(nullptr) {}
}; 

template<typename T>
struct LUE{
    No<T> *comeco;
    No<T> *fim;
    No<T> *ant;    //posição a ser escolhida
    No<T> *prox;   //posição a ser escolhida
    No<T> *aux;    //posição a ser escolhida
    int contador;
    int tamanho;


    void instanciar();

    void inserirInicio(T valor);

    bool inserirPosicao(T valor, int posicao);

    void inserirUltimo(T valor);

    void imprimir()const;

    bool removerInicio();

    bool removerPosicao(int posicao);

    bool removerFinal();
    
    bool contemItem(T valor);

    T obterItem(int posicao)const;

    int descobrirIndice(T valor);
};

template <typename T>
void LUE<T>:: instanciar(){
    comeco = nullptr;
    fim = nullptr;
    contador = -1;
    tamanho = 0;
}

template <typename T>
void LUE<T>:: inserirInicio(T valor){
    No<T> *novoNo = new No<T>(valor);
    novoNo->elo = nullptr;

    if(comeco == nullptr){
        comeco = novoNo;
        fim = novoNo;
        contador++;
        tamanho++;
        return;
    }
    novoNo->elo = comeco;//atualiza o endereço
    comeco = novoNo;//repassa os dados

    contador++;
    tamanho++;
}





template <typename T>
bool LUE<T>:: inserirPosicao(T valor, int posicao){
    if(posicao < 0 || posicao > contador + 1) return false;
    No<T> *novoNo = new No<T>(valor);
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
    tamanho++;
    return true;
}


template <typename T>
void LUE<T>:: inserirUltimo(T valor){
    No<T> *novoNo = new No<T>(valor);
    novoNo->elo = nullptr;

    if(comeco == nullptr){
        comeco = novoNo;
        fim = novoNo;
        contador++;
        tamanho++;
        return;
    }

    fim->elo = novoNo; 
    fim = novoNo;
    
    contador++;
    tamanho++;
}
/*
template <typename T>
void LUE<T>:: imprimir()const{
    if(comeco == NULL) return;

    this->aux = this->comeco;

    while(this->aux != NULL){
        std:: cout << this->aux->dado << " ";
        this->aux = this->aux->elo;
    }
}
    */


    template <typename T>
    void LUE<T>::imprimir() const {
        // Usa ponteiro local para não modificar o membro aux da struct durante a impressão
        No<T>* aux1 = comeco;
        while (aux1 != nullptr) {
            std::cout << aux1->dado << " ";
            aux1 = aux1->elo;
        }
        std::cout << "\n"; // Mantém o \n que estava na implementação original
    }


template <typename T>
bool LUE<T>:: removerInicio(){
    No<T> *aux1 = new No<T>;

    aux1 = comeco;
    if(comeco == NULL) return false;

    if(aux1 == fim){
        comeco = NULL;
        fim = NULL;
        contador--;
        tamanho--;

        delete aux1;
        return true;  
    }

    comeco = aux1->elo;
    contador--;
    tamanho--;
    delete aux1;

    return true;
}

template <typename T>
bool LUE<T>:: removerPosicao(int posicao){
    No<T> *aux1 = comeco;
    No<T>* ant = nullptr;
    int i = 0;

    if(posicao < 0 || posicao > contador) return false;

    if(posicao == 0){
        removerInicio();
        return true;
    }
    if(posicao == contador){
        removerFinal();
        return true;
    }

    do {
        if (i == posicao) {
            ant->elo = aux1->elo; 
            delete aux1;          
            contador--;
            tamanho--;           
            return true;
        }
        ant = aux1;              
        aux1 = aux1->elo;
        i++;
    } while (aux1 != NULL);

    return false;
}

template <typename T>
bool LUE<T>:: removerFinal(){
    No<T> *aux1 = comeco;

    if(fim == NULL) return false;

    if(comeco == fim){
        comeco = NULL;
        fim = NULL;
        contador--;
        tamanho--;

        delete aux1;
        return true;
    }

    while(aux1->elo != NULL){
        ant = aux1;
        aux1 = aux1->elo;
    }

    fim = ant;
    fim->elo = NULL;
    contador--;
    tamanho--;

    delete aux1;
    return true;
}

template <typename T>
bool LUE<T>:: contemItem(T valor){
    No<T> *aux1 = new No<T>;

    aux = comeco;
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
T LUE<T>:: obterItem(int posicao)const{
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
    throw std::out_of_range("NULL");
}

template <typename T>
int LUE<T>:: descobrirIndice(T valor){
    No<T> *aux1 = comeco;
    int i = 0;

    while( aux1 != NULL){
        if(aux1->dado == valor){
            return i;
        }
        else{
            i++;
            aux1 = aux1->elo;
        }
    }
    return -1;
}