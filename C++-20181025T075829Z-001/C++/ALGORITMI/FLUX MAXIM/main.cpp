#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <bitset>
#include <queue>
#define pb push_back
#define NMAX 1005

using namespace std ;

ifstream fin ( "maxflow.in" ) ;
ofstream fout ( "maxflow.out" ) ;

int N , M , C[NMAX][NMAX] , Flow[NMAX][NMAX] , Father[NMAX] ;
vector < int > G[NMAX] ;
queue < int > Q ;
bitset < NMAX > vis ;

void read()
{
    fin >> N >> M ;
    int x , y , value ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        fin >> x >> y >> value ;
        G[x].pb(y) ;
        G[y].pb(x) ;
        C[x][y] = value ;
    }
}

int BFS()
{
    vis.reset() ;
    Q.push(1) ;
    vis[1] = 1 ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        Q.pop() ;
        for ( vector<int> :: iterator it = G[k].begin() ; it != G[k].end() ; ++it )
            if ( !vis[*it] && C[k][*it] > Flow[k][*it] )
            {
                Q.push(*it) ;
                vis[*it] = 1 ;
                Father[*it] = k ;
            }
    }
    return vis[N] ;
}


int main()
{
    read() ;
    int flow = 0 , minim = 0 ;
    while ( BFS() )
    {
        for ( vector<int> :: iterator it = G[N].begin() ; it != G[N].end() ; ++it )
            if ( Flow[*it][N] < C[*it][N] && vis[*it] == 1 )
            {
                int node = *it ;
                minim = C[node][N] - Flow[node][N] ;
                while ( Father[node] != 0 )
                {
                    minim = min ( minim , C[Father[node]][node] - Flow[Father[node]][node] ) ;
                    node = Father[node] ;
                }
                flow += minim ;
                node = *it ;
                Flow[node][N] += minim ;
                Flow[N][node] -= minim ;
                while ( Father[node] != 0 )
                {
                    Flow[Father[node]][node] += minim ;
                    Flow[node][Father[node]] -= minim ;
                    node = Father[node] ;
                }
            }
    }
    fout << flow << '\n' ;
    return 0;
}
