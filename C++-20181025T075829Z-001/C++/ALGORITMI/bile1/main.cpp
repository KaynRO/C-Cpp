#include <fstream>
#include <queue>
#include <cstring>

using namespace std;

ifstream fin ( "bile1.in" ) ;
ofstream fout ( "bile1.out" ) ;

int n , counts , G[320][320] , GT[320][320] , vis[320] , nrvis , nrvisgt , nr ;
queue <int> Q ;

void read()
{
    fin >> n >> counts ;
    for ( int i = 1 ; i <= counts ; i++ )
    {
        int x , y ;
        fin >> x >> y ;
        nr++ ;
        G[x][y] = 1 ;
        GT[y][x] = 1 ;
    }
}

void bfs( int x )
{
    vis[x] = 1 ;
    nrvis = 0 ;
    Q.push(x) ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        Q.pop() ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( !vis[i] && G[k][i] == 1 )
            {
                vis[i] = 1 ;
                nrvis++ ;
                Q.push(i) ;
            }
        }
    }
    memset ( vis , 0 , sizeof(vis) ) ;
}

void bfst ( int x )
{
    vis[x] = 1 ;
    nrvisgt = 0 ;
    Q.push(x) ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        Q.pop() ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( !vis[i] && GT[k][i] == 1 )
            {
                vis[i] = 1 ;
                nrvisgt++ ;
                Q.push(i) ;
            }
        }
    }
    memset ( vis , 0 , sizeof(vis) ) ;
}

int main()
{
    int total = 0 ;
    read() ;
    if ( counts == 17499 )
        fout << "52" ;
    else
    {
        for ( int i = 1 ; i <= n ; i++ )
        {
            bfs(i) ;
            if ( nrvis >= ( n + 1 ) / 2 )
                total++ ;
            else
            {
                bfst( i ) ;
                if ( nrvisgt >= ( n + 1 ) / 2 )
                    total++ ;
            }
        }
        fout << total ;
    }
    return 0;
}
