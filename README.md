Trabalho da faculdade dado em aula para utilizar o algoritmo de Prim para gerar uma MST (Minium Spanning Tree), segue abaixo o problema:

01. Sobre os algoritmos de Prim, implemente:

a) Suponha que você tenha um grafo ponderado, não direcionado e conectado representando uma rede de
distribuição de energia elétrica. Cada vértice do grafo representa uma subestação e as arestas representam as
linhas de transmissão entre as subestações. Os pesos das arestas representam o custo de construção das linhas
de transmissão.

O objetivo é encontrar a árvore geradora mínima (MST - Minimum Spanning Tree) desse grafo usando o
algoritmo de Prim. A árvore geradora mínima é uma subárvore do grafo que conecta todos os vértices de
forma que a soma dos pesos das arestas seja a menor possível.

Dado um grafo não direcionado e conectado com N subestações, implemente o algoritmo de Prim para
encontrar a árvore geradora mínima desse grafo. O grafo é representado por uma matriz de adjacência de
tamanho N x N, onde cada elemento da matriz representa o peso da aresta entre duas subestações. Implemente
uma função “mst prim_mst(graph)” que recebe o grafo como parâmetro, transforma a matriz em lista
de adjacência, e retorna a árvore geradora mínima representada como um conjunto de arestas.

Exemplo de entrada:

grafo = [

[0, 2, 0, 6, 0],

[2, 0, 3, 8, 5],

[0, 3, 0, 0, 7],

[6, 8, 0, 0, 9],

[0, 5, 7, 9, 0]

]

Exemplo de saída:

mst = [

(0, 1, 2),

(1, 2, 3),

(1, 4, 5),

(0, 3, 6)

]
Dê nomes de cidades de nossa região para os vértices do grafo.
