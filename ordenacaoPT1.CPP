/*objetivo: comparar o desempenho dos dois algoritmos de ordenação,
medindo numero de comparações , trocas e tempo de execução. */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//'static' significa que a função ou variável é visível apenas dentro do arquivo onde está definida,
// evitando conflitos de nomes com outras partes do programa.
static int vetorOriginal[1000];
static int Qtd = 0;
//contadores long para armazenar o número de comparações e 
// trocas realizadas por cada algoritmo.
static long compBubble, trocaBubble;
static long compQuick, movQuick;

static int imprimeMenu() {
  system("cls");
  printf("\n ========= BUBBLE SORT x QUICK SORT ========= ");
  printf("\n =  1: Preencher o Vetor Manualmente         = ");
  printf("\n =  2: Preencher Vetor Aleatoriamente        = ");
  printf("\n =  3: Imprimir o Vetor                      = ");
  printf("\n =  4: Limpar o Vetor                        = ");
  printf("\n =  5: Comparar Bubble x Quick (vetor atual) = ");
  printf("\n =  6: Testar Automaticamente (10/20/1000)   = ");
  printf("\n =  7: Sair                                  = ");
  printf("\n ============================================= ");
  printf("\n Informe a opcao desejada: ");
  int resposta;
  scanf("%i", &resposta);
  return(resposta);
}

static void copiarVetor(int *origem, int *destino, int n) {
    for (int i = 0; i < n; i++)
        destino[i] = origem[i];
}

static void preencherManual() {
  char resp;
  do {
    printf("Insira o %i. valor no vetor: ", Qtd + 1);
    scanf("%i", &vetorOriginal[Qtd]);
    Qtd += 1;
    printf("Deseja inserir mais um valor? (S/N): ");
    scanf(" %c", &resp);
  } while (resp == 'S' || resp == 's');
}

static void preencherAleatorio() {
  int Tamanho;
  printf("Informe o tamanho do vetor que deseja criar: ");
  scanf("%i", &Tamanho);
  for (int i = 0; i < Tamanho; i++)
    vetorOriginal[i] = rand() % 100000;
  Qtd = Tamanho;
  printf("\n %i numeros gerados com sucesso!", Tamanho);
  getch();
}

static void imprimirVetor() {
  printf("\n Dados do Vetor (%i elementos): \n", Qtd);
  for (int i = 0; i < Qtd; i++)
    if (i == Qtd - 1)
      printf("%i ", vetorOriginal[i]);
    else
      printf("%i, ", vetorOriginal[i]);
  printf("\n");
  getch();
}

static void limparVetor() {
  for (int i = 0; i < Qtd; i++)
    vetorOriginal[i] = 0;
  Qtd = 0;
  printf("\n Vetor zerado com sucesso! \n");
  getch();
}

/* ================= BUBBLE SORT ================= */
static void bubbleSort(int *v, int n) {
    compBubble = 0;
    trocaBubble = 0;
    // 'i' controla quantas passagens foram feitas 
    for (int i = 0; i < n - 1; i++) {
        // 'j' percorre o vetor comparando elementos adjacentes
        for (int j = 0; j < n - 1 - i; j++) {
            compBubble++;
            if (v[j] > v[j + 1]) {
              // realiza a troca dos elementos 
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                trocaBubble++;
            }
        }
    }
}

/* ================= QUICK SORT ================= */
static int particiona(int *v, int baixo, int alto) {
    int pivo = v[alto]; // elemento de referencia para dividir o vetor
    int i = baixo - 1; //marca a fronteira entre elementos menores que o pivô
    for (int j = baixo; j < alto; j++) {
        compQuick++;
        if (v[j] < pivo) {
            i++;
            //move o elemento menor que o pivô para a esquerda da fronteira
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            movQuick += 3; //conta como 3 movimentos, pois envolve 3 atribuições
        }
    }
    //posiciona o pivô na posição correta, entre os elementos menores e maiores
    int aux = v[i + 1];
    v[i + 1] = v[alto];
    v[alto] = aux;
    movQuick += 3;
    return i + 1; //retorna a posição final do pivô
}
//chamada recursiva: ordena a metade esquerda e direita do pivô
static void quickSortRec(int *v, int baixo, int alto) {
    if (baixo < alto) {
        int p = particiona(v, baixo, alto);
        quickSortRec(v, baixo, p - 1);
        quickSortRec(v, p + 1, alto);
    }
}

static void quickSort(int *v, int n) {
    compQuick = 0;
    movQuick = 0;
    quickSortRec(v, 0, n - 1);
}

/* ================= COMPARACAO ENTRE OS DOIS ================= */
static void compararVetorAtual() {
  if (Qtd == 0) {
    printf("\n O vetor esta vazio! Preencha antes de comparar.\n");
    getch();
    return;
  }

  int *copia1 = (int*) malloc(Qtd * sizeof(int));
  int *copia2 = (int*) malloc(Qtd * sizeof(int));
  copiarVetor(vetorOriginal, copia1, Qtd);
  copiarVetor(vetorOriginal, copia2, Qtd);

  clock_t t1 = clock();
  bubbleSort(copia1, Qtd);
  clock_t t2 = clock();
  double tempoBubble = (double)(t2 - t1) / CLOCKS_PER_SEC;

  clock_t t3 = clock();
  quickSort(copia2, Qtd);
  clock_t t4 = clock();
  double tempoQuick = (double)(t4 - t3) / CLOCKS_PER_SEC;

  printf("\n Resultado da comparacao para %i elementos:\n\n", Qtd);
  printf(" | %-18s | %10s | %10s |\n", "Metrica", "Bubble", "Quick");
  printf(" |--------------------|------------|------------|\n");
  printf(" | %-18s | %10ld | %10ld |\n", "Comparacoes", compBubble, compQuick);
  printf(" | %-18s | %10ld | %10ld |\n", "Trocas/Movimentac.", trocaBubble, movQuick);
  printf(" | %-18s | %10.6f | %10.6f |\n", "Tempo (s)", tempoBubble, tempoQuick);

  free(copia1);
  free(copia2);
  getch();
}

static void testarAutomatico() {
  int tamanhos[] = {10, 20, 1000};
  printf("\n Comparacao automatica: Bubble Sort x Quick Sort\n\n");
  printf(" | %7s | %13s | %11s | %13s | %13s |\n",
         "Tamanho", "Bub-Compar.", "Bub-Trocas", "Quick-Compar.", "Quick-Movim.");
  printf(" |---------|---------------|-------------|---------------|---------------|\n");

  for (int t = 0; t < 3; t++) {
    int n = tamanhos[t];
    int *original = (int*) malloc(n * sizeof(int));
    int *copia1   = (int*) malloc(n * sizeof(int));
    int *copia2   = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
      original[i] = rand() % 100000;

    copiarVetor(original, copia1, n);
    copiarVetor(original, copia2, n);

    bubbleSort(copia1, n);
    quickSort(copia2, n);

    printf(" | %7i | %13ld | %11ld | %13ld | %13ld |\n",
           n, compBubble, trocaBubble, compQuick, movQuick);

    free(original);
    free(copia1);
    free(copia2);
  }
  getch();
}


void ordenacaoPT1(void) {
  int resposta;

  do {
    resposta = imprimeMenu();

    if (resposta == 1)
      preencherManual();
    else if (resposta == 2)
      preencherAleatorio();
    else if (resposta == 3)
      imprimirVetor();
    else if (resposta == 4)
      limparVetor();
    else if (resposta == 5)
      compararVetorAtual();
    else if (resposta == 6)
      testarAutomatico();

  } while (resposta != 7);

}
