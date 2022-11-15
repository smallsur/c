#define main_cpp
#ifdef main_cpp

#include <iostream>
#include <stdio.h>
// using namespace std;



const int add(const int x, const int y){
    return x + y;
}


int main(){
    
    int num4test = -1;
    printf("%d\n", num4test);
    int* ptr2num;
    ptr2num = &num4test;
    printf("%d\n", ptr2num);
    int z = add(10,23);
    std::cout << z << std::endl;

    // s is a pointer to const char,
    const char* s = "zhangawen";
    printf("%s\n", s);

    const char* array2string[] = {"string one", "string two", "string three"};
    printf("array2string[0] = %s\n", array2string[0]);
    printf("%c", array2string[0][1]);

    // for (int i=0; i<size_t(array2string); i++){
    //     printf("%s\n", array2string[i]);
    // }



    return 0;
}

#endif // main_cpp

