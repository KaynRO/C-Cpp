#include <iostream>

using namespace std ;

int n , v[1200] ;

int crescator ( int i )
{
    if ( i == 1 ) return 1 ;
    if ( v[i] >= v[i-1] ) return crescator ( i - 1 ) ;
    else return 0 ;
}

int main()
{
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ )
        cin >> v[i] ;
    if ( crescator ( n ) == 1 )
        cout << "DA" ;
    else cout << "NU" ;
    return 0 ;
}
