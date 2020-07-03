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
void list(int *arr);
void first(int *arr);
void last(int *arr);
void clear(int *arr);
void withdraw(int num, int *arr);
void ordain(int *arr);

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

        if(strncmp(function, "list",4) == 0)
            list(arr);
        else if(strncmp(function, "first",5) == 0)  
            first(arr);
        else if(strncmp(function, "last",4) == 0)
            last(arr);
        else if(strncmp(function, "clear",5) == 0)
            clear(arr);
        else if(strncmp(function, "sort",4) == 0)
            ordain(arr);
        else
            printf("Invalid command\n");
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
        else if(strncmp(function, "get",3) == 0)
            get(num,arr);
        else if(strncmp(function, "remove",6) == 0)
            withdraw(num,arr);
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
    if(arr[num-1] == '\0')
        printf("Invalid index\n");
    else 
        printf("%d\n",arr[num-1]);
}

void list(int *arr){
    for(int i=0; i<100;i++){
        if(arr[i] == '\0')
            break;
        printf("%d ",arr[i]);
    }
    if(arr[0]=='\0')
        printf("List is empty\n");
    else
        printf("\n");
        
}

void first(int *arr){
    if(arr[0]=='\0')
        printf("There is no element in the list\n");
    else
        printf("%d\n", arr[0]);
}
void last(int *arr){
    int last = 0;
    for(int i=0;i<100;i++){
        if(arr[i]=='\0'){
            last = i-1;
            break;
        }
    }
    if(arr[0]=='\0')
        printf("There is no element in the list\n");
    else
        printf("%d\n", arr[last]);
}

void clear(int *arr){
    memset(arr, '\0', sizeof(arr));
}

void withdraw(int num, int *arr){
    for(int i=num; i<100; i++){
        if(arr[num]=='\0'){
            arr[num-1] = '\0';
            break;
        }
        arr[num-1] = arr[num];
    }
}

void ordain(int *arr){
    int i = 1;
    int temp, j;
    while(arr[i]!='\0'){
        temp = arr[i];
        j = i-1;
        while((temp < arr[j]) &&( j>=0)){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = temp;
        i++;
    }
}
