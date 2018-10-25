#include <iostream>
#include <cstring>
#define MOD 1000000007

using namespace std ;

unsigned long long int N, A[3][3], Ax[3][3] ;

void multiply ( unsigned long long int A[3][3] , unsigned long long int B[3][3] , unsigned long long int C[3][3] )
{
    C[1][1] = ( A[1][1] * B[1][1] ) % MOD + ( A[1][2] * B[2][1] ) % MOD ;
    C[1][2] = ( A[1][1] * B[1][2] ) % MOD + ( A[1][2] * B[2][2] ) % MOD ;
    C[1][1] %= MOD, C[1][2] %= MOD ;
    C[2][1] = C[1][2], C[2][2] = C[1][1] ;
}

void goUp ( unsigned long long power )
{
    unsigned long long int C[3][3], AUX[3][3] ;
    memcpy ( C, A, sizeof(A) ) ;
    memcpy ( Ax, A, sizeof(A) ) ;
    for ( int i = 0 ; ( 1 << i ) <= power ; ++i )
    {
        if ( ( power & ( 1 << i ) ) > 0 )
        {
            memset ( AUX, 0, sizeof(AUX) ) ;
            multiply ( Ax, C, AUX ) ;
            memcpy ( Ax, AUX, sizeof(AUX) ) ;
        }
        memset ( AUX, 0, sizeof(AUX) ) ;
        multiply ( C, C, AUX ) ;
        memcpy ( C, AUX, sizeof(C) ) ;
    }
}

int main()
{
    cin >> N ;
    A[1][1] = 3 ;
    A[1][2] = 1 ;
    A[2][1] = 1 ;
    A[2][2] = 3 ;
    goUp(N - 1) ;
    cout << Ax[1][1] % MOD ;
    return 0 ;
}
