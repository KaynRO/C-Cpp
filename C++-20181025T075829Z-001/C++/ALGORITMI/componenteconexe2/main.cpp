#include <fstream>
#include <queue>

using namespace std;

ifstream fin ( "componenteconexe2.in" ) ;
ofstream fout ( "componenteconexe2.out" ) ;

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

int  solve()
{
   int out = 0 ;
    for ( int i = 1 ; i <= comp  ; i++ )
      {
        int leg = 0 ;
        int nrv = 0 ;
        for ( int j = 1 ; j <= n ; j++ )
            if ( vis[j] == i )
            {
                 nrv++ ;
                 for ( int k = 1 ;  k <= n ; k ++ )
                 if ( matrix[k][j] == 1 )
                 leg++ ;
             }
         out = out + ( leg - ( nrv -1 ) * 2  ) / 2 ;
      }
      return out ;
}

int main()
{
    read() ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( !vis[i] )
            bfs(i) ;

    fout << solve() ;
    return 0;
}
