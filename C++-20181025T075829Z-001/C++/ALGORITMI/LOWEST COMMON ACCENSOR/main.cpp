#include <fstream>
#include <vector>
#define NMAX 100005

using namespace std;

ofstream fout ( "lca.out" ) ;

int n , questions , base , Level[NMAX] , Father[NMAX] ;
vector<int> Son[NMAX] ;

void read()
{
    int value ;
    freopen ( "lca.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &n , &questions ) ;
    for ( int i = 2 ; i <= n ; i++ )
    {
        scanf ( "%d" , &value ) ;
        Father[i] = value ;
        Son[value].push_back(i) ;
    }
}

void DFS( int node )
{
    for ( vector<int> :: iterator it = Son[node].begin() ; it != Son[node].end() ; ++it )
    {
        Level[*it] = Level[node] + 1 ;
        DFS(*it) ;
    }
}

void Solve()
{
    int x , y ;
    while ( questions-- )
    {
        scanf ( "%d %d" , &x , &y ) ;
        if ( Level[x] < Level[y] )
            swap( x , y ) ;
        while ( Level[x] != Level[y] )
            x = Father[x] ;
        while ( x != y )
        {
            x = Father[x] ;
            y = Father[y] ;
        }
        fout << x << '\n' ;
    }

}
int main()
{
    read() ;
    DFS(1) ;
    Solve() ;
    return 0;
}
