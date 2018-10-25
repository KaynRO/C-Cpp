#include <fstream>
#include <algorithm>

using namespace std ;
ifstream fin ( "submatrix.in" ) ;
ofstream fout ( "submatrix.out" ) ;
int n , matrix[1200][1200] , dp[1200][1200] ;

int main()
{
    fin >> n ;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= n ; j++ )
            fin >> matrix[i][j] ;
    for ( int i = 1 ; i <= n ; i++ )
        dp[1][i] = matrix[1][i] ;
    for ( int i = 1 ; i <= n ; i++ )
        dp[i][1] = matrix[i][1] ;
    for ( int i = 2 ; i <= n ; i++ )
        for ( int j = 2 ; j <= n ; j++ )
            if ( matrix[i][j] == 1 )
                dp[i][j] = min ( min ( dp[i-1][j-1] , dp[i][j-1] ) , dp[i-1][j] ) + 1 ;
    int maxim = -1 ;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= n ; j++ )
            if ( dp[i][j] > maxim )
                maxim = dp[i][j] ;
    fout << maxim ;
    return 0 ;
}
