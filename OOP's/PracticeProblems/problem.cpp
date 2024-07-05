#include <iostream>
#include <stdexcept>
#include <vector>
#include<string>

using namespace std;

class MyException : exception{
    MyException(char * s){
        cout << "The error is " << s << endl;
    }
};

class Book{
    public:
    string name;
    string author;
    static int no;
    public:
    Book():name(""),author(""){no++;}
    Book(string n,string a):name(n),author(a){no++;}
    virtual void display_book(){
       cout<<name<<":"<<author<<endl;
    }
};
int Book::no=0;

template <typename T> 
class EBook : public Book{
    public:
    T size;
    EBook():Book(),size(0){}
    EBook(T s, string n, string a) : size(s), Book(n, a){}
    void display_book(){
        Book::display_book();
        cout<<size<<endl;
    }
};



class Publisher{
    public:
    string PublisherName;
    Publisher():PublisherName(""){}
     Publisher(string s):PublisherName(s){}
     void display_publisher(){
        cout<<PublisherName<<endl;
     }

};

class PrintedBook :public Book{
    public:
    int pages;
    Publisher p;
    PrintedBook():Book(),p(),pages(0){}
    PrintedBook(string n, string a, int pa, string pname) : Book(n,a),pages(pa),p(pname){}

     void display_book(){
        Book::display_book();
        cout<<pages<<endl;
        cout<<"Publisher details are:"<<endl;
        p.display_publisher();
    }
};

class Shelf{
    public:
    static int no_of_shelves;
   
    vector<Book*> books;

    Shelf(){no_of_shelves++;}

    void addBooks(Book * b){
        books.push_back(b);
        cout << "Book added" << endl;

        return;
    }
    void display_shelf(){
        for(int i=0;i<books.size();i++){
           books[i]->display_book();
        }
    }
    
};

int Shelf :: no_of_shelves = 0;



class Library{
    public:
    string name;
    
    vector <Shelf*> shelfs;

    Library(string name) : name(name){}

    void addShelf(Shelf * s){
        shelfs.push_back(s);
        cout << "Shelf Added" << endl;
    }

    bool isSpace(){
        if(shelfs.size() == 5) return false;
        return true;
    }

};



int menu(){
    cout << "Enter 1 to a E-Book" << endl;
    cout << "Enter 2 to a printer Book" << endl;
    cout << "Enter 3 to add shelf" << endl;
    cout << "Enter 4 to a check no of books" << endl;
    cout << "Enter 5 to a check no of shelfs" << endl;

    return 0;
}

int main(){
    Library * lib = new Library("MAIN_LIB");

    Shelf s;

    lib->addShelf(&s);

    int shelfno = 0;

    EBook<int> * eb;
    PrintedBook * pb;
    string s1, s2, s3, s4, s5;
    int i1, i2, i3, i4, i5;

    int ch;

    switch(ch){
        menu();
        cin >> ch;
        case 1:
            cout << "" << endl;
            cout << "Enter the size, book name, author name" << endl;
            cin >> i1 >> s1 >> s2;
            eb = new EBook<int>(i1, s1, s2);

            lib->shelfs[shelfno].push_back(eb);
            break;

        case 1:
            cout << "" << endl;
            cout << "Enter the size, book name, author name" << endl;
            cin >> i1 >> s1 >> s2;
            eb = new EBook<int>(i1, s1, s2);
            break;


            
    }

    return 0;
}