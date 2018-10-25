#include "Complex.h"

double Complex::return_real_part()
{
    return real_part ;
}

double Complex::return_imaginary_part()
{
    return imaginary_part ;
}

void Complex::set_real_part ( double value )
{
    real_part = value ;
}

void Complex::set_imaginary_part ( double value )
{
    imaginary_part = value ;
}

void Complex::read(ifstream& fin )
{
    fin >> real_part >> imaginary_part ;
    set_real_part(real_part) ;
    set_imaginary_part(imaginary_part) ;
}

void Complex::print(ofstream& fout )
{
    if ( imaginary_part >= 0 )
        fout << real_part << " + " << imaginary_part << "i" <<'\n' ;
    else
        fout << real_part << " - " << (-1) * imaginary_part << "i" <<'\n' ;

}

Complex add ( Complex A, Complex B )
{
    Complex C ;
    C.set_real_part( A.return_real_part() + B.return_real_part() ) ;
    C.set_imaginary_part ( A.return_imaginary_part() + B.return_imaginary_part() ) ;
    return C ;
}

Complex substract ( Complex A, Complex B )
{
    Complex C ;
    C.set_real_part( A.return_real_part() - B.return_real_part() ) ;
    C.set_imaginary_part ( A.return_imaginary_part() - B.return_imaginary_part() ) ;
    return C ;
}

Complex multiply ( Complex A, Complex B )
{
    Complex C ;
    int term1 =  A.return_real_part() * B.return_real_part() -  A.return_imaginary_part() * B.return_imaginary_part() ;
    int term2 = A.return_real_part() * B.return_imaginary_part() + A.return_imaginary_part() * B.return_real_part() ;
    C.set_real_part(term1) ;
    C.set_imaginary_part(term2) ;
    return C ;
}

Complex divide ( Complex A, Complex B )
{
    Complex C, D, E, F ;
    E.set_real_part(B.return_real_part()) ;
    E.set_imaginary_part( B.return_imaginary_part() * (-1) ) ;
    C = multiply ( A, E ) ;
    D = multiply ( B, E ) ;
    F.set_real_part((double)multiply( A, E ).return_real_part() / (double)multiply ( B, E ).return_real_part()) ;
    F.set_imaginary_part((double)multiply ( A, E ).return_imaginary_part() / (double)multiply ( B, E ).return_real_part()) ;
    return F ;
}
