#include "Complex.h"

using namespace std ;

ifstream fin ( "Complex.in" ) ;
ofstream fout ( "Complex.out" ) ;

void read() ;

int main()
{
    read() ;
    return 0;
}

void read()
{
    Complex A, B ;
    A.read(fin) ;
    B.read(fin) ;
    fout << "Suma numerelor este : " ;
    add ( A, B ).print(fout) ;
    fout << "Diferenta numerelor este : " ;
    substract ( A, B).print(fout) ;
    fout << "Produsul numerelor este : " ;
    multiply ( A, B ).print(fout) ;
    fout << "Catul numerelor este : " ;
    divide( A, B ).print(fout) ;
}
