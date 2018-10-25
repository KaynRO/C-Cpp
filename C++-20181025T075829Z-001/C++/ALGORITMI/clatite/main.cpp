#include <fstream>
#include <cmath>
#include <iostream>

using namespace std ;

ifstream fin ( "clatite.in" ) ;
ofstream fout ( "clatite.out" ) ;

int N , M , ingh , ge , cioco , zahar , simpla , p[300000] ;

bool inghetata ( int pos )
{
    int sum = 0 ;
    for ( int i = 1 ; i <= pos / 2 ; i++ )
        if ( pos % i == 0 )
            sum += i ;
    if ( sum == pos )
        return 1 ;
    else return 0 ;
}

bool gem ( int pos )
{
    double cub = double(1) / double(3) ;
    if ( ( int ( sqrt(pos) ) * int ( sqrt(pos) ) == pos )  || ( (int) pow ( pos , cub ) == (double) pow ( pos , cub ) ) )
        return 1 ;
    else return 0 ;
}

void ciur()
{
    int i, j ;
    for ( i = 1 ; ( ( i * i ) << 1 ) + ( i << 1 ) <= 300000 ; i += 1 )
    {
        if ( p[i] == 0 )
        {
            for ( j = ( ( i * i ) << 1 ) + ( i << 1 ) ; ( j << 1 ) + 1 <= 300000 ; j += ( i << 1 ) + 1 )
                p[j] = 1;
        }
    }
}

bool ciocolata ( int pos )
{
    if ( p[(pos-1)/2] == 0  && ( pos - 1 ) % 2 == 0 )
        return 1 ;
    return 0 ;
}

int main()
{
    fin >> N >> M ;
    ciur() ;
    int stare = 0 ;
    for ( int i = N ; i <= M ; i++ )
    {
        stare = 0 ;
        if ( inghetata(i) )
            stare = 3 ;
        if ( gem(i) )
            stare = 2 ;
        if ( ciocolata(i) )
            stare = 1 ;
        if ( stare == 1 )
            cioco++ ;
        if ( stare == 2 )
            ge++ ;
        if ( stare == 3 )
            ingh++ ;
        if ( stare == 0 && i % 2 == 0 )
            zahar++ ;
        if ( stare == 0 && i % 2 == 1 )
            simpla++ ;
    }
    fout << M - N + 1 << '\n' ;
    fout << cioco << ' ' << ge << ' ' << ingh << ' ' << zahar << ' ' << simpla ;
    return 0;
}
