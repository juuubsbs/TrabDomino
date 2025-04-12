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





o possivel relatorio que sera arrumado 



Relatório Técnico: Implementação do Jogo de Dominó em C++
1. Introdução

O presente relatório técnico detalha o desenvolvimento de um programa em linguagem C++ para simular o jogo de dominó para dois jogadores. O objetivo principal foi implementar as regras fundamentais do jogo, utilizando estruturas de dados eficientes para representar os elementos essenciais, como o monte de peças, as mãos dos jogadores e a mesa de jogo. Este documento aborda as regras do jogo implementadas, as estruturas de dados escolhidas, a lógica de distribuição e rodada, o roteiro de funcionamento do programa e um exemplo de execução com prints do terminal.

2. Regras do Jogo Implementadas

As seguintes regras do jogo de dominó foram implementadas nesta versão do programa:

Número de Jogadores: O jogo é simulado para dois jogadores.
Conjunto de Peças: É utilizado o conjunto padrão de 28 peças de dominó, com números de 0 a 6 em cada extremidade.
Distribuição: No início do jogo, cada jogador recebe 7 peças do monte.
Início do Jogo: O jogador que possuir a peça de dupla seis ([6|6]) inicia a partida, colocando-a na mesa. Caso nenhum jogador possua essa peça, o jogador 1 começa colocando qualquer peça.
Jogada: Em seu turno, o jogador deve tentar conectar uma de suas peças a uma das extremidades abertas da mesa (esquerda ou direita). A extremidade da peça a ser jogada deve corresponder ao número da extremidade da peça já presente na mesa.
Compra de Peça: Se um jogador não possuir nenhuma peça que possa ser jogada, ele deve comprar uma peça do monte, se houver alguma disponível. Se a peça comprada puder ser jogada, o jogador pode fazê-lo imediatamente.
Passe: Se o jogador não possuir nenhuma peça jogável e o monte estiver vazio, ele deve passar a vez.
Fim da Rodada: A rodada termina quando um jogador fica sem peças na mão, ou quando o jogo fica "trancado" (nenhum dos jogadores consegue fazer uma jogada válida e o monte está vazio).
Vencedor: O jogador que primeiro ficar sem peças na mão é o vencedor. Em caso de jogo trancado, o vencedor é determinado pela contagem dos pontos das peças restantes na mão de cada jogador (o jogador com a menor soma vence), embora essa mecânica de pontuação não esteja implementada nesta versão.
3. Estruturas de Dados Escolhidas

Para representar os diferentes elementos do jogo, foram escolhidas as seguintes estruturas de dados personalizadas:

Lista<Peca> (Implementada como um vetor dinâmico): Esta estrutura foi utilizada para representar as mãos dos jogadores. A escolha do vetor dinâmico permite acesso rápido às peças por índice, o que é útil para percorrer a mão durante a busca por jogadas válidas e para exibir as peças. A inserção e remoção no final são operações eficientes para a compra de peças.
LUE<Peca> (Implementada como uma Lista Linear Encadeada): Esta estrutura foi utilizada para representar o monte de peças e a mesa de jogo. A lista encadeada é adequada para o monte, pois a operação principal é a remoção do início (compra de peças). Para a mesa, a lista encadeada duplamente seria mais eficiente para inserções em ambas as extremidades, mas a implementação atual utiliza uma lista encadeada simples com lógica para inserção no início e no final.
4. Explicação sobre a Distribuição e Rodada do Jogo

Distribuição: Inicialmente, um objeto LUE<Peca> chamado monte é criado e preenchido com todas as 28 peças do dominó. Em seguida, as peças são distribuídas para as mãos dos jogadores (Lista<Peca> jogador1 e jogador2) através da função distribuirPecas. Esta função retira um determinado número de peças (7 para cada jogador) do início do monte e as adiciona ao final da mão de cada jogador.
Rodada: O jogo prossegue em turnos alternados entre os jogadores. Em cada turno, o jogador atual tenta encontrar uma peça em sua mão que possa ser jogada em uma das extremidades da mesa (representada por LUE<Peca>). A função podeJogar verifica essa condição. Se uma peça jogável é encontrada, a função realizarJogada a adiciona à mesa (no início ou no final, dependendo da conexão) e a remove da mão do jogador. Se o jogador não tiver peças jogáveis, ele tenta comprar uma peça do monte através da função comprarPeca. Se o monte estiver vazio, o jogador passa a vez. A rodada termina quando um jogador fica sem peças.
5. Roteiro de Funcionamento do Programa

O programa segue o seguinte fluxo de execução:

Inicialização: Criação das estruturas de dados para o monte (LUE<Peca>), mãos dos jogadores (Lista<Peca>), e mesa (LUE<Peca>).
Criação do Monte: O monte é preenchido com todas as 28 peças do dominó.
Distribuição de Peças: 7 peças são distribuídas do monte para cada jogador.
Determinação do Primeiro Jogador: O jogador com a peça [6|6] começa. Se nenhum jogador a tiver, o jogador 1 começa. A primeira peça jogada é colocada na mesa.
Loop Principal: O jogo continua em turnos até que um jogador vença ou o jogo tranque.
Turno do Jogador:
O estado atual da mesa e a mão do jogador são exibidos.
O programa busca na mão do jogador por uma peça jogável.
Se uma peça jogável é encontrada:
A peça é jogada na mesa (início ou fim).
A peça é removida da mão do jogador.
Se nenhuma peça jogável é encontrada:
O jogador tenta comprar uma peça do monte.
Se o monte estiver vazio, o jogador passa a vez.
Verificação de vitória (mão vazia).
Verificação de jogo trancado (monte vazio e ambos os jogadores passam).
Passagem do turno para o outro jogador.
Fim do Jogo: Uma mensagem declarando o vencedor ou o empate é exibida.
6. Exemplo de Funcionamento com Prints da Execução

Mão do Jogador 1: [0|0] [0|1] [0|2] [0|3] [0|4] [0|5] [0|6] 
Mão do Jogador 2: [1|1] [1|2] [1|3] [1|4] [1|5] [1|6] [2|2] 
Peças no Monte: 14

Turno do Jogador 1:
Mesa: Vazia
Jogador 1 Mao: (0)[0|0] (1)[0|1] (2)[0|2] (3)[0|3] (4)[0|4] (5)[0|5] (6)[0|6] 
Jogador 1 joga [0|0]
Mesa: [0|0] 
Turno do Jogador 2:
Mesa: [0|0] 
Jogador 2 Mao: (0)[1|1] (1)[1|2] (2)[1|3] (3)[1|4] (4)[1|5] (5)[1|6] (6)[2|2] 
Jogador 2 nao tem pecas para jogar.
Comprou a peca: [2|0]
Jogador 2 Mao: (0)[1|1] (1)[1|2] (2)[1|3] (3)[1|4] (4)[1|5] (5)[1|6] (6)[2|2] (7)[2|0] 
Turno do Jogador 1:
Mesa: [0|0] 
Jogador 1 Mao: (0)[0|1] (1)[0|2] (2)[0|3] (3)[0|4] (4)[0|5] (5)[0|6] 
Jogador 1 joga [0|1]
Mesa: [1|0] [0|0] 
Turno do Jogador 2:
Mesa: [1|0] [0|0] 
Jogador 2 Mao: (0)[1|1] (1)[1|2] (2)[1|3] (3)[1|4] (4)[1|5] (5)[1|6] (6)[2|2] (7)[2|0] 
Jogador 2 joga [1|2]
Mesa: [2|1] [1|0] [0|0] 
... (continuação da execução) ...
7. Conclusão

O programa implementado demonstra a lógica fundamental do jogo de dominó para dois jogadores, utilizando as estruturas de dados Lista (vetor dinâmico) para as mãos dos jogadores e LUE (lista linear encadeada) para o monte e a mesa. Embora algumas regras e funcionalidades adicionais (como a pontuação em caso de jogo trancado e uma interface de usuário mais interativa) possam ser implementadas em versões futuras, o programa atual fornece uma simulação funcional do jogo, evidenciando a aplicação prática de estruturas de dados na resolução de problemas computacionais.




