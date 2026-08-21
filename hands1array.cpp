#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

float temperatura[TAM];
int preenchido = 0; 

int imprimeMenu() {
  system("cls");
  printf("\n ============ ANALISE DE TEMPERATURAS ============ ");
  printf("\n =  1: Inserir as 10 Temperaturas                 = ");
  printf("\n =  2: Inserir Automaticamente (Aleatorio)        = ");
  printf("\n =  3: Mostrar Temperaturas                       = ");
  printf("\n =  4: Calcular Media                             = ");
  printf("\n =  5: Maior Valor e seu Indice                   = ");
  printf("\n =  6: Menor Valor e seu Indice                   = ");
  printf("\n =  7: Contar Valores Acima da Media              = ");
  printf("\n =  8: Executar Todas as Analises (c/ operacoes)  = ");
  printf("\n =  9: Sair                                       = ");
  printf("\n =================================================== ");
  printf("\n Informe a opcao desejada: ");
  int resposta;
  scanf("%i", &resposta);
  return(resposta);
}

/* le as 10 temperaturas -> percorre o array 1 vez (TAM operacoes) */
int inserirTemperaturas() {
  int operacoes = 0;
  printf("\n Informe as %i temperaturas:\n", TAM);
  for (int i = 0; i < TAM; i++) {
    printf(" Temperatura[%i]: ", i);
    scanf("%f", &temperatura[i]);
    operacoes++;
  }
  preenchido = 1;
  return operacoes;
}

/* preenche automaticamente com temperaturas aleatorias -> percorre o array 1 vez (TAM operacoes) */
int inserirAutomatico() {
  int operacoes = 0;
  for (int i = 0; i < TAM; i++) {
    /* gera valores entre -10.0 e 40.0, com uma casa decimal */
    float valor = -10.0 + (rand() % 501) / 10.0;
    temperatura[i] = valor;
    operacoes++;
  }
  preenchido = 1;
  return operacoes;
}

/*  mostra todos os elementos -> percorre o array 1 vez (TAM operacoes) */
int mostrarTemperaturas() {
  int operacoes = 0;
  printf("\n Indice:      ");
  for (int i = 0; i < TAM; i++) {
    printf("%6i", i);
    operacoes++;
  }
  printf("\n Temperatura: ");
  for (int i = 0; i < TAM; i++) {
    printf("%6.1f", temperatura[i]);
    operacoes++;
  }
  printf("\n");
  return operacoes;
}

/* calcula a media -> percorre o array 1 vez somando (TAM operacoes) */
float calcularMedia(int *operacoes) {
  float soma = 0;
  *operacoes = 0;
  for (int i = 0; i < TAM; i++) {
    soma += temperatura[i];
    (*operacoes)++;
  }
  return soma / TAM;
}

/* identifica o maior valor e seu indice -> percorre 1 vez (TAM-1 comparacoes) */
float encontrarMaior(int *indice, int *operacoes) {
  float maior = temperatura[0];
  *indice = 0;
  *operacoes = 0;
  for (int i = 1; i < TAM; i++) {
    (*operacoes)++;
    if (temperatura[i] > maior) {
      maior = temperatura[i];
      *indice = i;
    }
  }
  return maior;
}

/* identifica o menor valor e seu indice -> percorre 1 vez (TAM-1 comparacoes) */
float encontrarMenor(int *indice, int *operacoes) {
  float menor = temperatura[0];
  *indice = 0;
  *operacoes = 0;
  for (int i = 1; i < TAM; i++) {
    (*operacoes)++;
    if (temperatura[i] < menor) {
      menor = temperatura[i];
      *indice = i;
    }
  }
  return menor;
}

/* conta quantos valores estao acima da media -> percorre 1 vez (TAM operacoes) */
int contarAcimaMedia(float media, int *operacoes) {
  int contador = 0;
  *operacoes = 0;
  for (int i = 0; i < TAM; i++) {
    (*operacoes)++;
    if (temperatura[i] > media)
      contador++;
  }
  return contador;
}

void acaoInserir() {
  int op = inserirTemperaturas();
  printf("\n Temperaturas inseridas com sucesso! (%i operacoes de percurso)\n", op);
  getch();
}

void acaoInserirAutomatico() {
  int op = inserirAutomatico();
  printf("\n %i temperaturas geradas automaticamente com sucesso! (%i operacoes de percurso)\n", TAM, op);
  getch();
}

void acaoMostrar() {
  if (!preenchido) { printf("\n Array ainda nao foi preenchido!\n"); getch(); return; }
  int op = mostrarTemperaturas();
  printf("\n (%i operacoes de percurso)\n", op);
  getch();
}

void acaoMedia() {
  if (!preenchido) { printf("\n Array ainda nao foi preenchido!\n"); getch(); return; }
  int op;
  float media = calcularMedia(&op);
  printf("\n Media das temperaturas: %.2f\n", media);
  printf(" (%i operacoes de percurso)\n", op);
  getch();
}

void acaoMaior() {
  if (!preenchido) { printf("\n Array ainda nao foi preenchido!\n"); getch(); return; }
  int indice, op;
  float maior = encontrarMaior(&indice, &op);
  printf("\n Maior temperatura: %.2f (indice %i)\n", maior, indice);
  printf(" (%i operacoes de percurso)\n", op);
  getch();
}

void acaoMenor() {
  if (!preenchido) { printf("\n Array ainda nao foi preenchido!\n"); getch(); return; }
  int indice, op;
  float menor = encontrarMenor(&indice, &op);
  printf("\n Menor temperatura: %.2f (indice %i)\n", menor, indice);
  printf(" (%i operacoes de percurso)\n", op);
  getch();
}

void acaoAcimaMedia() {
  if (!preenchido) { printf("\n Array ainda nao foi preenchido!\n"); getch(); return; }
  int opMedia, opContagem;
  float media = calcularMedia(&opMedia);
  int contador = contarAcimaMedia(media, &opContagem);
  printf("\n Valores acima da media (%.2f): %i\n", media, contador);
  printf(" (%i operacoes para calcular media + %i para contar = %i no total)\n",
         opMedia, opContagem, opMedia + opContagem);
  getch();
}

void acaoExecutarTudo() {
  if (!preenchido) { printf("\n Array ainda nao foi preenchido!\n"); getch(); return; }

  int opTotal = 0;
  int op;

  printf("\n ===== RESULTADOS COMPLETOS =====\n");

  op = mostrarTemperaturas();
  opTotal += op;

  float media = calcularMedia(&op);
  opTotal += op;
  printf("\n Media: %.2f  (%i operacoes)\n", media, op);

  int idxMaior;
  float maior = encontrarMaior(&idxMaior, &op);
  opTotal += op;
  printf(" Maior valor: %.2f no indice %i  (%i operacoes)\n", maior, idxMaior, op);

  int idxMenor;
  float menor = encontrarMenor(&idxMenor, &op);
  opTotal += op;
  printf(" Menor valor: %.2f no indice %i  (%i operacoes)\n", menor, idxMenor, op);

  int contador = contarAcimaMedia(media, &op);
  opTotal += op;
  printf(" Valores acima da media: %i  (%i operacoes)\n", contador, op);

  printf("\n TOTAL DE OPERACOES DE PERCURSO NO PROGRAMA: %i\n", opTotal);
  printf(" (equivalente a %i passagens completas pelo array de %i elementos)\n",
         opTotal / TAM, TAM);
  getch();
}


int main() {
  srand((unsigned int) time(NULL));
  int resposta;

  do {
    resposta = imprimeMenu();

    if (resposta == 1)
      acaoInserir();
    else if (resposta == 2)
      acaoInserirAutomatico();
    else if (resposta == 3)
      acaoMostrar();
    else if (resposta == 4)
      acaoMedia();
    else if (resposta == 5)
      acaoMaior();
    else if (resposta == 6)
      acaoMenor();
    else if (resposta == 7)
      acaoAcimaMedia();
    else if (resposta == 8)
      acaoExecutarTudo();

  } while (resposta != 9);

  return 0;
}
