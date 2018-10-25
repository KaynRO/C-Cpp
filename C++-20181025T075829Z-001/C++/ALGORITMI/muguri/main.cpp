#include <fstream>
#include <vector>
#include <algorithm>
#define NMAX 1010

using namespace std ;

ifstream fin ( "muguri.in" ) ;
ofstream fout ( "muguri.out" ) ;

vector < int > INK, IN[NMAX] ;
vector < int > OUTK, P, OUT[NMAX] ;
int vis[NMAX] ;
int N, M, K ;

int main()
{
    int x, y ;
    int  popularitate = 0 ;
    int nrfriends = 0 ;
    fin >> N >> M >> K ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        fin >> x >> y ;
        IN[y].push_back(x) ;
        OUT[x].push_back(y) ;
        if ( x == K )
            OUTK.push_back(y) ;
        if ( y == K )
            INK.push_back(x) ;
    }
    for ( auto it : INK )
        for ( auto iq : OUTK )
            if ( it == iq )
                nrfriends++ ;
    fout << nrfriends << '\n' ;
    for ( auto it : INK )
        for ( auto iq : OUTK )
            if ( it == iq )
            {
                vis[it] = 1 ;
                P.push_back(it) ;
            }
    for ( auto it : INK )
        if ( vis[it] == 0 )
        {
            popularitate++ ;
            vis[it] = 1 ;
        }
    for ( auto it : OUTK )
        if ( vis[it] == 0 )
        {
            popularitate++ ;
            vis[it] = 1 ;
        }
    sort ( P.begin(), P.end() ) ;
    for ( auto it : P )
        fout << it << ' ' ;
    fout << '\n' ;
    fout << popularitate ;
    return 0 ;
}
