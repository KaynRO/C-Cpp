#include <fstream>
#include <cstring>
#include <cstdio>
#define NMAX 1100

using namespace std ;

ofstream fout ( "matperm2.out" ) ;

struct element
{
    int line ;
    int colomn ;
    int value ;
} X[NMAX][NMAX] ;

int N , M , P , orderLine[NMAX] , orderColomn[NMAX] , Y[NMAX][NMAX] , Q , QQ[NMAX][6] ;

void print()
{
    for ( int i = 1 ; i <= N ; i++ )
    {
        for ( int j = 1 ; j <= M ; j++ )
            fout << X[i][j].value << ' ' ;
        fout << '\n' ;
    }
}

void initialise()
{
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= M ; j++ )
        {
            X[i][j].value = ( i - 1 ) * M + j ;
            X[i][j].line = i ;
            X[i][j].colomn = j ;
            Y[i][j] = X[i][j].value ;
        }
}

void changeColomn ( int current , int to )
{
    for ( int i = 1 ; i <= N ; i++ )
        X[i][to].colomn = current ;
}

void changeLine( int current , int to )
{
    for ( int i = 1 ; i <= M ; i++ )
        X[to][i].line = current ;
}

void updateColomns()
{
    for ( int i = 1 ; i <= M ; i++ )
        if ( orderColomn[i] != i )
            changeColomn( orderColomn[i] , i ) ;
}

void updateLines()
{
    for ( int i = 1 ; i <= N ; i++ )
        if ( orderLine[i] != i )
            changeLine( orderLine[i] , i ) ;
}

void update()
{
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= M ; j++ )
            X[i][j].value = Y[X[i][j].line][X[i][j].colomn] ;
    for ( int i = 1 ; i <= Q ; i++ )
    {
        int a1 = QQ[i][1] ;
        int a2 = QQ[i][2] ;
        int b1 = QQ[i][3] ;
        int b2 = QQ[i][4] ;
        swap ( X[a1][a2].value , X[b1][b2].value ) ;
    }
}

void read()
{
    int x0 , y0 , x1 , y1 ;
    freopen ( "matperm2.in" , "r" , stdin ) ;
    scanf ( "%d %d %d" , &N , &M , &P ) ;
    initialise() ;
    for ( int k = 1 ; k <= P ; k++ )
    {
        for ( int i = 1 ; i <= N ; i++ )
            scanf ( "%d" , &orderLine[i] ) ;
        updateLines() ;
        for ( int i = 1 ; i <= M ; i++ )
            scanf ( "%d" , &orderColomn[i] ) ;
        updateColomns() ;
        if ( k == 1 )
        {
            scanf ( "%d" , &Q ) ;
            if ( Q != 0 )
                for ( int i = 1 ; i <= Q ; i++ )
                {
                    scanf ( "%d %d %d %d" , &x0 , &y0 , &x1 , &y1 ) ;
                    QQ[i][1] = x0 ;
                    QQ[i][2] = y0 ;
                    QQ[i][3] = x1 ;
                    QQ[i][4] = y1 ;
                }
        }
        update() ;
    }
    print() ;
}

int main()
{
    read() ;
    return 0;
}
