#include <bits/stdc++.h>
#define NMAX 56
#define KMAX 1006
#define INF ( 1 << 30 )

using namespace std ;

ofstream fout ( "lanterna.out" ) ;

struct Node
{
    int next ;
    int wats ;
    int time ;
} ;

bitset < NMAX >  base ;
queue < pair < int, int > > Q ;
vector < Node > G[NMAX] ;
int N, K, M, DP[NMAX][KMAX], SOL = INF,  bestWatt ;   // DP[i][j] = timpul minim pentru a ajunge in nodul i folosing j wati

void read()
{
    int x, y, wats, time ;
    bool refill ;
    Node S ;
    freopen ( "lanterna.in", "r", stdin ) ;
    scanf ( "%d %d", &N, &K ) ;
    for ( int i = 1 ; i <= N ; i++ )
    {
        scanf ( "%d", &refill ) ;
        base[i] = refill ;
    }
    scanf ( "%d", &M ) ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf ( "%d %d %d %d", &x, &y, &time, &wats ) ;
        S.next = y, S.wats = wats, S.time = time ;
        G[x].push_back(S) ;
        S.next = x ;
        G[y].push_back(S) ;
    }
}

int bellman_ford( int KX )
{
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 0  ; j <= KX ; j++ )
            DP[i][j] = INF ;

    SOL = INF ;
    Q.push( make_pair ( 1, 0 ) ) ;
    DP[1][0] = 0 ;

    while ( !Q.empty() )
    {
        int node = Q.front().first ;
        int wats_used = Q.front().second ;
        Q.pop() ;

        for ( vector < Node > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
        {
            int next_node = it->next ;
            int time = it->time ;
            int wats_to_consume = it->wats ;

            if ( wats_used + wats_to_consume <= KX ) // daca avem destula energie sa ajungem in nodul urmator
            {
                int wats_total = wats_used + wats_to_consume ;
                if ( base[next_node] ) // daca este baza reincarc bateria
                    wats_total = 0 ;
                int time_total = DP[node][wats_used] + time ;

                if ( time_total < DP[next_node][wats_total] ) // daca pot ajunge intr-un timp mai bun cu bateria curenta
                {
                    DP[next_node][wats_total] = time_total ;
                    Q.push( make_pair ( next_node, wats_total ) ) ; // introduc in coada

                    if ( next_node == N && time_total < SOL ) // daca am ajuns la destinatie tin minte solutia
                        SOL = time_total ;
                }
            }
        }
    }
    return SOL ;
}

inline int search_best()
{

    int st = 1, dr = K - 1, bestSOL = K, mid ;
    // cautam cea mai buna valoare a bateriei pentru care obtinem acelasi rezultat ca si KMAX

    while ( st <= dr )
    {
        mid = ( st + dr ) >> 1 ;
        if ( bellman_ford(mid) == bestWatt )
        {
            bestSOL = mid ;
            dr = mid - 1 ;
        }
        else st = mid + 1 ;
    }

    return bestSOL ;
}

int main()
{

    read() ;
    bestWatt = bellman_ford(K) ;
    fout << bestWatt << ' ' << search_best() ;

    return 0 ;
}
