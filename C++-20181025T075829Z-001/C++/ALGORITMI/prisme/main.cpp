#include <fstream>
#include <queue>

using namespace std;

ifstream fin ( "prisme.in" ) ;
ofstream fout ( "prisme.out" ) ;

int n , matrix[10][10] , sol[7] , vis[7] ;
queue <int> Q ;
struct triangle
{
    int a ;
    int b ;
    int c ;
} T[8] ;

void read()
{
    for ( int i = 1 ; i <= 6 ; i++ )
        fin >> T[i].a >> T[i].b >> T[i].c ;
}

void create_matrix()
{
    for ( int i = 1 ; i <= 6 ; i++ )
        for ( int j = i + 1 ; j <= 6 ; j++ )
            if ( T[i].a == T[j].b  || T[i].a == T[j].a || T[i].a == T[j].c || T[i].b == T[j].b  || T[i].b == T[j].a || T[i].b == T[j].c || T[i].c == T[j].b  || T[i].c == T[j].a || T[i].c == T[j].c )
                matrix[i][j] = 1 ;
}

int verify_cicle( int i , int j )
{
    if ( T[i].a == T[j].b  || T[i].a == T[j].a || T[i].a == T[j].c || T[i].b == T[j].b  || T[i].b == T[j].a || T[i].b == T[j].c || T[i].c == T[j].b  || T[i].c == T[j].a || T[i].c == T[j].c )
        return 1 ;
    return 0 ;
}

void bfs()
{
    vis[1] = 1 ;
    int st = 0 ;
    Q.push(1) ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        sol[++st] = k ;
        Q.pop() ;
        for ( int i = 1 ; i <= 6 ; i++ )
        {
            if ( !vis[i] && matrix[k][i] == 1 )
            {
                vis[i] = 1 ;
                Q.push(i) ;
            }
        }
    }
    if ( verify_cicle( 1 , st ) )
    for ( int i = 1 ; i <= st ; i++ )
        fout << sol[i] << ' ' ;

}


int main()
{
    read() ;
    create_matrix() ;
    bfs() ;
    return 0;
}
