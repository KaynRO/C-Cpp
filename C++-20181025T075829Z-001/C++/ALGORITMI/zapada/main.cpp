#include <fstream>
#include <vector>
#include <algorithm>
#define NMAX 105
#define INF ( 1 << 30 )
using namespace std ;

ofstream fout ( "zapada.out" ) ;

int N , M , TT[NMAX] , cost , Rank[NMAX] , roads , priority[NMAX] ;
struct edge
{
    int x ;
    int y ;
    int cost ;
} ;
vector < edge > APM , G , Read_Data ;

bool compare_test ( struct edge a , struct edge b )
{
    return a.cost < b.cost ;
}

int father ( int node )
{
    while ( node != TT[node] )
        node = TT[node] ;
    return node ;
}

void Union ( int x , int y )
{
    if ( Rank[x] > Rank[y] )
        TT[y] = x ;
    else TT[x] = y ;
    if ( Rank[x] == Rank[y] )
        Rank[y]++ ;
}

void read()
{
    freopen ( "zapada.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &N , &M ) ;
    edge data ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf ( "%d %d %d" , &data.x , &data.y , &data.cost ) ;
        G.push_back(data) ;
    }
    scanf ( "%d" , &roads ) ;
    for ( int i = 1 ; i <= roads ; i++ )
    {
        scanf ( "%d" , &priority[i] ) ;
        data = G[priority[i] - 1] ;
        Read_Data.push_back(data) ;
        G[priority[i] - 1].cost = 0 ;
    }

}

int main()
{
    int x , y ;
    read() ;
    for ( int i = 1 ; i <= N ; i++ )
        TT[i] = i ;
    sort ( G.begin() , G.end() , compare_test ) ;
    for ( vector < edge > :: iterator it = G.begin() ; it != G.end() ; ++it )
    {
        x = father ( it->x ) ;
        y = father ( it->y ) ;
        if ( x != y )
        {
            cost += it->cost ;
            Union ( x , y ) ;
            APM.push_back(*it) ;
        }
    }
    for ( vector < edge > :: iterator it = Read_Data.begin() ; it != Read_Data.end() ; ++ it )
        cost += it->cost ;
    fout << cost << '\n' ;
    return 0;
}
