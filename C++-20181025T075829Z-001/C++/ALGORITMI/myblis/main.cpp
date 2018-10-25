#include <fstream>
#include <deque>
#include <cstring>
#define NMAX 100100

using namespace std ;

ifstream fin ( "blis.in" ) ;
ofstream fout ( "blis.out" ) ;

deque < int > V ;
char B[NMAX] ;
int K , n ;

void read()
{
    fin >> K ;
    fin >> ( B + 1 ) ;
    n = strlen ( B + 1 ) ;
}

int compose ( int i , int j )
{
    int no = 0 ;
    for ( int s = i ; s <= j ; s++ )
        no = no * 10 + V[s] ;
    return no ;

}
unsigned binary_to_decimal()
{
    unsigned res = 0 ;
    int power = 1 ;
    for ( int i = K - 1 ; i >= 0 ; i-- )
    {
        res = res + power * V[i] ;
        power *= 2 ;
    }
    return res ;
}

void solve_part_I()
{
    int maxim = 0 ;
    for ( int i = 1 ; i <= K ; i++ )
        V.push_back( ( B[i] - '0' ) ) ;

    int number = 0 ;
    int k = K ;
    while ( k != n - 2 )
    {
        number = 0 ;
        number = binary_to_decimal() ;
        if ( number > maxim )
            maxim = number ;
        k++ ;
        V.push_back((B[k]-'0')) ;
        V.pop_front() ;

    }
    fout << maxim ;
}

int main()
{
    read() ;
    solve_part_I() ;
    return 0;
}
