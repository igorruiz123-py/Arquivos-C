#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Faça um programa que receba do usuário um arquivo que contenha o nome e a nota de
diversos alunos (da seguinte forma: NOME: JOÃO NOTA: 8), um aluno por linha. Mostre
na tela o nome e a nota do aluno que possui a maior nota.
*/

#define NUMBER_OF_STUDENTS 5
#define MAX_LEN 50
#define NUMBER_OF_GRADES 5
#define BASE 10

int CheckFile(FILE *file){

    if (file == NULL){
        perror("fopen");
        exit (EXIT_FAILURE); 
    }

    return 1;
}

int GetAndCheckFileName(char *FileName, size_t size){

    printf("Enter file name: ");
    fgets(FileName, size, stdin);
    FileName[strcspn(FileName, "\n")] = '\0';

    for (int i = 0; FileName[i] != '\0'; i++){
        if (FileName[i] >= '0' && FileName[i] <= '9'){
            printf("Invalid entry 1! \n");
            exit (EXIT_FAILURE);
        }
    }

    int FileNameLen = strlen(FileName);

    if (FileNameLen < 5){
        printf("Invalid entry 2! \n");
        exit (EXIT_FAILURE);
    }

    if (FileName[FileNameLen - 1] != 't' || FileName[FileNameLen - 2] != 'x' || FileName[FileNameLen - 3] != 't' || FileName[FileNameLen - 4] != '.'){
        printf("Invalid entry 3! \n");
        exit (EXIT_FAILURE);
    }

    printf("\n");

    return 1;
}

void MakeFile(char *FileName){

    char names[NUMBER_OF_STUDENTS][MAX_LEN];
    int grades[NUMBER_OF_GRADES];
    char buffer[MAX_LEN];

    for (int i = 0; i < NUMBER_OF_STUDENTS; i++){
        printf("Enter name of student: ");
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    printf("\n\n");

    for (int i = 0; i < NUMBER_OF_GRADES; i++){
        printf("Enter value for grade: ");
        fgets(buffer, sizeof(buffer), stdin);
        grades[i] = (int) strtol(buffer, NULL, BASE);
    }

    printf("\n\n");

    FILE *file;

    file = fopen(FileName, "w");

    CheckFile(file);

    for (int i = 0; i < NUMBER_OF_STUDENTS; i++){
        fprintf(file, "%s %d \n", names[i], grades[i]);
    }

    fclose(file);

    printf("\n");

    printf("file created! \n");
}

void ReadFile(char *FileName){

    char names[NUMBER_OF_STUDENTS][MAX_LEN];
    int grades[NUMBER_OF_STUDENTS];
    char line[MAX_LEN];

    int i = 0;
    FILE *file = fopen(FileName, "r");
    CheckFile(file);

    while (fgets(line, sizeof(line), file) && i < NUMBER_OF_STUDENTS){

        line[strcspn(line, "\n")] = '\0';

        char *last_space = strrchr(line, ' ');
        if (!last_space) continue;

        *last_space = '\0';
        strcpy(names[i], line);
        grades[i] = atoi(last_space + 1);

        i++;
    }

    fclose(file);

    // encontra maior nota
    int max_index = 0;
    for (int j = 1; j < i; j++){
        if (grades[j] > grades[max_index]){
            max_index = j;
        }
    }

    printf("\nStudents with highest grade:\n");
    printf("%s\n", names[max_index]);
}

int main(){

    char FileName[50];

    GetAndCheckFileName(FileName, sizeof(FileName));

    MakeFile(FileName);

    ReadFile(FileName);
}