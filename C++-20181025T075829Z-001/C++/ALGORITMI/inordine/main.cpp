#include <fstream>
#include <queue>
#include <cstring>
#include <vector>
#include <bitset>
#include <utility>
#define NMAX 1005

using namespace std ;

ifstream fin ( "inordine.in" ) ;
ofstream fout ( "inordine.out" ) ;

int N , root , ST[NMAX] , DR[NMAX] , INFO[NMAX] ;
bitset < NMAX > vis ;

void find_root()
{
    for ( int i = 1 ; i <= N ; i++ )
        if ( vis[i] == 0 )
            root = i ;
}
void SRD( int root )
{
    if ( root != 0 )
    {
        SRD(ST[root]) ;
        fout << root << ' ' ;
        SRD(DR[root]) ;
    }
}

int main()
{
    int x , stx , drx ;
    int nr ;
    pair < int , int > node ;
    fin >> N ;
    for ( int i = 1 ; i <= N ; i++ )
    {
        nr++ ;
        fin >> x >> stx >> drx ;
        ST[x] = stx ;
        DR[x] = drx ;
        vis[stx] = 1 ;
        vis[drx] = 1 ;
    }
    find_root() ;
    fout << root ;
    SRD(root) ;
    return 0;
}
