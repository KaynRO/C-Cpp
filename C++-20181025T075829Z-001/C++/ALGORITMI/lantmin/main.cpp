#include <fstream>
#include <queue>

using namespace std;

ifstream fin ( "lantminim.in" ) ;
ofstream fout ( "lantminim.out" ) ;

int n , matrix[120][120] , vis[120] , node_start , node_finish , father[120] ;
queue <int> Q ;

void read()
{
    fin >> n >> node_start >> node_finish ;
    while ( !fin.eof() )
    {
        int x , y ;
        fin >> x >> y ;
        matrix[x][y] = matrix[y][x] = 1 ;
    }
}

void bfs()
{
    vis[node_start] = 1 ;
    Q.push(node_start) ;
    father[node_start] = node_start ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        Q.pop() ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( matrix[k][i] == 1 && !vis[i] )
            {
                vis[i] = 1 ;
                Q.push(i) ;
                father[i] = k ;
                if ( i == node_finish )
                break ;

            }
        }
    }
}

void print()
{
    int i = node_finish ;
    int way[120] ;
        way[1] = node_finish ;
    int k = 1 ;
    while ( i != node_start )
    {
        way[++k] = father[i] ;
        i = father[i] ;
    }
    fout << k << '\n' ;
    for ( int i = k ; i >= 1  ; i-- )
    fout << way[i] << ' ' ;
}
int main()
{
    read() ;
    bfs() ;
    print() ;
    return 0;
}
