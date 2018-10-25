#include "Matrix.h"

using namespace std ;

ifstream fin ( "Matrix.in" ) ;
ofstream fout ( "Matrix.out" ) ;

void read() ;

int main()
{
    read() ;
    return 0;
}

void read()
{
    Matrix X1, X2 ;
    X1.read(fin) ;
    X2.read(fin) ;
    fout << "Daca adunam X1 si X2 obtinem : " << '\n' ;
    add ( X1, X2 ).print(fout) ;
    fout << "Daca scadem X1 si X2 obtinem : " << '\n' ;
    substract ( X1, X2 ).print(fout) ;
    fout << "Daca inmultim X1 si X2 obtinem : " << '\n' ;
    multiply ( X1, X2 ).print(fout) ;
}
