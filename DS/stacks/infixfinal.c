#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 100

int spaces(char chr)
{
    if (chr == ' ' || chr == '\t' || chr == '\n')
        return 1;
    else
        return 0;
}

int isOperator(char chr)
{
    if (chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '^'|| chr == '%')
        return 1;
    else
        return 0;
}

int instack_priority(char chr)
{
    if (chr == '^')
        return 4;
    else if (chr == '*' || chr == '/' || chr == '%')
        return 2;
    else if (chr == '+' || chr == '-')
        return 1;
    else
        return 0;
}

void push(char *stack, int *top, char c)
{
    if (*top == MAX - 1)
        printf("Stack Overflow!");
    else
    {
        *top = *top + 1;
        stack[*top] = c;
    }
}

char pop(char *stack, int *top)
{
    char c;
    if (*top == -1)
        printf("Stack Underflow");
    else
    {
        c = stack[*top];
        *top = *top - 1;
    }
    return c;
}

char peek(char *stack, int top)
{
    if (top == -1)
        return ' ';
    else
        return stack[top];
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

void infix_to_postfix(char *infix, char *postfix)
{
    char stack[MAX];
    int top = -1, i = 0, j = 0;
    char c;
    for(int i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == '(')
        {
            push(stack, &top, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((c = pop(stack, &top)) != '(')
            {
                postfix[j] = c;
                j++;
            }
        }
        else if (isOperator(infix[i]) == 1)
        {
            while (precedence(infix[i]) <= precedence(peek(stack, top)) && top != -1)
            {
                postfix[j] = pop(stack, &top);
                j++;
            }
            push(stack, &top, infix[i]);
        }
        else if (spaces(infix[i]) == 0)
        {
            postfix[j] = infix[i];
            j++;
        }
    }
    while (top != -1)
    {
        postfix[j] = pop(stack, &top);
        j++;
    }
    postfix[j] = '\0';
}

void infix_to_prefix(char *infix, char *prefix)
{
    char stack[MAX];
    int top = -1, j=0;
    char c;
    for(int i=strlen(infix)-1; i>=0; i--)
    {
        if (infix[i] == ')')
        {
            push(stack, &top, infix[i]);
        }
        else if (infix[i] == '(')
        {
            while ((c = pop(stack, &top)) != ')')
            {
                prefix[j] = c;
                j++;
            }
        }
        else if (isOperator(infix[i]) == 1)
        {
            while (precedence(infix[i]) < instack_priority(peek(stack, top)) && top != -1)
            {
                prefix[j] = pop(stack, &top);
                j++;
            }
            push(stack, &top, infix[i]);
        }
        else if (spaces(infix[i]) == 0)
        {
            prefix[j] = infix[i];
            j++;
        }
    }
    while (top != -1)
    {
        prefix[j] = pop(stack, &top);
        j++;
    }
    prefix[j] = '\0';
    strrev(prefix);
}

int operater(int a, int b, char c)
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

int evaluate_postfix(char *postfix)
{
    long int a,b,temp,result;
    int top = -1;
    char stack[MAX];
    for (int i = 0; i < strlen(postfix); i++)
    {
        if (isdigit(postfix[i]))
        {
            push(stack, &top, postfix[i] - '0');
        }
        else if (isOperator(postfix[i]) == 1)
        {
            a = pop(stack, &top);
            b = pop(stack, &top);
            temp = operater(a, b, postfix[i]);
            push(stack, &top, temp);
        }
    }
    result = pop(stack, &top);
    return result;
}

int evaluate_prefix(char *prefix)
{
    long int a,b,temp,result;
    int top = -1;
    char stack[MAX];
    for(int i=strlen(prefix)-1; i>=0; i--)
    {
        if(isdigit(prefix[i]))
        {
            push(stack, &top, prefix[i]-'0');
        }
        else if(isOperator(prefix[i])==1)
        {
            a=pop(stack, &top);
            b=pop(stack, &top);
            temp=operater(b, a, prefix[i]);
            push(stack, &top, temp);
        }
    }
    result=pop(stack, &top);
    return result;
}

int main()
{
    char infix[MAX], postfix[MAX], prefix[MAX];
    int result;
    while(1)
    {
        printf("\nEnter your choice: ");
        printf("\n1.Infix to Postfix\n2.Infix to Prefix\n3.Evaluate Postfix\n4.Evaluate Prefix\n5.Exit\n");
        int x;
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("\nEnter the infix expression(w/o spaces): ");
            scanf("%s", infix);
            infix_to_postfix(infix, postfix);
            printf("\nThe postfix expression is: %s\n", postfix);
            break;
        case 2:
            printf("\nEnter the infix expression(w/o spaces): ");
            scanf("%s", infix);
            infix_to_prefix(infix, prefix);
            printf("\nThe prefix expression is: %s\n", prefix);
            break;
        case 3:
            printf("\nEnter postfix expression(w/o spaces): ");
            scanf("%s", postfix);
            result = evaluate_postfix(postfix);                 
            printf("\nThe result is: %d\n", result);
            break;
        case 4:
            printf("\nEnter prefix expression(w/o spaces): ");
            scanf("%s", prefix);
            result = evaluate_prefix(prefix);
            printf("\nThe result is: %d\n", result);
            break;
        case 5:
            exit(0);
        default:    
            printf("\nInvalid input!");
        }
    }
    return 0;
}