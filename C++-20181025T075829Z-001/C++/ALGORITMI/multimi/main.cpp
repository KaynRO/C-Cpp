#include <iostream>
#include <vector>
#include <set>
#define NMAX 10000010

using namespace std ;

int N, L, K,dist[NMAX] ;

struct compare
{
    bool operator() ( pair < int, int > A1, pair < int, int > A2 ) const
    {
        if ( dist[A1.first] > L && dist[A2.first] <= L ) return A2 < A1 ;
        if ( dist[A1.first] <= L && dist[A2.first] > L ) return A1 < A2 ;
        return A1.second < A2.second ;
    }
};

set < pair < int, int >, compare > S ;

int main()
{
    cin >> N >> L >> K ;
    int D1, D2, C1 ;
    D1 = 0 ;
    for ( int i = 1 ; i <= N ; i++ )
    {
        cin >> D2 >> C1 ;
        S.insert(make_pair (i, C1) ) ;
        dist[i] = D1 + D2 ;
        D1 = D2 ;
    }
    int my_pos = 0 ;
    dist[0] = 0 ;
    while ( my_pos != N )
    {
        int next = choose_next(my_pos) ;
        sum += dist[next] - dist[my_pos] ;
        update_dist() ;
    }
    return 0;
}
