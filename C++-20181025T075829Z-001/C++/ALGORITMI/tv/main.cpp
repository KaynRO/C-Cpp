#include <fstream>
#include <vector>
#define NMAX 3006

using namespace std ;

ifstream fin ( "tv.in" ) ;
ofstream fout ( "tv.out" ) ;

int N , M ;
vector < pair < int , int > > H[NMAX] ;

int main()
{
    fin >> N >> M ;
    for ( int i = 1 ; i <= N - M ; i++ )
    {
        fin >> k ;
        for ( int j = 1 ; j <= k ; j++ )
        {
            fin >> index >> cost ;
            H[1].push_back( make_pair ( index ,cost ) ) ;

        }
    }

    return 0;
}
