#include <fstream>
#define NMAX 1000010
using namespace std ;

ifstream fin ( "cmmdc2.in" ) ;
ofstream fout ( "cmmdc2.out" ) ;

int freq[NMAX], value, maxx = -1, T[NMAX], no , N , K ;

void read()
{
    fin >> N >> K ;
    for ( int i = 1 ; i <= N ; i++ )
    {
        fin >> value ;
        freq[value]++ ;
        maxx = max ( maxx, value ) ;
    }
}

void solve()
{
    int d = 0 ;
    for ( int i = maxx ; i >= 2 && d == 0  ; i-- )
        if ( T[i] == 0 )
        {
            for ( int j = i ; j <= maxx ; j += i )
                T[i] += freq[j] ;
            if ( T[i] >= K )
            {
                d = i ;
                break ;
            }
        }
    T[1] = N ;
    if ( d == 0 ) d = 1 ;
    fout << d << '\n' ;
    for ( int i = maxx  ; i >= 1 && no < K  ; i-- )
        if ( freq[i] != 0 && (i % d) == 0 )
            while ( freq[i] != 0  && no < K )
            {
                fout << i << ' ' ;
                no++ ;
                freq[i]-- ;
            }
}

int main()
{
    read() ;
    solve() ;
    return 0;
}
