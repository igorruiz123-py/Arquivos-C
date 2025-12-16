#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Fac¸a um programa que receba do usuario um arquivo texto. Crie outro arquivo texto ´
contendo o texto do arquivo de entrada, mas com as vogais substitu´ıdas por ‘*’.
*/

void FlushBuffer(){
    int temp = 0;

    while((temp = getchar()) != '\n' && temp != EOF){};
}

void MkFile(char *FileName, int *lines){

    FILE *File;

    File = fopen(FileName, "w");

    if (File == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }

    char string[*lines][1024];

    for (int i = 0; i < *lines; i++){
        printf("Enter random text: ");
        fgets(string[i], 1024, stdin);
        fprintf(File, "%s", string[i]);
    }

    fclose(File);

    printf("\n");

    char CopyFileName[50];

    printf("Enter a new file name: ");
    fgets(CopyFileName, sizeof(CopyFileName), stdin);
    CopyFileName[strcspn(CopyFileName, "\n")] = '\0';

    FILE *CopyFile;

    CopyFile = fopen(CopyFileName,"w");

    char vowels[] = "aeiouAEIOU";

    if (CopyFile == NULL){
        perror("fopen");
    }

    for (int i = 0; i < *lines; i++){
        for (int j = 0; string[i][j] != '\0'; j++){
            for (int k = 0; vowels[k] != '\0'; k++){
                if (string[i][j] == vowels[k]){
                    string[i][j] = '*';
                    break;
                }
            }
        }

        fprintf(CopyFile, "%s", string[i]);
    }

    fclose(CopyFile);

    printf("%s was generated! \n", CopyFileName);
}



int PromptAndCheck(char *FileName, int *lines){

    printf("Enter number of lines: ");
    if (scanf(" %d", lines) == 0){
        FlushBuffer();
        return 0;
    }

    FlushBuffer();

    if (*lines < 0){
        FlushBuffer();
        return 0;
    }

    printf("\n");

    printf("Enter file name: ");
    fgets(FileName, sizeof(FileName), stdin);
    FileName[strcspn(FileName, "\n")] = '\0';

    FlushBuffer();

    printf("\n");

    for (int i = 0; FileName[i] != '\0'; i++){
        if (FileName[i] >= '0' && FileName[i] <= '9'){
            return 0;
        }
    }

    return 1;
}

int main(){

    char FileName[50];

    int lines = 0;

    if (PromptAndCheck(FileName, &lines)){
        MkFile(FileName, &lines);
    }

    else {
        printf("Error! \n");
        exit (EXIT_FAILURE);
    }
}