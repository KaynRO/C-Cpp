#include <fstream>
#include <map>

using namespace std ;

ifstream fin ( "castel.in" ) ;
ofstream fout ( "castel.out" ) ;

int n , val[1200] , key[15] , keys ;
map < int , int > M ;

void insert_map ( int x )
{
    int dup = x ;
    while ( dup != 0 )
    {
        int last = dup % 10 ;
        M[last] = M[last] + 1 ;
        dup = dup / 10 ;
    }
}

int main()
{
    fin >> n ;
    for ( int i = 1 ; i <= 9 ; i++ )
        M.insert ( make_pair ( i , 0 ) ) ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        fin >> val[i] ;
        insert_map(val[i]) ;
    }
    fin >> keys ;
    for ( int i = 1 ; i <= keys ; i++ )
        fin >> key[i] ;
    int maxim = -1 , index = 0 ;
    for ( int i = 1 ; i <= keys ; i++ )
        if ( M[key[i]] > maxim )
        {
            maxim = M[key[i]] ;
            index = key[i] ;
        }
    fout << index << ' ' << maxim ;
    return 0 ;
}
