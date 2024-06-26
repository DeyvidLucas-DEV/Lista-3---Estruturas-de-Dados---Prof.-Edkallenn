#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int vetor[], int tamanho, int *numComparacoes, int *numTrocas) {
    int i, j;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            (*numComparacoes)++;
            if (vetor[j] > vetor[j + 1]) {
                (*numTrocas)++;
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void gerarValoresAleatorios(int vetor[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100; // Valores aleatórios entre 0 e 99
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];
    gerarValoresAleatorios(vetor, tamanho);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    int numComparacoes = 0;
    int numTrocas = 0;
    bubbleSort(vetor, tamanho, &numComparacoes, &numTrocas);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    printf("Numero de comparacoes: %d\n", numComparacoes);
    printf("Numero de trocas: %d\n", numTrocas);

    return 0;
}
