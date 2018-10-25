#include <fstream>

using namespace std;

ifstream fin( "rucsac.in" ) ;
ofstream fout( "rucsac.out" ) ;
int n , g ;
int w , p ;
int i , j ;
int c [10001] ;

int main()
{
    fin >> n >> g ;
    for ( i = 1 ; i <= n ; i++ )
    {
        fin >> w >> p ;
        for ( j = g ; j >= 0 ; j-- )
            if ( w <= j )
                c[j] = max ( c[j] , c[j-w] + p ) ;
    }
    fout << c[g] ;
    return 0;
}
