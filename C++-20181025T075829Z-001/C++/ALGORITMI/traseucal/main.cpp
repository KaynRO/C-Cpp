#include <fstream>
#include <algorithm>

using namespace std ;

ifstream fin ( "traseucal.in" ) ;
ofstream fout ( "traseucal.out" ) ;

int n , m , matrix[15][15] , okk ;
int dl[] = { 2 , 2 , - 2 , -2 , 1 , 1 , -1 , -1 } , dc[] = { -1 , 1 , 1 , -1 , 2 , -2 , 2 , -2 } ;

int ok ( int x , int y )
{
    if ( x >= 1 && x <= n && y >= 1 && y <= m && matrix[x][y] == 0 )
        return 1 ;
    return 0 ;
}

int bkt ( int ln , int cn , int step )
{
    if ( ln == n && cn == m )
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
        exit(0) ;
        okk = 1 ;
    }
    else
    {
        matrix[ln][cn] = step ;
        for ( int i = 0 ; i < 8 ; i++ )
            if ( ok ( ln + dl[i] , cn + dc[i] ) )
                bkt ( ln + dl[i] , cn + dc[i] , step + 1 ) ;
        matrix[ln][cn] = 0 ;
    }
    return 0 ;
}

int main()
{
    fin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= m ; j++ )
        {
            fin >> matrix[i][j] ;
            if ( matrix[i][j] == 1 )
                matrix[i][j] = -1 ;
        }
    bkt ( 1 , 1 , 1 ) ;
    if ( okk == 0 )
        fout << "0" ;
    return 0 ;
}
