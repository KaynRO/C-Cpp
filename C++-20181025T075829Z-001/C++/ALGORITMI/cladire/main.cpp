#include <fstream>
#include <algorithm>
#define inf 9999
using namespace std ;

ifstream fin ( "cladire.in" ) ;
ofstream fout ( "cladire.out" ) ;

int n , m , dp[1200][1200] , matrix[1200][1200] ;

void bordare()
{
    for ( int i = 0 ; i <=n ; i++ )
        dp[i][0] = dp[i][m+1] = inf ;
    for ( int j = 0 ; j <= m ; j++ )
        dp[0][j] = dp[n+1][j] = inf ;
}

int main()
{
    int S ;
    fin >> n >> m >> S ;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= m ; j++ )
            fin >> matrix[i][j] ;
    bordare() ;
    dp[1][m] = matrix[1][m] ;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = m ; j > 0 ; j-- )
            if ( dp[i][j] != matrix[1][m] )
                dp[i][j] = min ( dp[i-1][j] , dp[i][j+1] ) + matrix[i][j] ;
    fout << S - dp[n][1] ;
    return 0 ;
}
