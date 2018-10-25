#include <bits/stdc++.h>
#define NMAX 10005

using namespace std ;

vector <short> G[NMAX];

int Cost[NMAX], S ;
short N, K;

struct compare
{
    inline bool operator () ( const int &x, const int &y )
    {
        return Cost[x] > Cost[y];
    }
};

void solve()
{
    priority_queue <short, vector<short>, compare> Q;
    int node , father ;
    for ( int i = 1 ; i <= N ; i++ )
    {
        Cost[i] = 1 ;
        if ( G[i].size() == 1 ) Q.push(i) ;
    }
    for ( int i = 1 ; i < N - K ; i++ )
    {
        node = Q.top() ;
        Q.pop() ;
        father = G[node][0] ;
        S += Cost[node] ;
        Cost[father] = Cost[father] + Cost[node] ;
        G[node].clear() ;
        G[father].erase ( find ( G[father].begin(), G[father].end(), node ) ) ;
        if( G[father].size() == 1 ) Q.push(father) ;
    }
}

int main()
{
    short int x , y ;
    freopen( "cezar.in" , "r" , stdin ) ;
    freopen ( "cezar.out" , "w" , stdout ) ;
    scanf ( "%hd %hd" , &N , &K ) ;
    for ( int i = 1 ; i < N ; i++ )
    {
        scanf ( "%hd %hd" , &x , &y ) ;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    solve() ;
    printf ( "%d" , S ) ;
    return 0;
}
