#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
Fac¸a um programa que receba do usuario um arquivo texto e um caracter. Mostre na tela ´
quantas vezes aquele caractere ocorre dentro do arquivo.
*/

void ReadFile(char *FileName, char *var){

    FILE *File;

    printf("file content: \n\n");

    File = fopen(FileName, "r");

    if (File == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }

    char string[1024];

    bool VarFound = false;

    int VarCounter = 0;

    while (fgets(string, sizeof(string), File) != NULL){

        printf("%s", string);

        for (int i = 0; string[i] != '\0'; i++){

            if (string[i] == *var){

                VarFound = true;
                VarCounter++;                
            }
        }
    }

    printf("\n");

    if (!VarFound){
        printf("Character not found! \n");
        exit (EXIT_FAILURE);
    }

    fclose(File);

    printf("\n\n");
    printf("the character '%c' apperead %d times in the file! \n", *var, VarCounter);
}

int PromptAndCheck(char *var){

    char buffer[10];

    printf("Enter character: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    for (int i = 0; buffer[i] != '\0'; i++){
        if (buffer[i] >= '0' && buffer[i] <= '9'){
            return 0;
        }
    }

    if (strlen(buffer) != 1){
        return 0;
    }

    *var = buffer[0];

    printf("\n");

    return 1;
}

int main(){

    char FileName[] = "arq.txt";

    char var;

    if (PromptAndCheck(&var)){
        ReadFile(FileName, &var);
    }
    else {
        printf("Error! \n");
        exit (EXIT_FAILURE);
    }
}