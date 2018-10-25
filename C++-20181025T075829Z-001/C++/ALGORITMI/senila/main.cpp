#include <fstream>
#include <algorithm>

using namespace std ;

ifstream fin ( "senila.in" ) ;
ofstream fout ( "senila.out" ) ;

int S , Z , K , A , M , N , L , C , R , m[250][250] ;

int deplasare ( int Z )
{
    int x = Z & 3 ;
    Z = Z >> 2 ;
    x = x << ( 2 * S - 2 ) ;
    Z = Z | x ;
    return Z ;
}

void partI()
{
    int z = Z ;
    while ( K-- )
        z = deplasare(z) ;
    fout << z << '\n' ;
}

void partII()
{
    int ln = 1 ;
    int cn = 1 ;
    int x = 0 ;
    int z = Z ;
    A %= S ;
    while ( A-- )
    {
        x = z & 3 ;
        z = deplasare(z) ;
        if ( x == 0 )
            cn++ ;
        if ( x == 1 )
            ln++ ;
        if ( x == 2 )
            cn-- ;
        if ( x == 3 )
            ln-- ;
    }
    fout << ln << ' ' << cn << '\n' ;
}

void print()
{
    for ( int i = 1 ; i <= M ; i++ )
    {
        for ( int j = 1 ; j <= N ; j++ )
            fout << m[i][j] << ' ' ;
        fout << '\n' ;
    }
}

void partIII()
{
    int ln = L ;
    int cn = C ;
    R++ ;
    int x ;
    while ( R -- && ln >= 1 && ln <= M && cn >= 1 && cn <= N )
    {
        m[ln][cn] = Z ;
        x = Z & 3 ;
        Z = deplasare(Z) ;
        if ( x == 0 )
            cn++ ;
        if ( x == 1 )
            ln++ ;
        if ( x == 2 )
            cn-- ;
        if ( x == 3 )
            ln-- ;
    }
    print() ;
}
int main()
{
    fin >> S >> Z >> K >> A ;
    fin >> M >> N >> L >> C >> R ;
    partI() ;
    partII() ;
    partIII() ;
    return 0;
}
