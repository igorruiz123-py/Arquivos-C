#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que:
    (a) Crie/abra um arquivo texto de nome “arq.txt”
    (b) Permita que o usuario grave diversos caracteres nesse arquivo
    (c) Feche o arquivo
Agora, abra e leia o arquivoe escreva na tela todo o conteúdo armazenados
*/

void FlushBuffer(){
    int temp = 0;

    while ((temp = getchar()) != '\n' && temp != EOF){};
}

void MkFile(char *FileName, int *lines, char string[][1024]){

    FILE *File;

    File = fopen(FileName, "w");

    if (File == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }
 
    for (int i = 0; i  < *lines; i++){
        printf("Enter random text: ");
        fgets(string[i], 1024, stdin);
        fprintf(File, "%s", string[i]);
    }

    fclose(File);

    printf("\n");
}


void ReadFile(char *FileName, int *lines, char string[][1024]){

    FILE *File;

    File = fopen(FileName, "r");

    if (File == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }

    for (int i = 0; i < *lines; i++){
        fgets(string[i], 1024, File);
        printf("%s", string[i]);
    }

    fclose(File);
}


int main(){

    int lines = 0;

    char FileName[] = "arq.txt";

    printf("Enter number of lines: ");
    if (scanf(" %d", &lines) == 0){
        exit (EXIT_FAILURE);
    }

    FlushBuffer();

    char string[lines][1024];

    printf("\n");

    MkFile(FileName, &lines, string);
    ReadFile(FileName, &lines, string);
}