#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Fac¸a um programa que permita que o usu´ ario entre com diversos nomes e telefone para
cadastro, e crie um arquivo com essas informac¸ ˜oes
*/


void FlushBuffer(){
    int temp = 0;

    while ((temp = getchar()) != '\n' && temp != EOF){};
}

typedef struct {

    char name[50];
    int TelephoneNumber;

}Users;

int GetFileName(char *string, size_t size){

    printf("Enter file name (.txt): ");
    fgets(string, size, stdin);
    string[strcspn(string, "\n")] = '\0';

    int StringLen = strlen(string);

    /*
    exemple:

    .txt = 3 
    StringLen = 8 
    0 -> 7
    string[StringLen - 1] = t
    string[StringLen - 2] = x
    string[StringLen - 3] = t
    string[StringLen - 4] = .

    file name = text.txt
    */
   
    if (string[StringLen - 1] != 't' && string[StringLen - 2] != 'x' && string[StringLen - 3] != 't' && string[StringLen - 4] != '.'){
        return 0;
    }

    for (int i = 0; string[i] != '\0'; i++){
        if (string[i] >= '0' && string[i] <= '9'){
            return 0;
        }
    }

    return 1;
}

int GetNumberOfUsers(int *var){

    printf("Enter number of users: ");
    if (scanf(" %d", var) == 0){
        FlushBuffer();
        return 0;
    }

    FlushBuffer();

    return 1;
}

int GetUserName(Users *var){

    printf("Enter user name: ");
    fgets(var->name, sizeof(var->name), stdin);
    var->name[strcspn(var->name, "\n")] = '\0';

    for (int i = 0; var->name[i] != '\0'; i++){
        if (var->name[i] >= '0' && var->name[i] <= '9'){
            return 0;
        }
    }

    return 1;
}

int GetUserTelephone(Users *var){

    printf("Enter user telephone number: ");
    if (scanf(" %d", &var->TelephoneNumber) == 0){
        FlushBuffer();
        return 0;
    }

    FlushBuffer();

    return 1;

}

int main(){

    int UserNumber;
    Users *user;

    if (GetNumberOfUsers(&UserNumber)){

        char FileName[50];

        if (!GetFileName(FileName, sizeof(FileName))){
            printf("Invalid entry! \n");
            exit (EXIT_FAILURE);
        }

        user = malloc(UserNumber * sizeof(Users));

        if (user == NULL){
            printf("Error to allocate memory! \n");
            exit (EXIT_FAILURE);
        }

        for (int i = 0; i < UserNumber; i++){

            printf("\n----- Data Entry For Users -----\n");


            if (!GetUserName(&user[i])){
                printf("Invalid Entry! \n");
                free(user);
                exit (EXIT_FAILURE);
            }

            if (!GetUserTelephone(&user[i])){
                printf("Invalid Entry! \n");
                free(user);
                exit (EXIT_FAILURE);
            }
        }

        FILE *file;

        file = fopen(FileName, "w");

        if (file == NULL){
            perror("fopen");
            exit (EXIT_FAILURE);
        }
        
        for (int i = 0; i < UserNumber; i++){

            fprintf(file, "USER NAME: %s \n", user[i].name);
            fprintf(file, "USER TELEPHONE NUMBER: %d \n", user[i].TelephoneNumber);
            fprintf(file, "-------------------------\n");
        }

        printf("file created! \n");

        fclose(file);
        free(user);
    }    

    else {
        printf("Invalid entry! \n");
        exit (EXIT_FAILURE);
    }

    return 0;
}