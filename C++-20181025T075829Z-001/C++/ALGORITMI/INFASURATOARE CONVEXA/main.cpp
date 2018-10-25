#include <cstdio>

#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

#define x first
#define y second

typedef pair<double, double> Point;

ifstream fin("infasuratoare.in");
ofstream fout("infasuratoare.out");

const int MAX_N = 120005;

int n ;
Point v[MAX_N];

Point stack[MAX_N];
int head;

void read()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i].x >> v[i].y;
}

inline double cross_product( const Point& A , const Point& B , const Point& C )
{
    return ( B.x - A.x ) * ( C.y - A.y ) - ( B.y - A.y ) * ( C.x - A.x ) ;
}

inline int cmp ( const Point& p1 , const Point& p2 )
{
    return cross_product( v[1] , p1 , p2 ) < 0 ;
}

void convex_hull()
{
    int pos = 1 ;
    for ( int i = 2 ; i <= n ; i++ )
        if ( v[i] < v[pos] )
            pos = i ;
    swap ( v[1] , v[pos] ) ;
    sort ( v + 2 , v + n + 1 , cmp ) ;
    head = 2 ;
    stack[1] = v[1] ;
    stack[2] = v[2] ;
    for ( int i = 3 ; i <= n ; i++ )
    {
        while ( head >= 2 && cross_product( stack[head - 1] , stack[head] , v[i] ) > 0 )
            head-- ;
        stack[++head] = v[i] ;
    }

}

void write()
{
    fout << fixed ;
    fout << head << '\n' ;
    for ( int i = head ; i >= 1 ; i-- )
        fout << setprecision(9) << stack[i].x << ' ' << stack[i].y << '\n' ;
}
int main()
{
    read();
    convex_hull();
    write();
}
