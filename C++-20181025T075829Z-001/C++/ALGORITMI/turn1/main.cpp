#include <fstream>
#include <vector>
#include <queue>
#include <cstdlib>
#define NMAX 10006

using namespace std ;

ifstream fin ( "turn1.in" ) ;
ofstream fout ( "turn1.out" ) ;

int N , M , vis[NMAX] , comp , nrcomp[NMAX] ;
vector < int > G[NMAX] ;
queue < int > Q ;

void BFS ( int node )
{
    ++comp ;
    Q.push(node) ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        vis[k] = comp ;
        Q.pop() ;
        for ( vector < int > :: iterator it = G[k].begin() ; it != G[k].end() ; ++it )
            if ( vis[*it] == 0 )
                Q.push(*it) ;
    }
}

int main()
{
    int x , y ;
    fin >> N >> M ;
    if ( M == 0 )
    {
        fout << "1 2" ;
        exit(0) ;
    }
    for ( int i = 1 ; i <= M ; i++ )
    {
        fin >> x >> y ;
        G[x].push_back(y) ;
        G[y].push_back(x) ;
    }
    for ( int i = 1 ; i <= N ; i++ )
        if ( vis[i] == 0 )
            BFS(i) ;
    for ( int i = 1 ; i <= N ; i++ )
        nrcomp[vis[i]]++ ;
    int max1 = -1 , max2 = -1 , comp1 = 0  , comp2 = 0 ;
    for ( int i = 1 ; i <= comp ; i++ )
    {
        if ( nrcomp[i] == max1 )
        {
            max2 = max1 ;
            comp2 = i ;
        }
        if ( nrcomp[i] > max1 )
        {
            max2 = max1 ;
            comp2 = comp1 ;
            max1 = nrcomp[i] ;
            comp1 = i ;
        }
        if ( nrcomp[i] < max1 && nrcomp[i] > max2 )
        {
            max2 = nrcomp[i] ;
            comp2 = i ;
        }
    }
    for ( int i = 1 ; i <= N ; i++ )
        if ( vis[i] == comp1 )
        {
            fout << i << ' ' ;
            break ;
        }
    for ( int i = 1 ; i <= N ; i++ )
        if ( vis[i] == comp2 )
        {
            fout << i << ' ' ;
            break ;
        }
    return 0 ;
}
