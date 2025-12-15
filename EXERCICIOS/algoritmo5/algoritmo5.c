#include <stdio.h>
#include <stdlib.h>

/*
Fac¸a um programa que receba do usuario um arquivo texto e mostre na tela quantas ´
linhas esse arquivo possui.
*/

void ReadFile(char *FileName){

    printf("File Content: \n\n");

    FILE *File;

    File = fopen(FileName, "r");

    if (File == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }

    int lines = 0;
    char string[1024];

    while (fgets(string, 1024, File) != NULL){
        printf("%s", string);
        lines++;
    }

    fclose(File);

    printf("\n\n");

    printf("the file has %d lines! \n", lines);

}

int main(){

    char FileName[] = "arq.txt";

    ReadFile(FileName);
}