#include <fstream>
#include <vector>
#define NMAX 110
#define INF ( 1 << 30 )

using namespace std ;

ifstream fin ( "firma.in" ) ;
ofstream fout ( "firma.out" ) ;
int N , M , H[NMAX][NMAX] ;

void initialise()
{
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= N ; j++ )
            if ( i == j )
                H[i][j] = 0 ;
            else H[i][j] = INF ;
}

void roy_floyd()
{
    for ( int k = 1 ; k <= N ; k++ )
        for ( int i = 1 ; i <= N ; i++ )
            for ( int j = 1 ; j <= N ; j++ )
                if ( ( H[i][j] > H[i][k] + H[k][j] || H[i][j] == INF ) && i != j && H[i][k] != INF && H[k][j] != INF )
                    H[i][j] = H[i][k] + H[k][j] ;
}

int verify ( int node )
{
    for( int i = 1 ; i <= N ; i++ )
        if ( i != node && H[node][i] == INF )
            return 0 ;
    return 1 ;
}

void print()
{
    for ( int i = 1 ; i <= N ; i++ )
    {
        for ( int j = 1 ; j <= N ; j++ )
            fout << H[i][j] << ' ' ;
        fout << '\n' ;
    }
}

int main()
{
    int x , y , cost , bestVf = 1 , sum , bestsum  = INF ;
    fin >> N >> M ;
    initialise() ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        fin >> x >> y >> cost ;
        H[x][y] = H[y][x] = cost ;
    }
    roy_floyd() ;
    //print() ;
    for ( int i = 1 ; i <= N ; i++ )
        if ( verify(i) )
        {
            sum = 0 ;
            for ( int j = 1 ; j <= N ; j++ )
                sum += H[i][j] ;
            if ( sum < bestsum )
            {
                bestVf = i ;
                bestsum = sum ;
            }
        }
    fout << bestVf ;
    return 0;
}
