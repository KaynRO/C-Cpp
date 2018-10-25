#include <stdio.h>
#include <stdlib.h>

int** transpune ( int **mat, int ln, int cn )
{
    int i, j ;

    int **matrix = (int** ) malloc ( ln * sizeof(int*) ) ;
    for ( i = 0 ; i <= ln - 1 ; i++ )
        matrix[i] = (int*) calloc ( cn, sizeof(int) ) ;


    for ( i = 0 ; i <= ln - 1 ; i++ )
        for ( j = 0 ; j <= cn - 1 ; j++ )
            matrix[j][i] = mat[i][j] ;


    return matrix;

}

int main()
{
    int i ;

    int **matrice = (int**) malloc ( 100 * sizeof(int*) ) ;
    for ( i = 0 ; i <= 99 ; i++ )
        matrice[i] = (int*) calloc ( 100, sizeof(int) ) ;

    int **mt = transpune(matrice, 100 , 100) ;

    return 0 ;
}
