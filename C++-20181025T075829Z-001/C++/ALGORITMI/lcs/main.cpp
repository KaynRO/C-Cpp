#include <fstream>
#include <cstring>

using namespace std;

ifstream fin ( "lcs.in" ) ;
ofstream fout ( "lcs.out" ) ;
int n , m ;
char A[200] , B[200] ;

int lcs ( int n , int m )
{
    if ( n == 1 || m == 1 )
    {
        if ( A[n] == B[m] )
            return 1 ;
        else
            return 0 ;
    }
    else
    {
        if ( A[n] == B[m] )
            return lcs ( n - 1 , m - 1 ) + 1 ;
        else
        {
            return lcs ( n - 1 , m ) ;
            return lcs ( n , m - 1 ) ;
        }
    }
}

int main()
{
    fin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> A[i] ;
    for ( int i = 1 ; i <= m ; i++ )
        fin >> B[i] ;
    fout << lcs ( n , m ) ;
    return 0;
}
