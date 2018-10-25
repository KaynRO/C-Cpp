#include <fstream>
#include <algorithm>
#define NMAX 1250
#define INF ( 1 << 30 )

using namespace std ;

ofstream fout ( "scara3.out" ) ;

int step[NMAX] , cost[NMAX] , Water[NMAX] , Energy[NMAX] ;

int main()
{
    int nr_water , nr_energisers , index , value , N ;
    freopen ( "scara3.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &N , &nr_water ) ;
    for ( int i = 1 ; i <= nr_water ; i++ )
    {
        scanf ( "%d %d" , &index , &value ) ;
        Water[index] = value ;
    }
    scanf ( "%d" , &nr_energisers ) ;
    for ( int i = 1 ; i <= nr_energisers ; i++ )
    {
        scanf ( "%d %d" , &index , &value ) ;
        Energy[index] = value ;
    }
    for ( int i = 1 ; i <= N ; i++ )
        step[i] = cost[i] = INF ;
    step[1] = 1 ;
    cost[1] = 0 ;
    for ( int i = 2 ; i <= N ; i++ )
    {
        step[i] = step[i - 1] + 1 ;
        cost[i] = cost[i - 1] ;
        for ( int j = i - 1 ; j ; j-- )
        {
            if ( j + Water[j] >= i )
            {
                if ( step[i] > step[j] + 1 )
                {
                    step[i] = step[j] + 1 ;
                    cost[i] = cost[j] ;
                }
                else if ( step[i] == step[j] + 1 )
                    cost[i] = min ( cost[i] , cost[j] ) ;
            }
            if ( j + 2 * Energy[j] >= i )
            {
                int q = ( i - j ) / 2 + ( i - j ) % 2 ;
                if ( step[i] > step[j] + 1 )
                {
                    step[i] = step[j] + 1 ;
                    cost[i] = cost[j] + q ;

                }
                else if ( step[i] == step[j] + 1 )
                    cost[i] = min ( cost[i] , cost[j] + q ) ;
            }
        }
    }
    fout << step[N] << ' ' << cost[N] ;
    return 0 ;
}
