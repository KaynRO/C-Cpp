#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#define NMAX 300
#define MMAX 40000
using namespace std ;

ofstream fout ( "urgenta.out" ) ;
int N , M , K , TT[NMAX] , Rank[NMAX] , cost , nrdestroyed , start ;
struct edge
{
    int x ;
    int y ;
    int cost ;
} G[MMAX] ;
bitset < MMAX > APM ;

void read()
{
    edge data ;
    freopen ( "urgenta.in" , "r" , stdin ) ;
    scanf ( "%d %d %d" , &N , &M , &K ) ;
    nrdestroyed = M ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf ( "%d %d %d" , &data.x , &data.y , &data.cost ) ;
        G[++start] = data ;
        cost += data.cost ;
    }

}

bool compare_test ( edge a , edge b )
{
    return a.cost < b.cost ;
}

void Union ( int x , int y )
{
    if ( Rank[x] > Rank[y] )
        TT[y] = x ;
    else TT[x] = y ;
    if ( Rank[x] == Rank[y] )
        Rank[y]++ ;
}

int father ( int node )
{
    while ( node != TT[node] )
        node = TT[node] ;
    return node ;
}

void find_K_APM()
{
    int count_K  = 0 ;
    for ( int i = 1 ; i <= N ; i++ )
        TT[i] = i ;
    for ( int i = 1 ; i <= start && count_K < N - K ; i++ )
    {
        int x = father ( G[i].x ) ;
        int y = father ( G[i].y ) ;
        if ( x != y )
        {
            cost -= G[i].cost ;
            Union ( x , y ) ;
            APM[i] = 1 ;
            nrdestroyed-- ;
            count_K++ ;
        }
    }
}

void print()
{
    fout << cost << '\n' ;
    fout << nrdestroyed << '\n' ;
    for ( int i = 1 ; i <= start ; i++ )
        if ( !APM[i] )
            fout << G[i].x << ' ' << G[i].y << '\n' ;
}

int main()
{
    read() ;
    sort ( G + 1  , G + M + 1 , compare_test ) ;
    find_K_APM() ;
    print() ;
    return 0;
}
