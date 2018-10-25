#include <fstream>
#include <queue>
#include <cstring>

using namespace std;

ifstream fin ( "lantmaxim.in" ) ;
ofstream fout ( "lantmaxim.out" ) ;

int n , m , matrix[30][30] , node_start , node_finish , sol[30] , solmax[30] , used[30][30]  , st = 0 , maxim = -100 , dist[30] ;
int father[30] ;
queue<int> Q ;

void read()
{
    fin >> n >> m ;
    int x , y ;
    for ( int i = 1 ; i <= m ; i++ )
    {
        fin >> x >> y ;
        matrix[x][y] = matrix[y][x] = 1 ;
    }
    fin >> node_start >> node_finish ;
}

void dfs ( int x )
{
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( matrix[x][i] == 1 && !used[x][i]  )
        {
            dist[i] = dist[x] + 1 ;
            father[i] = x ;
            used[x][i] = used[i][x] = 1 ;
            if ( i == node_finish )
            {
                if ( dist[node_finish] > maxim )
                {
                    st = 0 ;
                    maxim = dist[node_finish] + 1 ;
                    int lenght = dist[node_finish] ;
                    int nod = node_finish ;
                    while ( lenght >= 0 )
                    {
                        solmax[++st] = nod ;
                        fout << nod << ' ' ;
                        nod = father[nod] ;
                        lenght-- ;
                    }
                }
            }
            else
                dfs(i) ;
        }
    }
}

int main()
{
    read() ;
    dfs(node_start) ;
    //for ( int i = maxim ; i >= 1 ; i-- )
      //fout << solmax[i] << ' ' ;
    return 0;
}
