# Trabalho de Estrutura de Dados - Arrays, Matrizes e Ordenação

Trabalho desenvolvido em C/C++ para a disciplina de Estrutura de Dados, cobrindo quatro partes: ordenação, análise de arrays, busca sequencial em matrizes e análise de matrizes bidimensionais.

## Estrutura do projeto

O projeto é dividido em módulos, cada um em seu próprio arquivo, e um main.cpp que centraliza um menu principal para navegar entre eles.
```
├── main.cpp            # Menu principal - chama cada parte do trabalho
├── ordenacaoPT1.CPP     # Bubble Sort x Quick Sort
├── temperaturaPT2.CPP   # Análise de temperaturas (array unidimensional)
├── matrizloopPT3.cpp    # Busca sequencial em matriz (loops aninhados)
└── matrizPT4.cpp        # Análise de sensores de temperatura (matriz 2D)
```
## Partes do trabalho
### 1. Ordenação (Bubble Sort x Quick Sort)

Compara os dois algoritmos de ordenação, contando comparações e trocas/movimentações realizadas, além do tempo de execução. Permite preencher o vetor manualmente ou de forma aleatória, e testar automaticamente com vetores de 10, 20 e 1000 elementos.

### 2. Análise de Temperaturas (Array)

Armazena 10 temperaturas em um array e realiza: exibição dos elementos, cálculo da média, identificação do maior/menor valor (com índice), e contagem de valores acima da média. Cada operação conta o número de passagens pelo array.

### 3. Busca Sequencial em Matriz

Implementa busca sequencial com loops aninhados em matrizes, informando se o valor foi encontrado, em qual linha/coluna, e quantas comparações foram necessárias. Testado automaticamente em matrizes 2x2, 10x10 e 100x100, em três cenários: valor no início, valor no final e valor inexistente.

### 4. Análise de Sensores de Temperatura (Matriz)

Simula uma matriz de 5 sensores x 24 horas de leituras de temperatura. Calcula média por sensor, média geral, identifica a maior temperatura registrada (com sensor e horário) e conta leituras acima de um limite informado.

## Como compilar e executar

O projeto foi desenvolvido e testado no **VScode**, utilizando o compilador **MinGW (g++) **. Como usa bibliotecas específicas do Windows (conio.h, system("cls")), a compilação e execução foram validadas nesse ambiente.

```
bash
g++ main.cpp ordenacaoPT1.CPP temperaturaPT2.CPP matrizloopPT3.cpp matrizPT4.cpp -o main.exe
```

Depois, execute:
```
bash
.\main.exe
```
## Organização do código

Em vez de concentrar tudo em um único arquivo, o projeto foi dividido em módulos independentes — um para cada parte do trabalho. Isso facilita a leitura, a manutenção e a localização de cada funcionalidade específica. O `main.cpp` funciona como ponto de entrada do programa, exibindo o menu principal e direcionando para o módulo correspondente à opção escolhida.

## Tecnologias utilizadas
- linguagens: C/C++
- Bibliotecas: stdio.h, conio.h, stdlib.h, time.h
- IDE: VScode
- Compilador: MinGW

## Contribuintes 
- ([@nichollasimprota](https://github.com/nichollasimprota))
- ([@JoaoPcardoso301](https://github.com/JoaoPcardoso301))
- ([@derick-0](https://github.com/derick-0))
- ([@davidsantosfullstack-oss](https://github.com/davidsantosfullstack-oss))
