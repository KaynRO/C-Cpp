#include <iostream>

using namespace std;

int V[1000009], Sum[1000009], N, K ;
int main()
{
    int bestLG = -1 , idxA , idxB ;
    cin >> N >> K ;
    for ( int i = 1 ; i <= N ; i++ )
    {
        cin >> V[i] ;
        Sum[i] = ( Sum[i - 1] + V[i] ) % K ;
    }
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = i + 1 ; j <= N ; j++ )
            if ( ( Sum[j] - Sum[i] + V[i] ) % K == 0 && j - i + 1  > bestLG )
                bestLG = j - i + 1, idxA = i, idxB = j ;
    if ( bestLG == -1 )
        cout << "-1" ;
    else
        cout << idxA - 1 << ' ' << idxA << ' ' << idxB ;
    return 0 ;
}
