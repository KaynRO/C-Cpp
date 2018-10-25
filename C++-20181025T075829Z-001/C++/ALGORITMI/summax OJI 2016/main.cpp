#include <bits/stdc++.h>
#define NMAX 2010
#define INF 2000000000

using namespace std ;

ofstream fout ( "summax.out" ) ;

vector < pair < long int, long int  > > M[NMAX] ;

int test, N, st, dr ;

void build_path( int no )
{
    long int line = 1, colomn = 0 ;
    fout << colomn + 1 << ' ' ;
    while ( line != N )
    {
        int aux = colomn ;
        if ( M[line + 1][colomn].first == M[line + 1][colomn + 1].first  )
        {
            if ( no > M[line + 1][colomn].second )
            {
                no = no - M[line + 1][colomn].second ;
                colomn++ ;
            }
        }
        if ( M[line + 1][aux].first != M[line + 1][aux + 1].first )
        {
            int maxim = max ( M[line + 1][colomn].first, M[line + 1][colomn + 1].first ) ;
            if ( maxim == M[line + 1][colomn + 1].first )
                colomn++ ;
        }
        fout << colomn + 1 << ' ' ;
        line++ ;
    }
    fout << '\n' ;
}

void dynamic()
{
    for ( int i = N - 1 ; i >= 1 ; i-- )
        for ( int j = 0 ; j <= i - 1 ; j++ )
            if ( M[i + 1][j].first == M[i + 1][j + 1].first )
                M[i][j].first = M[i + 1][j].first + M[i][j].first, M[i][j].second = M[i + 1][j].second + M[i + 1][j + 1].second  < INF + 1 ? M[i + 1][j].second + M[i + 1][j + 1].second : INF + 1 ;
            else if ( M[i + 1][j].first > M[i + 1][j + 1].first )
                M[i][j].first = M[i + 1][j].first + M[i][j].first, M[i][j].second = M[i + 1][j].second ;
            else if ( M[i + 1][j].first < M[i + 1][j + 1].first )
                M[i][j].first = M[i + 1][j + 1].first + M[i][j].first, M[i][j].second = M[i + 1][j + 1].second ;
    if ( M[1][0].second > INF )
        M[1][0].second = INF + 1 ;
}

void solveI()
{
    dynamic() ;
    fout << M[1][0].second ;
}

void solveII()
{
    dynamic() ;
    for ( int i = st ; i <= dr ; i++ )
        build_path(i) ;
}

void read()
{
    int value ;
    freopen ( "summax.in", "r", stdin ) ;
    scanf ( "%d", &test ) ;
    scanf ( "%d %d %d", &N, &st, &dr ) ;
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= i ; j++ )
        {
            scanf ( "%d", &value ) ;
            if ( i != N )
                M[i].push_back( make_pair ( value, 0 ) ) ;
            else M[i].push_back( make_pair ( value, 1 ) ) ;
        }
    if ( test == 1 )
        solveI() ;
    else solveII() ;

}

int main()
{
    read() ;
    return 0;
}
