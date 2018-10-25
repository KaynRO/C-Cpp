#include <fstream>
#include <vector>
#define NMAX 12000

using namespace std ;

ifstream fin ( "combo.in" ) ;
ofstream fout ( "combo.out" ) ;

int N, M, start, best, maxim = -1 ;
char tip[NMAX] ;

int main()
{
    int x, y ;
    fin >> N >> M >> start ;
    for ( int i = 1 ; i <= N ; i++ )
        fin >> tip[i] ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        fin >> x >> y ;
        if ( best == 0 && tip[x] == 'A' )
            best = 1 ;
        if ( tip[y] == 'A' )
        {
            best++ ;
            if ( best > maxim )
                maxim = best ;
        }
        else
            best = 0 ;

    }
    if ( maxim == -1 )
        maxim = 1 ;
    fout << maxim ;
    return 0;
}
