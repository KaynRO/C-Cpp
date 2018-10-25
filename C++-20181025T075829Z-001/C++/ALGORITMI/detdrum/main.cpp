#include <fstream>

using namespace std;

ifstream fin ( "detdrum1.in" ) ;
ofstream fout ( "detdrum1.out" ) ;

int n , node , father[200] , way[200] ;

int main()
{
    fin >> n >> node ;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> father[i] ;
    int start = node ;
    int beg = 0 ;
    while ( start != 0 )
    {
        way[++beg] = start ;
        start = father[start] ;
    }
    for ( int i = beg ; i >= 1 ; i-- )
        fout << way[i] << ' ' ;
    return 0;
}
