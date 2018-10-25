#include <fstream>
#include <queue>
#include <cstring>
using namespace std;

ifstream fin ( "lant1.in" ) ;
ofstream fout ( "lant1.out" ) ;

int way[120] ;
int n , matrix[120][120] , vis[120] , node_start , node_finish , father[120] ,lenght , node_intermediate , lenght1 = 1 , lenght2 = 1 ;
queue <int> Q ;

void read()
{
    fin >> n >> node_start >> node_finish >> node_intermediate  ;
    while ( !fin.eof() )
    {
        int x , y ;
        fin >> x >> y ;
        matrix[x][y] = matrix[y][x] = 1 ;
    }
}

void bfs( int node_start , int node_finish )
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
                father[i] = k ;
                if ( i == node_finish ) break ;

            }
        }
    }
}

void print_first ( int node_start , int node_finish )
{
    int i = node_finish  ;
    way[1] = node_finish ;
    while ( i != node_start )
    {
        way[++lenght1] = father[i] ;
        i = father[i] ;
    }
    memset ( vis , 0 , sizeof(vis) ) ;
    memset ( father , 0 , sizeof(father) ) ;

}

void print_second ( int node_start , int node_finish )
{
  int i = node_finish  ;
  int mij = lenght1 ;
    way[++lenght1] = node_finish ;
    while ( i != node_start )
    {
        if ( father[i] != node_start )
        way[++lenght1] = father[i] ;
        i = father[i] ;
    }
    fout << lenght1  << '\n' ;
    for ( int i = mij ; i >= 1; i-- )
    fout << way[i] << ' ' ;
    for ( int i = lenght1  ; i > mij ; i-- )
    fout << way[i] << ' ' ;
}

int main()
{
    read() ;
    bfs( node_start  , node_intermediate )  ;
    print_first( node_start, node_intermediate ) ;
    bfs ( node_intermediate , node_finish ) ;
    print_second( node_intermediate , node_finish ) ;


    return 0;

}
