## Estrutura de Dominó

### Funções iniciais e ideias de como montá-las
###### `inicializar()`
<p> A princípio a função de inicialização iria criar uma nova lista de dominós, ou seja, um novo conjunto com 28 peças. Sabemos que cada peça possui dois números, um na parte superior e outro na parte inferior, a lista precisa ser ordenada de forma a gente já saber qual jogador possui a maior peça pra iniciar o jogo.
<p> Além disso, pensando que essa função irá distribuir as peças, também precisamos que ela receba como argumento o *número de jogadores*