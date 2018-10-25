#include <fstream>
#include <algorithm>
#define inf 99999
using namespace std ;

ifstream fin ( "comori.in" ) ;
ofstream fout ( "comori.out" ) ;

int n , m , dp[1200][1200] , matrix[1200][1200] ;

void bordare()
{
    for ( int i = 0 ; i <= n ; i++ )
        dp[i][0] = dp[i][m+1] = inf ;
    for ( int j = 0 ; j <= m ; j++ )
        dp[0][j] = dp[n+1][j] = inf ;
}

int main()
{
    fin >> n >> m ;
    int minim = inf ;
    bordare() ;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= m ; j++ )
            fin >> matrix[i][j] ;
    for ( int i = 1 ; i <= n ; i++ )
        dp[i][m] = matrix[i][m] ;
    for ( int j = m - 1  ; j > 0 ; j-- )
        for ( int i = 1 ; i <= n ; i++ )
            dp[i][j] = min ( min ( dp[i][j+1] , dp[i+1][j+1] ) , dp[i-1][j+1] ) + matrix[i][j] ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( dp[i][1] < minim  )
            minim = dp[i][1] ;
    fout << minim ;
    return 0 ;
}
