#include <fstream>
#include <queue>

using namespace std;

ifstream fin ( "dmax.in" ) ;
ofstream fout ( "dmax.out" ) ;

int n , matrix[120][120] , vis[120] , father[120] , lenght , m , maxim = -1 ;
queue <int> Q ;

void read()
{
    fin >> n >> m ;
    for ( int i = 1 ; i <= m ; i++ )
    {
        int x , y ;
        fin >> x >> y ;
        matrix[x][y] = matrix[y][x] = 1 ;
    }
}

void bfs()
{
    vis[1] = 1 ;
    Q.push(1) ;
    father[1] = 1;
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

            }
        }
    }
}

int calculate ( int x )
{
   int lenght = 0 ;
   int i = x ;
   while ( i != 1 )
   {
      lenght++ ;
      i = father[i] ;
   }
   return lenght ;
}
int main()
{
    read() ;
    int nod_maxim ;
    bfs() ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( father[i] != 0 )
        {
            if ( calculate(i) > maxim )
            {
                maxim = calculate(i) ;
                nod_maxim = i ;
            }
        }
    }
    fout << nod_maxim ;
    return 0;
}
