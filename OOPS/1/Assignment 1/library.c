#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book_record
{
    int number;
    int day;
    int month;
    int year;
    int copies;
    char subject[100];
    char title[100];
    char author[100];
};

int inputbooks(struct book_record book[], int count)
{
    char buffer[100];
    fflush(stdin);
    
    printf("Enter serial number of book: ");
    scanf("%d", &book->number);

    fgets(buffer, 100, stdin);
    strcpy(book->subject, buffer);

    fflush(stdin);

    printf("Enter title: ");
    fgets(buffer, 100, stdin);
    strcpy(book->title, buffer);

    fflush(stdin);

    printf("Enter author: ");
    fgets(buffer, 100, stdin);
    strcpy(book->author, buffer);

    fflush(stdin);

    printf("Enter subject: ");
    fgets(buffer, 100, stdin);
    strcpy(book->subject, buffer);


    fflush(stdin);
    printf("Enter the no. of copies: ");
    scanf("%d", &book->copies);
    fflush(stdin);
    printf("Enter the issue date:\n");
    printf("Day: ");
    scanf("%d",&book->day);
    printf("Month: ");
    scanf("%d",&book->month);
    printf("Year: ");
    scanf("%d",&book->year);
    return count;
}

void printbooks(struct book_record book[]){  //display
    printf("\nSerial number of book: %d\n", book->number);
    printf("\nTitle: %s", book->title);
    printf("\nAuthor: %s", book->author);
    printf("\nSubject: %s", book->subject);
    printf("\nNumber of copies: %d", book->copies);

    printf("\nIssue date: %d/%d/%d\n\n",book->day,book->month,book->year);
}

void search(struct book_record book[],int count){ //search based on title
    int i;
    char b[100];
    char t[100];
    printf("Enter the title to be searched: \n");

    fgets(b,100,stdin);
    strcpy(t,b);
    fflush(stdin);

    fflush(stdin);
    fgets(b,100,stdin);
    strcpy(t,b);
    fflush(stdin);
    for(i=0; i<count ;i++)
    {
        if(!strcmp(t , book[i].title)){
            printf("Title of book: %s\n",book[i].title);
            printf("Author of book: %s\n",book[i].author);
            printf("Subject related to book: %s\n",book[i].subject);
        }
        else{
        printf("Book not found!\n");
        }
    }
}
void searchauth(struct book_record book[],int count)
{
    int i;
    char b[100];
    char auth[100];
    printf("Enter the author to be searched: \n");

    fgets(b,100,stdin);
    strcpy(auth,b);
    fflush(stdin);

    fflush(stdin);
    fgets(b,100,stdin);
    strcpy(auth,b);
    fflush(stdin);
    for(i=0;i<count ;i++)
    {
        if(!strcmp(auth , book[i].author))
        {
            printf("Title of book: %s\n",book[i].title);
            printf("Author of book: %s\n",book[i].author);
            printf("Subject related to book: %s\n",book[i].subject);
        }
        else{
        printf("Book not found!\n");
        }
    }
}

int del(struct book_record book[],int count){
    char d[100]; 
    char b[100];
    printf("Enter the title of book to be deleted\n");
    getchar();
    fflush(stdin);
    fgets(b,100,stdin);
    strcpy(d,b);
    fflush(stdin);
    for(int i=0;i<count;i++)
    {
        if(strcmp(d ,book[i].title)==0)
        {
            book[i]=book[i+1];
            count=count-1;
            printf("The book deleted successfully!\n");
            return count;
        }
    }
    return count;
}

int choicee(){
    int choice;
    printf("\n1.Insert a book record\n2.Search based on title\n3.Search based on author\n4.Delete books\n5.Display all book records\n6.Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void menu(struct book_record book[], int count)
{
    int choice, number;
    do
    {
        choice = choicee();
        switch (choice)
        {
        case 1:
            for (int i = count; i < count+1; i++)
            {
                count = inputbooks(&book[i], count);
            }
            count++;
            break;
        case 2:
            search(book ,count);
            break;
        case 3:
            searchauth(book, count);
            break;
        case 4:
            count=del(book,count);
            break;
        case 5:
            for (int i = 0; i < count; i++)
            {
                printbooks(&book[i]);
            }
            break;
        default:
            printf("\nInvalid choice");
            break;
        }
    } while (choice != 6);
}

int main(){
    int count = 0;
    struct book_record book[100];
    menu(book, count);
    return 0;
}