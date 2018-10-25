#include <fstream>
#include <queue>

using namespace std;

ifstream fin ( "componenteconexe1.in" ) ;
ofstream fout ( "componenteconexe1.out" ) ;

int n , matrix[120][120] , vis[120] , comp ;
queue <int> Q ;

void read()
{
    fin >> n ;
    while ( !fin.eof() )
    {
        int x , y ;
        fin >> x >> y ;
        matrix[x][y] = matrix[y][x] = 1 ;
    }
}

void bfs( int x )
{
    comp++ ;
    vis[x] = comp ;
    Q.push(x) ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        Q.pop() ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( matrix[k][i] == 1 && !vis[i] )
            {
                vis[i] = comp ;
                Q.push(i) ;
            }
        }
    }
}

void print()
{
    for ( int i = 2 ; i <= comp  ; i++ )
        for ( int j = 1 ; i <= n ; j++ )
            if ( vis[j] == i )
            {
                fout << 1 << ' ' << j << '\n' ;
                break ;
            }
}
int main()
{
    read() ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( !vis[i] )
            bfs(i) ;
    fout << comp - 1 << '\n' ;
    print() ;
    return 0;
}
