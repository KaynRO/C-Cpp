#include <fstream>
#include <cstring>

using namespace std ;

ifstream fin ( "codul.in" ) ;
ofstream fout ( "codul.out" ) ;

char A[300] , B[300] ;
int n , m , BB[300][300] , sir[300] , pos ;

void read()
{
    fin >> ( A + 1 ) ;
    fin >> ( B + 1 ) ;
    n = strlen( A + 1 ) ;
    m = strlen( B + 1 ) ;
}

void LCS ()
{
    int i , j ;
    for ( i = 1 ; i <= n ; i++ )
        for ( j = 1 ; j <= m ; j++ )
        {
            if ( A[i] - '0' == B[j] - '0' )
                BB[i][j] = 1 + BB[ i - 1 ][ j - 1 ] ;
            else
            {
                if ( BB[ i - 1 ][j] == BB[i][ j - 1 ] )
                {
                    if (A[ i - 1 ] - '0' > B[ j - 1 ] - '0' )
                        BB[i][j] = BB[ i - 1 ][j] ;
                    else BB[i][j] = BB[i][ j - 1 ] ;
                }
                else
                    BB[i][j] = max ( BB[ i - 1 ][j] , BB[i][ j - 1 ]) ;

            }
            for ( i = n , j = m ; i > 0 ; )
            {
                if ( A[i] - '0' == B[j] - '0' )
                {
                    sir[++pos] = A[i] - '0' ;
                    --i ;
                    --j ;
                }
                else
                {
                    if ( BB[ i - 1 ][j] == BB[i][ j - 1 ] )
                    {
                        if ( A[ i - 1 ] - '0' > B[ j - 1 ] - '0' )
                            i-- ;
                        else j-- ;
                    }
                    else
                    {
                        if( BB[ i - 1 ][j] < BB[i][ j - 1 ] )
                            j-- ;
                        else i-- ;
                    }
                }
            }
        }
}


int main()
{
    read() ;
    LCS() ;
    for ( int i = pos ; i >= 1 ; i-- )
        fout << sir[i] ;
    return 0 ;
}
