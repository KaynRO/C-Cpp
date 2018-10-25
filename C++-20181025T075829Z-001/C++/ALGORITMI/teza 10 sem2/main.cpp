#include <iostream>

using namespace std;

int n ;
int a[200] ;

int verifica ( int i )
{
    if ( i == n )
        return 1 ;
    if ( a[i] != a[i+1] )
        verifica ( i +1 ) ;
    else return 0 ;
}



int main()
{
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ )
        cin >> a[i] ;
    if ( verifica(1) == 1 )
        cout << "Toate sunt diferite" ;
    else cout << "Nu sunt toate diferite" ;
    return 0;
}
