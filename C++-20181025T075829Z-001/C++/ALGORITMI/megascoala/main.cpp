#include <cstdio>
#include <fstream>
#define inf 0x3fffffff
using namespace std ;

ofstream fout ( "megascoala.out" ) ;
int n, a[105][105] , school[150][150] , min_cost , min1 = 0 , min2 = 0  , maxim = -1 ;

void citire()
{
    freopen("megascoala.in","r",stdin);
    int i, j;
    scanf("%d",&n);
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= n ; j++ )
            a[i][j] = inf ;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) scanf("%d",&a[i][j]);
}

void roy_floyd()
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (a[i][k] && a[k][j] && (a[i][j] > a[i][k] + a[k][j] || !a[i][j]) && i != j) a[i][j] = a[i][k] + a[k][j];
}

void solve()
{
    for ( int i = 1 ; i <= n - 1 ; i++ )
        for ( int j = i + 1 ; j <= n ; j++ )
        {
            maxim = -1 ;
            for ( int k = 1 ; k <= n ; k ++ )
                if ( k != i && k != j )
                    if ( min( a[k][i] , a[k][j] ) > maxim )
                        maxim = min ( a[k][i] , a[k][j] ) ;
            school[i][j] = maxim ;
        }
    int minim = inf ;
    for ( int i = 1 ; i <= n - 1 ; i++ )
        for ( int j = i + 1 ; j <= n ; j++ )
            if ( school[i][j] < minim )
            {
                minim = school[i][j] ;
                min1 = i ;
                min2 = j ;
            }
    fout << min1 << ' ' << min2 << ' ' << minim ;
}


int main()
{
    citire();
    roy_floyd();
    solve() ;
    return 0;
}
