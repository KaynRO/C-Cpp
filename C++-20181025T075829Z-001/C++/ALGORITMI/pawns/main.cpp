#include <fstream>
#include <bits/stdc++.h>
#define NMAX 1000

using namespace std ;

ofstream fout ( "pawns.out" ) ;
ifstream fin ( "pawns.in" ) ;

int Sprague[NMAX], postorder[NMAX], start, N, M, result, x, y, value, T ;
vector < int > G[NMAX] ;
bitset < NMAX > vis, frecv ;

void DFS ( int node )
{
    vis[node] = 1 ;
    for ( vector < int > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
        if ( !vis[*it] )
            DFS(*it) ;
    postorder[++start] = node ;
}

void SpragueGrandy()
{
    for ( int i = 2 ; i <= start ; i++ )
    {
        for ( vector < int > :: iterator it = G[postorder[i]].begin() ; it != G[postorder[i]].end() ; ++it )
            frecv[Sprague[*it]] = 1 ;
        for ( int j = 0 ; j <= NMAX ; j++ )
            if ( frecv[j] == 0 )
            {
                Sprague[postorder[i]] = j ;
                break ;
            }
        frecv.reset() ;
    }
}

void read()
{
    fin >> N >> M ;

    for ( int i = 1 ; i <= M ; i++ )
    {
        fin >> x >> y ;
        G[x].push_back(y) ;
    }

    for ( int i = 1 ; i <= N ; i++ )
    {
        if ( vis[i] != 1 )
            DFS(i) ;
    }

    SpragueGrandy() ;

    fin >> T ;

    for ( int i = 1 ; i <= T ; i++ )
    {
        result = 0 ;
        for ( int j = 1 ; j <= N ; j++ )
        {
            fin >> value ;
            if ( value % 2 == 1 )
                result ^= Sprague[j] ;
        }
        if ( result != 0 )
            fout << "1" << '\n' ;
        else
            fout << "0" << '\n' ;
    }
}

int main()
{
    read() ;
    return 0 ;
}
