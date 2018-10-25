#include <bits/stdc++.h>
#define DIMMAX 2001
#define NMAX 10001

using namespace std ;

int N, xA, yA, xB, yB, M[DIMMAX][DIMMAX], st = 0 ;
double R ;

bool distance ( double xA, double yA, double xB, double yB )
{
    double dist = sqrt ( ( xB - xA ) * ( xB - xA ) + ( yB - yA ) * ( yB - yA ) ) ;
    if ( dist - R <= 0.00001 )
        return true ;
    else return false ;
}

struct Point
{
    int x, y ;
} V[NMAX] ;

void read()
{
    int x, y ;
    cin >> N >> xA >> yA >> xB >> yB >> R ;
    for ( int i = 1 ; i <= N ; i++ )
    {
        cin >> x >> y ;
        if ( distance ( x, y, xA, yA ) && distance ( x, y, xB, yB ) )
            M[x][y] = -1 ;
        else if ( distance ( x, y, xA, yA ) || distance ( x, y, xB, yB ) )
        {
            M[x][y] = 1 ;
            V[++st].x = x ;
            V[st].y = y ;
        }
    }
}

int main()
{
    int nr = 0 ;
    read() ;
    for ( int i = 1 ; i <= N ; i++ )
        if ( M[V[i].x][V[i].y] == 1 )
            nr++ ;
    cout << nr ;
    return 0 ;
}
