#include <fstream>
#include <bitset>
#include <vector>
#define NMAX 120

using namespace std ;

ifstream fin ( "jaf.in" ) ;
ofstream fout ( "jaf.out" ) ;

int N, M, sediu_hoti, tinta, sediu_politie, timp_jaf, timp_politie, timp_hoti, timp_total, pericol[NMAX], nrpericole ;
bitset < NMAX > vis ;
vector < int > G[NMAX] ;

void DFSH (  int nod, int timp )
{
    vis[nod] = 1 ;
    for ( auto it : G[nod] )
        if ( !vis[it] )
        {
            if ( it == tinta )
            {
                timp_hoti = timp + 1 ;
                return ;
            }
            else
                DFSH ( it, timp + 1 ) ;
        }
}

void DFSP ( int nod, int timp )
{
    vis[nod] = 1 ;
    for ( auto it : G[nod] )
    {
        if ( it == tinta )
            timp_politie = timp + 1 ;
        if ( !vis[it] && !pericol[it] )
        {
            if ( it == tinta )
            {
                timp_politie = timp + 1 ;
                return ;
            }
            else DFSP ( it, timp + 1 ) ;
        }
    }
}

int main()
{
    int x, y ;
    fin >> N >> M ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        fin >> x >> y ;
        G[x].push_back(y) ;
        G[y].push_back(x) ;
    }
    fin >> sediu_hoti >> tinta >> sediu_politie >> timp_jaf ;
    fin >> nrpericole ;
    for ( int i = 1 ; i <= nrpericole ; i++ )
    {
        fin >> x ;
        pericol[x] = 1 ;
    }
    DFSH ( sediu_hoti, 0 ) ;
    vis.reset() ;
    if ( tinta == sediu_politie )
        timp_politie = 0 ;
    else
        DFSP ( sediu_politie, 0 ) ;
    timp_total = timp_hoti * 10 + timp_jaf ;
    timp_politie = timp_politie * 10 ;
    if ( timp_total >= timp_politie )
        fout << "hoti prinsi!!!" ;
    else fout << "paguba!!!" ;
    fout << '\n' << timp_politie ;
    return 0 ;
}
