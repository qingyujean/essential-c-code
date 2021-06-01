#include <string>
#include <iostream>

#include "../ch4_6/Triangular_iterator.h"
#include "../ch7_1/iterator_overflow.h"

using namespace std;

// 声明
extern void log_message(const char *);

bool has_elem(Triangular_iterator first, Triangular_iterator last, int elem){
    bool status = true;

    try{
        while(first != last){
            if(*first == elem)
                return status;
            ++first;
        }
    }catch(iterator_overflow &iof){
        log_message(iof.what_happened());
        log_message("check if iterators address same container");
    }
    status = false;
    return status;
}