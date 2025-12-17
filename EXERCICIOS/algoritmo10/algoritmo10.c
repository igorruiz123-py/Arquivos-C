#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Fac¸a um programa que leia o conte´udo de um arquivo e crie um arquivo com o mesmo
conte´udo, mas com todas as letras min´usculas convertidas para mai´usculas. Os nomes
dos arquivos ser˜ao fornecidos, via teclado, pelo usu´ ario. A func¸ ˜ao que converte
mai´uscula para min´uscula ´e o toupper(). Ela ´e aplicada em cada caractere da string.
*/

#define MAX_LINES 5
#define MAX_LEN 1024 

void CheckFileName(char *FileName){

    for (int i = 0; FileName[i] != '\0'; i++){
        if (FileName[i] >= '0' && FileName[i] <= '9'){
            printf("Error line 23! \n");
            exit (EXIT_FAILURE);
        }
    }
}

void CheckFile(FILE *file){

    if (file == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }
}

void MakeFiles(){

    // Nome do arquivo 1
    char FileName1[50];

    printf("Enter name for file 1: ");
    fgets(FileName1, sizeof(FileName1), stdin);
    FileName1[strcspn(FileName1, "\n")] = '\0';

    CheckFileName(FileName1);

    printf("\n");

    // Nome do arquivo 2
    char FileName2[50];

    printf("Enter name for file 2: ");
    fgets(FileName2, sizeof(FileName2), stdin);
    FileName2[strcspn(FileName2, "\n")] = '\0';

    CheckFileName(FileName2);

    printf("\n");

    // Arquivo 1
    FILE *file1;

    file1 = fopen(FileName1, "w");

    CheckFile(file1);

    char string[MAX_LINES][MAX_LEN];

    for (int i = 0; i < MAX_LINES; i++){
        printf("Enter random text: ");
        fgets(string[i], MAX_LEN, stdin);
        fprintf(file1, "%s", string[i]);
    }

    fclose(file1);

    printf("\n");

    printf("%s was generated! \n", FileName1);

    printf("\n");

    // Arquivo 2
    FILE *file2;

    file2 = fopen(FileName2, "w");

    CheckFile(file2);

    for (int i = 0; i < MAX_LINES; i++){
        for (int j = 0; string[i][j] != '\0'; j++){
            if (islower(string[i][j])){
                string[i][j] = toupper(string[i][j]);
            }
        }

        fprintf(file2, "%s", string[i]);
    }

    fclose(file2);

    printf("%s was generated \n", FileName2);
}

int main(){

    MakeFiles();
}