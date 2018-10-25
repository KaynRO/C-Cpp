#include <fstream>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <utility>
#include <cstring>
#define inf 0x3fffffff
#define MAXN 1000005
using namespace std;

ofstream fout ( "trmv.out" ) ;

int n , nrroutes , node_start , nrnodes_finish , sol = inf ;
int dist[MAXN] , vis[MAXN] , solmax[MAXN] ;
deque<int> Q ;
map< int , map < int , int > > M ;
map< int , int > :: iterator itm ;
map< int , map < int , int > > :: iterator it ;
int finish[MAXN] , order[MAXN] , st = 0 ;

void set_dist()
{
    for ( int i = 1 ; i <= n ; i++ )
        dist[i] = solmax[i] = inf ;
}

void read()
{
    int nrp , cost , node , current_node , x , finish_node ;
    freopen ( "trmv.in" , "r" , stdin ) ;
    scanf ( "%d %d %d %d" , &n , &nrroutes , &node_start , &nrnodes_finish ) ;
    set_dist() ;
    for ( int i = 1 ; i <= nrroutes ; ++i )
    {
        scanf ( "%d" , &nrp ) ;
        scanf ( "%d" , & x ) ;
        current_node = x ;
        for ( int j = 1 ; j <= ( nrp - 1 ) ; ++j )
        {
            scanf ( "%d %d" , &cost , &node ) ;
            if ( M[current_node].find(node) != M[current_node].end() )
            {
                M[current_node][node] = min( M[current_node][node] , cost ) ;
                M[node][current_node] = min( M[node][current_node] , cost ) ;
            }
            else
            {
                M[current_node].insert ( make_pair ( node , cost ) ) ;
                M[node].insert ( make_pair ( current_node , cost ) ) ;
            }

            current_node = node ;
        }
    }
    for ( int i = 1 ; i <= nrnodes_finish ; ++i )
    {
        scanf ( "%d" , &finish_node ) ;
        order[++st] = finish_node ;
        finish[finish_node] = 1 ;
    }
}

int bellman_ford ( int node_start )
{
    Q.push_back(node_start) ;
    vis[node_start] = 1 ;
    dist[node_start] = 0 ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        int distance = dist[k] ;
        Q.pop_front() ;
        vis[k] = 0 ;
        for ( itm = M[k].begin() ; itm != M[k].end() ; ++itm )
        {
            if ( distance + itm->second > dist[itm->first]  )
                continue ;
            if ( finish[itm->first] )
                solmax[itm->first] = distance + itm->second ;
            dist[itm->first] = distance + itm->second ;
            if ( !vis[itm->first] )
            {
                vis[itm->first] = 1 ;
                Q.push_back(itm->first) ;
            }
        }
    }
    for ( int i = 1 ; i <= st ; ++i )
        if ( finish[order[i]] )
        {
            if ( node_start == order[i])
                fout << "0" << ' ' ;
            else if ( solmax[order[i]] == inf )
                fout << "-1" << ' ' ;
            else fout << solmax[order[i]] << ' ' ;
        }
}

int main()
{
    read() ;
    bellman_ford(node_start) ;
    return 0;
}
