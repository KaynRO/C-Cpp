#include <iostream>
using namespace std ;
int main()
{
  unsigned long long  n , m , prod = 1 ;
  cin >> m >> n ;
  if ( m > n ) cout << "0" ;
  else
  {
  for ( int i = 1; i <= m ; i++ )
    prod = (( prod % 224737 ) * ( ( n - m + 1 ) % 224737 ) ) % 224737 ;
  cout << prod % 224737 ;
  }
  return 0 ;
}
