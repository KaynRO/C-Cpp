#include <fstream>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>
#define INF ( 1 << 30 )
#define NMAX 100006

using namespace std;

ofstream fout ( "dag.out" ) ;

struct node
{
    int deg ;
    int index ;
} D[NMAX] ;

int N , M , deg[NMAX] , maximum = -1 , vis[NMAX] ;
vector < int > G[NMAX] ;
map < int , vector < int > > Mx ;

void read()
{
    int x , y ;
    freopen ( "dag.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &N , &M ) ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf ( "%d %d" , &x , &y ) ;
        G[x].push_back(y) ;
        G[y].push_back(x) ;
        deg[x]++ ;
        deg[y]++ ;
    }
}

void solve()
{
    for ( int i = 1 ; i <= N ; i++ )
        Mx[deg[i]].push_back(i) ;
    for ( map < int , vector < int > > :: iterator it = Mx.begin() ; it != Mx.end() ; ++it )
    {
        for ( vector < int > :: iterator node = Mx[it->first].begin() ; node != Mx[it->first].end() ; ++node )
        {
            if ( !vis[*node] )
            {
                vis[*node] = 1 ;
                if ( it->first > maximum )
                    maximum = it->first ;
                for ( vector < int > :: iterator iq = G[*node].begin() ; iq != G[*node].end() ; ++iq )
                {
                    Mx[deg[*iq] - 1].push_back(*iq) ;
                    Mx[deg[*iq]].erase ( find ( Mx[deg[*iq]].begin() , Mx[deg[*iq]].end() , *iq ) ) ;
                }
            }
        }
    }
    fout << maximum ;
}

int main()
{
    read() ;
    solve() ;
    return 0;
}
