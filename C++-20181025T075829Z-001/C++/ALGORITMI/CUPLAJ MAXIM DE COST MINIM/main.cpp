#include <fstream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std ;

ofstream fout ( "cmcm.out" ) ;

const int MAX_N = 310 , DIM = 2 * ( 1 + MAX_N ) , MAX_INF = ( 1 << 30 ) ;
vector < int > G[DIM] ;
vector < pair < int , int > > Edge ;
int C[DIM][DIM] , Cost[DIM][DIM] ;
int N , M , E , S , D , cnt , total_cost ;
queue < int > Q ;
int dist[DIM] , TT[DIM] ;
bool inQueue[DIM] ;

void add_source_destination()
{
    S = 0 ;
    D = N + M + 1 ;
    for ( int i = 1 ; i <= N ; ++i )
    {
        G[S].push_back(i) ;
        G[i].push_back(S) ;
        C[S][i] = 1 ;
    }
    for ( int i = N + 1 ; i <= N + M ; ++i )
    {
        G[i].push_back(D) ;
        G[D].push_back(i) ;
        C[i][D] = 1;
    }
}

void read()
{
    freopen ( "cmcm.in" , "r" , stdin ) ;
    scanf ( "%d %d %d" , &N , &M , &E ) ;
    add_source_destination() ;
    for ( int i = 1 ; i <= E ; ++i )
    {
        int x , y , cost ;
        scanf ( "%d %d %d" , &x , &y , &cost ) ;
        y += N ;
        G[x].push_back(y) ;
        G[y].push_back(x) ;
        C[x][y] = 1 ;
        Cost[x][y] = cost ;
        Cost[y][x] = -cost ;
        Edge.push_back ( make_pair ( x , y ) ) ;
    }
}

bool bellman_ford()
{
    for ( int i = S ; i <= D ; ++i )
    {
        inQueue[i] = false ;
        dist[i] = MAX_INF ;
    }
    int node = S ;
    Q.push(node) ;
    dist[node] = 0 ;
    while ( !Q.empty() )
    {
        node = Q.front() ;
        Q.pop() ;
        inQueue[node] = false ;
        for ( vector < int > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
        {
            if ( dist[node] + Cost[node][*it] < dist[*it] && C[node][*it] > 0 )
            {
                TT[*it] = node ;
                dist[*it] = dist[node] + Cost[node][*it] ;
                if ( !inQueue[*it] )
                {
                    inQueue[*it] = true ;
                    Q.push(*it) ;

                }
            }
        }
    }
    if ( dist[D] == MAX_INF )
        return false ;
    else
    {
        ++cnt ;
        node = D ;
        while ( node != S )
        {
            C[TT[node]][node]-- ;
            C[node][TT[node]]++ ;
            total_cost += Cost[TT[node]][node] ;
            node = TT[node] ;
        }
        return true ;
    }
}

void solve_and_print()
{
    while ( bellman_ford() ) ;
    fout << cnt << ' ' << total_cost << '\n' ;
    for ( unsigned int i = 0 ; i < Edge.size() ; ++i )
        if ( !C[Edge[i].first][Edge[i].second] )
            fout << i + 1 << ' ' ;
}

int main()
{
    read() ;
    solve_and_print() ;
    return 0;
}
