# Projeto 2 Computaçao Grafica

1. Estenda o código criando um método que recebe uma tabela de arestas ativas (AET) de uma determinada linha de varredura e retornando uma lista com as paridades em cada aresta. Por exemplo, para o polígono do exemplo de aula, e a AET correspondente à linha de varredura y = 8, nós teremos 4 arestas sendo interceptadas, sendo que o algoritmo de paridade retornaria a sequência 1 0 1 0 para o bit de paridade em cada aresta. Faça ao menos 3 exemplos de linha de varredura para mostrar o funcionamento.


2. Modifique a implementação do algoritmo Scanline para gerar áreas preenchidas com determinado padrão de preenchimento (hachuras). A ideia é fazer uma implementação que aceite qualquer padrão passado como parâmetro. Uma ideia consiste em usar uma matriz para representar um padrão, composto de valores 0 e 1 que definem a hachura a ser desenhada. Faça 3 exemplos usando três padrões diferentes. DICA: Lembre do preenchimento de circunferências.

3. Estenda o código para realizar o preenchimento de vários polígonos simultaneamente usando Scanline. Pode considerar apenas 2 poligonos. DICA: Criar um método ou função que receba duas Tabelas de Arestas e gera uma Tabela de Arestas Única.
