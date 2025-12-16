#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Fac¸a um programa que receba do usuario um arquivo texto e mostre na tela quantas ´
letras sao vogais e quantas s ˜ ao consoantes. 
*/

void ReadFile(char *FileName){

    FILE *File;

    printf("File Content: \n\n");

    File = fopen(FileName, "r");

    if (File == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }

    char vows[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    int VowCounter = 0;

    int ConsonantCounter = 0;

    char string[1024];

    while (fgets(string, sizeof(string), File) != NULL){

    printf("%s", string);

    for (int i = 0; string[i] != '\0'; i++){

        bool IsVow = false;;

        for (int j = 0; j < 10; j++){
            if (string[i] == vows[j]){
                VowCounter++;
                IsVow = true;
                break;
            }
        }

        if (!IsVow &&
            ((string[i] >= 'a' && string[i] <= 'z') ||
             (string[i] >= 'A' && string[i] <= 'Z'))) {
            ConsonantCounter++;
        }
    }
}

    fclose(File);

    printf("\n\n");

    printf("the file has %d vows \n", VowCounter);

    printf("\n");

    printf("the file has %d consonants \n", ConsonantCounter);

}

int main(){

    char FileName[] = "arq.txt";

    ReadFile(FileName);
}