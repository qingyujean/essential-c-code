#include <string>
#include <iostream>

#include "../ch7_1/iterator_overflow.h"

using namespace std;

// 声明
extern void log_message(const char *);
extern string err_message[];
extern ostream log_file;

bool some_function(){
    bool status = true;

    catch(int errno){
        log_message( err_message[errno] );
        status = false;
    }
    catch(const char *str){
        log_message( str );
        status = false;
    }
    catch(iterator_overflow &iof){
        iof.what_happened(log_file);
        status = false;
    }
    catch( ... ){ // 捕获任何异常
        log_message( "exception of unknown type" ); 
        status = false;
    }

    return status;
}

int main(){

}