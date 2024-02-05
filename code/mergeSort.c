#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Função para combinar duas subarrays de arr[].
// A primeira subarray é arr[l..m]
// A segunda subarray é arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Crie arrays temporários
    int L[n1], R[n2];

    // Copie os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Combine os arrays temporários de volta em arr[l..r]
    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = l; // Índice inicial do subarray combinado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copie os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copie os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l é para o índice esquerdo e r é para o índice direito do
// subarray de arr a ser ordenado
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Encontre o ponto médio
        int m = l + (r - l) / 2;

        // Ordena a primeira e segunda metades
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Combina as metades ordenadas
        merge(arr, l, m, r);
    }
}

// Programa principal para testar as funções acima
int main() {
    FILE *file;
    int *array;
    int size = 500; // Ajuste este valor para o número correto de linhas no seu arquivo
    int i = 0;

    // Lê os números do arquivo de 500 números e armazena no array

    // Aloca memória para o array
    array = (int*) malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }

    // Abre o arquivo para leitura
    file = fopen("arrays/random_numbers_0500.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Lê os números do arquivo e armazena no array
    while (i < size && fscanf(file, "%d", &array[i]) == 1) {
        i++;
    }

    fclose(file);

    // Chama a função mergeSort 10 vezes, medindo o tempo médio de execução
    clock_t start, end;
    double cpu_time_used;
    double total_time = 0;
    int j;

    for (j = 0; j < 10; j++) {
        start = clock();
        mergeSort(array, 0, size - 1);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        total_time += cpu_time_used;
    }

    printf("Tempo medio de execucao: %f segundos\n", total_time / 10);

    // Libera a memória alocada para o array
    free(array);

    // Lê os números do arquivo de 1000 números e armazena no array
    size = 1000;
    i = 0;

    // Aloca memória para o array
    array = (int*) malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }

    // Abre o arquivo para leitura
    file = fopen("arrays/random_numbers_1000.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Lê os números do arquivo e armazena no array
    while (i < size && fscanf(file, "%d", &array[i]) == 1) {
        i++;
    }

    fclose(file);

    // Chama a função mergeSort 10 vezes, medindo o tempo médio de execução
    total_time = 0;

    for (j = 0; j < 10; j++) {
        start = clock();
        mergeSort(array, 0, size - 1);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        total_time += cpu_time_used;
    }

    printf("Tempo medio de execucao: %f segundos\n", total_time / 10);

    // Libera a memória alocada para o array
    free(array);

    // Lê os números do arquivo de 2000 números e armazena no array
    size = 2000;
    i = 0;

    // Aloca memória para o array
    array = (int*) malloc(size * sizeof(int));

    if (array == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }

    // Abre o arquivo para leitura
    file = fopen("arrays/random_numbers_2000.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Lê os números do arquivo e armazena no array
    while (i < size && fscanf(file, "%d", &array[i]) == 1) {
        i++;
    }

    fclose(file);

    // Chama a função mergeSort 10 vezes, medindo o tempo médio de execução
    total_time = 0;

    for (j = 0; j < 10; j++) {
        start = clock();
        mergeSort(array, 0, size - 1);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        total_time += cpu_time_used;
    }

    printf("Tempo medio de execucao: %f segundos\n", total_time / 10);

    // Libera a memória alocada para o array
    free(array);

    // Lê os números do arquivo de 3000 números e armazena no array
    size = 3000;
    i = 0;

    // Aloca memória para o array
    array = (int*) malloc(size * sizeof(int));

    if (array == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }

    // Abre o arquivo para leitura
    file = fopen("arrays/random_numbers_3000.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Lê os números do arquivo e armazena no array
    while (i < size && fscanf(file, "%d", &array[i]) == 1) {
        i++;
    }

    fclose(file);

    // Chama a função mergeSort 10 vezes, medindo o tempo médio de execução
    total_time = 0;

    for (j = 0; j < 10; j++) {
        start = clock();
        mergeSort(array, 0, size - 1);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        total_time += cpu_time_used;
    }

    printf("Tempo medio de execucao: %f segundos\n", total_time / 10);

    // Libera a memória alocada para o array
    free(array);

    // Lê os números do arquivo de 5000 números e armazena no array
    size = 5000;
    i = 0;

    // Aloca memória para o array
    array = (int*) malloc(size * sizeof(int));

    if (array == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }

    // Abre o arquivo para leitura
    file = fopen("arrays/random_numbers_5000.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Lê os números do arquivo e armazena no array
    while (i < size && fscanf(file, "%d", &array[i]) == 1) {
        i++;
    }

    fclose(file);

    // Chama a função mergeSort 10 vezes, medindo o tempo médio de execução
    total_time = 0;

    for (j = 0; j < 10; j++) {
        start = clock();
        mergeSort(array, 0, size - 1);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        total_time += cpu_time_used;
    }

    printf("Tempo medio de execucao: %f segundos\n", total_time / 10);

    // Libera a memória alocada para o array
    free(array);

    return 0;
}
