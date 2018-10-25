#include <fstream>
#include <cstdio>
#include <cstring>
#define LMAX 1000010

using namespace std ;

ifstream fin ( "parola.in" ) ;
ofstream fout ( "parola.out" ) ;

int passwordNumber, MOD, Rest, S[LMAX], seen[LMAX] ;
char password[LMAX] ;

int ASCII( char ch )
{
    return int(ch) ;
}

void read()
{
    int nrSOL, sum ;
    fin >> passwordNumber ;
    for ( int i = 1 ; i <= passwordNumber ; i++ )
    {
        fin >> MOD >> Rest ;
        fin >> (password + 1) ;

        nrSOL = 0, sum = 0 ;
        memset(seen, 0, sizeof(seen)) ;
        seen[0] = 1 ;

        for ( int i = 1 ; i <= strlen((password + 1)) ; i++ )
        {
            sum  = ( sum + ASCII(password[i]) ) % MOD ;
            nrSOL += seen[ ( sum + MOD - Rest ) % MOD ] ;
            seen[sum]++ ;
        }
        fout << nrSOL << '\n' ;
    }
}

int main()
{
    read() ;
    return 0;
}
