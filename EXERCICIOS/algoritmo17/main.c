#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*Escreva um programa que cadastre um login (usuário e senha) em um arquivo texto e faça uma busca do usuário e 
retornando se ele existe ou não e sua senha usando um algoritmo de busca*/

#define APPEND "a"
#define FILE_NAME "login.txt"
#define USERNAME_MAX_SIZE 16
#define BUFFER_LEN_MAX_SIZE 64
#define NUMERIC_BASE_STRTOL 10
#define MIN 1000
#define MAX 10000

typedef struct {

    char username[USERNAME_MAX_SIZE];
    int password;

} login;

int read_int_input(int *var){

    char buffer[BUFFER_LEN_MAX_SIZE];
    char *end;

    if (!fgets(buffer, sizeof(buffer), stdin)){
        printf("Error to read Number of Logins! \n");
        exit (EXIT_FAILURE);
    }

    *var = (int) strtol(buffer, &end, NUMERIC_BASE_STRTOL);

    if (end == buffer || (*end != '\n' && *end != '\0')){
        printf("Invalid entry for Number of Logins! \n");
        exit (EXIT_FAILURE);
    }

    return *var;
}

int check_number_of_employees(int *var){

    if (*var <= 0){
        printf("Invalid number of logins! \n");
        exit (EXIT_FAILURE);
    }

    return 1;
}

int check_malloc(login *var){

    if (var == NULL){
        perror("malloc");
        exit (EXIT_FAILURE);
    }

    return 1;
}

int check_file(FILE *var){

    if (var == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }

    return 1;
}

void get_user_name(login *var){

    int space_index = -1;
    char buffer[BUFFER_LEN_MAX_SIZE];
    char aux[BUFFER_LEN_MAX_SIZE];

    printf("Enter first and last name: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    if (strlen(buffer) < 8){
        printf("Name and last name must be at least 8 characters! \n");
        exit (EXIT_FAILURE);
    }

    for (int i = 0; buffer[i] != '\0'; i++){

        if (buffer[i] <= '9' && buffer[i] >= '0'){
            printf("Error, name and last name must be all characters! \n");
            exit (EXIT_FAILURE);
        }

        if (buffer[i] == ' '){
            space_index = i;
            break;
        }
    }

    if (space_index == -1){
        printf("It is required name and last name! \n");
        exit (EXIT_FAILURE);
    }

    aux[0] = buffer[0];

    strcpy(&aux[1], &buffer[space_index + 1]);

    strcpy(var->username, aux);
}

void generate_user_password(login *var){

    int password;

    password = rand() % (MAX - MIN + 1) + MIN;

    var->password = password;
}

int main(void){

    srand(time(NULL));

    int login_number;

    login *log;

    FILE *file;

    printf("Enter number of users: ");
    read_int_input(&login_number);
    check_number_of_employees(&login_number);

    log = malloc(login_number * sizeof(login));
    check_malloc(log);

    file = fopen(FILE_NAME, APPEND);
    check_file(file);
    
    printf("\n");
    
    for (int i = 0; i < login_number; i++){

        printf("--------- User Data Entry! -------------\n");

        get_user_name(&log[i]);
        generate_user_password(&log[i]);

    }

    printf("\n");

    for (int j = 0; j < login_number; j++){

        fprintf(file, "USER: %s \n", log[j].username);
        fprintf(file, "PASSWORD: %d \n", log[j].password);
        fprintf(file, "---------------------------------------------\n");
    }

    fclose(file);

    free(log);

    return 0;
}