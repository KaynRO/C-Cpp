#include <fstream>
#include <cstring>
#include <algorithm>
#include <climits>
#define INF LLONG_MIN
#define NMAX 2016

using namespace std ;

ofstream fout ( "maxsubsum.out" ) ;

int N , M ;
int V1[NMAX] , V2[NMAX] ;
long long int max1[NMAX] , max2[NMAX] , sumV1[NMAX] , sumV2[NMAX] ;

inline long long int max ( long long int a , long long int b )
{
    return a > b ? a : b ;
}

void read()
{
    freopen ( "maxsubsum.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &N , &M ) ;
    for ( int i = 1 ; i <= N ; i++ )
        scanf ( "%d" , &V1[i] ) ;
    for ( int i = 1 ; i <= M ; i++ )
        scanf ( "%d" , &V2[i] ) ;
}

void dynamic()
{
    for ( int i = 0 ; i <= N + 1 ; i++ )
        max1[i] = INF ;
    for ( int i = 0 ; i <= M + 1 ; i++ )
        max2[i] = INF ;
    sumV1[1] = V1[1] ;
    sumV1[0] = 0 ;
    sumV2[1] = V2[1] ;
    sumV2[0] = 0 ;
    for ( int i = 2 ; i <= N ; ++i )
        sumV1[i] = sumV1[i-1] + V1[i] ;
    for ( int j = 2 ; j <= M ; ++j )
        sumV2[j] = sumV2[j-1] + V2[j] ;
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = i  ; j <= N ; j++ )
            max1[j - i + 1] = max ( max1[j - i + 1] , sumV1[j] - sumV1[i - 1] ) ;
    for ( int i = 1 ; i <= M ; i++ )
        for ( int j = i  ; j <= M ; j++ )
            max2[j - i + 1] = max ( max2[j - i + 1] , sumV2[j] - sumV2[i - 1] ) ;
}

void solve()
{
    int maximum = max1[1] * 1 + max2[1] * 1 ;
    for ( int L1 = 1 ; L1 <= N ; L1++ )
        for ( int L2 = 1 ; L2 <= M ; L2++ )
            if ( max1[L1] * L2 + max2[L2] * L1 > maximum )
                maximum = max1[L1] * L2 + max2[L2] * L1 ;
    if ( maximum < 0 )
        maximum = 0 ;
    fout << maximum ;
}

int main()
{
    read() ;
    dynamic() ;
    solve() ;
    return 0;
}
