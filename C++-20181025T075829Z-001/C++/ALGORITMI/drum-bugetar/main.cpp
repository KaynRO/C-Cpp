#include <fstream>
#include <queue>
#include <utility>
#include <cstdio>
#include <vector>
#define NMAX 1200
#define INF 100000000
#define mp make_pair

using namespace std ;

ifstream fin ( "drum-bugetat.in" ) ;
ofstream fout ( "drum-bugetat.out" ) ;

int N , M , B , Cost[NMAX] , dist[NMAX], cost[NMAX] , start , finish , vis[NMAX] ;
vector < pair < int , int > > TT[NMAX] ;
queue < int > Q ;

void read()
{
    int x , y , mydist ;
    fin >> N >> M >> B ;
    fin >> start >> finish ;
    for ( int i = 1 ; i <= N ; i++ )
        fin >> Cost[i] ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        fin >> x >> y >> mydist ;
        TT[x].push_back( mp( y , mydist ) ) ;
        TT[y].push_back( mp ( x , mydist ) ) ;
    }
}

void initialise()
{
    for ( int i = 1 ; i <= N ; i++ )
        dist[i] = INF , cost[i] = INF , vis[i] = 0 ;
    cost[start] = 0 ;
    dist[start] = 0 ;
}

int bellman_ford( int value )
{
    initialise() ;
    Q.push(start) ;
    vis[start] = 1 ;
    while ( !Q.empty() )
    {
        int node = Q.front() ;
        Q.pop() , vis[node] = 0 ;
        int distance = dist[node] ;
        for ( vector < pair < int , int > > :: iterator it = TT[node].begin() ; it != TT[node].end() ; ++it )
        {
            int current = it->first ;
            int dist_now = it->second ;
            if ( distance + dist_now > dist[current] || distance + dist_now > dist[finish] )
                continue ;
            if ( Cost[current] + cost[node] > value )
                continue ;
            if ( dist[current] == distance + dist_now && cost[current] > cost[node] + Cost[current] )
                cost[current] = cost[node] + Cost[current] ;
            else if ( distance + dist_now < dist[current] )
            {
                dist[current] = distance + dist_now ;
                cost[current] = cost[node] + Cost[current] ;
            }
            if ( !vis[current] && current != finish )
            {
                vis[current] = 1 ;
                Q.push(current) ;
            }
        }
    }
    if ( cost[finish] > value )
        dist[finish] = INF ;
    return dist[finish] ;
}

int main()
{
    read() ;
    if ( N == 0 )
        fout << "-1" ;
    else
    {
        int mindist = INF , mincost = INF ;
        for ( int i = 0 ; i <= B ; i++ )
        {
            int value = bellman_ford(i) ;
            if ( value < mindist )
                mindist = value , mincost = i ;
            else if ( value == mindist && i < mincost )
                mincost = i ;
        }
        fout << mindist << ' ' << mincost ;
    }
    return 0;
}
