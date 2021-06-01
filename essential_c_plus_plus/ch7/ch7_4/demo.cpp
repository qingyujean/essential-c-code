#include <memory>

using namespace std;

// 声明
extern Mutex m;

void f(){
    try{
        int *p = new int; // 请求资源
        m.acquire();

        process(p);
    }catch(){
        m.release(); // 释放资源
        delete p;
        throw;
    }
}

class MuTexLock{
public:
    MuTexLock(Mutex m): _lock(m) { _lock.accquire(); }
    ~MuTexLock() { _lock.release(); }
private:
    Mutex & _lock;
};


void f2(){

    // auto_ptr是标准库提供的class template，它会自动删除通过new表达式分配的对象
    auto_ptr<int> p(new int); // 初始化操作发生于constructor内，资源的请求也在constructor内完成
    MutexLock m1(m)

    process(p);

    // p和m1的destructor会在此处被悄悄调用
}

int main(){
    auto_ptr<string> aps(new string("vermeer"));
    string *ps = new string("vermeer");
    if( (aps->size() == ps->size()) && (*aps==*ps) )
        // ...
}