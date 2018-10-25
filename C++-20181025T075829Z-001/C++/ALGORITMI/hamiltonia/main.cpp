#include <fstream>
#include <vector>
#include <iostream>
#include <cstring>
#include <cmath>
#define NMAX 1000

using namespace std ;

ifstream fin ( "hamiltonia.in" ) ;
ofstream fout ( "hamiltonia.out" ) ;

int N, M, vis[NMAX], sol[NMAX] ;
vector < int > G[NMAX] ;

int hamiltonian()
{
    for ( int i = 1 ; i <= N ; i++ )
        if ( G[i].size() < N / 2 )
            return 0 ;
    return 1 ;
}

int fnd ( int i, int k )
{
    for ( auto it : G[i] )
        if ( it == sol[k-1] )
            return 1 ;
    return 0 ;
}

int ok ( int i, int k )
{
    if ( k == 1 )
        return 1 ;
    if ( !vis[i] && fnd(i,k) )
        return 1 ;
}

int bkt( int k )
{
    if ( k == N + 1 )
    {
        fout <<"T" ;
        exit(0) ;
    }
    else
    {
        for ( int i = 1 ; i <= N ; i++ )
            if ( ok( i, k ) )
            {
                vis[i] = 1 ;
                sol[k] = i ;
                bkt( k + 1 ) ;
                vis[i] = 0 ;
            }
    }
}
int main()
{
    int x, y, bani ;
    fin >> N >> M ;
    int cost = 0 ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        fin >> x >> y >> bani ;
        G[x].push_back(y) ;
        G[y].push_back(x) ;
        if ( (int)(sqrt(bani)) * (int)(sqrt(bani)) == bani )
            cost += bani ;
    }
    fout << cost << '\n' ;
    if ( hamiltonian() )
        fout << "T" ;
    else
    {
        bkt(1) ;
        fout << "F" ;
    }
    return 0 ;
}
