#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <bitset>
#include <cstring>
#include <algorithm>
#define INF ( 1 << 30 )
#define NMAX 10005
#define MMAX 200005

using namespace std ;

ofstream fout ( "flood.out" ) ;

struct edge
{
    int x ;
    int y ;
    int cost ;
} G[MMAX] ;

int N , M , P , TT[NMAX] , Rank[NMAX] , cost , components , nr_united ;
vector < edge > APM ;

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
    while ( TT[node] != node )
        node = TT[node] ;
    return node ;
}

bool compare_edge ( edge a , edge b )
{
    return a.cost < b.cost ;
}
void read()
{
    int x , y ;
    freopen ( "flood.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &N , &M ) ;
    for ( int i = 1 ; i <= N ; i++ )
        TT[i] = i ;
    components = N ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf ( "%d %d" , &x , &y ) ;
        x = father ( x ) ;
        y = father ( y ) ;
        if ( x != y )
        {
            Union ( x , y ) ;
            components-- ;
        }
    }
    scanf ( "%d" , &P ) ;
    for ( int i = 1 ; i <= P ; i++ )
        scanf ( "%d %d %d" , &G[i].x , &G[i].y , &G[i].cost ) ;
}

void solve()
{
    int x , y ;
    sort ( G + 1 , G + P + 1 , compare_edge ) ;
    for ( int i = 1 ; i <= P && nr_united < components - 1 ; i++ )
    {
        x = father ( G[i].x ) ;
        y = father ( G[i].y ) ;
        if ( x != y )
        {
            cost += G[i].cost ;
            Union ( x , y ) ;
            APM.push_back ( G[i] ) ;
            nr_united++ ;
        }
    }
    fout << APM.size() << '\n' ;
    fout << cost << '\n' ;
    for ( vector < edge > :: iterator it = APM.begin() ; it != APM.end() ; ++it )
        fout << it->x << ' ' << it->y << ' ' << it->cost << '\n' ;
}

int main()
{
    read() ;
    solve() ;
    return 0;
}
