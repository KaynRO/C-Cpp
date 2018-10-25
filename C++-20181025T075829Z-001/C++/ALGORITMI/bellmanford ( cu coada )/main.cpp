#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#define NMAX 50500
#define INF 0x3f3f3f3f

using namespace std;

ofstream fout ( "bellmanford.out" ) ;

struct tip
{
    int node ;
    int cost ;
} ;

vector<tip> G[NMAX] ;
queue<int> Q ;
int n , m , dist[NMAX] , vis[NMAX] ;

void read()
{
    freopen ( "bellmanford.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &n , &m ) ;
    tip data ;
    int x , y , cost ;
    for ( int i = 1 ; i <= m ; i++ )
    {
        scanf ( "%d %d %d" , &x , &y , &cost ) ;
        data.node = y ;
        data.cost = cost ;
        G[x].push_back(data) ;
    }
    for ( int i = 2 ; i <= n ; i++ )
        dist[i] = INF ;
}

int bellman_ford()
{
    dist[1] = 0 ;
    Q.push(1) ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        int distance = dist[k] ;
        vis[k]++ ;
        if ( vis[k] > n )
            return -1 ;
        Q.pop() ;
        for ( vector<tip> :: iterator it = G[k].begin() ; it != G[k].end() ; ++it )
        {
            if ( distance + it->cost > dist[it->node] )
                continue ;
            dist[it->node] = distance + it->cost ;
            Q.push(it->node) ;
        }
    }
    return 1 ;
}

void print()
{
    if ( bellman_ford() < 0 )
        fout << "Ciclu negativ!" ;
    else
        for ( int i = 2 ; i <= n ; i++ )
        {
            if ( dist[i] == INF )
                dist[i] = 0 ;
            fout << dist[i] << ' ' ;
        }
}

int main()
{
    read() ;
    bellman_ford() ;
    print() ;
    return 0;
}
