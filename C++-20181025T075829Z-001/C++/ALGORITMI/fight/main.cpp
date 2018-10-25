#include <iostream>
#define MAXIM 100009
#define INF 100000
#include <vector>

using namespace std ;

int H[4], A[4], D[4], T ;
vector < int > SOL ;
int prim[MAXIM] ;

void ciur()
{
    prim[1] = 1 ;
    for ( int i = 4 ; i <= INF ; i += 2 )
        prim[i] = 1 ;
    for ( int i = 3 ; i <= INF ; i+= 2 )
        if ( prim[i] == 0 )
            for ( int j = i + i + i ; j <= INF ; j += i << 1 )
                prim[j] = 1 ;
}

int simulate( int j )
{
    int round = 1 ;
    int player = j ;
    while ( H[player] > 0 )
    {
        int substract ;
        if ( prim[round] == 1 )
        {
            substract = D[player] > A[3-player] ? D[player] - A[3-player] : 0 ;
            H[3-player] = H[3-player] - substract ;
        }
        else
        {
            substract = D[player] * round > A[3-player] ? D[player] * round - A[3-player] : 0 ;
            H[3-player] = H[3-player] - substract ;
        }
        A[3-player] = A[3-player] > 1 ? A[3-player] - 1 : 0 ;
        player = 3-player ;
        if ( H[player] <= 0 )
            return 3-player ;
        if ( prim[round] == 1 )
        {
            substract = D[player] > A[3-player] ? D[player] - A[3-player] : 0 ;
            H[3-player] = H[3-player] - substract ;
        }
        else
        {
            substract = D[player] * round > A[3-player] ? D[player] * round - A[3-player] : 0 ;
            H[3-player] = H[3-player] - substract ;
        }
        A[3-player] = A[3-player] > 1 ? A[3-player] - 1 : 0 ;
        player = 3-player ;
        round++ ;
    }
    return 3-player ;
}

int main()
{
    cin >> T ;
    ciur() ;
    for ( int i = 1 ; i <= T ; i++ )
    {
        cin >> H[1] >> A[1] >> D[1] >> H[2] >> A[2] >> D[2] ;
        H[0] = H[1] ;
        A[0] = A[1] ;
        D[0] = D[1] ;
        H[3] = H[2] ;
        A[3] = A[2] ;
        D[3] = D[2] ;
        int winner1 = simulate(1) ;
        H[1] = H[0] ;
        A[1] = A[0] ;
        D[1] = D[0] ;
        H[2] = H[3] ;
        A[2] = A[3] ;
        D[2] = D[3] ;
        int winner2 = simulate(2) ;
        if ( winner1 != winner2 )
            SOL.push_back(3) ;
        else
            SOL.push_back(winner1) ;
    }
    for ( auto it : SOL )
        cout << it << '\n' ;
    return 0;
}
