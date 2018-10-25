#include <iostream>
#define NMAX 1200

using namespace std ;

int TT[NMAX] , T , value , node ;

void read()
{
    cin >> T ;
    cout << "Case 1:" << '\n' ;

    for ( int i = 1 ; i <= T ; i++ )
        cin >> value ;
    for ( int j = 1 ; j <= value ; j++ )
        cin >> node,TT[node] = i ;
}

int main()
{
    read() ;
    return 0;
}
