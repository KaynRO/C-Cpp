#include <iostream>
#include <cstring>

using namespace std ;

int main()
{
    char s1[8] = "Andrei" ;
    char s2[30] = " are Mere " ;
    char s3[30] ;
    int k = 0 ;
    while ( cin >> s3 )
    {
        cout << s3 << ' ' << k ;
        k++ ;
    }
        return 0;
}
