#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <errno.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // Pivô
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor que o pivô
        if (arr[j] < pivot) {
            i++;    // Incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Separadamente, ordena os elementos antes e depois da partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


// Função para imprimir o array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int i = 0, n = 0;
    char len[10];
    char filename[100];
    while (true){

        printf("Digite qual arquivo .txt com numeros aleatorios voce quer digitar: \n");
        printf("Digite 'q' para sair");
        printf("Temos: '0500', '1000', '2000', '3000', '5000' (digite o tamanho do array) \n Escolha: ");
        scanf("%9s", len);
        if (strcmp(len, "q") == 0){
            return 1;
        }

        sprintf(filename, "../arrays/random_numbers_%s.txt", len);
        // Altere o caminho absoluto
        FILE *inputFile = fopen(filename,"r");
        printf("Arquivo a abrir: %s\n", filename);
        if (inputFile == NULL) {
            perror("Erro ao abrir o arquivo"); 
            exit(EXIT_FAILURE);
        }

        int *array = malloc(50 * sizeof(int)); // Assumindo que você tem até 50 números em cada linha
        if (array == NULL) {
            fprintf(stderr, "Falha ao alocar memoria!\n");
            exit(1);
        }
        double  sum = 0;
        for (int i = 0; i < 5000; i++){ // testa 5000 vezes e faz a media
            clock_t start = clock();
            while (fscanf(inputFile, "%d", &array[n]) != EOF) {
                n++;
                // Quando terminar de ler uma linha ou o array estiver cheio, ordena e calcula o tempo
                if (n == 50) { 
                    quickSort(array, 0, n - 1);
                    n = 0; // Reset para o próximo array
                }
            }
            clock_t end = clock();
            double time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;
            sum += time_spent; 
            printf("%lf\n", time_spent);
            }
        fclose(inputFile); 
        free(array); 
        printf("Tempo medio: %.10lf\n\n", (sum / 5000));
        }

    return 0;
}