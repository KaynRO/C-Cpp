#include <fstream>
#include <queue>

using namespace std;

ifstream fin ( "BFS.in" ) ;
ofstream fout ( "BFS.out" ) ;

int n  , matrix[120][120] , start , vis[120] , m ;

queue <int> Q ;

void read()
{
    fin >> n >> m >> start ;
    int x , y ;
    for ( int i = 1 ; i <= m ; i++ )
    {
        fin >> x >> y ;
        matrix[x][y] = matrix[y][x] = 1 ;
    }

}

void bfs ( int x )
{
    vis[x] = 1 ;
    Q.push(x) ;
    fout << x ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        Q.pop() ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( matrix[k][i] == 1 && !vis[i] )
            {
                vis[i] = 1 ;
                fout << ' ' << i ;
                Q.push( i ) ;
            }
        }
    }

}


int main()
{
    read() ;
    bfs ( start ) ;
    return 0;
}
