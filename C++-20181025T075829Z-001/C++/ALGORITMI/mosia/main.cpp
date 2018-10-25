#include <bits/stdc++.h>
#define NMAX 210
#define INF ( 1 << 30 )

using namespace std ;

ifstream fin ( "mosia.in" ) ;
ofstream fout ( "mosia.out" ) ;

struct Point
{
    int x ;
    int y ;
    int dist ;
    int position ;
} P[NMAX] ;

int N, head ;
Point stk[NMAX] ;
double earn[NMAX], best[NMAX], Best[NMAX] ;

inline double euclid_dist ( Point A, Point B )
{
    return sqrt ( (B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y) ) ;
}

inline int cross_product(const Point& A, const Point& B, const Point& C)
{
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

inline int cmp(const Point& p1, const Point& p2)
{
    return cross_product(P[1], p1, p2) < 0;
}

void sort_points()
{
    int pos = 1;
    for ( int i = 2 ; i <= N ; ++i )
        if ( P[i].x < P[pos].x || ( P[i].x ==P[pos].x && P[i].y < P[pos].y ) )
            pos = i ;
    swap( P[1], P[pos] ) ;
    sort( P + 2, P + N + 1, cmp ) ;
    P[N + 1] = P[1] ;
}

void convex_hull()
{
    sort_points();

    stk[1] = P[1];
    stk[2] = P[2];
    head = 2;

    for ( int i = 3 ; i <= N ; ++i )
    {
        while ( head >= 2 && cross_product ( stk[head - 1], stk[head], P[i] ) > 0 )
            --head ;
        stk[++head] = P[i] ;
    }
    for ( int i = 1 ; i <= head ; i++ )
        for ( int j = 1 ; j <= N ; j++ )
            if ( P[j].x == stk[i].x && P[j].y == stk[i].y && P[j].dist == stk[i].dist )
            {
                stk[i].position = j ;
                break ;
            }
}

void caseI() // moving the first
{
    best[stk[1].position] = earn[stk[1].position] ;
    best[stk[2].position] = best[stk[1].position] ;
    for ( int i = 3 ; i <= N - 1 ; i++ )
        best[stk[i].position] = max ( earn[stk[i].position] + best[stk[i - 2].position], best[stk[i - 1].position] ) ;
    best[stk[N].position] = best[stk[N - 1].position] ;
}

void caseII() // not moving the first
{
    Best[stk[1].position] = 0 ;
    Best[stk[2].position] = earn[stk[1].position] ;
    for ( int i = 3 ; i <= N ; i++ )
        Best[stk[i].position] = max ( earn[stk[i].position] + Best[stk[i - 2].position], Best[stk[i - 1].position] ) ;
    Best[stk[N].position] = Best[stk[N - 1].position] ;
}

void read()
{
    fin >> N ;
    for ( int i = 1 ; i <= N ; i++ )
        fin >> P[i].x >> P[i].y >> P[i].dist ;

}

int main()
{
    read() ;
    convex_hull() ;
    for ( int i = 1 ; i <= head  ; i++ )
    {
        if ( i == 1 )
            earn[stk[i].position] = double ( P[stk[i].position].dist * euclid_dist(P[stk[2].position], P[stk[N].position]) ) / double(2) ;
        else if ( i == N ) earn[stk[i].position] = double ( P[stk[i].position].dist * euclid_dist(P[stk[N - 1].position], P[stk[1].position] ) ) / double(2) ;
        else
            earn[stk[i].position] = double ( P[stk[i].position].dist * euclid_dist(P[stk[i - 1].position], P[stk[i + 1].position] ) ) / double(2) ;
    }
    caseI() ;
    caseII() ;
    double SOL = max( best[N], Best[N] ) ;
    fout << fixed << setprecision(6) << SOL ;
    return 0 ;
}
