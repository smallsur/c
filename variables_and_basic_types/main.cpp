#include <iostream>
#include <string>
#include "extern_type.h"
using namespace std;

void print_sizeof_type(){
    int q = 19;
    char w = 'a';
    wchar_t e = 'f';
    char16_t f = 'a';
    char32_t g = 'a';
    short h = 12;
    long i = 0;
    long long j = 0;
    float k = 0.;
    double d = 0.;
    long double l = 0.;

    cout << "size of q :" << sizeof(q) <<endl;
    cout << "size of w :" << sizeof(w) <<endl;
    cout << "size of e :" << sizeof(e) <<endl;
    cout << "size of f :" << sizeof(f) <<endl;
    cout << "size of g :" << sizeof(g) <<endl;
    cout << "size of h :" << sizeof(h) <<endl;
    cout << "size of i :" << sizeof(i) <<endl;
    cout << "size of j :" << sizeof(j) <<endl;
    cout << "size of k :" << sizeof(k) <<endl;
    cout << "size of d :" << sizeof(d) <<endl;
    cout << "size of l :" << sizeof(l) <<endl;
}

void define_type(){

    int i = 0;
    int j{0};
    int k = {0};
    int q(0);

    long double l = 3.14125;
//    int a{l}, b = {l}; not permit

    int c(l), d = l;
}
//int ex_value = 10;
void const_type(){
    const int i = 10;
//    int &j = i;
}
constexpr int compute_(int n){
    if(n==1 || n==0){
        return 1;
    }
    return compute_(n-1)+ compute_(n-2);
}

void get_(){
    string world;
    while(cin>>world){
        cout<<world<<endl;
    }
}
void getLine_(){
    string world;
    while(getline(cin,world)){
        cout<<world<<endl;
    }
}
void print_(const int *p, const int *q){
    while(p!=q){
        cout<<*p<<endl;
        p++;
    }
}
void print__(initializer_list<string> s){
//    for (auto k: s) {
//        cout<<k<<endl;
//    }
    for (auto begin = s.begin();  begin!=s.end() ; begin++) {
        cout<<*begin<<endl;
    }
}

int main(){

    print__({"qwe","wqewe","qwef","werwe"});
    return 0;
}