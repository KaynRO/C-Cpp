#include <cstdio>
#define M 5005

using namespace std ;

int main()
{
    int n , k , i , j , J , s , maxim , a[2][M] , b[2][M] ;
    FILE *f1 , *f2 ;
    f1 = fopen ( "joc13.in" , "r" ) ;
    fscanf( f1 , "%d %d" , &n , &k ) ;
    for ( i = 0 ; i < 2 ; i++ )
        for ( j = 0 ; j < n ; j++ )
            fscanf( f1 , "%d" , &a[i][j] ) ;
    fclose(f1) ;
    b[0][0] = a[0][0] ;
    b[1][0] = 0 ;
    for ( i = 1 ; i < n ; i++ )
        for( j = 0 ; j < 2 ; j++ )
        {
            maxim = -11111 ;
            s = a[j][i] ;
            for( J = 1 ; J < k && J <= i ; J++ )
            {
                s += a[j][i-J] ;
                if( s + b[1-j][i-J] > maxim ) maxim = s + b[1-j][i-J] ;
            }
            b[j][i] = maxim ;
        }
    f2 = fopen( "joc13.out" , "wt" ) ;
    if( b[0][n-1] + a[1][n-1] > b[1][n-1] )
        b[1][n-1] = b[0][n-1] + a[1][n-1] ;
    fprintf( f2 , "%d\n" , b[1][n-1] ) ;
    fclose(f2) ;
    return 0;
}
