#include <fstream>
#include <algorithm>
#define NMAX 1250

using namespace std ;

ofstream fout ( "scara3.out" ) ;
int step[NMAX], cost[NMAX] ;
int Water[NMAX] ;
int Energy[NMAX] ;
int main()
{
    int N , Waters , Energisers ;
    freopen ( "scara3.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &N , &Waters ) ;
    for( int i = 1 ; i <= Waters ; i++ )
    {
        scanf ( "%d %d" , &index , &value ) ;
        Water[index] = value ;
    }
    scanf ( "%d" , &Energisers ) ;
    for( int i = 1 ; i <= Energisers ; i++ )
    {
        scanf ( "%d %d" , &index , &value ) ;
        Energy[index] = value ;    
    }

    step[1] = 1;
    cost[1] = 0;
    for( int i = 2 ; i <= N ; i++ )
    {
        step[i] = step[i - 1] + 1 ;
        cost[i] = cost[i - 1] ;
        for( int j = i - 1 ; j ; j-- )
        {
            if(j + Water[j] >= i)
            {
                if(step[i] > step[j] + 1)
                {
                    step[i] = step[j] + 1 ;
                    cost[i] = cost[j] ;
                      
                }
                else if(step[i] == step[j] )
                    cost[i] = min(cost[i], cost[j]) ;
                            
            }
            if(j + 2 * Energy[j] >= i )
            {
                q = (i - j) / 2 + (i - j) % 2 ;
                if( step[i] > step[j] + 1 )
                {
                    step[i] = step[j] + 1 ;
                    cost[i] = cost[j] + q ;
                                    
                }
                else if( step[i] == step[j] + 1 )
                    cost[i] = min( cost[i], cost[j] + q ) ;
                        
            }        
        }    
    }
    fout << step[n] << ' ' << cost[n] << '\n';
    return 0 ;
}
