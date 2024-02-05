#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <errno.h>

void shellSort(int *array,int tamanho_array){
    for (int gap = tamanho_array/2; gap > 0;gap = gap/2){
        for(int i = gap; i < tamanho_array; i++){
            int atual = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > atual;j -= gap){
                array[j] = array[j - gap];
            }
            array[j] = atual;
        }
    }


}

/*Função para imprimir o array caso queira*/
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
        printf("Digite 's' para sair");
        printf("Temos: '0500', '1000', '2000', '3000', '5000' (digite o tamanho do array) \n Escolha: ");
        scanf("%9s", len);
        if (strcmp(len, "s") == 0){
            return 1;
        }
        sprintf(filename, "../arrays/random_numbers_%s.txt", len);                      

        FILE *inputFile = fopen(filename,"r");
        printf("Arquivo a abrir: %s\n", filename);
        if (inputFile == NULL) {
            perror("Erro ao abrir o arquivo"); 
            exit(EXIT_FAILURE);
        }

        int *array = malloc(50 * sizeof(int)); 
        if (array == NULL) {
            fprintf(stderr, "Falha ao alocar memoria!\n");
            exit(1);
        }

        double  sum = 0;
        for (int i = 0; i < 5000; i++){ 
            clock_t start = clock();
            while (fscanf(inputFile, "%d", &array[n]) != EOF) {
                n++;
                if (n == 50) { 
                    shellSort(array, n - 1);
                    n = 0;
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