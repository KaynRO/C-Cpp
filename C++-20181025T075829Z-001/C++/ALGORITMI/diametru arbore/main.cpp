#include <fstream>
#include <vector>
#include <queue>
#define Nmax 100002
#include <cstring>

using namespace std ;

ifstream fin ( "darb.in" ) ;
ofstream fout ( "darb.out" ) ;

vector<int> M[Nmax] ;
queue<int> Q ;
int n , vis[Nmax] , last , diametru , dist[Nmax] ;

void read()
{
    int x , y ;
    fin >> n ;
    for ( int i = 1 ; i < n ; i++ )
    {
        fin >> x >> y ;
        M[x].push_back(y) ;
        M[y].push_back(x) ;
    }
}

void bfs( int node )
{
    vis[node] = 1 ;
    memset( vis , 0 , sizeof(vis) ) ;
    memset ( dist , 0 , sizeof(dist) ) ;
    dist[node] = 1 ;
    Q.push(node) ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        Q.pop() ;
        for ( vector<int> :: iterator it = M[k].begin() ; it != M[k].end() ; ++it )
        {
            if ( !vis[*it] )
            {
                dist[*it] = dist[k] + 1 ;
                vis[*it] = 1 ;
                Q.push(*it) ;
                diametru = dist[*it] ;
                last = *it ;
            }
        }
    }
}

int main()
{
    read() ;
    bfs(1) ;
    bfs(last) ;
    fout << diametru ;
    return 0;
}
