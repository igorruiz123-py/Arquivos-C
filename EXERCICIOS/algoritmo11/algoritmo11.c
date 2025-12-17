#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Fac¸a um programa que receba dois arquivos do usu´ ario, e crie um terceiro arquivo com
o conte´udo dos dois primeiros juntos (o conte´udo do primeiro seguido do conte´udo do
segundo).
*/

#define MAX_LEN 1024
#define MAX_LINES 5

void CheckFileName(char *FileName){

    // Validar nomes dos arquivos
    for (int i = 0; FileName[i] != '\0'; i++){
        if (FileName[i] >= '0' && FileName[i] <= '9'){
            printf("Error line 19 \n");
            exit (EXIT_FAILURE);
        }
    }
}

void GetFileName(char *FileName, size_t size){

    // Entrada de nome dos arquivos
    printf("Enter name for file : ");
    fgets(FileName, size, stdin);
    FileName[strcspn(FileName, "\n")] = '\0';

    CheckFileName(FileName);

    printf("\n");
}

void CheckFile(FILE *file){

    if (file == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }
}

void MakeFile(char *FileName, char string[MAX_LINES][MAX_LEN]){

    // Criação dos arquivos
    FILE *file;

    file = fopen(FileName, "w");

    CheckFile(file);

    for (int i = 0; i < MAX_LINES; i++){
        printf("Enter random text: ");
        fgets(string[i], MAX_LEN, stdin);
        fprintf(file, "%s", string[i]);
    }

    fclose(file);

    printf("\n");

    printf("file '%s' was generated! \n", FileName);

    printf("\n");

}

void MakeThirdFile(char *FileName, char FileString1[MAX_LINES][MAX_LEN], char FileString2[MAX_LINES][MAX_LEN]){

    // Criando o arquivo 3
    FILE *file;

    file = fopen(FileName, "w");

    CheckFile(file);

    for (int i = 0; i < MAX_LINES; i++){
        fprintf(file, "%s", FileString1[i]);
    }

    for (int i = 0; i < MAX_LINES; i++){
        fprintf(file, "%s", FileString2[i]);
    }

    fclose(file);

    printf("\n");

    printf("file '%s' was generated! \n", FileName);

    printf("\n");

}

int main(){

    char FileName1[50];
    char FileName2[50];
    char FileName3[50];

    char FileString1[MAX_LINES][MAX_LEN];
    char FileString2[MAX_LINES][MAX_LEN];

    GetFileName(FileName1, sizeof(FileName1));
    GetFileName(FileName2, sizeof(FileName2));
    GetFileName(FileName3, sizeof(FileName3));

    MakeFile(FileName1, FileString1);
    MakeFile(FileName2, FileString2);

    MakeThirdFile(FileName3, FileString1, FileString2);

    return 0;
}