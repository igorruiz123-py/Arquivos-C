#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// TREINANDO LEITURA DE ARQUIVOS

/*
Há varias maneiras de fazer a leitura de um arquivo em C.

    1- Ler caractére por caractére por caractére com fgetc()
    2- Ler linha por linha usando fgets()
    3- Ler palavra/formato com fscanf()
*/

void TASK1(){

    char FileName[] = "aula2_int.txt";

    int array[1024];

    int counter = 0;

    FILE *file;

    file = fopen(FileName, "r");

    if (file == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }

    while (fscanf(file, "%d", &array[counter]) == 1) {
        counter++;
    }

    for (int i = 0; i < counter; i++){
        printf("array[%d] = %d \n", i, array[i]);
    }

    fclose(file);

    printf("\n");
}

void TASK2(){

    char string[1024];

    char FileName[] = "aula2_char.txt";

    FILE *file;

    file = fopen(FileName, "r");

    if (file == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }

    while (fgets(string, sizeof(string), file) != NULL) {
        printf("%s", string);
    }

    fclose(file);

}

int main(){
    
    // TASK 1 ler um arquivo que contém inteiros e armazenar seu conteúdo em um vetor e imprimir o conteúdo do vetor
    TASK1();

    // TASK2 Ler um arquivo que contém texto e armazenar seu conteúdo em um vetor e imprimir o conteúdo do vetor
    TASK2();
}