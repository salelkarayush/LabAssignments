#include<stdio.h>
#include<stdlib.h>
#define MAX 10

//basic
//decimal to hexadecimal
//matching parenthesis

int top = -1;
int arr[MAX];

void seek(){
    for(int i=0; i<=top;i++){
        printf("%d ", arr[i]);
    }
}

int isFull(){
    if(top == MAX-1){
        return 1;
    }
    else 
    return 0;
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else
    return 0;
}

int pop(){
    int item;
    if(isEmpty()){
        printf("Stack Underflow!");
        exit(1);
    }
    item = arr[top];
    top-=1;
    return item;

}

void push(int n){
    if(isFull()){
        printf("Stack overflow!");
        return;
    }
    top+=1;
    arr[top] = n;
}

void menu(){
    int choose=0;
    int n;
    int item;
    do
    {
        printf("Enter your choice: \n");
        printf("1.Push\n2.Pop\n3.Print element at the top\n4.Print all elements\n5.Exit\n");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                printf("Enter the element you want to add: ");
                scanf("%d",&n);
                push(n);
                printf("\n\n");
                break;
            case 2:
                item = pop();
                printf("The element deleted is %d", item);
                printf("\n\n");
                break;
            case 3:
                printf("The element at the top is %d", arr[top]);
                printf("\n\n");
                break;
            case 4:
                seek();
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