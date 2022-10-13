#include <iostream>
using namespace std;



int add(const int x, const int y){
    return x + y;
}


int main(){

    int z = add(10,23);
    cout << z << endl;
    return 0;
}