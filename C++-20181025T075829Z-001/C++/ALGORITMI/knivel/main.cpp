#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

ifstream fin ( "knivel.in" ) ;
ofstream fout ( "knivel.out" ) ;

struct tip
{
    int x ;
    int y ;
} ;
queue<tip> Q ;
vector<int> L[200] , Son[200] ;
int n , lvl ;

int main()
{
    fin >> n >> lvl ;
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
    sort ( L[lvl].begin() , L[lvl].end() ) ;
    for ( int i = 0 ; i <= L[lvl].size() - 1 ; ++i )
        fout << L[lvl][i] << ' ' ;
    return 0;
}
