#include <bits/stdc++.h>
#define NMAX 120000

using namespace std;


int RMQ[100][NMAX], m , t, n , x , y , k ;

int main()
{
    cin >> m ;
    for( int i = 1 ; i <= m ; i++ )
        cin >> RMQ[0][i] ;

    n = log2(m);
    k = 1;

    for( int i = 1 ; i <= n ; i++ )
    {
        for( int j = 1 ; j <= m - 2 * k + 1 ; j++ )
            RMQ[i][j] = min(RMQ[i - 1][j] , RMQ[i - 1][j + k]);

        k *= 2;
    }

    cin >> t ;
    for( int i = 1 ; i <= t ; i++ )
    {
        cin >> x >> y ;
        x++ ;
        y++ ;
        k = log2(y - x + 1);
        m = pow(2,k);
        cout << min(RMQ[k][x], RMQ[k][y - m + 1]) << '\n';
    }
    return 0;
}
