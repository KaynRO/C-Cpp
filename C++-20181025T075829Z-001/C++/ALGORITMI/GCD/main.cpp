#include <fstream>
#include <cstdio>
#include <algorithm>

using namespace std ;

ofstream fout ( "gcd.out" ) ;

long long T , N , M , MOD ;

long long compute ( long long value, long long MOD )
{
    long long ret = 1, divide = 2 ;
    while (value)
    {
        if ( value % 2 )
            ret = (ret * divide) % MOD, value-- ;
        divide = ( divide * divide ) % MOD ;
        divide %= MOD ;
        value /= 2 ;
    }
    return ret ;
}

void solve ( long long N, long long M, long long MOD )
{
    long long gcd = __gcd(N, M) ;
    long long answer = compute ( gcd, MOD ) - 1 ;
    if ( answer < 0 ) answer += MOD ;
    answer %= MOD ;
    fout << answer << '\n' ;
}

void read()
{
    freopen ( "gcd.in", "r", stdin ) ;
    scanf ( "%lld", &T ) ;
    for ( long long i = 1 ; i <= T ; i++ )
    {
        scanf ( "%lld %lld %lld", &N, &M, &MOD ) ;
        solve(N, M, MOD) ;
    }
}

int main()
{
    read() ;
    return 0;
}
