#include <fstream>
#include <map>
#include <string>
#define NMAX 65

using namespace std ;

ifstream fin ( "tricouri.in" ) ;
ofstream fout ( "tricouri.out" ) ;

map < char , int > Nr ;
map < char , int > M ;
map < int , string > K ;
map < int , char > Orderi ;
map < char , int > Orderc ;
int N , happy , maxim = -1 ;

void bkt ( int nr )
{
    if ( nr > N )
    {
        if ( happy > maxim )
            maxim = happy ;
    }
    else
    {
        string wanted = K[nr] ;
        char lft = wanted[0] ;
        char rght = wanted[1] ;
        int ok = 0 ;
        for ( int i = Orderc[lft] ; i <= Orderc[rght] ; i++ )
        {
            if ( Nr[Orderi[i]] != 0 )
            {
                Nr[Orderi[i]]-- ;
                happy++ ;
                ok = 1 ;
                bkt ( nr + 1 ) ;
                Nr[Orderi[i]]++ ;
                happy-- ;
            }
        }
        if ( ok == 0 )
        bkt ( nr + 1 ) ;
    }
}

int main()
{
    string q ;
    int s , m , l , x , t ;
    fin >> N ;
    for ( int i = 1 ; i <= N ; i++ )
    {
        fin >> q ;
        K[i] = q ;
    }
    fin >> s >> m >> l >> x >> t ;
    Nr['S'] = s ;
    Nr['M'] = m ;
    Nr['L'] = l ;
    Nr['X'] = x ;
    Nr['T'] = t ;
    Orderi[1] = 'S' ;
    Orderi[2] = 'M' ;
    Orderi[3] = 'L' ;
    Orderi[4] = 'X' ;
    Orderi[5] = 'T' ;
    Orderc['S'] = 1 ;
    Orderc['M'] = 2 ;
    Orderc['L'] = 3 ;
    Orderc['X'] = 4 ;
    Orderc['T'] = 5 ;
    bkt(1) ;
    fout << maxim ;
    return 0;
}
