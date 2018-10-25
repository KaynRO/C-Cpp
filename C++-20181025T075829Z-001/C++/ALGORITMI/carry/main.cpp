#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector < int > SOL ;
int L1[5], L2[5], C1, C2, T, best = 0 ;

void sortL()
{
    sort ( L1 + 1, L1 + 3 + 1 ) ;
    sort ( L2 + 1, L2 + 3 + 1 ) ;
}

int main()
{
    cin >> T ;
    for ( int i = 1 ; i <= T ; i++ )
    {
        best = 0 ;
        cin >> L1[1] >> L1[2] >> L1[3] >> C1 >> L2[1] >> L2[2] >> L2[3] >> C2 ;
        sortL() ;
        if ( C1 >= C2 )
            if ( L1[3] >= L2[2] && L1[2] >= L2[1] )
                best = C1 + C2 ;
        if ( best == 0 )
            best = 2 * ( min ( C1 , C2 ) ) ;
        SOL.push_back(best) ;
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
