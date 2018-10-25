#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#define NMAX 50010

using namespace std ;

ofstream fout ( "autobuze.out" ) ;

struct node
{
    int pos ;
    int value ;
};

int N, TT[NMAX], Rank[NMAX], nr, V[NMAX] , maxx ;
map < int, int > M ;
map < int, int > :: iterator it ;

int father( int node )
{
    while ( node != TT[node] )
        node = TT[node] ;
    return node ;
}

void Union ( int x, int y )
{
    if ( Rank[x] > Rank[y] )
        TT[y] = x ;
    else TT[x] = y ;
    if ( Rank[x] == Rank[y] )
        Rank[y]++ ;
}

void read()
{
    freopen ( "autobuze.in", "r", stdin ) ;
    scanf ( "%d", &N ) ;
    for ( int i = 1 ; i <= N ; i++ )
    {
        scanf("%d", &V[i]);
        M[V[i]] = i;
        if ( V[i] > maxx )
            maxx = V[i] ;
    }
    for ( int i = 1 ; i <= N ; i++ )
        TT[i] = i ;
}

void solve()
{
    for ( int i = 1 ; i <= N ; i++ )
        if ( maxx / V[i] < N )
            for ( int j = 2 * V[i] ; j <= maxx ; j += V[i] )
            {
                it = M.find(j) ;
                if ( it != M.end() )
                    Union( father(i), father(it->second) ) ;
            }
        else
        {
            for ( int k = 1 ; k <= N ; k++ )
                if ( V[k] % V[i] == 0 || V[i] % V[k] == 0 )
                    Union( father(i), father(k) ) ;
        }
}

void print()
{
    for ( int i = 1 ; i <= N ; i++ )
        if ( TT[i] == i )
            nr++ ;
    fout << nr ;
}

int main()
{
    read() ;
    solve() ;
    print() ;
    return 0 ;
}
