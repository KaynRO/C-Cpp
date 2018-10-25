#include <cstdio>

#define NMAX 101
#define KMAX 103
#define MOD 30011

using namespace std ;

unsigned N, K, arb[NMAX][NMAX],
         rad, p[NMAX];

void readinput()
{
    unsigned a, b;

    freopen( "iepuri2.in", "rt", stdin );
    scanf( "%u%u", &N, &K );

    for( int i = 0; i < N - 1; i++ )
    {
        scanf( "%u%u", &a, &b );
        arb[a][ ++arb[a][0] ] = b;
        p[b]=a;
    }
    for( int i = 1; i <= N; i++ )
        if( !p[i] ) rad = i;
}

unsigned m[NMAX][KMAX];

void go( unsigned rad )
{
    for( int i = 1; i <= arb[rad][0]; i++ )
        go( arb[rad][i] );

    for( int k = K; k >= 1; k-- )
    {
        m[rad][k] = 1;
        for( int i = 1; i <= arb[rad][0]; i++ )
        {
            m[ arb[rad][i] ][ k + 1 ] += m[ arb[rad][i] ][ k + 2 ];
            m[ arb[rad][i] ][ k + 1 ] %= MOD;

            long temp = m[rad][k];
            temp *= m[ arb[rad][i] ][ k + 1 ];
            m[rad][k] = temp % MOD;
        }
    }
}

void writeoutput()
{
    unsigned sum = 0;

    for( int i = 1; i <= K; i++ )
    {
        sum += m[rad][i];
        sum %= MOD;
    }

    freopen( "iepuri2.out", "wt", stdout );
    printf( "%u\n", sum );
}

int main()
{
    readinput();
    go( rad );
    writeoutput();
    return 0;
}
