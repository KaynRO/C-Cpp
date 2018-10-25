#include <fstream>
#include <algorithm>
#define inf 5000000
using namespace std;

ofstream fout ( "razboi.out" ) ;
int n , m , cost[520][520] , node ;
struct nod
{
    int index ;
    int value ;
} Node[520] ;

void set_cost()
{
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= n ; j++ )
            if ( i != j )
                cost[i][j] = cost[j][i] = inf ;
}
void read()
{
    int x , y , z ;
    freopen ( "razboi.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &n , &m ) ;
    set_cost() ;
    for ( int i = 1 ; i <= m ; i++ )
    {
        scanf ( "%d %d %d" , &x , &y , &z ) ;
        cost[x][y] = z ;
    }
    scanf ( "%d" , &node ) ;
}

void roy_floyd()
{
    int i, j, k ;
    for ( k = 1 ; k <= n ; k++ )
        for ( i = 1 ; i <= n ; i++ )
            for ( j = 1 ; j <= n ; j++ )
                if ( cost[i][k] && cost[k][j] && ( cost[i][j] > cost[i][k] + cost[k][j] || !cost[i][j]) && i != j )
                    cost[i][j] = cost[i][k] + cost[k][j];
}

int  part_one()
{
    for ( int i = 1 ; i <= n ; i++ )
        if ( cost[i][node] == inf )
        {
            fout << "0" << '\n' ;
            return 0 ;
        }
    int maxloc = -1 ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( cost[i][node] > maxloc )
            maxloc = cost[i][node] ;
    fout << maxloc << '\n' ;
    return 0 ;
}

int ok( int node )
{
    for ( int i = 1 ; i <= n ; i++ )
        if ( cost[i][node] == inf )
            return 0 ;
    return 1 ;
}

bool compare ( nod a , nod b )
{
    return a.value < b.value || ( a.value == b.value && a.index < b.index ) ;
}

int part_two()
{
    for ( int i = 1 ; i <= n ; i++ )
    {
        Node[i].index = i ;
        Node[i].value = 0 ;
        if ( ok(i) )
        {
            for ( int j = 1 ; j <= n ; j++ )
                Node[i].value = max ( Node[i].value , cost[j][i] ) ;
        }
    }
    sort ( Node + 1 , Node + n + 1 , compare ) ;
    for ( int i = 1 ; i <= n  ; i++  )
        if ( Node[i].value != 0 )
        {
            fout << Node[i].index << ' ' << Node[i].value ;
            return 0 ;
        }
    fout << "0" ;
    return 0 ;
}

int main()
{
    read() ;
    roy_floyd() ;
    part_one() ;
    part_two() ;
    return 0;
}
