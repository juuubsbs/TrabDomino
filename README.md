## Estrutura de Dominó

### Funções iniciais e ideias de como montá-las
#### `bool inicializar()`
A princípio a função de inicialização iria criar uma nova lista de dominós, ou seja, um novo conjunto com <span style="color: yellow;">__28 peças__</span>.

Sabemos que cada peça possui dois números, um na parte superior e outro na parte inferior, está função deve ser capaz de __criar todas as 28 possibilidades__, ou __manejar com as 28 peças já descritas em código__, como se fosse uma biblioteca.
a lista precisa ser ordenada de forma a gente já saber qual jogador possui a maior peça pra iniciar o jogo.

Além disso, pensando que essa função irá distribuir as peças, também precisamos que ela receba como argumento o *número de jogadores*, e retornasse caso não seja possível jogar com o *número de jogadores* estipulado.

__Exemplo:__ 
```cpp 
numJogadores > 4 || numJogadores < 2 ? return false else return true;
```

Por fim, acho que ela poderia chamar a próxima função...
#### `bool distribuir()`
Esta irá distribuir a quantidade de peças de acordo com a quantidade de jogadores
