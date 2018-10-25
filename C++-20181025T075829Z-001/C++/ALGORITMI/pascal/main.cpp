#include <iostream>

using namespace std;

int combinari ( int n , int m )
{
    if ( n == m ) return 1 ;
    else if ( m == 1 ) return n ;
    else return combinari ( n - 1 , m - 1 ) + combinari ( n - 1 , m ) ;
}
int main()
{
    int n , m ;
    cin >> n >> m ;
    cout << combinari ( n , m ) ;
    return 0;
}
