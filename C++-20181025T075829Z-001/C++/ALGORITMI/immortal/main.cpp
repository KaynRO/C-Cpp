#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

ifstream fin ( "immortal.in" ) ;
ofstream fout ( "immortal.out" ) ;

int n , m , nr , mx[25][25] , Mx[25][25] , k , beg , dead[500] ;
int dl[] = { -1 , 1 , 0 , 0 } , dc[] = { 0 , 0 , -1 , 1 } ;
struct immortal
{
    int x ;
    int y ;
} I[500] ;
struct event
{
    int ln1 ;
    int cn1 ;
    int ln2 ;
    int cn2 ;
} E[500] ;

int free ( int ln , int cn )
{
    if ( ln >= 1 && ln <= n && cn >= 1 && cn <= m && mx[ln][cn] == 0 )
        return 1 ;
    return 0 ;
}

int ok ( int ln , int cn )
{
    if ( ln >= 1 && ln <= n && cn >=1 && cn <= m && mx[ln][cn] != 0 )
        return 1 ;
    return 0 ;
}

void print()
{
    for ( int i = 1 ; i <= k ; i++ )
        fout << E[i].ln1 << ' ' << E[i].cn1 << ' ' << E[i].ln2 << ' ' << E[i].cn2 << '\n' ;
}

int bkt ( int beg )
{
    if ( beg == nr - 1 )
    {
        print() ;
        exit(0) ;
    }
    else
    {
        for ( int i  = 1 ; i <= nr ; i++ )
        {
            if ( !dead[i] )
            {
                int x = I[i].x ;
                int y = I[i].y ;
                for ( int j = 0 ; j < 4 ; j++ )
                {
                    if ( ok ( x + dl[j] , y + dc[j] ) && free ( x + 2 * dl[j] , y + 2 * dc[j] ) )
                    {
                        beg++ ;
                        k++ ;
                        E[k].ln1 = x ;
                        E[k].cn1 = y ;
                        E[k].ln2 = x + 2 * dl[j] ;
                        E[k].cn2 = y + 2 * dc[j] ;
                        int die = mx[ x + dl[j] ][ y + dc[j] ] ;
                        dead[die] = 1 ;
                        I[i].x = x + 2 * dl[j] ;
                        I[i].y = y + 2 * dc[j] ;
                        mx[ x + dl[j] ][ y + dc[j] ] = 0 ;
                        mx[ x + 2 * dl[j] ][ y + 2 * dc[j] ] = i ;
                        mx[x][y] = 0 ;
                        bkt( beg ) ;
                        dead[die] = 0 ;
                        beg-- ;
                        k-- ;
                        I[i].x = x ;
                        I[i].y = y ;
                        mx[ x + dl[j] ][ y + dc[j] ] = die ;
                        mx[ x + 2 * dl[j] ][ y + 2 * dc[j] ] = 0 ;
                        mx[x][y] = i ;
                    }
                }
            }
        }
    }
    return 0 ;
}

void read()
{
    int x , y ;
    fin >> n >> m >> nr ;
    beg = 0 ;
    for ( int i = 1 ; i <= nr ; i++ )
    {
        fin >> x >> y ;
        mx[x][y] = i ;
        I[i].x = x ;
        I[i].y = y ;
    }
}

int main()
{
    read() ;
    bkt( 0 ) ;
    return 0 ;
}
