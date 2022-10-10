// Develop a C program to implement the following:
// Accept two polynomials from the user
// Add the two polynomials
// Multiply the two polynomials
// Modify a given polynomial: Insert term and Delete term
// Accept the polynomials from a file

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define createnode(x) (x*)malloc(sizeof(x))

//add,multipy,modify(insert , delete)

struct node{
    int c;
    int pow;
    struct node* link;
};

struct node* addbeg(struct node *start, int cons, int power){
    struct node *tmp;
    tmp = createnode(struct node);
    tmp->c = cons;
    tmp->pow = power;
    tmp->link = start;
    start = tmp;
    return start;
}

struct node* addend(struct node *start, int cons, int power){
    struct node *p, *tmp;
    tmp = createnode(struct node);
    tmp->c = cons;
    tmp->pow = power;
    tmp->link = NULL;
    if (start == NULL)
        start = tmp;
    else
    {
        p = start;
        while (p->link != NULL)
            p = p->link;
        p->link = tmp;
    }
    return start;
}

struct node* create(struct node *start){
    int n,c,pow;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    start = NULL;
    if(n==0)
    return start;
    printf("NOTE: Enter the terms in decending order of power only!\n");
    printf("Enter the elements to insert of 1st term(constant,power): \n");
    scanf("%d", &c);
    scanf("%d", &pow);
    start = addbeg(start,c,pow);
    for(int i=2; i<=n; i++){
        printf("Enter the elements to insert of %dth term(constant,power): \n",i);
        scanf("%d", &c); 
        scanf("%d", &pow);
        start = addend(start,c,pow);
    }
    return start;
}

void display(struct node *start){
    struct node *p;
    if(start == NULL){
        printf("The list is empty!\n");
        return;
    }
    p = start;
    while(p != NULL){
        if(p->link == NULL){
            printf("%dx^%d", p->c, p->pow);
        }
        else
        printf("%dx^%d + ", p->c, p->pow);
        p = p->link;
    }
    printf("\n\n");
}

struct node* addition(struct node* start1 , struct node* start2){  
    struct node* start3 = NULL , *temp=NULL;
    while(start1!=NULL && start2!=NULL)
    {
        struct node* result;
        result = createnode(struct node);
        if(start3 == NULL)
        {
            start3 = result;
            temp = result;
        }
        else
        {
            temp->link=result;
            temp=result;
            temp->link = NULL;
        }
        if(start1->pow > start2->pow)
        {
            result->c = start1->c;
            result->pow = start1->pow;
            start1=start1->link;
        }
        else if(start1->pow<start2->pow)
        {
            result->c = start2->c;
            result->pow = start2->pow;
            start2 = start2->link;
        }
        else
        {
            result->c = start1->c+start2->c;
            result->pow = start1->pow;
            start1=start1->link;
            start2=start2->link;
        }
    }
    while(start1!=NULL)
    {
        struct node* result; 
        result = createnode(struct node);
        result->c = start1->c;
        result->pow = start1->pow;
        temp->link = result;
        temp = result;
        temp->link=NULL;
        start1 = start1->link;
    }
    while (start2!=NULL)
    {   
        struct node* result; 
        result = createnode(struct node);
        result->c = start2->c;
        result->pow = start2->pow;
        temp->link = result;
        temp=result;
        temp->link=NULL;
        start2 = start2->link;
    }
    return start3;
}

struct node* multiply(struct node* start1 , struct node* start2)
{
    struct node* start4 = NULL , *temp = NULL;
    while(start1!=NULL)
    {
        struct node* traverse = start2;
        while(traverse!=NULL)
        {   
            int flag = 1;
            int aftermath = start1->pow + traverse->pow;
            struct node* traverseResult = start4;
            while(traverseResult!=NULL) 
            {
                if(traverseResult->pow == aftermath)
                {
                    traverseResult->c += start1->c*traverse->c;
                    traverse = traverse->link;
                    flag = 0;
                    break;
                }
                traverseResult=traverseResult->link;
            }
            if(flag)
            {
                struct node* result;
                result = createnode(struct node);
                result->link = NULL;
                if(start4==NULL)
                {
                    start4 = result;
                    temp = result;
                }
                else
                {
                    temp->link=result;
                    temp=result;
                    temp->link = NULL;
                }
                result->c = start1->c*traverse->c;
                result->pow = start1->pow+traverse->pow;
                traverse = traverse->link;
            }
        }
        start1 = start1->link;
    }
    return start4;
}

struct node* deleteatbeg(struct node* start)
{
    if(start == NULL)
    {
        printf("List is Empty!\n");
        return start;
    }
    struct node* temp = start;
    start = start->link;
    free(temp);
    return start;
}

struct node* deleteatend(struct node* start)
{
    if(start==NULL)
    {
        printf("List is Empty!\n");
        return start;
    }
    struct node*tmp = start;
    while(tmp->link->link!=NULL)
        tmp=tmp->link;
    free(tmp->link);
    tmp->link=NULL;
    return start;
}

struct node* deleteatpos(struct node* start)
{
    if(start == NULL)
    {
        printf("List Empty\n");
        return start;
    }
    int pos;
    printf("Enter the position to be deleted:\n");
    scanf("%d",&pos);
    if(pos == 1)
    {
        start = deleteatbeg(start);
        return start;
    }
    
    //number of nodes
    int c = 0;
    struct node* tmp = start;
    while(tmp!=NULL)
    {
        c++;
        tmp=tmp->link;
    }
    if(pos == c)
    {
        start = deleteatend(start);
        return start;
    }
    int count = 1;
    struct node* traverse = start;
    while (traverse!=NULL && count<pos-1)
    {
        count++;
        traverse = traverse->link;
    }
    if(traverse == NULL || pos<1)
    {
        printf("Wrong Position\n\n");
        return start;
    }
    struct node* temp = traverse->link->link;
    free(traverse->link);
    traverse->link = temp;
    return start;
}

struct node *inputfromfile(struct node *start,int n)
{
    FILE *fp;
    if(n==1){
        //create file polynomial1.txt
        fp = fopen("polynomial1.txt", "w");
        printf("Enter the polynomial in the format 4x^3+2x^2+3x^1+5x^0 in file polynomial1.txt\n");
        fclose(fp);        
        //press "k" to continue after adding the polynomial
        printf("Press k to continue\n");
        char ch;
        scanf("%c",&ch);
        scanf("%c",&ch);
        if(ch=='k'){
            //read from file polynomial1.txt
            fp = fopen("polynomial1.txt", "r");
            char ch;
            int coeff, power;
            while (fscanf(fp, "%dx^%d", &coeff, &power) != EOF)
            {
                start = addend(start, coeff, power);
                fscanf(fp, "%c", &ch);
            }
            fclose(fp);
        }

    }
    
    else if(n==2){
        fp = fopen("polynomial2.txt", "w");
        printf("Enter the polynomial in the format 4x^3+2x^2+3x^1+5x^0 in file polynomial2.txt\n");
        fclose(fp);       
        printf("Press k to continue\n");
        char ch;
        scanf("%c",&ch);
        scanf("%c",&ch);
        if(ch=='k'){
            fp = fopen("polynomial2.txt", "r");
            char ch;
            int coeff, power;
            while (fscanf(fp, "%dx^%d", &coeff, &power) != EOF)
            {
                start = addend(start, coeff, power);
                fscanf(fp, "%c", &ch);
            }
            fclose(fp);
        }
    }
    return start;
}

void displaymenu(struct node* poly1 ,struct node* poly2,struct node* add,struct node* mul){
    int x=0;
    do{
        printf("1.Display polynomial 1\n2.Display polynomial 2\n3.Display added result\n4.Display multiplied result\n5.Exit\n");
        printf("Enter your choice: \n");
        scanf("%d",&x);
        switch(x){
            case 1:
                printf("Polynomial 1 is: ");
                display(poly1);
                printf("\n");
                break;
            case 2:
                printf("Polynomial 2 is: ");
                display(poly2);
                printf("\n");
                break;
            case 3:
                printf("The added polynomial is: ");
                display(add);
                printf("\n");
                break;
            case 4:
                printf("The multiplication result is: ");
                display(mul);
                printf("\n");
                break;
            case 5:
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }while(x!=5);
}

int main(){
    struct node* poly1 = NULL, *poly2 = NULL, *add = NULL, *multiplied = NULL;
    int choice;
    do{
        printf("1.Enter the polynomials\n2.Add two polynomials\n3.multiply two polynomials\n4.Modify\n5.Display\n6.Accept input from the file\n7.Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                poly1 = create(poly1);
                poly2 = create(poly2);
                break;
            case 2:
                add = addition(poly1,poly2);
                printf("The polynomial addition is: \n");
                display(add);
                break;
            case 3:
                multiplied = multiply(poly1,poly2);
                printf("The polynomial after multiplication is: \n");
                display(multiplied);
                break;
            case 4:
                while(add!=NULL){
                    struct node*x = add;
                    add = add->link;
                    free(x);
                }
                while(multiplied!=NULL){
                    struct node*x = multiplied;
                    multiplied = multiplied->link;
                    free(x);
                }
                int y=0;
                do{
                    printf("1.Change poly1\n2.Change poly2\n3.Delete a term in poly1\n4.Delete a term in poly2\n5.Exit\n");
                    printf("Enter your choice: \n");
                    scanf("%d",&y);
                    switch(y){
                        case 1:
                            poly1 = create(poly1);
                            break;
                        case 2:
                            poly2 = create(poly2);
                            break;
                        case 3:
                            display(poly1);
                            poly1 = deleteatpos(poly1);
                            break;
                        case 4:
                            display(poly2);
                            poly2 = deleteatpos(poly2);
                            break;
                        case 5:
                            break;
                        default:
                            printf("Invalid input\n");
                            break;
                    }
                }while(y!=5);
                break;
            case 5:
                displaymenu(poly1,poly2,add,multiplied);
                break;
            case 6:
                while(poly1!=NULL){
                    struct node*x = poly1;
                    poly1 = poly1->link;
                    free(x);
                }
                while(poly2!=NULL){
                    struct node*x = poly2;
                    poly2 = poly2->link;
                    free(x);
                }
                poly1 = inputfromfile(poly1,1);
                poly2 = inputfromfile(poly2,2);
                break;
            case 7:
                break;
            default:
                printf("Invalid input\n");
        }
    }while(choice!= 7);
    return 0;
}