#include <fstream>
#include <cmath>
using namespace std;

ifstream fin ( "banda1.in" ) ;
ofstream fout ( "banda1.out" ) ;

int g[30] , n , gmax ;

int main()
{
    int sum = 0 ;
    fin >> n >> gmax ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        fin >> g[i] ;
        sum += g[i] ;
    }
     double x = double( double(sum) / double(gmax)) ;
    fout << ceil(x) + 1;
    return 0;
}
