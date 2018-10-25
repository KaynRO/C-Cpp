#include "Matrix.h"

void Matrix::set_element ( int line, int colomn, int value )
{
    X[line][colomn] = value ;
}

int Matrix::return_value ( int line, int colomn )
{
    return X[line][colomn] ;
}

void Matrix::set_lines ( int value )
{
    lines = value ;
}

void Matrix::set_colomns ( int value )
{
    colomns = value ;
}

void Matrix::read ( ifstream& fin )
{
    int value ;
    fin >> lines >> colomns ;
    set_colomns(colomns) ;
    set_lines(lines) ;
    for ( int line_index = 1 ; line_index <= lines ; line_index++ )
        for ( int colomn_index = 1 ; colomn_index <= colomns ; colomn_index++ )
        {
            fin >> value ;
            set_element ( line_index, colomn_index, value ) ;
        }
}

void Matrix::print ( ofstream& fout )
{
    for ( int line_index = 1 ; line_index <= lines ; line_index++ )
    {
        for ( int colomn_index = 1 ; colomn_index <= colomns ; colomn_index++ )
            fout << return_value ( line_index, colomn_index ) << ' ' ;
        fout << '\n' ;
    }
}

Matrix add ( Matrix X1, Matrix X2 )
{
    Matrix X3 ;
    X3.set_lines( X1.lines ) ;
    X3.set_colomns( X1.colomns ) ;
    for ( int line_index = 1 ; line_index <= X1.lines ; line_index++ )
        for ( int colomn_index = 1 ; colomn_index <= X1.colomns ; colomn_index++ )
            X3.set_element ( line_index, colomn_index, X1.return_value ( line_index, colomn_index ) + X2.return_value ( line_index, colomn_index ) ) ;
    return X3 ;
}

Matrix substract ( Matrix X1, Matrix X2 )
{
    Matrix X3 ;
    X3.set_lines( X1.lines ) ;
    X3.set_colomns( X1.colomns ) ;
    for ( int line_index = 1 ; line_index <= X1.lines ; line_index++ )
        for ( int colomn_index = 1 ; colomn_index <= X1.colomns ; colomn_index++ )
            X3.set_element ( line_index, colomn_index, X1.return_value ( line_index, colomn_index ) - X2.return_value ( line_index, colomn_index ) ) ;
    return X3 ;
}

Matrix multiply ( Matrix X1, Matrix X2 )
{
    Matrix X3 ;
    X3.set_lines ( X1.lines ) ;
    X3.set_colomns ( X2.colomns ) ;
    for ( int index_line = 1 ; index_line <= X1.lines ; index_line++ )
        for ( int index_colomn = 1 ; index_colomn <= X2.colomns ; index_colomn++ )
            for ( int index_lline = 1 ; index_lline <= X1.colomns ; index_lline++ )
                X3.set_element ( index_line, index_colomn,  X3.return_value ( index_line, index_colomn ) + X1.return_value( index_line, index_lline ) * X2.return_value ( index_lline, index_colomn ) ) ;
    return X3 ;
}
