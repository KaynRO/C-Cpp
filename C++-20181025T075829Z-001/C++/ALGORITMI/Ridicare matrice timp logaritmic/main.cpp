#include <fstream>
#include <cstring>
#define MOD 1003
#define NMAX 200
using namespace std;

ifstream fin ( "exp.in" ) ;
ofstream fout ( "exp.out" ) ;

int n , M[NMAX][NMAX] , putere , Matrix[NMAX][NMAX] ;

void inmulteste ( int A[NMAX][NMAX] , int B[NMAX][NMAX] , int C[NMAX][NMAX] , int lenght )
{
    int i , j , k ;
    for ( i = 0 ; i < lenght ; i++ )
        for ( j = 0 ; j < lenght ; j++ )
            for ( k = 0 ; k < lenght ; k++ )
                C[i][j] = ( C[i][j] + 1LL * A[i][k] * B[k][j] ) % MOD ;
}

void ridica ( int putere , int lenght )
{
    int C[NMAX][NMAX] , AUX[NMAX][NMAX] , i ;
    memcpy ( C , Matrix , sizeof(Matrix) ) ;
    for ( i = 0 ; ( 1 << i ) <= putere ; ++i )
    {
        if ( putere & ( 1 << i ) )
        {
            memset ( AUX , 0 , sizeof(AUX) ) ;
            inmulteste ( M , C , AUX , lenght ) ;
            memcpy ( M , AUX , sizeof(AUX) ) ;
        }
        memset ( AUX , 0 , sizeof(AUX) ) ;
        inmulteste ( C , C , AUX , lenght ) ;
        memcpy ( C , AUX , sizeof(AUX) ) ;
    }
    memcpy ( M , AUX , sizeof(AUX) ) ;
}

void print()
{
    for ( int i = 0 ; i < n ; i++ )
    {
        for ( int j = 0 ; j < n ; j++ )
            fout << M[i][j] << ' ' ;
        fout << '\n' ;
    }
}

int main()
{
    fin >> n >> putere ;
    putere-- ;
    for ( int i = 0 ; i < n ; i++ )
        for ( int j = 0 ; j < n ; j++ )
            fin >> Matrix[i][j] ;
    ridica ( putere , n ) ;
    print() ;
    return 0;
}
