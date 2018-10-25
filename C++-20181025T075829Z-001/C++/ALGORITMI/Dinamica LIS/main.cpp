#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ( "sclm.in" ) ;
ofstream fout ( "sclm.out" ) ;

int n , v[1200] , dp[1200] , last[1200] ;

int main()
{
    int max , urm ;
    fin >> n ;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> v[i] ;
    dp[n] = 1 ;
    last[n] = 0 ;
    for ( int i = n - 1 ; i >= 1 ; i-- )
    {
         max = -1 ;
         urm = 0 ;
        for ( int j = i + 1 ; j <= n ; j++ )
        {
            if ( dp[j] > max && v[i] <= v[j] )
            {
                max = dp[j] ;
                urm = j ;
            }
        }
        dp[i] = max + 1 ;
        last[i] = urm ;
    }
    max = -1 ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( dp[i] > max )
        {
            max = dp[i] ;
            urm = i ;
        }
    fout << max + 1 << '\n' ;
    while ( urm != 0 )
    {
        fout << v[urm] << ' ' ;
        urm = last[urm] ;
    }

    return 0;
}
