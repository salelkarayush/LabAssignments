#include <bits/stdc++.h>
using namespace std;

class Library
{
    int serial;
    int day;
    int month;
    int year;
    int price;
    string title;
    string author;

public:
    void insert_book(Library *lib, int &count);
    void display(Library *lib, int count);
    void SearchAuthor(Library *lib, int count);
    void SearchTitle(Library *lib, int count);
    void del(Library *lib, int count);
};

void Library::SearchTitle(Library *lib, int count)
{
    string tocheck;
    cout << "Enter the book title to be searched" << endl;
    fflush(stdin);
    getline(cin, tocheck);
    fflush(stdin);
    for (int i = 0; i < count; i++)
    {
        if (tocheck.compare((lib + i)->title) == 0)
        {
            cout << left;
            cout << setw(15) << "Serial No." << setw(15) << "Title" << setw(15)
                 << "Author" << setw(15) << "Publishing date" << right << setw(15) << "Copies" << endl;
            cout << left;
            cout << setw(15) << (lib + i)->serial << setw(15) << (lib + i)->title << setw(15)
                 << (lib + i)->author << (lib + i)->day << "/" << (lib + i)->month << "/" << setw(9)
                 << (lib + i)->year << right << setw(15) << (lib + i)->price << endl;
            return;
        }
    }
    cout << "Book with Title not found\n";
}

void Library::del(Library *lib, int count)
{
    string d;
    cout << "Enter the title to be deleted" << endl;
    fflush(stdin);
    getline(cin, d);
    fflush(stdin);
    for (int i = 0; i < count; i++)
    {
        if ((d.compare((lib + i)->title) == 0))
        {
            lib[i] = lib[i + 1];
            count--;
            cout << "Book deleted successfully!" << endl;
            return;
        }
    }
    cout << "Book title not found" << endl;
}

void Library::SearchAuthor(Library *lib, int count)
{
    string tocheck;
    fflush(stdin);
    cout << "Enter the Author's Name" << endl;
    fflush(stdin);
    getline(cin, tocheck);
    for (int i = 0; i < count; i++)
    {
        if (tocheck.compare((lib + i)->author) == 0)
        {
            cout << left;
            cout << setw(15) << "Serial No." << setw(15) << "Title" << setw(15) << "Author"
                 << setw(15) << "Publishing date" << right << setw(15) << "Copies" << endl;
            cout << left;
            cout << setw(15) << (lib + i)->serial << setw(15) << (lib + i)->title << setw(15)
                 << (lib + i)->author << (lib + i)->day << "/" << (lib + i)->month << "/" << setw(9)
                 << (lib + i)->year << right << setw(15) << (lib + i)->price << endl;
            return;
        }
    }
    cout << "Author Not found" << endl;
}

void Library::display(Library *lib, int count)
{
    cout << left;
    cout << setw(15) << "Serial No." << setw(15) << "Title" << setw(15) << "Author"
         << setw(15) << "Publishing date" << right << setw(15) << "Copies" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << left;
        cout << setw(15) << (lib + i)->serial << setw(15) << (lib + i)->title << setw(15)
             << (lib + i)->author << (lib + i)->day << "/" << (lib + i)->month << "/" << setw(9)
             << (lib + i)->year << right << setw(15) << (lib + i)->price << endl;
    }
}

void Library ::insert_book(Library *lib, int &count)
{
    lib->serial = rand();
    getline(cin, lib->title);
    cout << "Enter the title of the book\n";
    fflush(stdin);
    getline(cin, lib->title);
    cout << "Enter the author of the book\n";
    getline(cin, lib->author);
    cout << "Enter the issue date:" << endl;
    cout << "Day: ";
    cin >> lib->day;
    cout << "Month: ";
    cin >> lib->month;
    cout << "Year:";
    cin >> lib->year;
    cout << "Enter the number of copies of the book" << endl;
    cin >> lib->price;
    count++;
}

int main()
{
    int n;
    cout << "Enter the capacity of Library: ";
    cin >> n; 
    Library *lib = new Library[n];
    int count = 0;
    while (1)
    {
        int sw;
        cout << "1-Insert Book\n2-Search By Author\n3-Search By title\n4-Display All Records\n5-Delete book record\n6-Exit\n";
        cin >> sw;
        switch (sw)
        {
        case 1:
            lib->insert_book(lib + count, count);
            break;
        case 2:
            lib->SearchAuthor(lib, count);
            break;
        case 3:
            lib->SearchTitle(lib, count);
            break;
        case 4:
            lib->display(lib, count);
            break;
        case 5:
            lib->del(lib, count);
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
    return 0;
}