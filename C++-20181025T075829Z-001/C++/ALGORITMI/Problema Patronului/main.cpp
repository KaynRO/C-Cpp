#include <iostream>
#define NMax 61
#define LMax 201

using namespace std;

int n , L ;
int g[NMax] , Nr[LMax] , Uz[LMax][NMax] ;

int main()
{
    Nr[0] = 0 ;
    cin >> n >> L ;
    for ( int i = 1 ; i <= n ; i++ )
        cin >> g[i] ;
    int S , k , i ;
    for ( S = 1 ; S <= L ; ++S )
        for ( Nr[S] = -1 , i = 1 ; i <= n ; i++ )
            if ( g[i] <= S && Nr[S-g[i]] != -1 && !Uz[S-g[i]][i] )
                if ( Nr[S] < 1 + Nr[S-g[i]] )
                {
                    Nr[S] = 1 + Nr[S-g[i]] ;
                    for ( k = 1 ; k <= n ; k++ )
                        Uz[S][k] = Uz[S-g[i]][k] ;
                    Uz[S][i] = 1 ;
                }
    if ( Nr[L] == -1 ) cout << "IMPOSIBIL" ;
    else
    {
        for ( int i = 1 ; i <= n ; i++ )
            if ( Uz[L][i8] ) cout << g[i] << ' ' ;
    }

    return 0;
}
