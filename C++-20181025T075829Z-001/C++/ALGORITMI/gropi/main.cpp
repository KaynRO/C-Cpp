#include <bits/stdc++.h>
#define NMAX 100100
#define KMAX 1000100
#define INF ( 1 << 30 )

using namespace std ;

ofstream fout ( "gropi.out" ) ;

struct EDGE
{
    int X ;
    int Y ;
    int now_time ;
    int best_time ;
};

bool compare ( EDGE A, EDGE B )
{
    return A.X < B.X ;
}

int N, K, minT[NMAX], maxT[NMAX], order[NMAX] ; // minT[X] = cel mai aproape nod de X care nu este mai aproape de 1
//maxT[X] = cel mai departe nod de nodul X care nu este mai departe decat 1

vector < EDGE > G ;

void read()
{
    int x, y, current, best, st ;
    EDGE S ;
    freopen ( "gropi.in", "r", stdin ) ;
    scanf ( "%d %d", &N, &K ) ;
    for ( int i = 1 ; i <= N - 1 ; i++ )
    {
        scanf ( "%d %d %d %d", &x, &y, &current, &best ) ;
        S.X = x, S.Y = y, S.now_time = current, S.best_time = best ;
        G.push_back(S) ; // inseram muchiile in vectorul G
        S.X = y, S.Y = x ;
        G.push_back(S) ;
    }

    sort ( G.begin(), G.end(), compare ) ; // le sortam crescator dupa capatul din stanga
    order[1] = 0, st = 0 ;
    for ( int i = 2 ; i <= N ; i++ )
    {
        while ( G[st].X == i - 1 && st <= G.size() - 1 ) // tinem minte pe ce pozitie incep , in vectorul de muchii , muchiiile cu capatul stanga in i
            st++ ;
        order[i] = st ; // nodul X va avea muchiile de pe pozitiile order[X] pana la strict mai mic ca order[X + 1]
    }

}

void DFS( int node, int prev )
{
    maxT[node] = 0 ;
    minT[node] = 0 ;
    for ( int i = order[node] ; i < order[node + 1] ; i++ )
    {
        int next = G[i].Y ;
        if ( next == prev ) continue ;
        DFS( next, node ) ;
        if ( maxT[node] < G[i].now_time + maxT[next] ) maxT[node] = G[i].now_time + maxT[next] ; // vedem nodurile cele mai departate si mai apropiate
        if ( minT[node] < G[i].best_time + minT[next] ) minT[node] = G[i].best_time + minT[next] ;
    }
}

int minCost ( int start, int prev, int available )
{
    int sum  = 0 ;
    for ( int i = order[start] ; i < order[start + 1] ; i++ )
    {
        int next = G[i].Y ;
        if ( next == prev ) continue ;
        int improve = available - maxT[next] ;
        if ( improve > G[i].now_time ) improve = G[i].now_time ; // daca putem imbunatati tinem minte cu cat
        if ( improve < G[i].best_time ) improve = G[i].best_time ;
        sum += G[i].now_time - improve + minCost ( next, start, available - improve ) ; // actualizam bugetul si plecam mai departe
    }
    return sum ; // returnam costul de care avem nevoie
}

int bs()
{
    int st = minT[1], dr = maxT[1], mid ;
    while ( st < dr )
    {
        mid = ( st + dr ) >> 1 ;
        if ( minCost( 1, 0, mid ) <= K ) // vrem sa vedem daca bugetul pentru a avea diferenta maxima de timp = mid < K
            dr = mid ;
        else st = mid + 1 ;
    }
    return st ;
}


int main()
{
    read() ;
    DFS( 1, 0 ) ;
    fout << bs() ;
    return 0;
}
