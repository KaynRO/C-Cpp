#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin ( "mere.in" ) ;
ofstream fout ( "mere.out" ) ;

int nr ;
int matrix [250][250] ;
bool use[250] ;
int numbers = 0 ;

struct apple
{
    int x ;
    int y ;
    int z ;
    int r ;
} apl[250] ;

void read ()
{
    fin >> nr ;
    for ( int i = 1 ; i <= nr ; i ++ )
    {
        fin >> apl[i].x >> apl[i].y >> apl[i].z >> apl[i].r ;
        apl[i].z = apl[i].z - apl[i].r ;
    }

}

int pw ( int x )
{
    return x * x ;
}
void touch ()
{

    int k , j ;
    for ( j = 1 ; j <= nr ; j++ )
        for ( k = 1 ; k <= nr ; k++ )
            if ( pw( ( apl[j].x - apl[k].x ) )  + pw( ( apl[j].y - apl[k].y ) )  <= pw ( apl[j].r + apl[k].r  ) )
                if ( apl[k].z < apl[j].z )
                    matrix[j][k] = 1;

}

void walk ( int x )
{
    long int i ;
    use[x] = true ;
    for ( i = 1 ; i <= nr ; i++ )
        if ( matrix[x][i] && !use[i] )
        {
            numbers ++ ;
            walk(i);
        }
}

int print()
{
    for ( int i = 1 ; i <= nr ; i++ )
    {
        for ( int j = 1 ; j <= nr ; j ++ )
            fout << matrix[i][j] << ' ' ;
        fout << '\n' ;
    }

}
int main()
{
    read() ;
    touch () ;
    walk(1) ;
    //print() ;
    fout << numbers + 1;
    return 0;
}
