#include <fstream>
#define NMAX 1000005

using namespace std ;

ifstream fin ( "stalpisori.in" ) ;
ofstream fout ( "stalpisori.out" ) ;

int V[NMAX], N, K ;

int main()
{
    fin >> N >> K ;

    for (  int i = 1 ; i <= N ; ++i )
        fin >> V[i] ;

    int st = 1, dr = K, maxx1 = 0, maxx2 = 0 ;

    for ( int i = 1 ; i <= N ; ++i )
    {
        while ( V[dr + 1] - V[i] < V[i] - V[st] && st <= i && dr <= N )
            st++, dr++ ;
        maxx2 = max ( V[i] - V[st], V[dr] - V[i] ) ;
        maxx1 = max ( maxx1, maxx2 ) ;
    }

    fout << maxx1 ;

    return 0;
}
