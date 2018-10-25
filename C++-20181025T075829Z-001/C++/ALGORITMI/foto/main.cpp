#include <iostream>

using namespace std ;

int N, M, A[105][105] ;

int main()
{
    cin >> N >> M ;
    int minLinie = N, maxLinie = 1, minColoana = M, maxColoana = 1, element ; // initial poza are dimensiunile matricei

    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= M ; j++ )
        {
            cin >> element ;
            A[i][j] = element ;
            if ( element == 1 )
            {
                if ( i < minLinie ) // daca gasim un element inafara dimensiunilor pozei curente le schimbam ;
                    minLinie = i ;
                if ( i > maxLinie )
                    maxLinie = i ;
                if ( j < minColoana )
                    minColoana = j ;
                if ( j > maxColoana )
                    maxColoana = j ;
            }
        }

    cout << maxLinie - minLinie + 1 << ' ' << maxColoana - minColoana + 1 << '\n' ; // dimensiunile pozei
    for ( int i = minLinie ; i <= maxLinie ; i++ )
    {
        for ( int j = minColoana ; j <= maxColoana ; j++ ) // afisam din matrice liniile si coloanele respectiv
            cout << A[i][j] << ' ' ;
        cout << '\n' ;
    }
    return 0 ;
}
