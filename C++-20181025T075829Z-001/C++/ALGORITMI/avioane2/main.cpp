#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <utility>
#include <queue>
#include <bitset>
#include <cstring>
#include <algorithm>
#define INF ( 1 << 30 )
#define NMAX 30006
#define TMAX 1000000 ;

using namespace std ;

ofstream fout ( "avioane2.out" ) ;

struct plane
{
    int time_come ;
    int time_arrive ;
    int destination ;
    int cost ;
} ;

queue < pair < int , int > > Q ;
vector < plane > G[NMAX] ;
bitset < NMAX > inQueue ;
int N , M , K , cost[NMAX] ;

void bellman_ford ( int destination , int max_time )
{
    int sol = INF ;
    inQueue.reset() ;
    for ( int i = 1 ; i <= N ; i++ )
        cost[i] = INF ;
    inQueue[1] = 1 ;
    cost[1] = 0 ;
    Q.push ( make_pair ( 1 , 0 ) ) ;
    while ( !Q.empty() )
    {
        int current_node = Q.front().first ;
        int current_time = Q.front().second ;
        Q.pop() ;
        inQueue[current_node] = 0 ;
        for ( vector < plane > :: iterator it = G[current_node].begin() ; it != G[current_node].end() ; ++it )
        {
            if ( current_time > it->time_come || it->time_arrive > max_time )
                continue ;
            if ( cost[current_node] + it->cost > sol )
                continue ;
            if ( cost[current_node] + it->cost > cost[it->destination] )
                continue ;
            cost[it->destination] = cost[current_node] + it->cost ;
            if ( it->destination == destination )
                sol = cost[it->destination] ;
            if ( !inQueue[it->destination] )
            {
                inQueue[it->destination] = 1 ;
                Q.push ( make_pair ( it->destination , it->time_arrive ) ) ;
            }
        }
    }
    if ( cost[destination] != INF )
        fout << cost[destination] ;
    else fout << "-1" ;
    fout << '\n' ;
}

void read()
{
    freopen ( "avioane2.in" , "r" , stdin ) ;
    scanf ( "%d %d %d" , &N , &M , &K ) ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        plane X ;
        int from ;
        scanf ( "%d %d %d %d %d" , &from , &X.time_come , &X.destination , &X.time_arrive , &X.cost ) ;
        G[from].push_back (X) ;
    }
    for ( int i = 1 ; i <= K ; i++ )
    {
        int destination , max_time ;
        scanf ( "%d %d" , &destination , &max_time ) ;
        bellman_ford ( destination , max_time ) ;
    }
}

int main()
{
    read() ;
    return 0 ;
}
