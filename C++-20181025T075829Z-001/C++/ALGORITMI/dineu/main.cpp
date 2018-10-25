#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin( "dineu.in" ) ;
ofstream fout ( "dineu.out" ) ;

int n , m , pers[25][25] , sol[25] , solmax[25] , maxim , k ;
int matrix[25][25] ;

int read()
{
    int nr , x ;
    fin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        fin >> nr ;
        for ( int j = 1 ; j <= nr ; j++ )
        {
            fin >> x ;
            pers[i][x] = 1 ;
        }
    }
}

void create()
{
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= n ; j++ )
            for ( int k = 1 ; k <= m ; k++ )
                if ( pers[i][k] == 1 && pers[j][k] == 1 && i != j )
                    matrix[i][j] = 1 ;
}

int ok( int x , int p )
{
    for ( int i = 1 ; i <= x ; i++ )
        if ( matrix[p][sol[i]] != 1 )
            return 0 ;
    return 1 ;
}

int before(int x )
{
    for ( int i = 1 ; i <= x ; i++ )
        if ( sol[i] != solmax[i] )
            return 0 ;
    return 1 ;
}
int do_verify(int k)
{
    int ok = 1 ;
    for ( int i = 1 ; i <= k ; i++ )
        if ( sol[i] < solmax[i] && before(i) )
            ok = 0 ;
    if ( ok == 0 )
        for ( int i = 1 ; i <= k ; i++ )
            solmax[i] = sol[i] ;
}
int solve()
{
    for ( int i = 1 ; i <= n ; i++ )
    {
        sol[1] = i ;
        k = 1 ;
        for ( int j = 1 ; j <= n ; j++ )
        {
            if ( ok( k , j ) )
                sol[++k] = j ;
        }

        if ( k > maxim )
        {
            maxim = k ;
            for ( int i = 1 ; i <= k ; i++ )
                solmax[i] = sol[i] ;
        }
        if ( k == maxim )
            do_verify(k) ;
    }
}

void print()
{
    sort( solmax + 1 , solmax + maxim + 1 ) ;
    fout << maxim << '\n' ;
    for ( int i = 1 ; i <= maxim ; i++ )
        fout << solmax[i] << ' ' ;
}
int main()
{
    read() ;
    create() ;
    solve() ;
    print() ;
    return 0;
}
