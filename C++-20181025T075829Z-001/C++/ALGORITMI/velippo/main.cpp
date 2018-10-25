#include <iostream>
#include <vector>
using namespace std ;

int T ;
vector < unsigned long long > SOL ;


int main()
{
    cin >> T ;
    unsigned long long  sum ;
    unsigned long long x, y ;
    for ( int i = 1 ; i <= T ; i++ )
    {
        sum = 0 ;
        cin >> x >> y ;
        unsigned long long stl = 1 ;
        unsigned long long st = 1 ;
        unsigned long long dr  = 1 ;
        while ( st > 0 && dr > 0 )
        {
            st = ( x - stl + 1 ) ;
            dr = ( y - stl + 1 ) ;
            if ( st == 0 || dr == 0 || st < 0 || dr < 0 )
                break ;
            sum = sum + ( st * dr ) ;
            stl++ ;
        }
        SOL.push_back(sum) ;
    }
    int pos = 0 ;
    for ( auto it : SOL )
    {
        ++pos ;
        cout << it ;
        if ( pos != SOL.size() )
            cout << '\n' ;
    }
    return 0;
}
