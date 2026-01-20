#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define READ "r"
#define FILE_PATH "/home/ruiz1/Desktop/C/ARQUIVOS/EXERCICIOS/algoritmo17/output/login.txt"
#define LINE_MAX_SIZE 128
#define USER_MAX_SIZE 64
#define PASSWORD_MAX_SIZE 64

int find_user(const char *file_name, const char *target_user, char *password_out){

    FILE *file = fopen(file_name, READ);

    if (file == NULL){
        perror("fopen");
        exit (EXIT_FAILURE);
    }

    char line[LINE_MAX_SIZE];
    char user[USER_MAX_SIZE];

    while (fgets(line, sizeof(line), file)){

        if (strncmp(line, "USER:", 5) == 0){

            sscanf(line, "USER: %31s", user);

            if (strcmp(user, target_user) == 0){

                if (fgets(line, sizeof(line), file)){
                    sscanf(line, "PASSWORD: %31s", password_out);
                    fclose(file);
                    return 1;
                }
            }
        }
    }

    fclose(file);
    return 0;
}

int main(void){

    char password[PASSWORD_MAX_SIZE];

    char user[USER_MAX_SIZE];

    printf("Enter username: ");
    fgets(user, sizeof(user), stdin);
    user[strcspn(user, "\n")] = '\0';

    printf("\n");

    if (find_user(FILE_PATH, user, password)){
        printf("User found! '%s' Password: '%s' \n", user, password);
    }
    else{
        printf("User: '%s' not found! \n", user);
    }

    return 0;
}