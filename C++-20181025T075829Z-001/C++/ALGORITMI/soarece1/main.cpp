#include <fstream>
#include <algorithm>

using namespace std ;

ifstream fin ( "soarece1.in" ) ;
ofstream fout ( "soarece1.out" ) ;
int n , m , lnst , cnst , lnfi , cnfi , matrix[15][15] , sol[15][15] , vis[15][15] , nrsol , okk ;

int ok ( int x , int y )
{
    if ( x >= 1 && x <= n && y >= 1 && y <= m && matrix[x][y] == 0 )
        return 1 ;
    return 0 ;
}

int bkt ( int ln , int cn , int step )
{
    if ( ln == lnfi && cn == cnfi && okk == 0 )
    {
        matrix[ln][cn] = step ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            for ( int j = 1 ; j <= m ; j++ )
                if ( matrix[i][j] == - 1 )
                    fout << "0" << ' ' ;
                else fout << matrix[i][j] << ' ' ;
            fout << '\n' ;
        }
        okk = 1 ;
    }
    else
    {
        matrix[ln][cn] = step ;
        if ( ok ( ln + 1 , cn ) )
            bkt( ln + 1 , cn , step + 1 ) ;
        if ( ok ( ln - 1 , cn ) )
            bkt ( ln - 1 , cn , step + 1 ) ;
        if ( ok ( ln , cn + 1 ) )
            bkt ( ln , cn + 1 , step + 1 ) ;
        if ( ok ( ln , cn - 1 ) )
            bkt ( ln , cn - 1 , step + 1 ) ;
        matrix[ln][cn] = 0 ;
    }
    return 0 ;
}

int main()
{
    fin >> n >> m ;
    char c ;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= m ; j++ )
        {
            fin >> c ;
            if ( c == 'S' )
            {
                lnst = i ;
                cnst = j ;
            }
            if ( c == 'B' )
            {
                lnfi = i ;
                cnfi = j ;
            }
            if ( c == '#' )
                matrix[i][j] = -1 ;
        }
    fin >> lnst >> cnst >> lnfi >> cnfi ;
    bkt ( lnst , cnst , 1 ) ;
    if ( okk == 0 )
        for ( int i = 1 ; i <= n ; i++ )
        {
            for ( int j = 1 ; j <= m ; j++ )
                fout << "0" << ' ' ;
            fout << '\n' ;
        }
    return 0 ;
}
