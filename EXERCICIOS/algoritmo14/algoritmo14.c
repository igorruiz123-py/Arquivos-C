#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Faça um programa que leia um arquivo contendo o nome e o preço de diversos produtos
(separados por linha), e calcule o total da compra.
*/

void ReadFile(char *FileName){
    
    FILE *file;

    file = fopen(FileName, "r");

    if (file == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }

    char line[1024];
    int numbers[5];
    int index = 0;

    printf("File content: \n\n");

    while (fgets(line, sizeof(line), file) != NULL){

        printf("%s", line);

        if (isdigit(line[0])){
            numbers[index++] = atoi(line);
        }
    }

    printf("\n\n");

    printf("Numbers found: \n\n");

    int sum = 0;
    for (int i = 0; i < 5; i++){
        printf("numbers[%d] = %d \n", i, numbers[i]);
        sum = sum + numbers[i];
    }

    printf("\n");

    printf("Sum of numbers: %d \n", sum);

    fclose(file);
}

int main(){

    char FileName[] = "compras.txt";

    ReadFile(FileName);
}