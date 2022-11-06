#include<stdio.h>
#include<stdlib.h>
#define MAX 10

//basic
//matching parenthesis
//decimal to hexadecimal

void seek(int arr[], int *top){
    for(int i=0; i<=*(top);i++){
        printf("%d ", arr[i]);
    }
}

int isFull(int **top){
    if(**top == MAX-1){
        return 1;
    }
    else
    return 0;
}

int isEmpty(int **top){
    if(**top == -1){
        return 1;
    }
    else
    return 0;
}

void push(int arr[], int *top){
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

int pop(int arr[], int *top){
    int item;
    if(isEmpty(&top)){
        printf("Stack Underflow!");
        exit(1);
    }
    item = arr[*top];
    *(top)-=1;
    return item;
}

void menu(){
    int top = -1;
    int arr[MAX];
    int choose=0;
    int item;
    do
    {
        printf("Enter your choice: \n");
        printf("1.Push\n2.Pop\n3.Print element at the top\n4.Print all elements\n5.Exit\n");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                push(arr, &top);
                printf("\n\n");
                break;
            case 2:
                item = pop(arr, &top);
                printf("The element deleted is %d", item);
                printf("\n\n");
                break;
            case 3:
                printf("The element at the top is %d", arr[top]);
                printf("\n\n");
                break;
            case 4:
                seek(arr, &top);
                printf("\n\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    }while(choose != 5);
}

int main(){
    menu();
    return 0;
}