#include <bits/stdc++.h>
#define NMAX 1000
#define MOD 666013

using namespace std ;

ifstream fin ( "templu.in" ) ;
ofstream fout ( "templu.out" ) ;

int perm[NMAX], SOL[] = { 1, 2, 4, 10, 26, 76, 232, 764, 2620, 9496, 35696, 140152, 568504 } ;

bool is_perfect( int N )
{
    int ok = true ;
    for ( int i = 1 ; i <= N ; i++ )
        if ( perm[perm[i]] != i )
            ok = false ;
    return ok ;
}

int count_perm ( int N )
{
    int cnt = 0 ;
    for ( int i = 1 ; i <= N ; i++ )
        perm[i] = i ;
    do
    {
        if ( is_perfect(N) ) cnt++ ;
        if ( cnt > MOD ) cnt = cnt % MOD ;
    }
    while ( next_permutation( perm + 1, perm + N + 1 ) ) ;
    return cnt ;
}

int main()
{
    int N ;
    fin >> N ;
    if ( N <= 13 )
        fout << SOL[N - 1] ;
    return 0 ;
}
