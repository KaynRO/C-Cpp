#include <fstream>
#include <vector>
using namespace std ;

ofstream fout ( "clasic.out" ) ;

int T , N , value ;

void read()
{
    freopen ( "clasic.in", "r", stdin ) ;
    scanf( "%d", &T ) ;
    for ( int i = 1 ; i <= T ; i++ )
    {
        int sum = 0 ;
        scanf("%d", &N ) ;
        for ( int i = 1 ; i <= N ; i++ )
            scanf( "%d", &value ), sum = sum ^ value ;
        fout << sum << '\n' ;
    }
}

int main()
{
    read() ;
    return 0;
}
