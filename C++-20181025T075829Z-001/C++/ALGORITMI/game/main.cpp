#include <fstream>
#include <bits/stdc++.h>
#define NMAX 10009

using namespace std ;

ofstream fout ( "game.out" ) ;

int xr, value, nr ;

void read()
{
    freopen ( "game.in", "r", stdin ) ;
    for ( int i = 1 ; i <= 10 ; i++ )
    {
        scanf ( "%d", &nr ) ;
        xr = 0 ;
        for ( int j = 1 ; j <= nr ; j++ )
        {
            scanf ( "%d", &value ) ;
            xr = xr ^ ( value % 4 ) ;
        }
        if ( xr != 0 )
            fout << "1" << '\n' ;
        else
            fout << "0" << '\n' ;
    }
}

int main()
{
    read() ;
    return 0;
}
