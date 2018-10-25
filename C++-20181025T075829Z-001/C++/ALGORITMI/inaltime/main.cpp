#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

ifstream fin ( "inaltime.in" ) ;
ofstream fout ( "inaltime.out" ) ;

struct tip
{
    int x ;
    int y ;
} ;
queue<tip> Q ;
vector<int> L[200] , Son[200] ;
int n ;

int main()
{
    fin >> n ;
    int value , radix ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        fin >> value ;
        Son[value].push_back(i) ;
        if ( value == 0 )
            radix = i ;
    }
    tip info ;
    info.x = radix ;
    info.y = 1 ;
    Q.push( info ) ;
    while ( !Q.empty() )
    {
        tip data = Q.front() ;
        int k = data.x ;
        int lev = data.y ;
        L[lev].push_back(k) ;
        Q.pop() ;
        for ( vector<int> :: iterator it = Son[k].begin() ; it != Son[k].end() ; ++it )
        {
            info.x = *it ;
            info.y = lev + 1 ;
            Q.push(info) ;
        }
    }
    for ( int i = n ; i >= 1 ; i-- )
        if ( L[i].size() > 0 )
        {
            fout << i << ' ' ;
            break ;
        }
    return 0;
}
