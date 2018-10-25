#include <iostream>
#include <climits>
#include <cmath>
using namespace std ;
unsigned long long  expo[1000000] , sum[1000000] ;
int oksum ( unsigned long long  x , unsigned long long  y )
{
    if ( ULLONG_MAX  - y <= x ) return -1 ;
    else return 1 ;
}

int okprod ( unsigned long long  x , unsigned long long  y )
{
    if ( x == 0 || y == 0 ) return 1 ;
    else
    {
        if ( ULLONG_MAX  / y <= x ) return -1 ;
        else return 1 ;
    }
}

unsigned long long okpow (  unsigned long long b , unsigned long long  p )
{
    unsigned long long rez = 1 ;
    if ( b == 0 ) return 0 ;
    while( p != 0 )
    {
        if( p%2 == 0 )
        {
            if ( okprod ( b , b ) != -1 )
            {
                b = b * b ;
                p/=2;
            }
            else return -1 ;
        }
        else
        {
            if ( okprod ( rez , b ) != - 1 )
            {
                rez = rez * b ;
                p--;
            }
            else return -1 ;
        }
    }
    return rez ;
}

int main()
{
    unsigned long long b , p ;
    unsigned long long nr , n ;
    cin >> n ;
    for ( unsigned long long i = 1 ; i <= n ; i++ )
    {
        cin >> nr ;
        for ( unsigned long long  j = 1 ; j <= nr ; j++ )
        {
            cin >> b >> p ;
            unsigned long long powe = okpow( b , p ) ;
            if ( powe != -1  && oksum( powe , sum[i] ) == 1 )
                sum[i] += powe ;
            else
            {
                expo[i] = 1 ;
                break ;
            }
        }
    }
    for ( unsigned long long  i = 1 ; i <= n ; i++ )
    {
        if ( expo[i] == 1 ) cout << "Overflow!" ;
        else cout << sum[i] ;
        cout << '\n' ;
    }
    return 0 ;
}
