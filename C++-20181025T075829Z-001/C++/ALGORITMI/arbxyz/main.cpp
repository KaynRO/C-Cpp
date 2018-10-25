#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#define NMAX 100005
using namespace std ;

ofstream fout ( "arbxyz.out" ) ;

int N , X , Y , Z , T , TT[NMAX] , last , lft , rgt ;
vector < int > G[NMAX] ;
queue < int > Q ;
bitset < NMAX > vis ;

void BFS ( int node )
{
    vis.reset() ;
    vis[node] = 1 ;
    Q.push(node) ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        Q.pop() ;
        for ( vector < int > :: iterator it = G[k].begin() ; it != G[k].end() ; ++it )
        {
            if ( !vis[*it] )
            {
                TT[*it] = k ;
                last = *it ;
                vis[*it] = 1 ;
                Q.push(*it) ;
            }
        }
    }
}

void solve ( int N , int X , int Y , int Z )
{
    BFS(1) ;
    lft = last ;
    BFS(last) ;
    rgt = last ;
}

void read()
{
    int x , y ;
    freopen ( "arbxyz.in" , "r" , stdin ) ;
    scanf ( "%d" , &T ) ;
    for ( int i = 1 ; i <= T ; i++ )
    {
        scanf ( "%d %d %d %d" , &N , &X , &Y , &Z ) ;
        for ( int i = 1 ; i <= N - 1 ; i++ )
        {
            scanf ( "%d %d" , &x , &y ) ;
            G[x].push_back(y) ;
            G[y].push_back(x) ;
        }
        solve ( N , X , Y , Z ) ;
    }

}

int main()
{
    read() ;
    return 0 ;
}
