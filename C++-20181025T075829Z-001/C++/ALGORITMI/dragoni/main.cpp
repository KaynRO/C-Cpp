#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define NMAX 850

using namespace std ;

ofstream fout ( "dragoni.out" ) ;

int N, M, Dragon[NMAX], test_number, inQueue[NMAX], Config[NMAX][NMAX] ;
int DP[NMAX][NMAX] ;

vector < pair < int, int > > G[NMAX] ;
queue < int > Q ;
typedef bool (*compare) ( pair < int, int >, pair < int, int > ) ;

bool cmp ( pair < int, int > A, pair < int, int > B )
{
    return DP[A.first][A.second] < DP[B.first][B.second] ;
}

bool ascending ( pair < int, int > A, pair < int, int > B )
{
    return A.second < B.second ;
}

priority_queue < pair < int, int >, vector < pair < int, int > >, compare > X(cmp) ;

void read()
{
    int from, to, distance ;
    freopen ( "dragoni.in", "r", stdin ) ;
    scanf ( "%d", &test_number ) ;
    scanf ( "%d %d", &N, &M ) ;
    for ( int i = 1 ; i <= N ; i++ )
        scanf ( "%d", &Dragon[i] ) ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf ( "%d %d %d", &from, &to, &distance ) ;
        G[from].push_back ( make_pair ( to, distance ) ) ;
        G[to].push_back ( make_pair ( from, distance ) ) ;
    }
}

void solveI()
{
    int my_dragon = Dragon[1], best = Dragon[1] ;
    inQueue[1] = 1 ;
    Q.push(1) ;
    while ( !Q.empty() )
    {
        int node = Q.front() ;
        Q.pop() ;
        for ( vector < pair < int, int > > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
        {
            if ( my_dragon < it->second )
                continue ;
            if ( !inQueue[it->first] )
            {
                inQueue[it->first] = 1 ;
                Q.push(it->first) ;
                if ( Dragon[it->first] > best )
                    best = Dragon[it->first] ;
            }
        }
    }
    fout << best ;
}

void solveII()
{
    int sol = INF ;
    for ( int i = 1 ; i <= N ; i++ )
        sort ( G[i].begin(), G[i].end(), ascending ) ;
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= N ; j++ )
            DP[i][j] = INF ;
    X.push( make_pair ( 1, 1 ) ) ;
    Config[1][1] = 1 ;
    DP[1][1] = 0 ;
    while ( !X.empty() )
    {
        int node = X.top().first ;
        int d_type = X.top().second ;
        int distance = DP[node][d_type] ;
        Config[node][d_type] = 0 ;
        if ( Dragon[d_type] < Dragon[node] )
            d_type = node ;
        X.pop() ;
        for ( vector < pair < int, int > > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
        {
            if ( distance + it->second >= sol || distance + it->second >= DP[it->first][d_type] )
                continue ;
            if ( Dragon[d_type] < it->second )
                continue ;
            DP[it->first][d_type] = distance + it->second ;
            if ( it->first == N )
            {
                sol = distance + it->second ;
                continue ;
            }
            if ( !Config[it->first][d_type] )
            {
                Config[it->first][d_type] = 1 ;
                X.push( make_pair ( it->first, d_type ) ) ;
            }
        }

    }
    fout << sol ;
}

int main()
{
    read() ;
    if ( test_number == 1 )
        solveI() ;
    else solveII() ;
    return 0 ;
}
