#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class Library{
    public:
        string title,author,publisher;
        int price;
    
        Library()
        {
            title = " ";
            author = " ";
            publisher = " ";
            price = 0;
        }

        Library(Library&b)
        {
            title = b.title;
            author = b.author;
            publisher = b.publisher;
            price = b.price;
        }

        void accept();
        void single_display();
        void display();
}l;

void Library::accept()
{
    cout<<"\nEnter Book Title: ";
    cin>>title;
    cout<<"\nEnter Book Author: ";
    cin>>author;
    cout<<"\nEnter Book Pubisher: ";
    cin>>publisher;
    cout<<"\nEnter Price of Book: ";
    cin>>price;
    cout<<endl;
}

void Library::single_display()
{
    cout<<endl;
    cout<<"Book Title   : "<<title<<endl;
    cout<<"Author Name  : "<<author<<endl;
    cout<<"Publisher    : "<<publisher<<endl;
    cout<<"Price of Book: "<<price<<endl;
}

void Library::display()
{
    cout<<"\n"<<title<<"\t\t"<<author<<"\t\t"<<publisher<<"\t\t\t"<<price;
}   

Library search()
{
    int flag=0;
    string title;
    ifstream fin("book.dat");
    cout<<"\nEnter Book Title: ";
    cin>>title;
    while(fin.read((char*)&l,sizeof(l)))
    {
        if(title.compare(l.title)==0)
        {
            l.single_display();
            flag++;
            return l;
        }
    }
    fin.close();
    if(flag==0)
    cout<<"Book with Title: "<<title<<" not available...\n";
}


void addBook()
{
    int choice;
    cout<<"\n1.Enter a book";
    cout<<"\n2.Add a default book";
    cout<<"\n3.Copy a book";
    cout<<"\n\nEnter your choice: ";
    cin>>choice;
    ofstream fout;
    switch(choice)
    {
        case 1: 
                fout.open("book.dat",ios::app);
                l.accept();
                fout.write((char*)&l,sizeof(l));
                cout<<"Book data saved in file...\n";
                fout.close();
                break;
        
        case 2: 
                fout.open("book.dat",ios::app);
                l;
                fout.write((char*)&l,sizeof(l));
                cout<<"Book data saved in file...\n";
                fout.close();
                break;
        
        case 3: 
                fout.open("book.dat",ios::app);
                l=search();
                fout.write((char*)&l,sizeof(l));
                cout<<"Book data saved in file...\n";
                fout.close();
                break;

        default: cout<<"Enter a valid choice.....";
    }
}

void displayAllBooks()
{
    ifstream fin("book.dat");
    cout<<endl<<endl;
    for (int i =0;i<100;i++)
        cout<<"_";
    cout<<"\nTITLE\t\tAuthor\t\tPublisher\t\tPrice\n";
    for (int i =0;i<100;i++)
        cout<<"=";
    cout<<endl;
    int rec=0;
    while(fin.read((char*)&l,sizeof(l)))
    {
        l.display();
        rec++;
    }
    fin.close();
    cout<<endl;
    cout<<"\nTotal "<<rec<<" Records in file...\n";
}

int main()
{
    int ch;
    do{
        cout<<"\n-----------LIBRARY MANAGEMENT SYSTEM----------";
        cout<<"\n1. Add New Book\n";
        cout<<"2. Display All Books\n";
        cout<<"3. EXIT.\n";
        cout<<"\nEnter you choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: addBook(); 
                    break;
            case 2: displayAllBooks(); 
                    break;
            case 3: cout<<"\nTHANKYOU!!!!!\n\n"; 
                    break;
            default: cout<<"\nEnter valid choice...";
        }
    }while(ch!=3);
    return 0;
}