// Develop a C a program to convert:
// 1. Infix expression to postfix
// 2. Infix expression to prefix
// 3. Evaluation of a Postfix expression
// 4. Evaluation of a Prefix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX 20

char stack[MAX];
int top = -1;

void push(char a){
    if(top == MAX-1){
        printf("Stack overflow!");
        return;
    }
    else
    top++;
    stack[top] = a;
}

int pop(){
    int item;
    if(top == -1){
        printf("Stack Underflow!");
        exit(1);
    }
    item = stack[top];
    top-=1;
    return item;

}

int precedence(char x){
    switch(x){
        case '(':
            return 0;
            break;
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
        case '%':
            return 2;
            break;
        case '^':
            return 4;
            break;
    }
}

int operations(int a, int b, char c)
{
    switch (c)
    {
    case '+':
        return a+b;
    case '-':
        return b-a;
    case '*':
        return a*b;
    case '/':
        return b/a;
    case '%':
        return b%a;
    case '^':
        return pow(b,a);
    default:
        return 0;
    }
}

void infix_to_prefix(char a[]){
    char buffer;
    strrev(a);
    for(int i=0; a[i]!='\0'){
        if(a[i]=='('){
            a[i]= ')';
        }
        if(a[i]==')'){
            a[i]=='(';
        }
        if(isalnum(a[i])){
            printf("%c",a[i]);
        }
        else if(a[i] == '('){
            push(a[i]);
        }
        else if(a[i]==')'){
            while((buffer = pop()) != '('){
                printf("%c", buffer);
            }
        }
        else{
            while(precedence(stack[top])>=precedence(a[i]))
                printf("%c", pop());
            push(a[i]);
        }
    }
    while(top != -1)
    {
        printf("%c", pop());
    }
}

void infix_to_postfix(char a[]){
    char buffer;
    for(int i=0; i<strlen(a); i++){
        if(isalnum(a[i])){
            printf("%c",a[i]);
        }
        else if(a[i] == '('){
            push(a[i]);
        }
        else if(a[i]==')'){
            while((buffer = pop()) != '('){
                printf("%c", buffer);
            }
        }
        else{
            while(precedence(stack[top])>=precedence(a[i]))
                printf("%c", pop());
            push(a[i]);
        }
    }
    while(top != -1)
    {
        printf("%c", pop());
    }
}

int main(){
    char infix[100];
    int choice=0;
    printf("Enter your choice:\n");
    printf("1.Infix to Postfix\n2.Infix to Prefix\n3.Postfix Evaluation\n4.Prefix Evaluation\n5.Exit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the Infix Operation(w/o spaces): ");
            scanf("%s",&infix);
            infix_to_postfix(infix);
            break;
        case 2:
            printf("Enter the Infix Operation(w/o spaces): ");
            scanf("%s",&infix);
            infix_to_prefix(infix);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Invalid Choice!");
    }
    printf("Enter the infix operatrion: ");
    scanf("%s",&infix);
    infix_to_postfix(infix);
    return 0;
}