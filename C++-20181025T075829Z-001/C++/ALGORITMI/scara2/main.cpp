#include <fstream>
#include <cstring>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#define inf 0x3fffffff
using namespace std;

ofstream fout ( "scara2.out" ) ;
int nrstairs , nrwater , nrenergiser , dist[150] , inqueue[150][15000] , mincost = inf ;
struct type
{
    int node ;
    int cost ;
    int watervalue ;
    int energiservalue ;
} Info[150] ;

struct product
{
    int level ;
    int value ;
} W[150] , E[150] ;
vector< pair < int , int > > G[150] ;
vector< pair < int , int > > :: iterator it ;
deque < pair < int , int > > Q ;

void read()
{
    int level , value ;
    freopen ( "scara2.in" , "r" , stdin ) ;
    scanf ( "%d" , &nrstairs ) ;
    scanf ( "%d" , &nrwater ) ;
    for ( int i = 1 ; i <= nrwater ; i++ )
    {
        scanf ( "%d %d" , &level , &value ) ;
        Info[level].watervalue = value ;
        W[i].level = level ;
        W[i].value = value ;
    }
    scanf ( "%d" , &nrenergiser ) ;
    for ( int i = 1 ; i <= nrenergiser ; i++ )
    {
        scanf ( "%d %d" , &level , &value ) ;
        Info[level].energiservalue = value ;
        E[i].level = level ;
        E[i].value = value ;
    }
}

int already ( int x , int y )
{
    if ( G[x].size() >= 1 )
    {
        for ( int i = 0 ; i <= G[x].size() - 1 ; i++ )
            if ( G[x][i].first == y )
                return 1 ;
    }
    return 0 ;
}
void set_values()
{
    G[0].push_back ( make_pair ( 1 , 0 ) ) ;
    for ( int i = 1 ; i <= nrwater ; i++ )
        for ( int node = 2 ; node <= W[i].value ; node++ )
            G[W[i].level].push_back( make_pair ( W[i].level + node , 0 ) ) ;
    for ( int i = 1 ; i <= nrenergiser ; i++ )
        for ( int node = 1 ; node <= 2 * E[i].value ; node++ )
            if ( !already ( E[i].level , E[i].level +  node ) )
                G[E[i].level].push_back( make_pair ( E[i].level +  node , node / 2 + node % 2 ) ) ;
    for ( int i = 1 ; i <= nrstairs ; i++ )
        dist[i] = inf ;

}

void bellman_ford()
{
    inqueue[0][0] = 1 ;
    Q.push_back ( make_pair ( 0 , 0 ) ) ;
    int total_cost = 0 ;
    while ( !Q.empty() )
    {
        int current_node = Q.front().first ;
        int current_cost = Q.front().second ;
        int distance = dist[current_node] ;
        inqueue[current_node][current_cost] = 0 ;
        Q.pop_front() ;
        for ( it = G[current_node].begin() ; it != G[current_node].end() ; ++it )
        {
            if ( distance + 1 > dist[it->first] )
                continue ;
            if ( it->first == nrstairs )
            {
                if ( dist[it->first] == distance + 1 )
                    mincost = min ( mincost  , current_cost + it->second ) ;
                else mincost = current_cost + it->second ;
                continue ;
            }
            total_cost =  current_cost + it->second ;
            dist[it->first] = distance + 1 ;
            if ( !inqueue[it->first][total_cost]  )
            {
                inqueue[it->first][total_cost] = 1 ;
                Q.push_back ( make_pair ( it->first , total_cost ) ) ;
            }
        }
    }
    fout << dist[nrstairs] << ' ' << mincost ;
}
int main()
{
    read() ;
    set_values() ;
    bellman_ford() ;
    return 0;
}
