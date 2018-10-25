#include <fstream>
#define NMAX 1000200

using namespace std ;

ifstream fin ("prieteni.in") ;
ofstream fout ("prieteni.out") ;

int P[NMAX], Rank[NMAX], N, K ;

int leader ( int node )
{
    while ( node != P[node] )
    {
        node = P[node] ;
    }
    return node ;
}

void solve ( int value )
{
    value = leader(value) ;
    fout << Rank[value] + 1 << '\n' ;
}

void unite( int x, int y )
{

    x = leader(x) ;
    y = leader(y) ;

    if ( x != y )
    {
        if ( x < y )
        {
            P[y] = x ;
            Rank[x] = Rank[x] + Rank[y] + 1 ;
        }
        else
        {
            P[x] = y ;
            Rank[y] = Rank[y] + Rank[x] + 1 ;
        }
    }

}

void read()
{
    int type, value, x, y ;
    fin >> N >> K ;
    for ( int i = 1 ; i <= N ; i++ )
        P[i] = i ;
    for ( int i = 1 ; i <= K ; i++ )
    {
        fin >> type ;
        if ( type == 2 )
        {
            fin >> value ;
            solve(value) ;
        }
        else
        {
            fin >> x >> y ;
            unite(x, y) ;
        }
    }
}

int main()
{
    read() ;
    return 0;
}
