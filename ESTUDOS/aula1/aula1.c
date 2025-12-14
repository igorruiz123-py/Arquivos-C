#include <stdio.h>
#include <windows.h>

// ARQUIVOS

/*
Um arquivo (ou file) é uma sequência de bytes que reside no disco (ou outro
dispositivo de armazenamento).

A estrutura de um arquivo é semelhante à da memória do computador, mas os bytes de um arquivo não podem ser endere-
çados individualmente. O acesso a um arquivo é estritamente sequencial: para
chegar ao 5o byte é preciso passar pelo 1o, 2o, 3o e 4o bytes.

Para que um programa possa manipular um arquivo, é preciso associar a ele
uma variável do tipo FILE (trata-se de uma struct definida no arquivo stdio.h).
Esta operação de associação é conhecida como abertura do arquivo e é executada
pela função fopen (abreviatura de file open). O primeiro argumento
de fopen é o nome do arquivo e o segundo argumento é "r" ou "w" para indicar
se o arquivo deve ser aberto para leitura (read) ou para escrita (write).
A função devolve o endereço de um FILE (ou NULL, se não encontra o arquivo
especificado). Depois de usar o arquivo, convém fechá-lo com a função fclose
(abreviatura de file close).

Para ler um arquivo, usa-se a função fscanf (abreviatura de file scanf ). Tal
como scanf, a função fscanf devolve o número de objetos efetivamente lidos.
*/

// WRINTING FILES
void WrintingFile(FILE **pF){

    char cwd[MAX_PATH];

    char FileName[] = "test_aula_1.txt";

    *pF = fopen(FileName, "a");

    if (*pF == NULL){
        exit (EXIT_FAILURE);
    }

    fprintf(*pF, "I am writing random text into a file that i just created \n");
    fprintf(*pF, "I am writing random text into a file that i just created \n");
    fprintf(*pF, "I am writing random text into a file that i just created \n");
    fprintf(*pF, "I am writing random text into a file that i just created \n");
    fprintf(*pF, "I am writing random text into a file that i just created \n");
    fprintf(*pF, "I am writing random text into a file that i just created \n");
    fprintf(*pF, "I am writing random text into a file that i just created \n");
    fprintf(*pF, "I am writing random text into a file that i just created \n");
    fprintf(*pF, "I am writing random text into a file that i just created \n");


    fclose(*pF);

    GetCurrentDirectory(MAX_PATH, cwd);
    printf("File '%s' created at %s \n",FileName ,cwd);

    printf("\n");
}

// READING FILES
void ReadingFile(FILE **pF){

    char FileName[] = "test_aula_1.txt";
    char buffer[1024];

    printf("FILE CONTENT: \n");

    *pF = fopen(FileName, "r");

    if (*pF == NULL){
        exit (EXIT_FAILURE);
    }

    while (fgets(buffer, 1024, *pF) != NULL){

        printf("%s \n", buffer);
    }

    fclose(*pF);

}

int main(){

    FILE *FileIn;
    FILE *FileOut;

    WrintingFile(&FileIn);
    ReadingFile(&FileOut);
}