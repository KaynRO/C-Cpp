#include <bits/stdc++.h>
#define NMAX 3100
#define INF ( 1 << 30 )

using namespace std ;

ofstream fout ( "lover.out" ) ;

int N, M, K, Price[NMAX], TT[NMAX], dist[NMAX], Cost[NMAX] ;
bool inQueue[NMAX] ;

vector < pair < int, int > > G[NMAX] ;
vector < int > path, fuel ;
queue < int > Q ;

bool compare ( int x, int y )
{
    return Price[x] < Price[y] ;
}

void read()
{
    int x, y, distance ;
    freopen ( "lover.in", "r", stdin ) ;
    scanf ( "%d %d %d", &N, &M, &K ) ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf ( "%d %d %d", &x, &y, &distance ) ;
        G[x].push_back( make_pair ( y, distance ) ) ;
        G[y].push_back( make_pair ( x, distance ) ) ;
    }
    for ( int i = 1 ; i <= N - 1 ; i++ )
        scanf ( "%d", &Price[i] ) ;
}

void bellman_ford()
{
    for ( int i = 1 ; i <= N ; i++ )
        dist[i] = INF ;
    int SOL = INF ;
    TT[1] = 1 ;
    Q.push(1) ;
    dist[1] = 0 ;
    inQueue[1] = true ;
    while ( !Q.empty() )
    {
        int node = Q.front() ;
        int distance = dist[node] ;
        Q.pop() ;
        for ( vector < pair < int, int > > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
        {
            if ( distance + it->second >= dist[it->first] || distance + it->second >= SOL )
                continue ;
            dist[it->first] = distance + it->second ;
            TT[it->first] = node ;
            if ( !inQueue[it->first] )
            {
                inQueue[it->first] = true ;
                Q.push(it->first) ;
            }
        }
    }
}

int search_fuel ( int start, int left )
{
    int bestSOL = -1 ;
    for ( int i = 0 ; i <= path.size() - 1 ; i++ )
        if ( dist[path[i]] > dist[start] && dist[path[i]] - dist[start] <= left && Price[path[i]] < bestSOL )
            bestSOL = path[i] ;
    return bestSOL ;
}

void Greedy ( int node, int dest, int left )
{
    int SOL = 0 ;
    int start = node, finish = dest,available = left ;
    while ( start != finish )
    {
        if ( available >= dist[dest] - dist[start] )
        {
            start = dest ;
            break ;
        }

        int best = fuel[0] ; // cea mai ieftina benzinarie
        int distance = dist[best] - dist[start] ; // cat trebuie sa parcurg pana la ea
        if ( available >= distance ) // daca pot ajunge
        {
            start = best ;
            available -= distance ;
            SOL = SOL + ( K - available ) * Price[best] ; // fac plinul si adun costul
            available = K ;
        }
        else
        {
            best = search_fuel( start, available )  ;// caut cea mai buna benzinarie la care pot ajunge
            distance = dist[best] - dist[start] ;
            start = best ;
            available -= distance ;
            SOL = SOL + ( K - available ) * Price[best] ;
            available = K ;
        }
    }
    fout << SOL ;
}

void make_path()
{
    int node = N ;
    path.push_back(node) ;
    while ( TT[node] != 1 )
    {
        node = TT[node] ;
        path.push_back(node) ;
    }
    path.push_back(1) ;
    reverse( path.begin(), path.end() ) ;
    fuel = path ;
    sort ( fuel.begin(), fuel.end(), compare ) ;
    Greedy ( 1, N, 0 ) ;
}

int main()
{
    read() ;
    bellman_ford() ;
    make_path() ;
    return 0 ;
}
