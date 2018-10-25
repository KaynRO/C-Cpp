#include <bits/stdc++.h>
#define mp make_pair
#define NMAX 1200

using namespace std ;

ofstream fout( "retea.out" ) ;

vector < pair < int , int > > TT[NMAX] ;
priority_queue < pair < int , int > > PQ ;

int N , M , K ;

void read()
{
    int x , y , cost ;
    freopen( "retea.in" , "r" , stdin ) ;
    scanf( "%d %d %d" , &N , &M , &K ) ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf( "%d %d %d" , &x , &y , &cost ) ;
        TT[x].push_back( mp( x , cost ) ) ;
        TT[y].push_back( mp( y , cost ) ) ;
    }
}

int main()
{
    read() ;
    dynamic() ;
    bellman_ford() ;
    return 0 ;
}
