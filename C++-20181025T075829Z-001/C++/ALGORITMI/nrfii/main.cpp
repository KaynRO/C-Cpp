#include <fstream>
#include <vector>

using namespace std;

ifstream fin ( "nrfii.in" ) ;
ofstream fout ( "nrfii.out" ) ;

vector<int> Son[200] ;
int n ;

int main()
{
    int value ;
    fin >> n ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        fin >> value ;
        Son[value].push_back(i) ;
    }
    int maxim = 0 ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( Son[i].size() > maxim )
            maxim = Son[i].size() ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( Son[i].size() == maxim )
            fout << i << ' ' ;

    return 0;
}
