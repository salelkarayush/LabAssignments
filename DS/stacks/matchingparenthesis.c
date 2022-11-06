#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10

//basic
//matching parenthesis
//decimal to hexadecimal

int isFull(int **top){
    if(**top == MAX-1){
        return 1;
    }
    else
    return 0;
}

void push(char arr[], int *top){
    int n;
    printf("Enter the element you want to add: ");
    scanf("%d",&n);
    if(isFull(&top)){
        printf("Stack overflow!");
        return;
    }
    *(top)+=1;
    arr[*top] = n;
}

void ifmatch(char pare[], char stack[], int *top){
    for(int i = 0; i < strlen(pare); i++){
        if(pare[i]=='[' || pare[i]=='{' || pare[i]=='('){
            push(pare , &top);
        }
        else{
            printf("Unbalanced!");
        }
    }
}

 int main(){
    int top = -1;
    char stack[MAX];
    char pare[100];
    printf("Enter the parenthesis: ");
    scanf("%s", &stack);
    ifmatch(pare, stack, &top);
    printf("%s", stack);
    return 0;
 }
