#include <iostream>
#include <algorithm>

using namespace std;

int n , m , matrix[10][10] , lnst , cnst , step ;
int dl[] = { 2 , 2 , -2 , -2 , 1 , 1 , -1 , -1 } , dc[] = { -1 , 1 , -1 , 1 , 2 , -2 , 2 , -2 } ;

int ok ( int ln , int cn )
{
    if ( ln >= 1 && cn >= 1 && ln <= n && cn <= m && matrix[ln][cn] == 0 )
        return 1 ;
    return 0 ;
}

void print()
{
    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= m ; j++ )
            cout << matrix[i][j] << ' ';
        cout << '\n' ;
    }
}

void bkt ( int ln , int cn , int step )
{
    if ( step == n * m )
    {
        print() ;
        exit(0) ;
    }
    else
    {
        for ( int i = 0 ; i < 8 ; i++ )
        {
            if ( ok ( ln + dl[i] , cn + dc[i] ) )
            {
                matrix[ ln + dl[i] ][ cn + dc[i] ] = step + 1 ;
                bkt ( ln + dl[i] , cn + dc[i] , step + 1 ) ;
                matrix[ ln + dl[i] ][ cn + dc[i] ] = 0 ;
            }
        }
    }
}

int main()
{
    cin >> n >> m >> lnst >> cnst ;
    matrix[lnst][cnst] = 1 ;
    bkt ( lnst , cnst , 1 ) ;
    return 0;
}
