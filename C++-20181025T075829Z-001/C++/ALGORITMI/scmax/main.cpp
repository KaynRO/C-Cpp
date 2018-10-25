#include <fstream>

using namespace std;

ifstream fin ( "scmax.in" ) ;
ofstream fout ( "scmax.out" ) ;

int n , v[100200] , best[100200] , last[100200] , radix , maxim = -1 ;


int main()
{
    fin >> n ;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> v[i] ;
    best[n] = 1 ;
    last[n] = -1 ;
    for ( int i = n - 1 ; i >= 1 ; i-- )
    {
        best[i] = 1 ;
        last[i] = -1 ;
        for ( int j = i + 1 ; j <= n ; j++ )
        {
            if ( v[i] < v[j] && best[i] < best[j] + 1 )
            {
                last[i] = j ;
                best[i] = best[j] + 1 ;
                if ( best[i] > maxim )
                {
                    maxim = best[i] ;
                    radix = i ;
                }
            }
        }
    }
    fout << maxim << '\n' ;
    int start = radix ;
    while ( start != -1 )
    {
        fout << v[start] << ' ' ;
        start = last[start] ;
    }
    return 0;
}
