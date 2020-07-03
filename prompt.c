/*
   ============================================================================
Name        : Prompt.c
Author      : 
Version     :
Copyright   : 
Description : Hello World in C, Ansi-style
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void parse(char* command, int *arr);
void add(int num,int *arr);
void get(int num,int *arr);
void clear(int *list);

void print_entry(char *entry) {
    printf("You entered: %s\n", entry);
}

int main(int argc, char *argv[]) {
    char input[201];
    int  *arr = (int *)malloc(sizeof(int)*100);
    memset(arr, '\0', sizeof(arr));

    while(1) {
        printf("prompt> ");
        if (fgets(input, 200, stdin) == NULL) {
            printf("An error ocurred.\n");
            break;
        }

        if (strncmp(input, "exit\n", 5) == 0) {
            printf("Leaving. Good bye.\n");
            break;
        }
        parse(input, arr);
    }
    free(arr);
    return EXIT_SUCCESS;
}

void parse(char* command, int *arr){
    char function[6];
    char argument[5];
    int space;
    int num;
    memset(function, '\0', sizeof(function));
    memset(argument, '\0', sizeof(argument));

    for(int i=0; i<201; i++){
        function[i] = command[i];
        if (command[i] == ' '){
            space = i+1;
            break;
        }
        else if(command[i] == '\0'){
            space = -1;
            break;
        }
    }
    if(space<0){
        printf("%s\n",function);
    }
    else{
        int x = 0;
        for(int j=space; j<201; j++){
            if(command[j] == '\0')
                break;
    
            argument[x++] = command[j];
        }
        sscanf(argument, "%d", &num);
        if(strncmp(function, "put",3) == 0)
            add(num, arr);
        else if(strncmp(function, "get",3) == 0){
            //printf("O comando foi:  %s %d\n", function, num);
            get(num,arr);
        }
        else
            printf("Invalid command\n");
    }
}

void add(int num,int *arr){
    for (int i=0;i<100;i++)
        if(arr[i]=='\0'){
            arr[i]=num;
            break;
        }
}
void get(int num,int *arr){
    printf("%d\n",arr[num-1]);
}

void clear(int *arr){
    memset(arr, '\0', sizeof(arr));
}
