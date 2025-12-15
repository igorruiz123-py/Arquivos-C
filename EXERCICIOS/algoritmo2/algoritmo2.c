#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Suponha dado um arquivo contendo código C com comentários. Escreva um
programa que leia esse arquivo, remova os comentários, e grave o código limpo em
outro arquivo.
*/

void ReadCFile(char *FileName, char string[][1024]){

    FILE *File;

    File = fopen(FileName, "r");

    if (File == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }

    for (int i = 0; i < 9; i++){
        fgets(string[i], 1024, File);
    }

    fclose(File);
}

void CopyContentIntoAnotherFile(char *FileName, char string[][1024]){

    FILE *File;

    for (int i = 0; i < 9; i++){
        char *comment = strstr(string[i], "//");
        if (comment != NULL){
            *comment = '\0';
        }
    }

    File = fopen(FileName, "w");

    for (int j = 0; j < 9; j++){
        fprintf(File, "%s", string[j]);
    }

    fclose(File);

}

int main(){

    char FileName1[] = "exemplo.c";
    char FileName2[] = "exemplo_copy.c";
    char string[9][1024];

    ReadCFile(FileName1, string);
    CopyContentIntoAnotherFile(FileName2, string);
}