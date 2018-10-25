#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
#include <bitset>
#define INF ( 1 << 30 )
#define NMAX 100005

using namespace std ;

ofstream fout ( "grafxy.out" ) ;

int N , M , dist[NMAX] , cardX , cardY ;
queue < int > Q ;
vector < int > G[NMAX] , X ;
bitset < NMAX > vis ;

void read()
{
    int x , y , value ;
    freopen ( "grafxy.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &N , &M ) ;
    for ( int i = 1 ; i <= N ; i++ )
        dist[i] = INF ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf ( "%d %d" , &x , &y ) ;
        G[x].push_back(y) ;
        G[y].push_back(x) ;
    }
    scanf ( "%d" , &cardX ) ;
    for ( int i = 1 ; i <= cardX ; i++ )
    {
        scanf ( "%d" , &value ) ;
        X.push_back(value) ;
    }
    scanf ( "%d" , &cardY ) ;
    for ( int i = 1 ; i <= cardY; i++ )
    {
        scanf ( "%d" , &value ) ;
        Q.push(value) ;
        vis[value] = 1 ;
        dist[value] = 0 ;
    }

}

void BFS ()
{
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        Q.pop() ;
        vis[k] = 0 ;
        for ( vector < int > :: iterator it = G[k].begin() ; it != G[k].end() ; ++it )
        {
            if ( dist[k] + 1 > dist[*it] )
                continue ;
            dist[*it] = dist[k] + 1 ;
            if ( !vis[*it] )
            {
                vis[*it] = 1 ;
                Q.push(*it) ;
            }
        }
    }
}
int main()
{
    read() ;
    BFS() ;
    for ( vector < int > :: iterator it = X.begin() ; it != X.end() ; ++it )
        fout << dist[*it] << '\n' ;
    return 0 ;
}
