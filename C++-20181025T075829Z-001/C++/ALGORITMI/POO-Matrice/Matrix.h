#include <fstream>
#define NMAX 900

using namespace std ;

class Matrix
{
public :
    int lines ;
    int colomns ;
    int X[NMAX][NMAX] ;
public :
    void set_element ( int line, int colomn, int value ) ;
    int return_value ( int line, int colomn ) ;
    void set_colomns ( int value ) ;
    void set_lines ( int value ) ;
    void read( ifstream& fin ) ;
    void print( ofstream& fout ) ;
};

Matrix add ( Matrix X1, Matrix X2 ) ;
Matrix multiply ( Matrix X1, Matrix X2 ) ;
Matrix substract ( Matrix X1, Matrix X2 ) ;
