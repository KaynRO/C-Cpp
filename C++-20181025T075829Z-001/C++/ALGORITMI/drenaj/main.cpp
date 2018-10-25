#include <fstream>
#include <cstring>
using namespace std;

ifstream fin ( "drenaj.in" ) ;
ofstream fout ( "drenaj.out" ) ;

int n , m  , nr , matrix[120][120] , vis[120][120] , dl[]= {-1,0,1,0} , dc[]= {0,1,0,-1} , ok , k ;
void read()
{
    fin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= m ; j++ )
            fin >> matrix[i][j] ;

}

int vecc ( int lin , int col , int value )
{
    if ( matrix[ lin + 1 ][ col ] < value && lin + 1 <= n  )
        ok = 1 ;
    if ( matrix[ lin - 1 ][ col ] < value && lin - 1 >= 1  )
        ok = 1 ;
    if ( matrix[ lin ][ col + 1 ] < value && col + 1 <= m  )
        ok = 1 ;
    if ( matrix[ lin ][ col - 1 ] < value && col - 1 >= 1  )
        ok = 1 ;
}

int fil ( int lin , int col , int value )
{
    vis[lin][col] = 1 ;
    vecc ( lin , col , value ) ;

    if ( matrix[ lin + 1 ][ col ] == value && !vis[ lin + 1 ][ col ]  && lin + 1 <= n  )
        fil ( lin + 1 , col , value ) ;
    if ( matrix[ lin  ][ col + 1 ] == value && !vis[ lin ][ col + 1 ] && col + 1 <= m   )
        fil ( lin , col + 1  , value ) ;
    if ( matrix[ lin - 1 ][ col ] == value && !vis[ lin - 1 ][ col ] && lin - 1 >= 1 )
        fil ( lin - 1 , col , value ) ;
    if ( matrix[ lin ][ col - 1 ] == value && !vis[ lin ][ col - 1 ]  && col - 1 >= 1 )
        fil ( lin , col - 1 , value ) ;
}




void print()
{
    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= m ; j++ )
            fout << matrix[i][j] << ' ' ;
        fout << endl ;
    }
}
int main()
{
    read() ;
    //print() ;
    int i , j ;
    for ( i = 1 ; i <= n ; i++ )
        for ( j = 1 ; j <= m ; j++ )
        {
            ok = 0 ;
            if ( !vis[i][j] )
            {
                fil ( i , j , matrix[i][j] ) ;
                if ( ok == 0 ) nr ++ ;
            }
        }
    fout << nr ;
    return 0;
}
