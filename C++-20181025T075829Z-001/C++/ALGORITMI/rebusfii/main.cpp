#include <iostream>

using namespace std ;

int main()
{
    char nr[2000], c ;
    int answer = 0 ;
    cin.getline(nr , 2000 ) ;
    for ( int i = 0 ; i <= 2000 && nr[i] >= '0' && nr[i] <= '9' ; i++ )
    {
        c = nr[i] ;
        if ( c == '6' || c == '9' || c == '0' )
            answer++ ;
        if ( c == '8' )
            answer += 2 ;
    }
    cout << answer ;
    return 0 ;
}
