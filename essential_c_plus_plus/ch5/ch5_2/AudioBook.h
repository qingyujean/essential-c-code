#include <iostream>
#include <string.h>

#include "Book.h"

using namespace std;

class AudioBook: public Book {
public:
    AudioBook(const string &title, const string &author, const string &narrator): Book(title, author), _narrator(narrator) {
        cout << "AudioBook::AudioBook( " << _title 
             << ", " << _author
             << ", " << _narrator
             << " ) constructor\n";
    }

    virtual ~AudioBook() { cout << "AudioBook::~AudioBook() destructor!\n"; }
    virtual void print() const { 
        cout << "AudioBook::print() -- I am a AudioBook object!\n"
             << "My title is: " << _title << '\n'
             << "My auor is: " << _author << '\n'
             << "My narrator is: " << _narrator << endl; 
        }

    const string & narrator() const { return _narrator; } // 访问函数
private:
protected: // 可以被派生类直接访问
    string _narrator;
};