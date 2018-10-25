#include <fstream>
#include <queue>
#include <map>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#define inf 0x3fffffff

using namespace std;

ofstream fout ( "zmeu.out" ) ;
int n , m , nriesiri , vis[1200] , iesire[1200] , nod_fat , zana[7] , dist[1200] , sol[7] , miniesire[7] ;
queue<int> Q ;
vector< pair < int , int > > G[1200] ;
vector< pair < int , int > > :: iterator it ;
vector< int > P ;
vector< int > :: iterator itm ;
struct drum
{
    int zn[7] ;
} Z[7] ;

void citeste()
{
    int x , y , cost ;
    freopen ( "zmeu.in" , "r" , stdin ) ;
    scanf ( "%d %d %d" , &n , &m , &nriesiri ) ;
    scanf ( "%d %d %d %d %d %d" , &nod_fat , &zana[1] , &zana[2] , &zana[3] , &zana[4] , &zana[5] ) ;
    for ( int i = 1 ; i <= m ; i++ )
    {
        scanf ( "%d %d %d" , &x , &y , &cost ) ;
        G[x].push_back ( make_pair( y , cost ) ) ;
        G[y].push_back ( make_pair ( x , cost ) ) ;
    }
    for ( int i = 1 ; i <= nriesiri ; i++ )
    {
        scanf ( "%d" , &x ) ;
        iesire[x] = 1 ;
    }
    for ( int i = 1 ; i <= 5 ; i++ )
        miniesire[i] = sol[i] = inf ;
}

void bellman_ford ( int nod )
{
    memset ( vis ,0, sizeof(vis) ) ;
    for ( int i = 1 ; i <= n ; i++ )
        dist[i] = inf ;
    if ( iesire[zana[nod]] == 1 )
        miniesire[nod] = 0 ;
    dist[zana[nod]] = 0 ;
    vis[zana[nod]] = 1 ;
    Q.push(zana[nod]) ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        int distance = dist[k] ;
        vis[k] = 0 ;
        Q.pop() ;
        for ( it = G[k].begin() ; it != G[k].end() ; ++it )
        {
            if ( distance + it->second > dist[it->first] )
                continue ;
            if ( it->first == nod_fat )
            {
                if ( sol[nod] > distance + it->second )
                {
                    dist[it->first] = distance + it->second ;
                    sol[nod] = dist[it->first] ;
                }
                vis[it->first] = 1 ;
                Q.push(it->first) ;
                continue ;
            }
            if ( iesire[it->first] == 1 && distance + it->second < miniesire[nod] )
                miniesire[nod] = distance + it->second ;
            dist[it->first] = distance + it->second ;
            if ( !vis[it->first] )
            {
                vis[it->first] = 1 ;
                Q.push(it->first) ;
            }
        }
    }
    for ( int i = 1 ; i <= 5 ; i++ )
        Z[nod].zn[i] = dist[zana[i]] ;
}

void permuta()
{
    int solmin = inf , sum = 0 , i ;
    do
    {
        sum = 0 ;
        sum = sum + sol[P[0]] ;
        for ( i = 0 ; i <= P.size() - 2 ; i++ )
            sum = sum + Z[P[i]].zn[P[i+1]] ;
        sum = sum + miniesire[P[P.size()-1]] ;
        if ( sum < solmin )
            solmin = sum ;
    }
    while ( next_permutation(P.begin() , P.end() ) ) ;
    fout << solmin  ;
}
int main()
{
    citeste() ;
    for ( int i = 1 ; i <= 5 ; i++ )
        bellman_ford(i) ;
    for ( int i = 1 ; i <= 5 ; i++ )
        P.push_back(i) ;
    permuta() ;
    return 0;
}
