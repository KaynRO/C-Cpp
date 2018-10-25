#include <fstream>
#include <algorithm>
#include <cstring>
#define mod  100003
using namespace std;

ofstream fout ( "2sah.out" ) ;

long long n , k , t0 , t1 , t2 , t3 ;
int test ;

void read()
{
    freopen ( "2sah.in" , "r" , stdin ) ;
    scanf ( "%d" , &test ) ;
    scanf ( "%lld %lld" , &n , &k ) ;
}

void solve_testI()
{
    long long x = 3 ;
    long long answer = 1 ;
    k-- ;
    for ( unsigned int i = 0 ; ( 1 << i ) <= k ; ++i )
    {
        if ( ( ( 1 << i ) & k ) > 0 )
            answer = ( answer * x ) % mod ;
        x = ( x * x ) % mod ;
    }
    fout << answer ;
}

int solve_testII()
{
    k = n + 2 - k ;
    if( k < 3 )
    {
        fout << 1 ;
        return 0 ;
    }
    t1 = t2 = 1 ;
    for( int i = 3 ; i <= k ; i++ )
    {
        t3 = ( t0 + t1 + t2 ) % mod ;
        t0 = t1 ;
        t1 = t2 ;
        t2 = t3 ;
    }
    fout << t3 ;
    return 0 ;
}
int main()
{
    read() ;
    if ( test == 1 )
        solve_testI() ;
    else solve_testII() ;

    return 0;
}
