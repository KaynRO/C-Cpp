#include <fstream>
#include <bits/stdc++.h>
#define NMAX 10009

using namespace std ;

ofstream fout ( "nim.out" ) ;

int xr, T, value, nr ;

void read()
{
    freopen ( "nim.in", "r", stdin ) ;
    scanf ( "%d", &T ) ;
    for ( int i = 1 ; i <= T ; i++ )
    {
        scanf ( "%d", &nr ) ;
        xr = 0 ;
        for ( int j = 1 ; j <= nr ; j++ )
        {
            scanf ( "%d", &value ) ;
            xr = xr ^ value ;
        }
        if ( xr != 0 )
            fout << "DA" << '\n' ;
        else
            fout << "NU" << '\n' ;
    }
}

int main()
{
    read() ;
    return 0;
}
