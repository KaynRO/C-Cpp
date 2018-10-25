#include <fstream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

ifstream fin ( "paznici.in" ) ;
ofstream fout ( "paznici.out" ) ;

struct tip
{
    int ln ;
    int cn ;
} info;
queue <tip> Q ;
int n , m , p , matrix[250][250] , copym[250][250] ;
int dl[] = { 1 , -1 , 0 , 0 } , dc[] = { 0 , 0 , 1 , -1 } ;
struct paznic
{
    int ln ;
    int cn ;
    int range ;
} P[250] ;

void cpy ()
{
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= m ; j++ )
            matrix[i][j] = copym[i][j] ;
}
void cpy2()
{
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= m ; j++ )
            copym[i][j] = matrix[i][j] ;
}
void read()
{
    char c ;
    fin >> n >> m >> p ;
    fin.get() ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= m ; j++ )
        {
            fin >> c ;
            if ( c == '-' )
                matrix[i][j] = 0 ;
            if ( c == '#' )
                matrix[i][j] = -1 ;
        }
        fin.get() ;
    }
    for ( int i = 1 ; i <= p ; i++ )
        fin >> P[i].ln >> P[i].cn >> P[i].range ;
    cpy2() ;

}
int lee ( int x , int y , int range )
{
    matrix[x][y] = 1 ;
    info.ln = x ;
    info.cn = y ;
    Q.push(info) ;
    while ( !Q.empty() )
    {
        int line = Q.front().ln ;
        int colomn = Q.front().cn ;
        Q.pop() ;
        for ( int i = 0 ; i <=3 ; i++ )
        {
            int ln = line + dl[i] ;
            int cn = colomn + dc[i] ;
            if ( ln >= 1 && ln <= n && cn >= 1 && cn <= m && matrix[line][colomn] <= range && matrix[ln][cn] == 0 )
            {
                matrix[ln][cn] = matrix[line][colomn] + 1 ;
                info.ln = ln ;
                info.cn = cn ;
                Q.push(info) ;
            }
        }
    }

}

int main()
{
    int nr = 0 ;
    for ( int i = 1 ; i <= p ; i++ )
        lee ( P[i].ln , P[i].cn , P[i].range ) ;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= m ; j++ )
            if ( matrix[i][j] == 0 )
                nr++ ;
    fout << nr ;
    return 0 ;
}
