#include <fstream>
#include <vector>
#include <bitset>

#define NMAX 10010

using namespace std ;

ifstream fin ( "java.in" ) ;
ofstream fout ( "java.out" ) ;

int N, M, E, T, P, st[NMAX], dr[NMAX] ;

vector < int > G[NMAX] ;
bitset < NMAX > vis ;

int pairUP ( int node )
{
    if (vis[node]) return 0 ;
    vis[node] = 1 ;

    for ( vector < int > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
        if ( !dr[*it] )
        {
            st[node] = *it ;
            dr[*it] = node ;
            return 1 ;
        }
    for ( vector < int > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
        if ( pairUP(dr[*it]) )
        {
            st[node] = *it ;
            dr[*it] = node ;
            return 1 ;
        }

    return 0 ;
}

void solve()
{
    int ok = 1;

    while (ok)
    {
        ok = 0 ;
        vis.reset() ;
        for ( int i = 1 ; i <= M ; i++ )
            if ( !st[i] )
                ok |= pairUP(i) ;
    }

    int sol = 0 ;
    for ( int i = 1 ; i <= M ; i++ )
        sol += ( st[i] > 0 ) ;

    fout << sol << '\n';

}

void reset()
{
    for ( int i = 1 ; i <= max(N, M) ; i++ )
    {
        st[i] = 0 ;
        dr[i] = 0 ;
        G[i].clear() ;
    }
}

int main()
{
    fin >> T ;
    for ( int i = 1 ; i <= T; i++ )
    {
        fin >> M >> N >> E ;
        int x, y ;
        for ( int j = 1 ; j <= E ; j++ )
        {
            fin >> x >> y;
            G[x].push_back(y) ;
        }
        solve() ;
        reset() ;
    }

    return 0 ;
}
