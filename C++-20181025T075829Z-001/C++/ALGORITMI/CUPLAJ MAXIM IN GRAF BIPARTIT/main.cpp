#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <bitset>
#define MAXN 10010

using namespace std ;

ifstream fin ( "cuplaj.in" ) ;
ofstream fout ( "cuplaj.out" ) ;

int N , M , E , draw , sol , st[MAXN] , dr[MAXN] ;
vector<int> G[MAXN] ;
bitset < MAXN > vis ;
int  TT[MAXN] , C[MAXN] ;

int pairup ( int node )
{
    if ( vis[node] ) return 0 ;
    vis[node] = 1 ;
    for ( vector < int > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
        if ( !st[*it] || pairup(st[*it]) )
        {
            st[*it] = node ;
            dr[node] = *it ;
            return 1 ;
        }
    return 0 ;
}

void cuplaj()
{
    memset ( st , 0 , sizeof(st) ) ;
    memset ( dr , 0 , sizeof(dr) ) ;
    int ok = 1 ;
    while (ok)
    {
        vis.reset() ;
        ok = 0 ;
        for ( int i = 1 ; i <= N ; i++ )
            if ( !dr[i] )
                ok |= pairup(i) ;
    }

}

void read()
{
    fin >> N >> M >> E ;
    int x , y ;
    for ( int i = 1 ; i <= E ; i++ )
    {
        fin >> x >> y ;
        G[x].push_back(y) ;
    }
}

void print()
{
    for ( int i = 1 ; i <= N ; i++ )
        sol += ( dr[i] > 0 ) ;
    fout << sol << '\n' ;
    for ( int i = 1 ; i <= N ; i++ )
        if ( dr[i] > 0 )
            fout << i << ' ' << dr[i] << '\n' ;
}

int main()
{
    read() ;
    cuplaj() ;
    print() ;
    return 0;
}
