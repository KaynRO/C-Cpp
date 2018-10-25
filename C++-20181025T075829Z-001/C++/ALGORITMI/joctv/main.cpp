#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#define NMAX 106
#define INF ( 1 << 30 )

using namespace std ;

ifstream fin ( "joctv.in" ) ;
ofstream fout ( "joctv.out" ) ;

int N , M[NMAX][NMAX] , sum[NMAX] , maximum = -1 , best[NMAX] , bestsum ;

int main()
{
    fin >> N ;
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= N ; j++ )
            fin >> M[i][j] ;
    for ( int i1 = 1 ; i1 <= N ; i1++ )
        for ( int i2 = i1  ; i2 <= N ; i2++ )
        {
            memset ( sum , 0 , sizeof(sum) ) ;
            int colomn = 1 ;
            while ( colomn != N + 1 )
            {
                for ( int ln = i1 ; ln <= i2 ; ln++ )
                    sum[colomn] += M[ln][colomn] ;
                colomn++ ;
            }
            bestsum = sum[1] ;
            memset ( best , 0 , sizeof(best) ) ;
            for ( int cn = 1 ; cn <= colomn ; cn++ )
            {
                best[cn] = max ( best[cn-1] + sum[cn] , sum[cn] ) ;
                if ( bestsum < best[cn] )
                    bestsum = best[cn] ;
            }
            if ( bestsum > maximum )
                maximum = bestsum ;
        }
    fout << maximum ;
    return 0 ;
}
