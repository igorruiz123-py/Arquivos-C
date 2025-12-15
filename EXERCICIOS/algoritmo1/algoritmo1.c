#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

/*
Escreva um programa que crie um arquivo e faça uma cópia desse arquivo.
*/

void ModifyFileNames(char *filename1, char *filename2){

    char const *text = "_copy";
    char const *extension = ".txt";

    strcpy(filename2, filename1);

    strcat(filename2, text);

    strcat(filename1, extension);

    strcat(filename2, extension);

}

void MkFile(char *filename, char string[][50]){

    char cwd[MAX_PATH];

    FILE *file;

    file = fopen(filename, "w");

    if (file == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }

    for (int i = 0; i < 5; i++) {
        printf("Enter random text %d: ", i + 1);
        fgets(string[i], 50, stdin);
        fprintf(file, "%s", string[i]);
    }
    fclose(file);

    printf("\n");

    GetCurrentDirectory(MAX_PATH, cwd);
    printf("File: %s created at %s \n", filename, cwd);

    printf("\n");
}

void CopyFile_(char *filename, char string[][50]){

    FILE *file;

    char cwd[MAX_PATH];

    file = fopen(filename, "w");

    if (file == NULL){
        exit (EXIT_FAILURE);
    }

    for (int i = 0; i < 5; i++) {
        fprintf(file, "%s", string[i]);
    }

    fclose(file);

    GetCurrentDirectory(MAX_PATH, cwd);
    printf("File: %s created at %s \n", filename, cwd);

    printf("\n");
}

int main(){

    char FileName1[50];
    char FileName2[50];
    char string[5][50];

    printf("Enter file name: ");
    fgets(FileName1, sizeof(FileName1), stdin);
    FileName1[strcspn(FileName1, "\n")] = '\0';

    ModifyFileNames(FileName1, FileName2);

    printf("\n");

    MkFile(FileName1, string);

    CopyFile_(FileName2, string);

}