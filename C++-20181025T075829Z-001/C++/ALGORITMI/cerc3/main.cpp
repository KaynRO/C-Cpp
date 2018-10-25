#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
#define NMAX 2016

using namespace std ;

ofstream fout ( "cerc3.out" ) ;

struct circle
{
    int x ;
    int y ;
    int radius ;
} ;

struct solution
{
    double sol1x ;
    double sol2x ;
    double sol1y ;
    double sol2y ;
} Circle[NMAX] ;
int N ;
map < double , vector < circle > > D ;
map < double , int > Max ;

bool compare_criteria ( circle a , circle b )
{
    return a.y < b.y ;
}

double centre_distance ( circle a , circle b )
{
    return sqrt ( ( b.y - a.y ) * ( b.y - a.y ) + ( b.x - a.x ) * ( b.x - a.x ) ) ;
}

void find_maximum ( double straight )
{
    int maximum = -1 ;
    int cnt = 0 ;
    for ( vector < circle > :: iterator it = D[straight].begin() ; it != D[straight].end() ; ++it )
    {
        double firstterm = straight * straight + 1 ;
        double secondterm = 2 * ( it->x + ( it->y * straight ) )  ;
        double freeterm = it->x * it->x + it->y * it->y - it->radius * it->radius ;
        double delta = secondterm * secondterm - 4 * firstterm * freeterm ;
        double sol1 = ( secondterm + sqrt(delta) ) / ( 2 * firstterm ) ;
        double sol2 = ( secondterm - sqrt(delta) ) / ( 2 * firstterm ) ;
        Circle[++cnt].sol1x = sol2 ;
        Circle[cnt].sol2x = sol1 ;
        Circle[cnt].sol1y = sol2 * straight ;
        Circle[cnt].sol2y = sol1 * straight ;
    }
}

void read()
{
    circle data ;
    freopen ( "cerc3.in" , "r" , stdin ) ;
    scanf ( "%d" , &N ) ;
    for ( int i = 1 ; i <= N ; i++ )
    {
        scanf ( "%d %d %d" , &data.x , &data.y , &data.radius ) ;
        double straight_ratio = ( (double) data.y / (double) data.x ) ;
        D[straight_ratio].push_back(data) ;
    }
}

void partI()
{
    fout << D.size() << ' ' ;
}

void partII()
{
    for ( map < double , vector < circle > > :: iterator it = D.begin() ; it != D.end() ; ++it )
        find_maximum( it->first ) ;
    //for ( map < double , int > :: iterator it = Max.begin() ; it != Max.end() ; ++it )
    //fout << it->first << ' ' << it->second << '\n' ;
}

int main()
{
    read() ;
    partI() ;
    partII() ;
    return 0;
}
