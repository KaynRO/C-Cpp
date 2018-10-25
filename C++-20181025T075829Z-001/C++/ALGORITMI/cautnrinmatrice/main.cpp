#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ( "cautanrinmatrice.in" ) ;
ofstream fout ( "cautanrinmatrice.out" ) ;

long long n , m , matrix[1200][1200] , p , st ;
struct coada
{
    int value ;
    int lin ;
    int col ;
} sir[200000] ;

int mij = 0 ;

int binary( int x )
{
    int left = 1 ;
    int right = st ;
    while ( left <= right )
    {
        mij = ( left + right ) / 2 ;
        if ( sir[mij].value == x )
            return mij  ;
        else
        {
            if ( x > sir[mij].value  )
                left = mij + 1 ;
            else
                right = mij - 1 ;

        }
    }
    return 0 ;
}
int main()
{
    fin >> n >> m ;
    int type = 0 ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        type = i % 2 ;

        for ( int j = 1 ; j <= m ; j++ )
            fin >> matrix[i][j] ;
        if ( type == 1 )
        {
            for ( int j = 1 ; j <= m ; j++ )
            {
                sir[++st].value = matrix[i][j] ;
                sir[st].lin = i ;
                sir[st].col = j ;
            }
        }
        else
        {
            for ( int j = m ; j >= 1 ; j-- )
            {
                sir[++st].value = matrix[i][j] ;
                sir[st].lin = i ;
                sir[st].col = j ;
            }
        }



    }
    fin >> p ;
    int x ;
    for ( int i = 1 ; i <= p ; i++ )
    {
        fin >> x ;
        int k = binary(x) ;
        if ( k == 0 )
            fout << k << '\n' ;
        else fout << sir[k].lin << ' ' << sir[k].col << '\n' ;

    }
    return 0;
}
