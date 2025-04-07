## Estrutura de Dominó

### Funções iniciais e ideias de como montá-las
#### `bool inicializar()`
A princípio a função de inicialização iria criar uma nova lista de dominós, ou seja, um novo conjunto com __28 peças__.

Sabemos que cada peça possui dois números, um na parte superior e outro na parte inferior, está função deve ser capaz de __criar todas as 28 possibilidades__, ou __manejar com as 28 peças já descritas em código__, como se fosse uma biblioteca.
A lista precisa ser ordenada de forma a gente já saber qual jogador possui a maior peça pra iniciar o jogo.

Além disso, pensando que essa função irá distribuir as peças, também precisamos que ela receba como argumento o *número de jogadores*, e retornasse caso não seja possível jogar com o *número de jogadores* estipulado.

__Exemplo:__ 
```cpp 
numJogadores > 4 || numJogadores < 2 ? return false else return true;
```

Por fim, acho que ela poderia chamar a próxima função...
#### `bool distribuir()`
Esta irá distribuir a quantidade de peças de acordo com a quantidade de jogadores, ela precisa analisar todas as 28 peças e selecioná-las de forma aleatória e enviar para cada jogador __somente 7 peças__.

#### `bool inserirMesa()`
Está função deve ser capaz de receber qual jogador está enviando a peça à mesa, e qual peça está sendo enviada, além disso, precisa saber qual foi a última peça inserida à mesa, dessa forma irá retornar `true` caso a peça faça sentido no jogo e `false` caso contrário.

Após realizar a inserção da peça na lista da mesa, é necessário remover está peça da lista do jogador.

#### `bool inseri



>Markdown


