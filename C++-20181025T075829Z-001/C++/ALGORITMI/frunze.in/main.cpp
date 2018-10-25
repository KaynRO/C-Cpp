#include <fstream>
#include <vector>

using namespace std;

ifstream fin ( "frunze.in" ) ;
ofstream fout ( "frunze.out" ) ;

int n , father[200] , nrf , f[200] , ok[200] ;

int main()
{
    fin >> n ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        fin >> father[i] ;
        if ( father[i] == 0 )
            fout << i << '\n' ;
    }
    for ( int i = 1 ; i <= n ; i++ )
        ok[father[i]] = 1 ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( ok[i] == 0 )
        {
            nrf++ ;
            f[nrf] = i ;
        }
    fout << nrf << '\n' ;
    for ( int i = 1 ; i <= nrf  ; i++ )
        fout << f[i] << ' ' ;
    return 0;
}
