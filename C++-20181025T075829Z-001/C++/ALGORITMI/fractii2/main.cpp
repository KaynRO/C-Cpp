#include <fstream>
#include <algorithm>
#define MOD 100003
using namespace std;

ifstream fin ( "fractii2.in" ) ;
ofstream fout ( "fractii2.out" ) ;

int test , n , sol[2010][1010] , m , lft , rht , from ;

void solve_testI()
{
    for ( int i = 1 ; i <= n - 1 ; ++i )
        fout << i << ' ' ;
    fout << n - 1 ;
}

void solve_testII()
{
    sol[2][1] = 1 ;
    for( int i = 3 ; i <=n ; i++ )
    {
        m = i / 2 ;
        for( int j = 1 ; j <= m ; j++ )
        {
            from = i - j ;
            lft = ( j + 1 ) / 2 - 1 ;
            rht = ( i - j ) / 2 ;
            sol[i][j] = sol[i][j-1] + sol[i-j][rht] - sol[i-j][lft] ;
            if ( sol[i][j] < 0 )
                sol[i][j] += MOD ;
            if ( sol[i][j] >= MOD )
                sol[i][j] -= MOD ;
        }
    }
    fout << sol[n][n/2] ;
}

int main()
{
    fin >> test >> n ;
    if ( test == 1 )
        solve_testI() ;
    else solve_testII() ;
    return 0;
}
