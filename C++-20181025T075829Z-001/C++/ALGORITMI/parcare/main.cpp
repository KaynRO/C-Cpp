#include <iostream>
#define NMAX 120

using namespace std ;

int dl[] = { 0, 0, -1, 1 } ;
int dc[] = { 1, -1, 0, 0 } ;

int nr, N, M , Mx[NMAX][NMAX] ;

void fill_it ( int i, int j )
{
    int line , colomn ;
    nr++ ;
    Mx[i][j] = -1 ;
    for ( int k = 0 ; k <= 3 ; k++ )
    {
        line = dl[k] + i ;
        colomn = dc[k] + j ;
        if ( line >= 1 && line <= N && colomn >= 1 && colomn <= M && Mx[line][colomn] == 1 )
            fill_it( line, colomn ) ;
        }
}

void complete_fill ( int i, int j, int value )
{
    int line , colomn ;
    Mx[i][j] = value ;
    for ( int k = 0 ; k <= 3 ; k++ )
    {
        line = dl[k] + i ;
        colomn = dc[k] + j ;
        if ( line >= 1 && line <= N && colomn >= 1 && colomn <= M && Mx[line][colomn] == -1 )
            complete_fill( line, colomn , value ) ;
        }
}


int main()
{
    cin >> N >> M ;
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= M ; j++ )
            cin >> Mx[i][j] ;
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= M ; j++ )
            if ( Mx[i][j] == 1 )
            {
                nr = 0 ;
                fill_it(i, j) ;
                complete_fill(i, j, nr) ;
            }
    for ( int i = 1 ; i <= N ; i++ )
    {
        for ( int j = 1 ; j <= M ; j++ )
            cout << Mx[i][j] << ' ' ;
        cout << '\n' ;
    }
    return 0 ;
}
