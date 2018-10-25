#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std ;

ifstream fin ("sumtri1.in" ) ;
ofstream fout ( "sumtri1.out" ) ;

int n , matrix[120][120] , dp[120][120] , beg , way[150] ;

int find_path ( int ln , int cn )
{
    way[++beg] = matrix[ln][cn] ;
    if ( ln == 1 && cn == 1 ) return 0 ;
    if ( dp[ln-1][cn-1] == 0 )
        find_path ( ln - 1 , cn ) ;
    else
    {
        if ( dp[ln-1][cn] == 0 )
            find_path ( ln - 1 , cn - 1 ) ;
        else if  ( dp[ln-1][cn-1] < dp[ln-1][cn] )
            find_path( ln - 1 , cn - 1 ) ;
        else find_path ( ln - 1 , cn ) ;
    }
}

int main()
{
    fin >> n ;
    int minim = 0x3f3f3f3 ;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= i ; j++ )
            fin >> matrix[i][j] ;
    dp[1][1] = matrix[1][1] ;
    for ( int i = 2 ; i <= n ; i++ )
        for ( int j = 1 ; j <= i ; j++ )
        {
            if ( dp[i-1][j-1] == 0 )
                dp[i][j] = dp[i-1][j] ;
            else if ( dp[i-1][j] == 0 )
                dp[i][j] = dp[i-1][j-1] ;
            else dp[i][j] = min ( dp[i-1][j-1] , dp[i-1][j] ) ;
            dp[i][j] += matrix[i][j] ;
        }
    int ok ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( dp[n][i] < minim )
        {
            minim = dp[n][i] ;
            ok = i ;
        }
    find_path ( n , ok ) ;
    fout << minim << '\n' ;
    for ( int i = beg ; i > 0 ; i-- )
        fout << way[i] << ' ' ;
    return 0 ;
}
