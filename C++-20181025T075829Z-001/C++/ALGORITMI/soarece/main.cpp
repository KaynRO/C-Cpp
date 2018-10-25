#include <fstream>
#include <algorithm>

using namespace std ;

ifstream fin ( "soarece.in" ) ;
ofstream fout ( "soarece.out" ) ;
int n , m , lnst , cnst , lnfi , cnfi , matrix[15][15] , sol[15][15] , vis[15][15] , nrsol ;

int ok ( int x , int y )
{
    if ( x >= 1 && x <= n && y >= 1 && y <= m && matrix[x][y] == 0 )
        return 1 ;
    return 0 ;
}

int bkt ( int ln , int cn )
{
    if ( ln == lnfi && cn == cnfi )
        nrsol++ ;
    else
    {
        matrix[ln][cn] = 2 ;
        if ( ok ( ln + 1 , cn ) )
            bkt( ln + 1 , cn ) ;
        if ( ok ( ln - 1 , cn ) )
            bkt ( ln - 1 , cn ) ;
        if ( ok ( ln , cn + 1 ) )
            bkt ( ln , cn + 1 ) ;
        if ( ok ( ln , cn - 1 ) )
            bkt ( ln , cn - 1 ) ;
        matrix[ln][cn] = 0 ;
    }
    return 0 ;
}

int main()
{
    fin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= m ; j++ )
            fin >> matrix[i][j] ;
    fin >> lnst >> cnst >> lnfi >> cnfi ;
    bkt ( lnst , cnst ) ;
    fout << nrsol ;
    return 0 ;
}
