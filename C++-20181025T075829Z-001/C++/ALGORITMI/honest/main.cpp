#include <fstream>
#include <queue>
#include <vector>
#include <cstdio>
#include <utility>
#include <cstring>
using namespace std ;

ofstream fout ( "honest.out" ) ;

vector < pair < int , int > > G[1010] ;
int n , m ,  vis[1010] , gr[1010] , topological[1010] , st , how[1010] ;

void read()
{
    freopen ( "honest.in" , "r" , stdin) ;
    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; i++ )
    {
        int x , y ;
        char c ;
        scanf ( "%d %c %d" , &x , &c , &y ) ;
        if ( c == 'c' )
            G[x].push_back( make_pair ( y , 1 ) ) ;
        else G[x].push_back ( make_pair ( y , -1 ) ) ;
    }

}

void dfs ( int x )
{
    vis[x] = 1 ;
    for ( int i = 0  ; i < G[x].size() ; i++ )
        if ( !vis[G[x][i].first]  )
            dfs(G[x][i].first) ;
    topological[++st] = x ;
}

void sort_top()
{
    for ( int i = 1 ; i <= n ; i++ )
        if ( !vis[i] )
            dfs(i) ;
}

int dfs_kind( int x )
{
    vis[x] = 1 ;
    for ( int i = 0 ; i < G[x].size() ; i++ )
    {
        if ( !vis[G[x][i].first] )
        {
            if ( how[x] == 1 && !how[G[x][i].first] )
                how[G[x][i].first] = G[x][i].second  ;
            if ( how[x] == -1 && !how[G[x][i].first] )
                how[G[x][i].first] = -G[x][i].second ;
            if ( how[x] == 0 && G[x][i].second != how[G[x][i].first] && !how[G[x][i].first])
                how[x] = -1 ;
            if ( how[x] == 0 && G[x][i].second == how[G[x][i].first] && !how[G[x][i].first])
                how[x] = 1 ;
            dfs_kind ( G[x][i].first ) ;
        }
    }
}
int main()
{
    read() ;
    sort_top() ;
    for ( int i = 1 ; i <= st ; i++ )
        fout << topological[i] << ' ' ;
    memset ( vis , 0 , sizeof (vis) ) ;
    how[topological[st]] = 1 ;
    dfs_kind ( topological[st] ) ;
    int ok = 0 , nr = 0 ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( how[i] == -1 )
            nr++ ;
    if ( nr > n/2 ) ok = 1 ;
    if ( ok == 0 )
    {
        for ( int i = 1 ; i <= n ; i++ )
            if ( how[i] == -1 ) fout << "0" << '\n' ;
            else
                fout << how[i] << '\n'  ;
    }
    else
    {
        for ( int i = 1 ; i <= n ; i++ )
            if ( how[i] == -1 ) fout << "1" << '\n' ;
            else
                fout << "0" << '\n'  ;
    }
    return 0 ;
}
