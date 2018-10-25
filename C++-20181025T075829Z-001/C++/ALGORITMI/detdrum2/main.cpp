#include <fstream>
#include <vector>

using namespace std;

ifstream fin ( "detdrum2.in" ) ;
ofstream fout ( "detdrum2.out" ) ;

vector<int> Son[200] ;

int n , p , q , father[200] , wayp[200] , wayq[200] , begp , begq ;

int main()
{
    fin >> n >> p >> q ;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> father[i] ;
    int node = p ;
    while ( node != 0 )
    {
        wayp[++begp] = node ;
        node = father[node] ;
    }
    node = q ;
    while ( node != 0 )
    {
        wayq[++begq] = node ;
        node = father[node] ;
    }
    int ii = 0 , jj = 0 ;
    for ( int i = 1 ; i <= begp ; i++ )
    {
        for ( int j = 1 ; j <= begq ; j++ )
            if ( wayp[i] == wayq[j] )
            {
                ii = i ;
                jj = j ;
                break ;
            }
        if ( ii != 0 )
            break ;
    }
    for ( int i = 1 ; i < ii ; i++ )
        fout << wayp[i] << ' ' ;
    for ( int j = jj  ; j >= 1 ; j-- )
        fout << wayq[j] << ' ' ;
    return 0 ;
}
