#include <fstream>
#include <cstring>
#define NMAX 1010

using namespace std ;

ifstream fin ( "harddp.in" ) ;
ofstream fout ( "harddp.out" ) ;

char A[NMAX], B[NMAX], value ;
int nrT, nrC, nr0, nr1, maxNr1, maxNr0 ;

int main()
{
    fin >> nrT ;
    for ( int i = 1 ; i <= nrT ; i++ )
    {
        fin >> nrC ;
        maxNr1 = 0 , maxNr0 = 0 , nr1 = 0 , nr0 = 0 ;
        fin >> A ;
        for ( int j = 0 ; j < nrC ; j++ )
            if ( A[j] == '1' )
                nr1++ ;
            else nr0++ ;
        if ( nr1 < nr0 )
            value = '1' ;
        else value = '0' ;
        for ( int j = 0  ; j < nrC ; j++ )
            fout << value ;
        fout << '\n' ;
    }
    return 0;
}
