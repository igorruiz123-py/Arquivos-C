#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Faça um programa que recebe um vetor de 10 números, converta cada um desses
números para binário e grave a sequência de 0s e 1s em um arquivo texto. Cada número
deve ser gravado em uma linha.
*/

void FlushBuffer(){
    int temp = 0;

    while((temp = getchar()) != '\n' && temp != EOF){};
}

int GetNumbers(int *array){

    for (int i = 0; i < 10; i++){
        printf("Enter number: ");
        if (scanf(" %d", &array[i]) == 0){
            FlushBuffer();
            return 0;
        }
    }

    return 1;
}

void ConvertDecimalToBinary(int num, FILE *file) {
    char bin[32];
    int i = 0;

    if (num == 0) {
        fprintf(file, "0\n");
        return;
    }

    while (num > 0) {
        bin[i++] = (num % 2) + '0';
        num /= 2;
    }

    for (int j = i - 1; j >= 0; j--) {
        fputc(bin[j], file);
    }
    fputc('\n', file);
}

int main(){

    int numbers[10];

    FILE *file;

    file = fopen("bins.txt", "w");

    if (file == NULL){
        printf("error!\n");
        exit (EXIT_FAILURE);
    }

    if (GetNumbers(numbers)){
        
        for (int i = 0; i < 10; i++){
            ConvertDecimalToBinary(numbers[i], file);
        }
    }
    else{
        printf("error!\n");
    }

    fclose(file);
    return 0;

}