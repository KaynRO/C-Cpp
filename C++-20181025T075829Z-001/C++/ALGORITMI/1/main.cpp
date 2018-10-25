#include <bits/stdc++.h>

using namespace std ;

ifstream fin ( "bac.in" ) ;

int main()
{
    int x, A[1010], B[1010], C[2020], elemA = 0, elemB = 0, pos1 = 1, pos2 = 1, n, m, st = 0 ;

    fin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        fin >> x ;
        if ( x % 2 == 0 ) A[++elemA] = x ;
    }
    for ( int i = 1 ; i <= m ; i++ )
    {
        fin >> x ;
        if ( x % 2 == 0 ) B[++elemB] = x ;
    }
    while ( pos1 <= elemA && pos2 <= elemB )
    {
        while ( A[pos1] > B[pos2] && pos1 <= elemA && pos2 <= elemB )
            C[++st] = B[pos2], pos2++ ;
        while ( A[pos1] < B[pos2] && pos1 <= elemA && pos2 <= elemB )
            C[++st] = A[pos1], pos1++ ;
        while ( A[pos1] == B[pos2] && pos1 <= elemA && pos2 <= elemB )
            C[++st] = A[pos1], pos1++, pos2++ ;
    }
    while ( pos1 <= elemA )
        C[++st] = A[pos1], pos1++ ;
    while ( pos2 <= elemB )
        C[++st] = B[pos2], pos2++ ;
    for ( int i = st ; i >= 1 ; i-- )
        cout << C[i] << ' ' ;
    return 0 ;
}
