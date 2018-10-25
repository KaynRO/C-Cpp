#include <fstream>

using namespace std ;

ifstream fin ( "dmin2.in" ) ;
ofstream fout ( "dmin2.out" ) ;


int main()
{
    int N , M ;
    fin >> N >> M ;
    fout << ( ( N - 1 ) * ( N - 2 ) ) / 2 - M ;
    return 0;
}
