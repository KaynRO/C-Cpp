#include <iostream>
#include <vector>
#include <bitset>
#define NMAX 2000

using namespace std ;

vector < int > G[NMAX], comp[NMAX] ;
int N, M, x, y, nrComp, used[NMAX] ;
bool ok = true ;

void DFS ( int node )
{
    used[node] = 1 ;
    comp[nrComp].push_back(node) ;
    for ( vector < int > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
        if ( !used[*it] )
            DFS(*it) ;
}

int main()
{
    cin >> N >> M ;
    if ( M == 0 )
        for ( int i = 1 ; i <= N ; i += 3 )
            cout << i << ' ' << i + 1 << ' ' << i + 2 << '\n' ;
    else
    {
        for ( int i = 1 ; i <= M ; i++ )
            cin >> x >> y, G[x].push_back(y), G[y].push_back(x) ;

        for ( int i = 1 ; i <= N ; i++ )
            if ( !used[i] && G[i].size() != 0 )
            {
                nrComp++ ;
                DFS(i) ;
            }

        for ( int i = 1 ; i <= nrComp ; i++ )
            if ( comp[i].size() == 2 )
                for ( int ii = 1 ; ii <= N ; ii++ )
                    if ( G[ii].size() == 0 )
                    {
                        comp[i].push_back(ii), G[ii].push_back(comp[i][0]), G[ii].push_back(comp[i][1]), G[comp[i][1]].push_back(ii),
                             G[comp[i][0]].push_back(ii) ;
                        break ;
                    }

        for ( int i = 1 ; i <= N ; i++ )
        {
            if ( G[i].size() == 0 )
            {
                for ( int ii = 1 ; ii <= N ; ii++ )
                    if ( G[ii].size() == 0 && ii != i )
                    {
                        ++nrComp ;
                        comp[nrComp].push_back(ii), comp[nrComp].push_back(i), G[i].push_back(ii), G[ii].push_back(i) ;
                        break ;
                    }
                for ( int ii = 1 ; ii <= N ; ii++ )
                    if ( G[ii].size() == 0 && ii != i )
                    {
                        comp[nrComp].push_back(ii) ;
                        G[ii].push_back(comp[nrComp][0]), G[ii].push_back(comp[nrComp][1]),
                        G[comp[nrComp][1]].push_back(ii), G[comp[nrComp][0]].push_back(ii) ;
                        break ;
                    }
            }
        }
        for ( int i = 1 ; i <= nrComp ; i++ )
            if ( comp[i].size() != 3 && comp[i].size() != 0 )
            {
                cout << "-1" ;
                return 0 ;
            }
        for ( int i = 1 ; i <= nrComp ; i++ )
        {
            for ( int j = 0 ; j <= 2 ; j++ )
                cout << comp[i][j] << ' ' ;
            cout << '\n' ;
        }
    }
    return 0 ;
}
