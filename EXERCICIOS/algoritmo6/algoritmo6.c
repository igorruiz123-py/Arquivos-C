#include <stdio.h>
#include <stdlib.h>

/*
Fac¸a um programa que receba do usuario um arquivo texto e mostre na tela quantas vogais existe no arquivo
*/

void ReadFile(char *FileName){

    FILE *File;

    printf("File Content: \n\n");

    File = fopen(FileName,"r");

    if (File == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }

    char vows[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    char string[1024];
    int vow = 0;

    while (fgets(string, sizeof(string), File) != NULL){

        printf("%s", string);

        for (int i = 0; string[i] != '\0'; i++){

            for (int j = 0; j < 10; j++){

                if (string[i] == vows[j]){
                    vow++;
                }
            }
        }
    }

    fclose(File);

    printf("\n\n");

    printf("the file has %d vows \n", vow);
}

int main(){

    char FileName[] = "arq.txt";

    ReadFile(FileName);
}