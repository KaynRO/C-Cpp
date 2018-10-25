#include <bits/stdc++.h>
#define NMAX 20010
#define INF ( 1 << 29 )

using namespace std ;

ifstream fin ("problema.in") ;
ofstream fout ("problema.out") ;

int N, M[4][NMAX], DP[4][NMAX] ; // DP[i][j] = numarul minim de schimbari, din 0 in 1, pentru a ajunge pe linia i , coloana j

int main()
{
    int val1, val2 ;
    char line1[NMAX], line2[NMAX] ;

    fin >> N, fin.get() ;
    fin.getline(line1, N + 2) ;
    fin.getline(line2, N + 2) ;

    for ( int j = 1 ; j <= N && line1[j - 1] >= '0' && line1[j - 1] <= '1' ; j++ )
        M[1][j] = line1[j - 1] - '0' ;
    for ( int j = 1 ; j <= N && line2[j - 1] >= '0' && line2[j - 1] <= '1' ; j++ )
        M[2][j] = line2[j - 1] - '0' ;

    for ( int i = 1 ; i <= 2 ; i++ )
        for ( int j = 1 ; j <= N ; j++ )
            DP[i][j] = INF ;

    if ( M[1][1] == 1 ) DP[1][1] = 0 ; // initializam prima coloana
    else DP[1][1] = 1 ;

    if ( M[2][1] == 1 ) DP[2][1] = 0 ;
    else DP[2][1] = 1 ;


    int line = 1, colomn = 2 ; // pornim cu linia 1 , coloana 2
    while ( colomn != N + 1 )
    {

        val1 = DP[line][colomn - 1] ; // putem veni ori din stanga
        val2 = DP[3 - line][colomn - 1] + 1 - M[3 - line][colomn] ; // sau de jos/sus

        DP[line][colomn] =  min ( val1, val2 ) ; // vedem minimul

        if ( M[line][colomn] == 0 )
            DP[line][colomn]++ ; // daca pe pozitia curenta este 0 incrementam nr de schimbari

        line = 3 - line ; // mergem si pe linia a 2
        if ( line == 1 ) colomn++ ; // dupa ce am terminat ambele linii mergem pe coloana urmatoare

    }

    fout << min ( DP[1][N], DP[2][N] ) << endl ; // vedem minimul de pe coloana N

    return 0 ;
}
