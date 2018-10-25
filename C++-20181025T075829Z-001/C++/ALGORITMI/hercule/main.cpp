#include <fstream>

using namespace std;

ifstream fin ( "hercule.in" ) ;
ofstream fout ( "hercule.out" ) ;

int n , m , matrix[15][15] , nrsol , steps , dl[] = { 1 , -1 , 0 , 0 } , dc[] = { 0 , 0 , -1 , 1 } , vis[15][15] ;

int ok ( int ln , int cn , int steps )
{
    if ( ln > 0 && ln < n + 1 && cn > 0 && cn < m + 1 && steps < matrix[ln][cn] && vis[ln][cn] == 0 )
        return 1 ;
    return 0 ;
}

void bkt ( int ln , int cn , int step )
{
    //fout << ln << ' ' << cn << '\n' ;
    if ( ln == n && cn == m )
        nrsol++ ;
    else
    {
        for ( int i = 0 ; i < 4 ; i++ )
            if ( ok ( ln + dl[i] , cn + dc[i] , step + 1 ) )
            {
                vis[ln+dl[i]][cn+dc[i]] = 1 ;
                bkt ( ln + dl[i] , cn + dc[i] , step + 1 ) ;
                vis[ln+dl[i]][cn+dc[i]] = 0 ;
            }
    }
}

int main()
{
    fin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= m ; j++ )
            fin >> matrix[i][j] ;
    vis[1][1] = 1 ;
    bkt ( 1 , 1 , 0 ) ;
    fout << nrsol ;
    return 0;
}
