#include <fstream>
#define NMAX 520

using namespace std ;

ifstream fin ( "pav.in" ) ;
ofstream fout ( "pav.out" ) ;

int M[NMAX][NMAX], N, cnt ;

int dl[] = { 0, 0, 1, 1 } ;
int dc[] = { 0, 1, 0, 1 } ;

void pav ( int lat, int cx, int cy, int px, int py )
{
    if ( lat == 1 ) return ;
    lat >>= 1 ;
    for ( int i = 0 ; i < 4 ; i++ )
        if ( px >= cx + dl[i] * lat && px < cx + dl[i] * lat + lat && py >= cy + dc[i] * lat && py < cy + dc[i] * lat + lat )
        {
            cnt++ ;
            for ( int j = 0 ; j < 4 ; j++ )
                if ( i != j )
                    M[cx + dl[j] + lat - 1][cy + dc[j] + lat - 1] = cnt ;
            for ( int j = 0 ; j < 4 ; j++ )
                if ( i != j )
                    pav ( lat, cx + dl[j] * lat, cy + dc[j] * lat, cx + dl[j] + lat - 1, cy + dc[j] + lat - 1 ) ;
                else
                    pav ( lat, cx + dl[j] * lat, cy + dc[j] * lat, px, py ) ;
        }

}

int main()
{
    int px, py ;
    fin >> N >> px >> py ;
    pav ( 1 << N, 1, 1, px, py ) ;
    for ( int i = 1 ; i <= 1 << N ; i++ )
    {
        for ( int j = 1 ; j <= 1 << N ; j++ )
            fout << M[i][j] << ' ';
        fout << '\n' ;
    }
    return 0;
}
