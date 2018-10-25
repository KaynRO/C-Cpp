#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cmath>

#define NMAX 810
#define INF ( 1 << 29 )

using namespace std ;

ifstream fin ( "adapost.in" ) ;
ofstream fout ( "adapost.out" ) ;

int N , C[NMAX][NMAX] , Flow[NMAX][NMAX] , st[NMAX] , dr[NMAX] , TT[NMAX] , destination , nr , inQueue[NMAX] ;
queue < int > Q ;
double cost , D[NMAX][NMAX] , distances[NMAX] , dist[NMAX] ;
vector < pair < int , double > > G[NMAX] ;
vector < int > g[NMAX] ;
struct point
{
    double x ;
    double y ;
} soldier[NMAX] , shelter[NMAX] ;

inline double point_distance ( point a , point b )
{
    return ( double ) sqrt ( ( double ) ( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) ) ) ;
}

inline bool pairup ( int x )
{
    if ( inQueue[x] )
        return 0 ;
    inQueue[x] = 1 ;
    for ( vector < int > :: iterator it = g[x].begin() ; it != g[x].end() ; ++it )
        if ( !st[*it] || pairup( st[*it] ) )
        {
            st[*it] = x ;
            dr[x] = *it ;
            return 1 ;
        }
    return 0 ;
}

inline int minimum_pairup ()
{
    int ok = 1 ;
    int nr = 0 ;
    memset ( st , 0 , sizeof(st) ) ;
    memset ( dr , 0 , sizeof(dr) ) ;
    while ( ok )
    {
        memset ( inQueue , 0 , sizeof(inQueue) ) ;
        ok = 0 ;
        for ( int i = 1 ; i <= N ; ++i )
            if ( !dr[i] && pairup(i) )
            {
                ok = 1 ;
                nr++ ;
            }
    }
    return nr ;
}

inline bool bellman_ford()
{
    for ( int i = 1 ; i <= destination ; ++i )
        dist[i] = INF ;
    Q.push(0) ;
    inQueue[0] = 1 ;
    dist[0] = 0 ;
    while ( !Q.empty() )
    {
        int x = Q.front() ;
        Q.pop() ;
        inQueue[x] = 0 ;
        if ( x == destination )
            continue ;
        for ( vector < pair < int , double > > :: iterator it = G[x].begin() ; it != G[x].end() ; ++it )
            if ( dist[it->first] > dist[x] + it->second && C[x][it->first] > 0 )
            {
                dist[it->first] = dist[x] + it->second ;
                TT[it->first] = x ;
                if ( !inQueue[it->first] )
                {
                    inQueue[it->first] = 1 ;
                    Q.push(it->first) ;
                }
            }
    }
    if ( dist[destination] == INF )
        return 0 ;
    return 1 ;
}

inline void minim_flow_maxim_cost()
{
    cost = 0 ;
    int x ;
    memset ( inQueue , 0 , sizeof(inQueue) ) ;
    while ( bellman_ford() )
    {
        x = destination ;
        while ( x )
        {
            C[TT[x]][x]-- ;
            C[x][TT[x]]++ ;
            x = TT[x] ;
        }
        cost += dist[destination] ;
    }
}

inline void build_graph( double x )
{
    for ( int i = 1 ; i <= N ; i++ )
    {
        G[0].push_back ( make_pair ( i , 0 ) ) ;
        C[0][i] = 1 ;
        G[N + i].push_back( make_pair ( destination , 0 ) ) ;
        C[N + i][destination] = 1 ;
        for ( int j = 1 ; j <= N ; ++j )
            if ( D[i][j] <= x )
            {
                G[i].push_back ( make_pair ( N + j , D[i][j] ) ) ;
                G[N + j].push_back ( make_pair ( i , -D[i][j] ) ) ;
            }
    }

}

inline bool verify( double x )
{
    for( int i = 1 ; i <= N ; ++ i )
        g[i].clear();
    for( int i = 1 ; i <= N ; ++ i )
        for( int j = 1 ; j <= N ; ++ j )
            if( D[i][j] <= x)
                g[i].push_back(j);
    if( minimum_pairup() == N )
        return 1;
    return 0;
}

inline int bin_search()
{
    int li = 1 ;
    int ls = nr ;
    int mij , sol ;
    while( li <= ls )
    {
        mij = ( li + ls ) >> 1 ;
        if( verify ( distances[mij] ) )
        {
            sol = mij ;
            ls = mij - 1 ;
        }
        else
            li = mij + 1 ;
    }
    return sol ;
}
int main()
{
    fin >> N ;
    destination = 2 * N + 1 ;
    for ( int i = 1 ; i <= N ; i++ )
        fin >> soldier[i].x >> soldier[i].y ;
    for ( int i = 1 ; i <= N ; i++ )
        fin >> shelter[i].x >> shelter[i].y ;
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= N ; j++ )
        {
            D[i][j] = point_distance( soldier[i] , shelter[j] ) ;
            distances[++nr] = D[i][j] ;
        }
    sort ( distances + 1 , distances + nr + 1 ) ;
    int sol = bin_search() ;
    build_graph ( distances[sol] ) ;
    minim_flow_maxim_cost() ;
    fout  << setprecision(5) << fixed << distances[sol] << ' ' << cost << '\n' ;
    return 0 ;
}
