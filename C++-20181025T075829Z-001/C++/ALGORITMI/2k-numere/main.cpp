#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

ofstream fout ( "knumere.out" ) ;

map<long long,int> M ;
map<long long,int> ::iterator it ;
int n , m , x ;

void read()
{
    freopen ( "knumere.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        scanf ( "%d" , &x ) ;
        if ( M.find(x) != M.end() )
            M[x]++ ;
        else
            M.insert ( make_pair( x , 1 ) ) ;
    }
}
int main()
{
    read() ;
    for ( it = M.begin() ; it != M.end() ; ++it )
        if ( it->second == 1 )
            fout << it->first << ' ' ;
    fout << sizeof(M) ;
    return 0;
}
