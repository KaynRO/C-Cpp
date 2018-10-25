#include <fstream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#define inf 0x3fffffff

using namespace std;

ofstream fout ( "lanturi.out" ) ;
int n , m , node_start , node_finish , dist[1200] , vis[1200] , many[1200] , sol , nr = 1 ;
vector< pair < int , int > > G[1200] ;
queue<int> Q , C ;
vector< pair < int , int > > :: iterator it ;

void read()
{
    int x , y , cost ;
    freopen ( "lanturi.in" , "r" , stdin ) ;
    scanf ( "%d %d %d %d" , &n , &m , &node_start , &node_finish ) ;
    for ( int i = 1 ; i <= m ; i++ )
    {
        scanf ( "%d %d %d" , &x , &y , &cost ) ;
        G[x].push_back( make_pair ( y , cost ) ) ;
        G[y].push_back( make_pair ( x , cost ) ) ;
    }
    for ( int i = 1 ; i <= n ; i++ )
        dist[i] = inf ;
}

void bellman_ford()
{
    vis[node_start] = 1 ;
    sol = inf ;
    Q.push(node_start) ;
    dist[node_start] = 0 ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        int distance = dist[k] ;
        vis[k] = 0 ;
        Q.pop() ;
        for ( it = G[k].begin() ; it != G[k].end() ; ++it )
        {
            if ( distance + it->second > dist[it->first] )
                continue ;
            dist[it->first] = distance + it->second ;
            if ( !vis[it->first] )
            {
                vis[it->first] = 1 ;
                Q.push(it->first) ;
            }
        }
    }
}

int main()
{
    read() ;
    bellman_ford() ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( dist[i] != inf )
            C.push(i) ;
    while ( !C.empty() )
    {
        for ( it = G[C.front()].begin() ; it != G[C.front()].end() ; ++it )
            if ( dist[it->first] == dist[C.front()] + it->second )
            {
                many[it->first]++ ;
                many[C.front()]++ ;
            }
        C.pop() ;
    }
    fout << many[node_finish] ;
    return 0;
}
