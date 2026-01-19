#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Escreva um programa que simule um cadastro de um funionário de uma empresa com os seguintes dados:
nome completo, idade, sexo, data de nascimento e CPF. Escreva o output em um arquivo texto*/

#define MAX_NAME_LEN 64
#define MAX_DATEBIRTH_LEN 16
#define MAX_CPF_LEN 32
#define MAX_TITLE_LEN 24
#define MAX_BUFFER_SIZE 64
#define NUMERIC_BASE 10
#define FILE_NAME "employees.txt"
#define WRITE "w"

typedef struct {

    char name[MAX_NAME_LEN];
    int age;
    char sex;
    char birthdate[MAX_DATEBIRTH_LEN];
    char CPF[MAX_CPF_LEN];
    char title[MAX_TITLE_LEN];

} employee;

int read_int_input(int *var){

    char buffer[MAX_BUFFER_SIZE];
    char *end;

    if (!fgets(buffer, sizeof(buffer), stdin)){
        printf("Error to read Employee Numbers! \n");
        exit (EXIT_FAILURE);
    }

    *var = (int) strtol(buffer, &end, NUMERIC_BASE);

    if (end == buffer || (*end != '\n' && *end != '\0')){
        printf("Invalid entry on Employee Number! \n");
        exit (EXIT_FAILURE);
    }

    return *var;
}

void check_malloc(employee *var){

    if (var == NULL){
        perror("malloc");
        exit (EXIT_FAILURE);
    }
}

void check_file(FILE *file){

    if (file == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }
}

int get_name(employee *foo){

    printf("Enter name: ");
    fgets(foo->name, sizeof(foo->name), stdin);
    foo->name[strcspn(foo->name, "\n")] = '\0';

    for (int i = 0; foo->name[i] != '\0'; i++){
        
        if (foo->name[i] >= '9' && foo->name[i] <= '0'){
            printf("Invalid entry for Employee Name! \n");
            exit (EXIT_FAILURE);
        }
    }

    return 1;
}

int get_age(employee *foo){

    printf("Enter age: ");
    read_int_input(&foo->age);

    if (foo->age < 18 || foo->age >= 65){
        printf("Invalid entry for Employee Age! \n");
        exit (EXIT_FAILURE);
    }

    return 1;
}

int get_sex(employee *foo){

    char buffer[MAX_BUFFER_SIZE];

    printf("Enter sex (M or F): ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    if (strlen(buffer) != 1){
        printf("Invalid entry for Employee Sex! \n");
        exit (EXIT_FAILURE);
    }

    if (buffer[0] != 'M' && buffer[0] != 'F'){
        printf("Invalid entry for Employee Sex! \n");
        exit (EXIT_FAILURE);
    }

    foo->sex = buffer[0];

    return 1;
}

int get_birth_date(employee *foo){

    // 0 1 2 3 4 5 6 7 8 9
    // x x / x x / x x x x

    printf("Enter date of birth as (xx/xx/xxxx): ");
    fgets(foo->birthdate, sizeof(foo->birthdate), stdin);
    foo->birthdate[strcspn(foo->birthdate, "\n")] = '\0';

    if (foo->birthdate[2] != '/' || foo->birthdate[5] != '/'){
        printf("Invalid entry for Employee Date of Birth! \n");
        exit (EXIT_FAILURE);
    }

    int buffer[] = {0, 1, 3, 4, 6, 7, 8, 9};

    for (int i = 0; i < 8; i++){
        char c = foo->birthdate[buffer[i]];
        if (c < '0' || c > '9'){
            printf("Invalid entry for Employee Date of Birth! \n");
            exit (EXIT_FAILURE);
        }
    }

    return 1;
}

int get_CPF(employee *foo){

    // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 
    // x x x . x x x . x x x - x x

    printf("Enter CPF as (xxx.xxx.xxx-xx): ");
    fgets(foo->CPF, sizeof(foo->CPF), stdin);
    foo->CPF[strcspn(foo->CPF, "\n")] = '\0';

    if (foo->CPF[3] != '.' || foo->CPF[7] != '.' || foo->CPF[11] != '-'){
        printf("Invalid entry for Employee CPF! \n");
        exit (EXIT_FAILURE);
    }

    int buffer[] = {0,1,2,4,5,6,8,9,10,12,13};

    for (int i = 0; i < 11; i++) {
        char c = foo->CPF[buffer[i]];
        if (c < '0' || c > '9') {
            printf("Invalid entry for Employee CPF! \n");
            exit (EXIT_FAILURE);
        }
    }

    return 1;

}

int main(void){

    FILE *text_file;

    int employee_number;

    employee *emp;

    printf("Enter number of employees: ");
    read_int_input(&employee_number);

    if (employee_number <= 0){
        printf("Invalid number of employees! \n");
        exit (EXIT_FAILURE);
    }
    
    emp = malloc(employee_number * sizeof(employee));
    check_malloc(emp);

    for (int i = 0; i < employee_number; i++){

        printf("---- Data Entry for %d Emplyoee ---- \n", i + 1);

        get_name(&emp[i]);
        get_age(&emp[i]);
        get_sex(&emp[i]);
        get_birth_date(&emp[i]);
        get_CPF(&emp[i]);
        
        printf("\n");
    }

    printf("\n");

    text_file = fopen(FILE_NAME, WRITE);

    check_file(text_file);

    for (int j = 0; j < employee_number; j++){

        fprintf(text_file, "EMPLOYEE NAME: %s \n", emp[j].name);
        fprintf(text_file, "EMPLOYEE AGE: %d \n", emp[j].age);
        fprintf(text_file, "EMPLOYEE SEX: %c \n", emp[j].sex);
        fprintf(text_file, "EMPLOYEE BIRTH DATE: %s \n", emp[j].birthdate);
        fprintf(text_file, "EMPLOYEE CPF: %s \n", emp[j].CPF);
        fprintf(text_file, "---------------------------------------------------------------\n");
    }

    fclose(text_file);

    free(emp);

    return 0;
}