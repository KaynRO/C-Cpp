#include <fstream>
#include <vector>
#include <cstring>
#define NMAX 2010

using namespace std ;

ifstream fin ( "galaxia.in" ) ;
ofstream fout ( "galaxia.out" ) ;

int  Mx[NMAX][NMAX] ;
int main()
{
    int N, M, drumuri = 0, x, y ;
    memset ( Mx, 0, sizeof(Mx) ) ;
    fin >> N >> M ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        fin >> x >> y ;
        if ( !Mx[x][y] || !Mx[y][x] )
            drumuri++ ;
        Mx[x][y] = 1 ;
        Mx[y][x] = 1 ;
    }
    if ( N == 1 )
    {
        fout << "GALAXIE SPECIALA" ;
        exit(0) ;
    }
    if ( drumuri == ( N * ( N - 1 ) ) / 2 )
        fout << "GALAXIE SPECIALA" ;
    else fout << ( N * ( N - 1 ) ) / 2  - drumuri ;
    return 0;
}
