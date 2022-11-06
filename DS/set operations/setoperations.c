// Develop a C program to perform the following set operations using a single linked list.
// Set Union
// Set Intersection
// Set Difference

#include <stdio.h>
#include <stdlib.h>
#define createnode(x) (x*)malloc(sizeof(x))

struct node
{
    int data;
    struct node *link;
};

struct node *create(struct node *start, int a)
{
    struct node *temp, *p;
    int n;
    printf("Enter the number of elements in set %d: ", a);
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;
    for (int i = 0; i < n; i++)
    {
        temp = createnode(struct node);
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->link = NULL;
        if (start == NULL)
            start = temp;
        else
        {
            p = start;
            while (p->link != NULL)
                p = p->link;
                p->link = temp;
        }
    }
    return start;
};

void display(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        printf("\nThe List is empty");
        return;
    }
    p = start;
    printf("\nLinked list is: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n");
};

struct node *setunion(struct node *start1, struct node *start2)
{
    struct node *start3, *temp, *p;
    start3 = NULL;
    p = start1;
    while (p != NULL)
    {
        temp = createnode(struct node);
        temp->data = p->data;
        temp->link = NULL;
        if (start3 == NULL)
            start3 = temp;
        else
        {
            struct node *q = start3;
            while (q->link != NULL)
                q = q->link;
            q->link = temp;
        }
        p = p->link;
    }
    p = start2;
    while (p != NULL)
    {
        temp = createnode(struct node);
        temp->data = p->data;
        temp->link = NULL;
        if (start3 == NULL)
            start3 = temp;
        else
        {
            struct node *q = start3;
            while (q->link != NULL)
                q = q->link;
            q->link = temp;
        }
        p = p->link;
    }
    return start3;
}

// intersection
struct node *setintersection(struct node *start1, struct node *start2)
{
    struct node *temp, *p, *q, *r;
    int n1, n2, n3;
    n1 = numberofnodes(start1);
    n2 = numberofnodes(start2);

    struct node *start3 = NULL;
    p = start1;
    while (p != NULL)
    {
        q = start2;
        while (q != NULL)
        {
            if (p->data == q->data)
            {
                temp = createnode(struct node);
                temp->data = p->data;
                temp->link = NULL;
                if (start3 == NULL)
                    start3 = temp;
                else
                {
                    r = start3;
                    while (r->link != NULL)
                        r = r->link;
                    r->link = temp;
                }
            }
            q = q->link;
        }
        p = p->link;
    }
    return start3;
}

struct node *setdifference(struct node *start1, struct node *start2)
{
    struct node *temp, *p, *q, *r;
    struct node* start3 = NULL;
    p = start1;
    while (p != NULL)
    {
        q = start2;
        while (q != NULL)
        {
            if (p->data == q->data)
                break;
            q = q->link;
        }
        if (q == NULL)
        {
            temp = createnode(struct node);
            temp->data = p->data;
            temp->link = NULL;
            if (start3 == NULL)
                start3 = temp;
            else
            {
                r = start3;
                while (r->link != NULL)
                    r = r->link;
                r->link = temp;
            }
        }
        p = p->link;
    }
    return start3;
}

int main()
{
    struct node *start1 = NULL, *start2 = NULL;
    int choice;
    while (1)
    {
        printf("\n1.Create lists\n2.Display lists\n3.Union of lists\n4.Intersection of lists\n5.Set difference of lists\n6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            start1 = create(start1, 1);
            start2 = create(start2, 2);
            break;
        case 2: 
            display(start1);
            display(start2);
            break;
        case 3:
            display(setunion(start1, start2));
            break;
        case 4:
            display(setintersection(start1, start2));
            break;
        case 5:
            display(setdifference(start1, start2));
            break;
        case 6:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}
