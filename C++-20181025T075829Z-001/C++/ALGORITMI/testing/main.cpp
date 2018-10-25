#include <iostream>

using namespace std ;

struct tmp
{
    char a ;
    short b ;
    int c ;
    long long d ;
};

int main()
{
    tmp str ;
    cout << sizeof(str) << '\n' ;
    cout << sizeof(str.a) + sizeof(str.b) + sizeof(str.c) + sizeof(str.d) ;
    int a = 1 , b = 2 , c = 3 , d = 4 ;
    int expr = (( a + b )) * (( c + d )) ;
    cout << expr ;
    return 0;
}
