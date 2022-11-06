#include<stdio.h>
#define max 30

char stack[max];
int top = -1;

void push(char ch)
{
    if(top==max-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++(top)] = ch;
    return;
}

void pop()
{
    if(top==-1)
    {
        printf("Stack underflow\n");
        return;
    }
    stack[top] = '0';
    (top)--;
    return;
}

void isBalanced(char string[])
{
    int i=0;
    while(string[i]!='\0')
    {
        if(string[i]=='{' || string[i]=='[' || string[i]=='(')
        {
            push(string[i]);
        }
        else
        {
            if(top==-1) 
            {
                printf("More closing Brackets\n");
                return;
            }
            if(string[i]==']' && stack[top]!='[' || string[i]=='}' && stack[top]!='{' || string[i]==')' && stack[top]!='(')
            {
                printf("Mismatch\n");
                return;
            }
            pop(stack , top);
        }
        i++;
    }
    if(top==-1)
    {
        printf("Balanced\n");
    }
    else
    {
        printf("More Opening Brackets\n");
    }
    return;
}
int main()
{
    char string[20];
    printf("Enter the brackets equation:\n");
    scanf("%s",string);
    isBalanced(string);
}