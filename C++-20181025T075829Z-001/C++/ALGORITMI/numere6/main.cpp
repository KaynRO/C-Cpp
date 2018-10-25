#include <bits/stdc++.h>
#define NMAX 9100
#define MOD  9973

using namespace std ;

ifstream fin ( "numere6.in" ) ;
ofstream fout ( "numere6.out" ) ;

unsigned long long DP[5][NMAX] ;
int A, B ;

int prime ( int value )
{
    if ( value == 2 )
        return 1 ;
    if ( value == 1 )
        return 0 ;
    if ( value % 2 == 0 )
        return 0 ;
    for ( int i = 3 ; i * i <= value ; i += 2 )
        if ( value % i == 0 )
            return 0 ;
    return 1 ;
}

void special_cases()
{
    if ( A == 1 )
    {
        fout << "1" ;
        exit(0) ;
    }
    if ( B == 1 )
    {
        fout << "1" ;
        exit(0) ;
    }
    for ( int i = 11 ; i <= B ; i++ )
        if ( B % i == 0 && prime(i) )
            fout << "0", exit(0) ;
}


int main()
{
    fin >> A >> B ;
    int D[NMAX], div = 0 ;
    for ( int i = 1 ; i <= B ; i++ )
        if ( B % i == 0 )
            D[++div] = i ;
    for ( int i = 1 ; i <= div && D[i] <= 9 ; i++ )
        DP[1][D[i]] = 1 ;

    for ( int i = 2 ; i <= A ; i++ )
    {
        for ( int j = 1 ; j <= div ; j++ )
            DP[2][D[j]] = 0 ;
        for ( int j = 1 ; j <= div ; j++ )
        {
            DP[2][1] = 1 ;
            for ( int k = 1 ; k <= div && D[k] <= 9 ; k++ )
                if ( D[j] % D[k] == 0 )
                    DP[2][D[j]] = ( DP[2][D[j]] + DP[1][D[j]/D[k]] ) % MOD ;
        }
        for ( int i = 1 ; i <= div ; i++ )
            DP[1][D[i]] = DP[2][D[i]] ;
    }

    fout << DP[1][B] ;
    return 0 ;
}
