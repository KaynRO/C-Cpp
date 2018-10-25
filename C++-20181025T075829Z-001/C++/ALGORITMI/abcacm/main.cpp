#include <fstream>
#include <cstring>
#define MOD 9907
#define NMAX 5
using namespace std;

ifstream fin ( "abcacm.in" ) ;
ofstream fout ( "abcacm.out" ) ;

int M[NMAX][NMAX], putere, Matrix[NMAX][NMAX], nrT, A, B, C ;
long long int power ;

void inmulteste ( int A[NMAX][NMAX], int B[NMAX][NMAX], int C[NMAX][NMAX] )
{
    int i, j, k ;
    for ( i = 1 ; i <= 3 ; i++ )
        for ( j = 1 ; j <= 3 ; j++ )
            for ( k = 1 ; k <= 3 ; k++ )
                C[i][j] = ( C[i][j] + 1LL * A[i][k] * B[k][j] ) % MOD ;
}

void ridica ( long long int putere )
{
    int C[NMAX][NMAX], AUX[NMAX][NMAX] ;
    long long int i ;
    memcpy ( C, Matrix, sizeof(Matrix) ) ;
    for ( i = 0 ; ( 1 << i ) <= putere ; ++i )
    {
        if ( putere & ( 1 << i ) )
        {
            memset ( AUX, 0, sizeof(AUX) ) ;
            inmulteste ( M, C, AUX ) ;
            memcpy ( M, AUX, sizeof(AUX) ) ;
        }
        memset ( AUX, 0, sizeof(AUX) ) ;
        inmulteste ( C, C, AUX ) ;
        memcpy ( C, AUX, sizeof(AUX) ) ;
    }
    memcpy ( M, AUX, sizeof(AUX) ) ;
}

void print()
{
    for ( int i = 1 ; i <= 3 ; i++ )
    {
        for ( int j = 1 ; j <= 3 ; j++ )
            fout << M[i][j] << ' ' ;
        fout << endl ;
    }
    //fout << M[3][2] << '\n' ;
}

int main()
{
    fin >> nrT ;
    for ( int i = 1 ; i <= nrT ; i++ )
    {
        fin >> A >> B >> C >> power ;
        power -= 2 ;
        Matrix[1][1] = 0, Matrix[1][2] = A, Matrix[1][3] = 0, Matrix[2][1] = 1, Matrix[2][2] = B, Matrix[2][3] = 0,
                                         Matrix[3][1] = 0, Matrix[3][2] = C, Matrix[3][3] = 1 ;

        //if ( power == 1 ) fout << C << '\n' ;
        //else
        {
            ridica(power) ;
            print() ;
        }
    }
    return 0;
}
