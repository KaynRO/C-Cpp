#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#define NMAX 2016
#define INF ( 1 << 30 )
#define CMAX 200

using namespace std ;

ifstream fin ( "salesman.in" ) ;
ofstream fout ( "salesman.out" ) ;

queue < pair < int , int > > Q ;
vector < pair < int , int > > G[NMAX] ;
int N , M , inQueue[CMAX][NMAX] , dist[CMAX][NMAX] , node_start ;

void bellman_ford()
{
    inQueue[1 << node_start][node_start] = 1 ;
    dist[1 << node_start][node_start] = 0 ;
    Q.push ( make_pair ( 1 << node_start , node_start ) ) ;
    while ( !Q.empty() )
    {
        int current_config = Q.front().first ;
        int current_node = Q.front().second ;
        Q.pop() ;
        for ( vector < pair < int , int > > :: iterator it = G[current_node].begin() ; it != G[current_node].end() ; ++it )
        {
            if ( ( current_config & ( 1 << it->first ) ) == 0 )
            {
                if ( dist[ current_config + ( 1 << it->first )][it->first] <= dist[current_config][current_node] + it->second && inQueue[ current_config + ( 1 << it->first )][it->first] == 1 ) ;
                else
                {
                    dist[ current_config + ( 1 << it->first )][it->first] = dist[current_config][current_node] + it->second ;
                    inQueue[ current_config + ( 1 << it->first )][it->first] = 1 ;
                    Q.push ( make_pair ( current_config + ( 1 << it->first ) , it->first ) ) ;
                }
            }
            else
            {
                if ( dist[current_config][it->first] <= dist[current_config][current_node] + it->second && inQueue[current_config][it->first] == 1 ) ;
                else
                {
                    dist[current_config][it->first] = dist[current_config][current_node] + it->second ;
                    inQueue[current_config][it->first] = 1 ;
                    Q.push ( make_pair ( current_config , it->first ) ) ;
                }
            }
        }
    }
}

int main()
{
    int x , y , cost , full_config = 0 ;
    fin >> N >> M >> node_start ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        fin >> x >> y >> cost ;
        G[x].push_back ( make_pair ( y , cost ) ) ;
        G[y].push_back ( make_pair ( x , cost ) ) ;
    }
    for ( int i = 0 ; i <= 100 ; i++ )
        for ( int j = 1 ; j <= N ; j++ )
            dist[i][j] = INF ;
    for ( int i = 1 ; i <= N  ; i++ )
        full_config = full_config + ( 1 << i ) ;
    bellman_ford() ;
    fout << dist[full_config][node_start] ;
    return 0;
}
