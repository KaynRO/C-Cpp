#include <bits/stdc++.h>
#define NMAX 50100
#define MMAX 200100

using namespace std ;

ofstream fout ( "fotbal2.out" ) ;

int N, M, start, vis[NMAX], beg, Which[NMAX], Order[NMAX], SOL[NMAX] , out[MMAX] ;
vector < pair < int, int > > TT[NMAX] ;
vector < int > Path ;
stack < int > S ;

void read()
{
    int x, y ;
    freopen ( "fotbal2.in", "r", stdin ) ;
    scanf ( "%d %d", &N, &M ) ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        if ( i == 1 ) start = x ;
        scanf ( "%d %d", &x, &y ) ;
        TT[x].push_back( make_pair ( y, i ) ) ;
        TT[y].push_back( make_pair ( x, i ) ) ;
    }
}

void add_node()
{
    int new_node = N + 1 ;
    for ( int i = 1 ; i <= N ; i++ )
        if ( TT[i].size() % 2 == 1 && TT[i].size() )
        {
            TT[i].push_back( make_pair ( new_node, M + i ) ) ;
            TT[new_node].push_back( make_pair ( i, M + i ) ) ;
        }
}

void build_euler_path( int node, int edge )
{
    vis[node] = 1 ;
    for ( int i = 0 ; i <= TT[node].size() - 1 ; i++ )
        if ( !out[TT[node][i].first] )
        {
            out[TT[node][i].first] = 1 ;
            build_euler_path(TT[node][i].first, TT[node][i].second ) ;
        }
    Order[++beg] = node ;
    Which[beg] = edge ;

}

int main()
{
    bool is_eulerian = true ;
    read() ;
    for ( int i = 1 ; i <= N ; i++ )
        if ( TT[i].size() % 2 == 1 )
            is_eulerian = false ;
    if ( is_eulerian ) fout << "0" << '\n' ;
    else fout << "2" << '\n' ;
    if ( !is_eulerian )
    {
        add_node() ;
        for ( int i = 1 ; i <= N ; i++ )
            if ( !vis[i] )
                build_euler_path(i, 0 ) ;
        for ( int i = beg - 1 ; beg >= 1 ; beg-- )
            if ( Which[i] > 0 && Which[i] <= M )
                SOL[Which[i]] = Order[i] ;
        for ( int i = 1 ; i <= M ; i++ )
            fout << SOL[i] << '\n' ;
    }
    return 0;
}
