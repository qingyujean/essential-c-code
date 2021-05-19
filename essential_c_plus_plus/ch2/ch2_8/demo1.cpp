#include<iostream>

using namespace std;

// 参考：https://www.cnblogs.com/Esfog/archive/2012/04/23/2467249.html

int fun(int a)
{
    cout<<"fun"<<endl;
    return 0;
}
 
int main(){
    cout<<fun<<endl;
    cout<<*fun<<endl;
    cout<<&fun<<endl;
    cout<<*****fun<<endl;

    int(*p0)(int)=fun;
    int(*p1)(int)=*fun;
    int(*p2)(int)=&fun;
    p0(1);
    p1(1);
    p2(1);

    int(*p)(int)=fun; // p是函数指针
    p(1);
    // (&p)(1);   
    (*p)(1);
    (****p)(1);
}