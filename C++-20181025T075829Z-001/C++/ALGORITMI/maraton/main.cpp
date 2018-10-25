#include <fstream>
#include <cmath>

using namespace std ;

ifstream fin ( "maraton.in" ) ;
ofstream fout ( "maraton.out" ) ;

int N , Q , st[100100] ;

int main()
{
    int  distance , speed , time ;
    fin >> N ;
    for ( int i = 1 ; i <= N ; i++ )
    {
        fin >> distance >> speed ;
        time = distance / speed ;
        if ( distance % speed != 0  )
        time++ ;
        st[time] ++ ;
    }
    fin >> Q ;
    for ( int i = 1 ; i <= 100050 ; i++ )
        st[i] += st[i-1] ;
    for ( int i = 1 ; i <= Q ; i++ )
    {
        fin >> time ;
        fout << st[time] << '\n' ;
    }
    return 0;
}
