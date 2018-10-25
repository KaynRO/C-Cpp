#include <fstream>
#include <vector>
#include <cstring>
#define NMAX 120

using namespace std ;

ofstream fout ( "drumuriprime.out" ) ;
ifstream fin ( "drumuriprime.in" ) ;

int N, M, k, vis[NMAX], NrG, eticheta[NMAX], node, tip ;
vector < int > G[NMAX] ;

int prim ( int x )
{
    if ( x < 2 )
        return 0 ;
    if ( x == 2 )
        return 1 ;
    if ( x % 2 == 0 )
        return 0 ;
    for ( int i = 3 ; i * i <= x ; i += 2 )
        if ( x % i == 0 )
            return 0 ;
    return 1 ;
}

void DFS ( int nod )
{
    vis[nod] = 1 ;
    if ( nod != node && prim(eticheta[nod]) && tip == 0 )
    {
        fout << "1" ;
        tip = 1 ;
    }
    for ( vector < int > :: iterator it = G[nod].begin() ; it != G[nod].end() ; ++it )
        if ( !vis[*it] )
            DFS(*it) ;
}

int main()
{
    int x, y ;
    fin >> NrG ;
    for ( int j = 1 ; j <= NrG ; j++ )
    {
        for ( auto it : G )
            it.clear() ;
        memset ( vis, 0, sizeof(vis) ) ;
        memset ( eticheta, 0, sizeof(eticheta) ) ;
        fin >> N >> M ;
        for ( int i = 1 ; i <= N ; i++ )
            fin >> eticheta[i] ;
        for ( int i = 1 ; i <= M ; i++ )
        {
            fin >> x >> y ;
            G[x].push_back(y) ;
            G[y].push_back(x) ;
        }
        fin >> k ;
        for ( int i = 1 ; i <= N ; i++ )
            if ( eticheta[i] == k )
                node = i ;
        tip = 0 ;
        if ( !prim(k) )
            fout << "-1" ;
        else
        {
            DFS(node) ;
            if ( tip == 0 )
                fout << "0" ;
        }
        fout << '\n' ;
    }
    return 0 ;
}
