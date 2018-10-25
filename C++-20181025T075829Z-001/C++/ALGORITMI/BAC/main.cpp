#include <iostream>

using namespace std;

int main()
{
    int x , y ;
    for (  x = 1 ; x <= 10 ; x++ )
        for ( y = 6 ; y <= 10 ; y++ )
        if ( x * ( y - 5 ) >= 0 )
        cout << "DA" << '\n' ;
    return 0;
}
