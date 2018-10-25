#include <fstream>
#define INF (1<<30)
#define NMAX 10100

using namespace std ;

ifstream fin ( "rafturi.in" ) ;
ofstream fout ( "rafturi.out" ) ;

int N , C , best[NMAX] , height[NMAX] ;

int minim ( int x , int y , int z )
{
    return min ( min ( x , y ) , z )  ;
}

void read()
{
    fin >> C >> N ;
    int dulap , raft ;
    for ( int i = 1 ; i <= N ; i++ )
    {
        fin >> dulap >> raft ;
        height[dulap] = max ( height[dulap] , raft ) ;
    }
    for ( int i = 1 ; i <= C ; i++ )
        best[i] = INF ;
}

void solve()
{
    best[0] = 0 ;
    best[1] = height[1] ;
    if ( height[2] == 0 )
        best[2] = best[1] ;
    else best[2] = max ( height[1] , height[2] ) ;
    for ( int i = 3 ; i <= C ; i++ )
    {
        if ( height[i] == 0 )
            best[i] = min ( best[i] , best[i-1] ) ;
        else
            best[i] = minim ( max ( height[i] , height[i-1] ) + best[i-2] , min ( best[i] , height[i] + best[i-1] ) ,
                              min ( best[i] , max ( max ( height[i-2] , height[i-1] ) , height[i] ) + best[i-3] ) ) ;
    }
    fout << best[C] ;
}

int main()
{
    read() ;
    solve() ;
    return 0;
}
