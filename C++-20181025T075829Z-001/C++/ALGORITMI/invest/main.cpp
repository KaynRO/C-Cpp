#include <fstream>
#include <limits>
#include <iomanip>
#define N 120

using namespace std ;

ifstream fin ( "invest.in" ) ;
ofstream fout ( "invest.out" ) ;

double TB[N] , SB[N] , TT[N] , ST[N] , castig[N] ;
int n ;

void read()
{
    fin >> n ;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> TB[i] ;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> SB[i] ;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> TT[i] ;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> ST[i] ;

}

void solve()
{
    double nr1 = 0 , nr2 = 0 , nr3 = 0  , maxim ;
    castig[0] = 100 ;

    for ( int i = 1 ; i <= n ; i++ )
    {
        nr1 = ( castig[i-1] - TB[i] ) * SB[i] ;

        if ( i >= 6 )
            nr2 = ( castig[i-6] - TT[i-5] ) * ST[i-5] ;

        nr3 = castig[i-1] ;

        maxim = max ( nr1, max ( nr2 , nr3 ) ) ;

        castig[i] = maxim ;
    }

    fout << fixed << setprecision(4) << castig[n] ;
}

int main()
{
    read() ;
    solve() ;
    return 0;
}
