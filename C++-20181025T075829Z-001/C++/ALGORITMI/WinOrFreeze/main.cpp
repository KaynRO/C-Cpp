#include <bits/stdc++.h>
#define NMAX 3500000

using namespace std ;

long long int q, first = -1, second = -1 ;
int divs ;


int main()
{
    cin >> q ;

    for ( long long int i = 2 ; i <= NMAX ; i++ )
    {
        while ( q % i == 0 && q >= 2 )
        {
            q /= i ;
            divs++ ;
            if ( first == -1 )
                first = i ;
            else if ( second == -1 )
                second = i ;
        }
    }

    if ( q > 1 )
        second = q, divs++ ;

    if ( divs <= 1 )
        cout << "1" << '\n' << "0" ;
    else if ( divs > 2 )
        cout << "1" << '\n' << first * second ;
    else
        cout << "2" ;
    return 0 ;
}
