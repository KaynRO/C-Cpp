#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#define NMAX 100005
using namespace std ;

ofstream fout ( "arbore.out" ) ;

int N , M , TT[NMAX] , Wage[NMAX] ;
vector<int> SS[NMAX] ;

void update ( int root , int increase )
{
    Wage[root] += increase ;
    for ( vector < int > :: iterator it = SS[root].begin() ; it != SS[root].end() ; ++it )
        Wage[*it] += increase ;
}

int find_employee ( int salary )
{
    for ( int i = 1 ; i <= N ; i++ )
        if ( Wage[i] == salary )
        {
            fout << i << '\n' ;
            return 0 ;
        }
    fout << "-1" ;
    return 0 ;
}

void read()
{
    int x , y , operation , increase , root , salary ;
    freopen ( "arbore.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &N , &M ) ;
    for ( int i = 1 ; i <= N - 1 ; i++ )
    {
        scanf ( "%d %d" , &x , &y ) ;
        TT[y] = x ;
        SS[x].push_back(y) ;
    }
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf ( "%d" , &operation ) ;
        if ( operation == 1 )
        {
            scanf ( "%d %d" , &root , &increase ) ;
            update ( root , increase ) ;
        }
        if ( operation == 2 )
        {
            scanf ( "%d" , &salary ) ;
            find_employee( salary ) ;
        }
    }
}

int main()
{
    read() ;
    return 0;
}
