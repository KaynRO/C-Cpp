#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#define NMAX 20000

using namespace std ;

ifstream fin ( "dezbateri.in" ) ;
ofstream fout ( "dezbateri.out" ) ;

int N , M , better[NMAX] ;
vector < int > G[NMAX] ;

void read()
{
    char line[150] ;
    fin >> N >> M ;
    if ( N == 1 )
    {
        fout << "1" ;
        exit(0) ;
    }
    fin.get() ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        fin.getline ( line , 150 ) ;
        char *p1 = strtok ( line , ">" ) ;
        char *p2 = strtok ( NULL , ">" ) ;
        char *comma = strstr ( p1 , "," ) ;
        if ( comma != NULL )
        {
            char *dx = strtok ( p1 , "," ) ;
            char *dy = strtok ( NULL , "," ) ;
            G[atoi(p2)].push_back(atoi(dx)) ;
            G[atoi(p2)].push_back(atoi(dy)) ;
            better[atoi(dx)]++ ;
            better[atoi(dy)]++ ;
        }
        else
        {
            char *dx = strtok ( p2 , "," ) ;
            char *dy = strtok ( NULL , "," ) ;
            G[atoi(dx)].push_back(atoi(p1)) ;
            G[atoi(dy)].push_back(atoi(p1)) ;
            better[atoi(p1)] += 2 ;
        }
    }
}

int find_solo()
{
    for ( int i = 1 ; i <= N ; i++ )
        if ( better[i] == 0 )
        {
            better[i] = -1 ;
            return i ;
        }
    return 0 ;
}

void solve()
{
    vector < int > sol ;
    int count = 0 ;
    int x = find_solo() ;
    while (x)
    {
        sol.push_back(x) ;
        count++ ;
        for ( vector < int > :: iterator it = G[x].begin() ; it != G[x].end() ; ++it )
            better[*it]-- ;
        x = find_solo() ;
    }
    if ( count == N )
        for ( vector < int > :: iterator it = sol.begin() ; it != sol.end() ; ++it )
            fout << *it << ' ' ;
    else fout << "0" ;
}

int main()
{
    read() ;
    solve() ;
    return 0 ;
}
