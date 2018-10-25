#include <fstream>
#include <queue>

using namespace std;

ifstream fin ( "lungimeminima.in" ) ;
ofstream fout ( "lungimeminima.out" ) ;

int n , matrix[120][120] , vis[120] , node_start , father[120] ,lenght ;
queue <int> Q ;

void read()
{
    fin >> n >> node_start >> lenght ;
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
    father[node_start] = node_start ;
    Q.push(node_start) ;
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
                if ( father[i] == 0 )
                father[i] = k ;

            }
        }
    }
}
int calculate ( int x )
{
   int ll = 0 ;
   int i = x ;
   while ( i != node_start )
   {
      ll++ ;
      i = father[i] ;
   }
   if ( lenght == ll ) return 1 ;
   return 0 ;
}
int main()
{
    read() ;
    bfs() ;
        int show[120] ;
        int numbers = 0 ;
        for ( int i = 1 ; i <= n ; i++ )
            if ( father[i] != 0 && calculate(i)  )
            {
                numbers++ ;
                show[numbers] = i ;
            }
        fout << numbers << '\n';
        for ( int i = 1 ; i <= numbers ; i++ )
            fout << show[i] << ' '  ;


    return 0;

}
