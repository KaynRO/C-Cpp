#include <iostream>
#include <fstream>

using namespace std ;
ofstream fout ( "cuv.out" ) ;

int n, m ;
char alfabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v','w', 'x', 'y', 'z' } ;
char sol[100] ;

void print()
{
    for ( int i = 1 ; i <= m ; i++ )
        cout << sol[i] ;
    cout << '\n' ;
}
void bkt ( int k )
{
    if ( k >= m + 1 )
        print() ;
    else
    {
        for ( int i = 0 ; i <= n - 1 ; i++ )
        {
            sol[k] = alfabet[i] ;
            bkt( k + 1 ) ;
        }
    }
}

int main()
{
    cin >> n >> m ;
    bkt(1) ;
    return 0;
}
