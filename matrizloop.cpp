#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100  

int matriz[MAX][MAX];
int Linhas = 0;
int Colunas = 0;


int imprimeMenu() {
  system("cls");
  printf("\n ============ BUSCA SEQUENCIAL EM MATRIZ ============ ");
  printf("\n =  1: Definir Dimensoes e Preencher Manualmente     = ");
  printf("\n =  2: Preencher Matriz Automaticamente (Sequencial) = ");
  printf("\n =  3: Imprimir Matriz                               = ");
  printf("\n =  4: Buscar um Valor                                = ");
  printf("\n =  5: Testar Automaticamente (2x2, 10x10, 100x100)  = ");
  printf("\n =  6: Sair                                          = ");
  printf("\n ====================================================== ");
  printf("\n Informe a opcao desejada: ");
  int resposta;
  scanf("%i", &resposta);
  return(resposta);
}

/* ================= BUSCA SEQUENCIAL ================= */
int buscaSequencial(int m, int n, int valor, int *linhaEncontrada, int *colunaEncontrada) {
    int comparacoes = 0;
    int encontrado = 0;

    for (int i = 0; i < m && !encontrado; i++) {
        for (int j = 0; j < n; j++) {
            comparacoes++;
            if (matriz[i][j] == valor) {
                *linhaEncontrada = i;
                *colunaEncontrada = j;
                encontrado = 1;
                break;
            }
        }
    }

    if (!encontrado) {
        *linhaEncontrada = -1;
        *colunaEncontrada = -1;
    }
    return comparacoes;
}


void definirDimensoes() {
  printf("Informe o numero de linhas (max %d): ", MAX);
  scanf("%i", &Linhas);
  printf("Informe o numero de colunas (max %d): ", MAX);
  scanf("%i", &Colunas);

  if (Linhas > MAX || Colunas > MAX || Linhas <= 0 || Colunas <= 0) {
    printf("\n Dimensoes invalidas! Usando 2x2 como padrao.\n");
    Linhas = 2;
    Colunas = 2;
  }
}

void preencherManual() {
  definirDimensoes();
  for (int i = 0; i < Linhas; i++)
    for (int j = 0; j < Colunas; j++) {
      printf("Elemento [%i][%i]: ", i, j);
      scanf("%i", &matriz[i][j]);
    }
  printf("\n Matriz preenchida com sucesso!\n");
  getch();
}

void preencherSequencial() {
  definirDimensoes();
  int valor = 0;
  for (int i = 0; i < Linhas; i++)
    for (int j = 0; j < Colunas; j++) {
      matriz[i][j] = valor;
      valor++;
    }
  printf("\n Matriz %i x %i preenchida automaticamente (0 a %i)!\n",
         Linhas, Colunas, Linhas * Colunas - 1);
  getch();
}

void imprimirMatriz() {
  if (Linhas == 0 || Colunas == 0) {
    printf("\n A matriz ainda nao foi preenchida!\n");
    getch();
    return;
  }
  printf("\n Matriz %i x %i:\n\n", Linhas, Colunas);
  for (int i = 0; i < Linhas; i++) {
    for (int j = 0; j < Colunas; j++)
      printf("%6i", matriz[i][j]);
    printf("\n");
  }
  getch();
}

void buscarValor() {
  if (Linhas == 0 || Colunas == 0) {
    printf("\n A matriz ainda nao foi preenchida!\n");
    getch();
    return;
  }

  int valor, linha, coluna;
  printf("Informe o valor a ser buscado: ");
  scanf("%i", &valor);

  int comp = buscaSequencial(Linhas, Colunas, valor, &linha, &coluna);

  printf("\n ===== Resultado da Busca =====\n");
  if (linha != -1) {
    printf(" Valor %i ENCONTRADO na Linha %i, Coluna %i\n", valor, linha, coluna);
  } else {
    printf(" Valor %i NAO ENCONTRADO na matriz\n", valor);
  }
  printf(" Comparacoes realizadas: %i\n", comp);
  getch();
}

/* ================= TESTE AUTOMATICO ================= */
void testarTamanho(int m, int n) {
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      matriz[i][j] = i * n + j;

  int totalElementos = m * n;
  int valorInicio     = matriz[0][0];
  int valorFinal      = matriz[(totalElementos - 2) / n][(totalElementos - 2) % n]; 
  int valorInexistente = totalElementos + 1000;

  int linha, coluna, comp;

  printf("\n===== Matriz %d x %d (%d elementos) =====\n", m, n, totalElementos);

  comp = buscaSequencial(m, n, valorInicio, &linha, &coluna);
  printf(" Busca no INICIO   -> valor=%-6i | Encontrado: SIM | Linha=%-3i Coluna=%-3i | Comparacoes=%i\n",
         valorInicio, linha, coluna, comp);

  comp = buscaSequencial(m, n, valorFinal, &linha, &coluna);
  printf(" Busca no FINAL    -> valor=%-6i | Encontrado: SIM | Linha=%-3i Coluna=%-3i | Comparacoes=%i\n",
         valorFinal, linha, coluna, comp);

  comp = buscaSequencial(m, n, valorInexistente, &linha, &coluna);
  printf(" Busca INEXISTENTE -> valor=%-6i | Encontrado: NAO | Linha=%-3i Coluna=%-3i | Comparacoes=%i\n",
         valorInexistente, linha, coluna, comp);
}

void testarAutomatico() {
  testarTamanho(2, 2);
  testarTamanho(10, 10);
  testarTamanho(100, 100);
  getch();
}


int main() {
  int resposta;

  do {
    resposta = imprimeMenu();

    if (resposta == 1)
      preencherManual();
    else if (resposta == 2)
      preencherSequencial();
    else if (resposta == 3)
      imprimirMatriz();
    else if (resposta == 4)
      buscarValor();
    else if (resposta == 5)
      testarAutomatico();

  } while (resposta != 6);

  return 0;
}
