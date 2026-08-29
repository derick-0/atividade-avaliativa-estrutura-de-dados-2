#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
// Declaração das funções para cada parte do projeto
void ordenacaoPT1(void);
void temperaturaPT2(void);
void matrizloopPT3(void);
void matrizPT4(void);

int main(void) {
    srand((unsigned int) time(NULL)); 
    int opcao;
    do {
        system("cls");
        printf("\n ============ MENU PRINCIPAL ============ ");
        printf("\n =  1: Ordenacao (Bubble Sort x Quick Sort) = ");
        printf("\n =  2: Analise de Temperaturas              = ");
        printf("\n =  3: Busca Sequencial em Matriz           = ");
        printf("\n =  4: Matriz (Preenchimento e Impressao)   = ");
        printf("\n =  5: Sair                                 = ");
        printf("\n ========================================= ");
        printf("\n Informe a opcao desejada: ");
        scanf("%i", &opcao);

        switch (opcao) {
            case 1:
                ordenacaoPT1();
                break;
            case 2:
                temperaturaPT2();
                break;
            case 3:
                matrizloopPT3();
                break;
            case 4:
                matrizPT4();
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                getch();
                break;
        }
    } while (opcao != 5);

    return 0;
}