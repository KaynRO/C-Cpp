#include <iostream>
#include <algorithm>
#define NMAX 300010

using namespace std ;

long long N, K, sum[NMAX], V[NMAX], sumK[NMAX] ;
long long max1 = -1, max2 = -1, pos1, pos2 , val1 , val2 ;

int module( int x )
{
    return x >= 0 ? x : -x ;
}

int main()
{
    cin >> N >> K ;
    for ( int i = 1 ; i <= N ; i++ )
        cin >> V[i] ;

    sum[1] = V[1] ;

    for ( int i = 2 ; i <= N ; i++ )
        sum[i] = sum[i - 1] + V[i] ;

    for ( int i = K ; i <= N ; i++ )
        sumK[i] = sum[i] - sum[i - K + 1] + V[i - K + 1] ;

    for ( int i = K ; i <= N ; i++ )
        if ( sumK[i] > max1 && ( module(i - pos2) >= K && pos2 == 0 ) )
            max2 = max1, pos2 = pos1,max1 = sumK[i], pos1 = i ;
        else if ( sumK[i] > max1 && ( module(i - pos1 ) >= K || pos1 == 0 ) )
            max2 = max1 , pos2 = pos1 , max1 = sumK[i] , pos1 = i ;
        else if ( sumK[i] == max1 && ( module(pos1 - i) >= K || pos1 == 0 ) )
            max2 = sumK[i], pos2 = i ;
        else if ( sumK[i] < max1 && sumK[i] > max2 && sumK[i] &&  ( module(pos1 - i) >= K || pos1 == 0 ) )
            max2 = sumK[i], pos2 = i ;

    for ( int i = K ; i <= N  ; i++ )
        if ( sumK[i] == max1 )
        {
            val1 = i - K + 1 ;
            pos2 = i ;
            break ;
        }
    for ( int i = pos2 + K ; i <= N ; i++ )
        if ( sumK[i] == max2 )
        {
            val2 = i - K + 1 ;
            break ;
        }
    if ( val1 >= val2 ) cout << val1 << ' ' << val2 ;
    else cout << val1 << ' ' << val2 ;
    return 0;
}
