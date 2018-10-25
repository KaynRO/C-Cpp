#include <fstream>
#include <cstring>
#include <cstdio>
#include <string>
#define INF 999999999
#define NMAX 110

using namespace std ;

ifstream fin ( "edit.in" ) ;
ofstream fout ( "edit.out" ) ;

int c[10] , cmin[NMAX][NMAX] , opmin[NMAX][NMAX] , n , m ;
char s[NMAX] , d[NMAX] ;

void read()
{
    fin.getline( s , NMAX ) ;
    fin.getline( d , NMAX ) ;
    n = strlen(s) ;
    m = strlen(d) ;
    for ( int i = 1 ; i <= 6 ; i++ )
        fin >> c[i] ;
}

void solve()
{
    for ( int j = m - 1 ; j >= 0 ; j-- )
    {
        cmin[n][j] = ( m - j ) * c[2] ;
        opmin[n][j] = 2 ;
    }
    for ( int i = n - 1 ; i >= 0 ; i-- )
    {
        cmin[i][m] = ( n - i ) * c[3] ;
        opmin[i][m] = 3 ;
        if ( c[6] < cmin[i][m] )
        {
            cmin[i][m] = c[6] ;
            opmin[i][m] = 6 ;
        }
    }
    for ( int i = n - 1 ; i >= 0 ; i-- )
        for ( int j = m - 1 ; j >= 0 ; j-- )
        {
            cmin[i][j] = c[2] + cmin[i][ j + 1 ] ;
            opmin[i][j] = 2 ;
            if ( s[i] == d[j] && c[1] + cmin[ i + 1 ][ j + 1 ] < cmin[i][j] )
            {
                cmin[i][j] = c[1] + cmin[ i + 1 ][ j + 1 ] ;
                opmin[i][j] = 1 ;
            }
            if ( cmin[i][j] > c[3] + cmin[ i + 1 ][j] )
            {
                cmin[i][j] = c[3] + cmin[ i + 1 ][j] ;
                opmin[i][j] = 3 ;
            }
            if ( cmin[i][j] > c[4] + cmin[ i + 1 ][ j + 1 ] )
            {
                cmin[i][j] = c[4] + cmin[ i + 1 ][ j + 1] ;
                opmin[i][j] = 4 ;
            }
            if ( s[i] == d[ j + 1 ] && s[ i + 1 ] == d[j] && cmin[i][j] > c[5] + cmin[ i + 2 ][ j + 2 ] )
            {
                cmin[i][j] = c[5] + cmin[ i + 2 ][ j + 2 ] ;
                opmin[i][j] = 5 ;
            }
            if ( cmin[i][j] > c[6] + cmin[n][j] )
            {
                cmin[i][j] = c[6] + cmin[n][j] ;
                opmin[i][j] = 6 ;
            }
        }
}

int main()
{
    read() ;
    solve() ;
    fout << cmin[0][0] ;
    return 0;
}
