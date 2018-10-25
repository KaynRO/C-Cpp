#include <fstream>
#include <queue>
#include <map>
#define NMAX 510 ;

using namespace std ;

ofstream fout ( "razboi.out" ) ;

int N , M , retreat_node ;
map < int , map < int , int > > G ;

void read()
{
    freopen ( "razboi.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &N , &M ) ;
    int x , y , cost ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf ( "%d %d %d" , &x , &y , &cost ) ;
        G[x][y] = cost ;
    }
    scanf ( "%d" , &retreat_node ) ;
}

int verify ( int node )
{
    if ( G[node].size() == N - 1 )
        return 1 ;
    return 0 ;
}

void roy_floyd()
{
    for ( int k = 1 ; k <= N ; k++ )
        for ( map < int , int > :: iterator i = G[k].begin() ; i != G[k].end() ; ++i )
            for ( map < int , int > :: iterator j = G[i->first].begin() ; j != G[i->first].end() ; ++j )
                if ( G[k].find ( j->first ) != G[k].end() && G[k][j->first] > i->second + j->second )
                    G[k][j->first] = i->second + j->second ;
                else
                {
                    G[k].insert ( make_pair ( j->first , 0 ) ) ;
                    G[k][j->first] = i->second + j->second ;
                }
}

void first_part()
{
    int MAX_local = -1 ;
    if ( verify ( retreat_node ) )
    {
        for (  map < int , int >  :: iterator it = G[retreat_node].begin() ; it !=G[retreat_node].end() ; ++it )
            if ( it->second > MAX_local )
                MAX_local = it->second ;
        fout << MAX_local << '\n' ;
    }
    else fout << "0" << '\n' ;
}

void print()
{
    for ( int i = 1 ; i <= N ; i++ )
    {
        for ( map < int , int > :: iterator it = G[i].begin() ; it != G[i].end() ; ++it )
            fout << i << ' ' << it->first << ' ' << it->second << '\n' ;
    }
}

int main()
{
    read() ;
    roy_floyd() ;
    first_part() ;
    print() ;
    return 0;
}
