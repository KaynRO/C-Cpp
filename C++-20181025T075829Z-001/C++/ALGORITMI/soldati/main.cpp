#include <fstream>
#include <vector>

using namespace std;

ofstream fout ( "soldati.out" ) ;
int n , m , used[17000] , st , beg , win[17000] , lose[17000] , soldier[17000] ;
vector <int> G[17000] , Day[17000] ;

void read()
{
    int x , y , i ;
    freopen ( "soldati.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &n , &m ) ;
    for ( i = 1 ; i <= m ; i++ )
    {
        scanf ( "%d %d" , &x , &y ) ;
        G[y].push_back(x) ;
        win[x]++ ;
        lose[y]++ ;
    }
}

void src()
{
    for ( int i = 1 ; i <= n ; i ++ )
        if ( win[i] > 0 && lose[i] == 0 )
        {
            Day[1].push_back(i) ;
            used[i] = 1 ;
            soldier[i] = 1 ;
        }
}

int not_end()
{
    for ( int i = 1 ; i <= n ; i++ )
        if ( used[i] == 0 ) return 1 ;
    return 0 ;
}

void solve()
{
    src() ;
    st = 1 ;
    int ok = 0 ;
    while ( not_end() )
    {
        st++ ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            ok = 0 ;
            if ( used[i] == 0 )
            {
                if ( G[i].size() >= 1 )
                {
                    for ( int j = 0 ; j <= G[i].size() - 1 ; j++ )
                        if ( soldier[G[i][j]] <= st - 1 && soldier[G[i][j]] > 0 )
                            ok = 1 ;
                            else break ;
                }
                if ( ok == 1 )
                {
                    Day[st].push_back(i) ;
                    used[i] = 1 ;
                    fout << i << ' ' << st << endl ;
                    soldier[i] = st ;
                }
            }
        }
    }
    fout << st ;
}
int main()
{
    read() ;
    solve() ;
    return 0;
}
