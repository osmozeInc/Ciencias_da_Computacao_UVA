usar matriz de adjacência para aumentar a conectividade



|---------------REQUISITOS--------------|

🎓 Projeto: Campo Minado em Grafo — Versão Jogador Humano (Terminal)

🧩 Objetivo
Implementar o jogo Campo Minado (Minesweeper) jogável no terminal, onde o tabuleiro é representado como um grafo, e o jogador humano 
interage via teclado. O objetivo é encontrar todas as células seguras sem explodir em uma mina, utilizando raciocínio com base nas pistas numéricas.

🧱 Adaptação: Campo Minado como Grafo

Célula do tabuleiro	= Vértice do grafo

Vizinha da célula	 = Aresta entre vértices
Mina	= Atributo de um vértice (minado = True)

Número da célula =	num_minas_adjacentes do vértice

🛠️ Requisitos Técnicos

1. Estrutura de Grafo

Reutilizar a estrutura de grafo da disciplina.

Cada vértice armazena:

minado: booleano
revelado: booleano
num_minas_adjacentes: inteiro calculado na inicialização

2. Geração do Tabuleiro

O programa inicializa um grafo representando o tabuleiro 

Minas são distribuídas aleatoriamente.

Para cada vértice, calcula-se num_minas_adjacentes com base nos vizinhos.

3. Interface no Terminal

Exibir o grafo no terminal:
Exibir células ocultas
Número (0 a 8) para células reveladas

Exemplo:

4. Interação do Jogador
O jogador digita comandos como:

abrir 3 → revela a célula 3

marcar 2 → marca/desmarca a célula 2 como mina

O jogo deve:

Revelar a célula e exibir o número de minas adjacentes.

Encerrar com derrota se for uma mina.

Revelar áreas automaticamente se num_minas_adjacentes == 0.

5. Condições de Vitória/Derrota

Vitória: todas as células seguras foram reveladas.

Derrota: o jogador abre uma célula com mina.

🧠 Exemplo de Lógica de Revelação

Ao abrir uma célula com num_minas_adjacentes == 0, o jogo deve:

Usar busca em largura (BFS) ou DFS no grafo para revelar recursivamente as vizinhas também com 0.