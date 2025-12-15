#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Escreva um programa que conte o número de ocorrências de cada um dos caracteres
de um arquivo.
*/

void ReadFile(char *FileName, char string[][1024]){

    FILE *File;

    File = fopen(FileName, "r");

    if (File == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }

    for (int i = 0; i < 5; i++){
        fgets(string[i], 1024, File);
    }

    fclose(File);
}

void CountChar(char string[][1024]){

    int count[256] = {0};

    for (int i = 0; i < 5; i++) {

        for (int j = 0; string[i][j] != '\0'; j++) {

            unsigned char c = string[i][j];
            count[c]++;
        }
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            printf("charactere '%c' appears %d times\n", i, count[i]);
        }
    }
}

int main(){

    char FileName[] = "exercicio.txt";
    char string[5][1024]; 

    ReadFile(FileName, string);
    CountChar(string);
}