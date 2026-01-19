#include <stdio.h>
#include <stdlib.h>

/*

BINARY FILES

*/

#define WRITE "wb"
#define READ "rb"
#define FILE_NAME "binary.dat"
#define COUNT 1

int write_binary_file(FILE *file){

    for (int i = 1; i <= 10; i++){

        fwrite(&i, sizeof(int), COUNT, file);
    }

    return 1;
}

int read_binary_file(FILE *file){

    int value;

    while(fread(&value, sizeof(int), COUNT, file)){
        printf("value = %d \n", value);
    }

    return 1;
}

int check_file(FILE *file){

    if (file == NULL){
        perror("fopen");
        exit(-1);
    }

    return 1;
}

int main(void){

    FILE *binary_file;

    binary_file = fopen(FILE_NAME, WRITE);

    check_file(binary_file);

    write_binary_file(binary_file);

    fclose(binary_file);

    binary_file = fopen(FILE_NAME, READ);

    check_file(binary_file);

    read_binary_file(binary_file);

    fclose(binary_file);

    return 0;
}
