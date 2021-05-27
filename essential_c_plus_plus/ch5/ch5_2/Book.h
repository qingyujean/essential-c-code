#include <iostream>
#include <string.h>

#include "LibMat.h"

using namespace std;

class Book: public LibMat {
public:
    Book(const string &title, const string &author): _title(title), _author(author) {
        cout << "Book::Book( " << _title 
             << ", " << _author << " ) constructor\n";
    }

    virtual ~Book() { cout << "Book::~Book() destructor!\n"; }
    virtual void print() const { 
        cout << "Book::print() -- I am a Book object!\n"
             << "My title is: " << _title << '\n'
             << "My auor is: " << _author << endl; 
        }

    const string & title() const { return _title; } // 访问函数
    const string & author() const { return _author; }
private:
protected: // 可以被派生类直接访问
    string _title;
    string _author;
};