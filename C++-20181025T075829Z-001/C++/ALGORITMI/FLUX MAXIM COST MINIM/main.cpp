#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cstring>
#define INF ( 1 << 30 )
#define MAXN 355
#define FOR( i , n ) for ( int i = 1 ; i <= n ; ++i )
#define FORIT(it , n ) for ( vector < int > :: iterator it = G[n].begin() ; it != G[n].end() ; ++it )

using namespace std ;

ofstream fout ( "fmcm.out" ) ;
vector < int > G[MAXN] ;
int S , D , N , M , TT[MAXN] , Sol , C[MAXN][MAXN] , Cost[MAXN][MAXN] , dist[MAXN] ;
bitset < MAXN > vis ;
queue < int > Q ;

void read()
{
    freopen ( "fmcm.in" , "r" , stdin ) ;
    scanf ( "%d %d %d %d" , &N , &M , &S , &D ) ;
    int x , y , capacity , cost ;
    FOR( i , M )
    {
        scanf ( "%d %d %d %d" , &x , &y , &capacity , &cost ) ;
        G[x].push_back(y) ;
        G[y].push_back(x) ;
        C[x][y] = capacity ;
        Cost[x][y] = cost ;
        Cost[y][x] = -cost ;
    }
}

void maxim_flow_minim_cost()
{
    int flow ;
    for (;;)
    {
        Q.push(S) ;
        vis.reset() ;
        FOR ( i , N )
        dist[i] = INF ;
        dist[S] = 0 ;
        while ( !Q.empty() )
        {
            int node = Q.front() ;
            vis[node] = 0 ;
            Q.pop() ;
            FORIT ( it , node )
            if ( dist[*it] > dist[node] + Cost[node][*it] && C[node][*it] )
            {
                dist[*it] = dist[node] + Cost[node][*it] ;
                TT[*it] = node ;
                if ( !vis[*it] )
                {
                    vis[*it] = 1 ;
                    Q.push(*it) ;
                }
            }
        }
        if ( dist[D] == INF )
            break ;
        flow = INF ;
        int node = D ;
        while ( node != S )
        {
            flow = min ( flow , C[TT[node]][node] ) ;
            node = TT[node] ;
        }
        node = D ;
        while ( node != S )
        {
            C[TT[node]][node] -= flow ;
            C[node][TT[node]] += flow ;
            node = TT[node] ;
        }
        Sol += flow * dist[D] ;
    }
}

int main()
{
    read() ;
    maxim_flow_minim_cost() ;
    fout << Sol ;
    return 0;
}
