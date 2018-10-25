#include <fstream>
#include <queue>
#include <vector>
#include <bitset>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#define NMAX 1005
#define MMAX 10005
#define pb push_back

using namespace std;

ifstream fin ( "critice.in" ) ;
ofstream fout ( "critice.out" ) ;

int N , M , C[NMAX][NMAX] , F[NMAX][NMAX] , TT[NMAX] , valor[NMAX] ;
bitset <NMAX> vis ;
queue < int > Q ;
vector < int > G[NMAX] , Sol ;
struct edge
{
    int x ;
    int y ;
} E[MMAX] ;

void read()
{
    fin >> N >> M ;
    int x , y , z ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        fin >> x >> y >> z ;
        G[x].pb(y) ;
        G[y].pb(x) ;
        C[x][y] = C[y][x] = z ;
        E[i].x = x , E[i].y = y ;
    }
}

int BFS()
{
    vis.reset() ;
    vis[1] = 1 ;
    Q.push(1) ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        Q.pop() ;
        for ( vector < int > :: iterator it = G[k].begin() ; it != G[k].end() ; ++it )
            if ( !vis[*it] && F[k][*it] != C[k][*it] )
            {
                TT[*it] = k ;
                vis[*it] = 1 ;
                Q.push(*it) ;
            }
    }
    return vis[N] ;
}

void DFS ( int node , int value )
{
    valor[node] = value ;
    for ( vector < int > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
        if ( !valor[*it] && F[node][*it] < C[node][*it] )
            DFS ( *it , value ) ;
}

void maxflow()
{
    int minim ;
    while ( BFS() )
    {
        for ( vector < int > :: iterator it = G[N].begin() ; it != G[N].end() ; ++it )
            if ( F[*it][N] < C[*it][N] && vis[*it] == 1 )
            {
                int node = *it ;
                minim = C[node][N] - F[node][N] ;
                while ( TT[node] != 0 )
                {
                    minim = min ( minim , C[TT[node]][node] - F[TT[node]][node] ) ;
                    node = TT[node] ;
                }
                node = *it ;
                F[node][N] += minim ;
                F[N][node] -= minim ;
                while ( TT[node] != 0 )
                {
                    F[TT[node]][node] += minim ;
                    F[node][TT[node]] -= minim ;
                    node = TT[node] ;
                }
            }
    }
}

int main()
{
    read() ;
    maxflow() ;
    DFS ( 1 , 1 ) ;
    DFS ( N , 2 ) ;
    for ( int i = 1 ; i <= M ; i++ )
        if ( abs ( F[E[i].x][E[i].y] ) == C[E[i].x][E[i].y ] && ( valor[E[i].x] + valor[E[i].y] == 3 ) )
            Sol.pb (i) ;
    fout << Sol.size() << '\n' ;
    for ( vector < int > :: iterator it = Sol.begin() ; it != Sol.end() ; ++it )
        fout << *it << '\n' ;
    return 0;
}
