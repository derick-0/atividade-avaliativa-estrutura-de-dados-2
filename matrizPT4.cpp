#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define SENSORES 5
#define HORAS 24

static float sensores[SENSORES][HORAS];
static int preenchido = 0;


static int imprimeMenu() {
  system("cls");
  printf("\n ============ ANALISE DE SENSORES DE TEMPERATURA ============ ");
  printf("\n =  1: Preencher Manualmente                                 = ");
  printf("\n =  2: Preencher Automaticamente (Aleatorio)                 = ");
  printf("\n =  3: Mostrar Matriz de Leituras                            = ");
  printf("\n =  4: Media de Cada Sensor                                  = ");
  printf("\n =  5: Maior Temperatura (Sensor e Horario)                  = ");
  printf("\n =  6: Media Geral (120 Medicoes)                            = ");
  printf("\n =  7: Contar Leituras Acima de um Limite                    = ");
  printf("\n =  8: Executar Todas as Analises (c/ operacoes)             = ");
  printf("\n =  9: Sair                                                  = ");
  printf("\n =============================================================== ");
  printf("\n Informe a opcao desejada: ");
  int resposta;
  scanf("%i", &resposta);
  return(resposta);
}


/* preenche manualmente -> percorre a matriz 1 vez (5*24 = 120 operacoes) */
static int preencherManual() {
  int operacoes = 0;
  printf("\n Informe as %i medicoes de cada um dos %i sensores:\n", HORAS, SENSORES);
  for (int i = 0; i < SENSORES; i++) {
    for (int j = 0; j < HORAS; j++) {
      printf(" Sensor %i, Hora %2i: ", i, j);
      scanf("%f", &sensores[i][j]);
      operacoes++;
    }
  }
  preenchido = 1;
  return operacoes;
}

/* preenche automaticamente com valores aleatorios -> percorre a matriz 1 vez (120 operacoes) */
static int preencherAutomatico() {
  int operacoes = 0;
  for (int i = 0; i < SENSORES; i++) {
    for (int j = 0; j < HORAS; j++) {
      /* gera valores entre 15.0 e 35.0, com uma casa decimal */
      sensores[i][j] = 15.0 + (rand() % 201) / 10.0;
      operacoes++;
    }
  }
  preenchido = 1;
  return operacoes;
}

/*  media de cada sensor -> percorre a matriz 1 vez (5*24 = 120 operacoes) */
static void mediaPorSensor(float medias[SENSORES], int *operacoes) {
  *operacoes = 0;
  for (int i = 0; i < SENSORES; i++) {// percorre cada sensor (linha)
    float soma = 0;
    for (int j = 0; j < HORAS; j++) { //soma todas as leituras do sensor (colunas)
      soma += sensores[i][j];
      (*operacoes)++;
    }
    medias[i] = soma / HORAS;
  }
}

/*  maior temperatura, sensor e horario -> percorre a matriz 1 vez (120 operacoes) */
static float encontrarMaior(int *sensorMaior, int *horaMaior, int *operacoes) {
  float maior = sensores[0][0]; //assume a primeira leitura como maior inicial
  *sensorMaior = 0;
  *horaMaior = 0;
  *operacoes = 0;
  for (int i = 0; i < SENSORES; i++) {
    for (int j = 0; j < HORAS; j++) {
      (*operacoes)++;
      if (sensores[i][j] > maior) {
        maior = sensores[i][j];
        *sensorMaior = i;// guarda a posição do sensor (linha) e do horário (coluna) da maior leitura
        *horaMaior = j;
      }
    }
  }
  return maior;
}

/*  media geral das 120 medicoes -> percorre a matriz 1 vez (120 operacoes) */
static float mediaGeral(int *operacoes) {
  float soma = 0;
  *operacoes = 0;
  for (int i = 0; i < SENSORES; i++) {
    for (int j = 0; j < HORAS; j++) {
      soma += sensores[i][j];
      (*operacoes)++;
    }
  }
  return soma / (SENSORES * HORAS);
}

/*  conta leituras acima de um limite -> percorre a matriz 1 vez (120 operacoes) */
static int contarAcimaLimite(float limite, int *operacoes) {
  int contador = 0;
  *operacoes = 0;
  for (int i = 0; i < SENSORES; i++) {
    for (int j = 0; j < HORAS; j++) {
      (*operacoes)++;
      if (sensores[i][j] > limite)
        contador++;
    }
  }
  return contador;
}

static void acaoPreencherManual() {
  int op = preencherManual();
  printf("\n Matriz preenchida com sucesso! (%i operacoes de percurso)\n", op);
  getch();
}

static void acaoPreencherAutomatico() {
  int op = preencherAutomatico();
  printf("\n Matriz preenchida automaticamente com sucesso! (%i operacoes de percurso)\n", op);
  getch();
}

static void acaoMostrarMatriz() {
  if (!preenchido) { printf("\n Matriz ainda nao foi preenchida!\n"); getch(); return; }
  printf("\n         ");
  for (int j = 0; j < HORAS; j++)
    printf("%5i", j);
  printf("\n");
  for (int i = 0; i < SENSORES; i++) {
    printf(" Sensor%i:", i);
    for (int j = 0; j < HORAS; j++)
      printf("%5.1f", sensores[i][j]);
    printf("\n");
  }
  printf("\n (%i operacoes de percurso)\n", SENSORES * HORAS);
  getch();
}

static void acaoMediaPorSensor() {
  if (!preenchido) { printf("\n Matriz ainda nao foi preenchida!\n"); getch(); return; }
  float medias[SENSORES];
  int op;
  mediaPorSensor(medias, &op);
  printf("\n Media de cada sensor:\n");
  for (int i = 0; i < SENSORES; i++)
    printf(" Sensor %i: %.2f\n", i, medias[i]);
  printf(" (%i operacoes de percurso)\n", op);
  getch();
}

static void acaoMaiorTemperatura() {
  if (!preenchido) { printf("\n Matriz ainda nao foi preenchida!\n"); getch(); return; }
  int sensorMaior, horaMaior, op;
  float maior = encontrarMaior(&sensorMaior, &horaMaior, &op);
  printf("\n Maior temperatura registrada: %.2f\n", maior);
  printf(" Sensor responsavel: %i\n", sensorMaior);
  printf(" Horario da ocorrencia: %ih\n", horaMaior);
  printf(" (%i operacoes de percurso)\n", op);
  getch();
}

static void acaoMediaGeral() {
  if (!preenchido) { printf("\n Matriz ainda nao foi preenchida!\n"); getch(); return; }
  int op;
  float media = mediaGeral(&op);
  printf("\n Media geral das %i medicoes: %.2f\n", SENSORES * HORAS, media);
  printf(" (%i operacoes de percurso)\n", op);
  getch();
}

static void acaoAcimaLimite() {
  if (!preenchido) { printf("\n Matriz ainda nao foi preenchida!\n"); getch(); return; }
  float limite;
  printf("\n Informe o limite de temperatura: ");
  scanf("%f", &limite);
  int op;
  int contador = contarAcimaLimite(limite, &op);
  printf("\n Limite informado: %.1f\n", limite);
  printf(" Quantidade de leituras acima do limite: %i\n", contador);
  printf(" (%i operacoes de percurso)\n", op);
  getch();
}

static void acaoExecutarTudo() {
  if (!preenchido) { printf("\n Matriz ainda nao foi preenchida!\n"); getch(); return; }

  int opTotal = 0;
  int op;

  printf("\n ===== RESULTADOS COMPLETOS =====\n");

  float medias[SENSORES];
  mediaPorSensor(medias, &op);
  opTotal += op;
  printf("\n Media de cada sensor: (%i operacoes)\n", op);
  for (int i = 0; i < SENSORES; i++)
    printf("  Sensor %i: %.2f\n", i, medias[i]);

  int sensorMaior, horaMaior;
  float maior = encontrarMaior(&sensorMaior, &horaMaior, &op);
  opTotal += op;
  printf("\n Maior temperatura: %.2f | Sensor %i | Horario %ih  (%i operacoes)\n",
         maior, sensorMaior, horaMaior, op);

  float media = mediaGeral(&op);
  opTotal += op;
  printf(" Media geral (%i medicoes): %.2f  (%i operacoes)\n", SENSORES * HORAS, media, op);

  float limite;
  printf("\n Informe o limite de temperatura para contagem: ");
  scanf("%f", &limite);
  int contador = contarAcimaLimite(limite, &op);
  opTotal += op;
  printf(" Limite informado: %.1f\n", limite);
  printf(" Quantidade de leituras acima do limite: %i  (%i operacoes)\n", contador, op);

  printf("\n TOTAL DE OPERACOES DE PERCURSO NO PROGRAMA: %i\n", opTotal);
  printf(" (equivalente a %i passagens completas pela matriz de %i posicoes)\n",
         opTotal / (SENSORES * HORAS), SENSORES * HORAS);
  getch();
}


void matrizPT4(void) {
  int resposta;

  do {
    resposta = imprimeMenu();

    if (resposta == 1)
      acaoPreencherManual();
    else if (resposta == 2)
      acaoPreencherAutomatico();
    else if (resposta == 3)
      acaoMostrarMatriz();
    else if (resposta == 4)
      acaoMediaPorSensor();
    else if (resposta == 5)
      acaoMaiorTemperatura();
    else if (resposta == 6)
      acaoMediaGeral();
    else if (resposta == 7)
      acaoAcimaLimite();
    else if (resposta == 8)
      acaoExecutarTudo();

  } while (resposta != 9);

}
