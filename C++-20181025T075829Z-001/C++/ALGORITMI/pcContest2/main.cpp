#include <iostream>
#include <vector>
#include <utility>
#define NMAX 110

using namespace std ;

int N, M, A[NMAX][NMAX], B[NMAX][NMAX] ;
vector < pair < int, int > > V ;

int checkLineF ( int line )
{
    for ( int j = 1 ; j <= M ; j++ )
        if ( A[line][j] == 1 || A[line][j] == -1 ) return 1 ;
    return 0 ;
}

int checkColomnF( int colomn )
{
    for ( int i = 1 ; i <= N ; i++ )
        if ( A[i][colomn] == 1 || A[i][colomn] == -1 ) return 1 ;
    return 0 ;
}

int checkLine( int line )
{
    for ( int j = 1 ; j <= M ; j++ )
        if ( A[line][j] == 1 ) return 1 ;
    return 0 ;
}

int checkColomn( int colomn )
{
    for ( int i = 1 ; i <= N ; i++ )
        if ( A[i][colomn] == 1 ) return 1 ;
    return 0 ;
}

int main()
{
    cin >> N >> M ;
    bool ok = true ;

    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= M ; j++ )
            A[i][j] = -1 ;

    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= M ; j++ )
        {
            cin >> B[i][j] ;
            if ( B[i][j] == 1 ) V.push_back( make_pair ( i, j ) ) ;
        }

    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= M ; j++ )
            if ( B[i][j] == 0 )
            {
                for ( int jj = 1 ; jj <= M ; jj++ )
                    A[i][jj] = 0 ;
                for ( int ii = 1 ; ii <= N ; ii++ )
                    A[ii][j] = 0 ;
            }

    while ( ok )
    {
        ok = false ;
        for ( vector < pair < int, int > > :: iterator it = V.begin() ; it != V.end() ; ++it )
        {
            if ( checkColomn(it->second) == 0 && checkLine(it->first) == 0 )
            {
                if ( checkColomnF(it->second) == 0 && checkLineF(it->first) == 0 && A[it->first][it->second] == 0 )
                {
                    cout << "NO" ;
                    return 0 ;
                }
                if ( A[it->first][it->second] == -1 ) A[it->first][it->second] = 1, ok = true ;
            }
            else if ( ( checkColomn(it->second) == 1 || checkLine(it->first) == 1 ) && A[it->first][it->second] == -1 )
                A[it->first][it->second] = 1, ok = true ;
        }
    }

    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= M ; j++ )
            if ( A[i][j] == -1 )
            {
                cout << "NO" ;
                return 0 ;
            }

    cout << "YES" << '\n' ;

    for ( int i = 1 ; i <= N ; i++ )
    {
        for ( int j = 1 ; j <= M ; j++ )
            cout << A[i][j] << ' ' ;
        cout << '\n' ;
    }

    return 0 ;
}
