#include <bits/stdc++.h>
#define NMAX 2100
#define INF ( 1 << 30 )

using namespace std ;

ofstream fout ( "ubuntzei.out" ) ;

int N, M, K, SOL = INF, vis[NMAX], dist[NMAX] ;
short int order[NMAX] ;
vector < pair < int, int > > G[NMAX] ;
map < int, map < string, bool > > inQueue ;
map < int, map < string, int > > Dist ;
queue < pair < int, string > > Q ;
queue < int > X ;
string start_config, final_config ;

void read()
{
    int toVisit, x, y, dist ;
    memset ( order, -1, sizeof(order) ) ;
    freopen ( "ubuntzei.in", "r", stdin ) ;
    scanf ( "%d %d", &N, &M ) ;
    scanf ( "%d", &K ) ;
    for ( int i = 1 ; i <= K ; ++i )
    {
        scanf ( "%d", &toVisit ) ;
        order[toVisit] = i - 1 ;
    }
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf ( "%d %d %d", &x, &y, &dist ) ;
        G[x].push_back( make_pair ( y, dist ) ) ;
        G[y].push_back( make_pair ( x, dist ) ) ;
    }
}

void prepare_config()
{
    if ( K == 0 ) start_config = "0", final_config = "0" ;
    for ( int i = 1 ; i <= K  ; i++ )
    {
        start_config += "0" ;
        final_config += "1" ;
    }
}

void make_dist()
{
    for ( int i = 1 ; i <= N ; i++ )
        dist[i] = INF ;
    dist[1] = 0 ;
    vis[1] = 1 ;
    X.push(1) ;
    while ( !X.empty() )
    {
        int node = X.front() ;
        X.pop() ;
        int distance = dist[node] ;
        vis[1] = 0 ;
        for ( vector < pair < int, int > > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
        {
            if ( distance + it->second > dist[it->first] )
                continue ;
            dist[it->first] = distance + it->second ;
            if ( it->first == N ) continue ;
            if ( !vis[it->first] )
            {
                X.push(it->first) ;
                vis[it->first] = 1 ;
            }
        }

    }
    fout << dist[N] ;
}

void check ( int node )
{
    if ( dist[node] + Dist[node][final_config] < SOL )
        SOL = dist[node] + Dist[node][final_config] ;
}

void bellman_ford()
{
    Dist[1][start_config] = 0 ;
    inQueue[1][start_config] = 1 ;
    Q.push( make_pair ( 1, start_config ) ) ;

    while ( !Q.empty() )
    {
        int node = Q.front().first ;
        string current_config = Q.front().second ;
        string aux = current_config ;
        int distance = Dist[node][current_config] ;
        inQueue[node][current_config] = 0 ;
        Q.pop() ;
        for ( vector < pair < int, int > > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
        {
            int next_node = it->first ;
            current_config = aux ;

            if (  order[next_node] != -1 && current_config[order[next_node]] == '0' )
            {
                current_config[order[next_node]] = '1' ;
                Dist[next_node][current_config] = distance + it->second ;
                if ( !inQueue[next_node][current_config] )
                {
                    Q.push( make_pair ( next_node, current_config ) ) ;
                    inQueue[next_node][current_config] = 1 ;
                }
                continue ;
            }

            if ( Dist[next_node].find(current_config) != Dist[next_node].end() && ( distance + it->second > Dist[next_node][current_config] || distance + it->second > SOL ) )
                continue ;
            if ( node == N && current_config == final_config && distance + it->second < SOL )
            {
                SOL = distance + it->second ;
                continue ;
            }

            Dist[next_node][current_config] = distance + it->second ;
            if ( !inQueue[next_node][current_config] )
            {
                inQueue[next_node][current_config] = 1 ;
                Q.push( make_pair ( next_node, current_config ) ) ;
            }
        }
    }
    fout << SOL ;
}

int main()
{
    read() ;
    if ( K == 0 )
        make_dist() ;
    else
    {
        prepare_config() ;
        bellman_ford() ;
    }
    return 0 ;
}
