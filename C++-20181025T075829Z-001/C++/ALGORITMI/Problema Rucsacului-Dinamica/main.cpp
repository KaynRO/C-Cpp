#include <fstream>
#define NMAX 5001

using namespace std ;

ifstream fin("rucsac.in") ;
ofstream fout("rucsac.out") ;

int n , G ;
int g[ 2 * NMAX ] , c[ 2 * NMAX ] , dp[ 2 * NMAX ] ;

int main()
{
    fin >> n >> G ;
    for( int i = 1; i <= n; ++i )
    {
        fin >> g[i] >> c[i] ;
    }
    for( int i = 1 ; i <= n ; i++ )
    {
        for( int j = G ; j >= g[i] ; j-- )
            dp[j] = max(dp[j],dp[j - g[i]] + c[i]) ;
    }
    fout << dp[G] << '\n' ;
    return 0;
}
