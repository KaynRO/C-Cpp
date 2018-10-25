#include <fstream>
#include <queue>

using namespace std;

ifstream fin ( "bila.in" ) ;
ofstream fout ( "bila.out" ) ;

int n , m , steps = 1 , maxim = -1 , matrix[25][25] , lnst , cnst ;
int dl[] = { 1 , -1 , 0 , 0 } , dc[] = { 0 , 0 , -1 , 1 } ;

int ok ( int ln , int cn )
{
    if ( ln >= 1 && ln <= n && cn >= 1 && cn <= m )
        return 1 ;
    return 0 ;
}

void bkt ( int ln , int cn )
{
    if ( ln == 1 || ln == n || cn == 1 || cn == m )
    {
        if ( steps > maxim )
            maxim = steps ;
    }
    else
    {
        for ( int i = 0 ; i < 4 ; i++ )
            if ( ok ( ln + dl[i] , cn + dc[i] ) && matrix[ln+dl[i]][cn+dc[i]] < matrix[ln][cn] )
            {
                steps++ ;
                bkt( ln + dl[i] , cn + dc[i] ) ;
                steps-- ;
            }
    }

}
int main()
{
    fin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= m ; j++ )
            fin >> matrix[i][j] ;
    fin >> lnst >> cnst ;
    bkt ( lnst , cnst ) ;
    if ( maxim == -1 )
        fout << "0"  ;
    else
        fout << maxim  ;
    return 0;
}
