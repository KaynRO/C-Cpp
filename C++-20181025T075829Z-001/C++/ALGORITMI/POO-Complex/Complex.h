#include <fstream>

using namespace std ;

class Complex
{
  public :
    double real_part ;
    double imaginary_part ;
  public :
    double return_real_part () ;
    double return_imaginary_part () ;
    void set_real_part ( double value ) ;
    void set_imaginary_part ( double value ) ;
    void read(ifstream& fin) ;
    void print(ofstream& fout) ;
};

Complex add ( Complex A , Complex B ) ;
Complex substract ( Complex A , Complex B ) ;
Complex multiply ( Complex A , Complex B ) ;
Complex divide ( Complex A , Complex B ) ;
