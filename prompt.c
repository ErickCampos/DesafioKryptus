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

void print_entry(char *entry) {
    printf("You entered: %s\n", entry);
}

void put(int *n){
    printf("Oi %d\n",n[0]);
}

void clear(int *list){
    memset(list, '\0', sizeof(list));
}
//void get(int n){
//
//}   

//void list(){

//}
int convertArray2Int(char *argument){
    int i = 0;
    int num = 0;
    while (argument[i] != '\0'){
        num =  (argument[i]-'0')+(num*10);
        i++;
    }
    printf("%d\n",num);
    return num;
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
        for(int j=space; j<201; j++){
            if(command[j] == '\0')
                break;
            argument[j] = command[j];
        }
        num = convertArray2Int(argument);
        printf("%d\n",num);
    }
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
