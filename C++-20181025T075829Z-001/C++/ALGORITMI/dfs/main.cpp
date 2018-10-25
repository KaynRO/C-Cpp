#include <fstream>

using namespace std;

ifstream fin ( "dfs.in" ) ;
ofstream fout ( "dfs.out" ) ;

int n , m , x , matrix[120][120] , vis[120] ;

void read()
{
   fin >> n >> m >> x ;
   for ( int i = 1 ; i <= m ; i++ )
   {
     int x , y ;
     fin >> x >> y ;
     matrix[x][y] = matrix[y][x] = 1 ;
   }
}

void dfs( int x)
{
   vis[x] = 1 ;
   fout << x << ' ' ;
   for ( int i = 1 ; i <= n ; i++ )
   {
      if ( !vis[i] && matrix[x][i] == 1 )
        dfs(i);
   }
}
int main()
{
    read() ;
    dfs(x) ;
    return 0;
}
