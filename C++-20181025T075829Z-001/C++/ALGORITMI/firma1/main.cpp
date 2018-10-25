#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

ifstream fin ( "firma1.in" ) ;
ofstream fout ( "firma1.out" ) ;

struct tip
{
    int x ;
    int y ;
} ;
queue<tip> Q ;
vector<int> L[200] , Son[200] ;
int n , S[200] ;

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
    int maxlevel ;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> S[i] ;
    for ( int i = n ; i >= 1 ; i-- )
        if ( L[i].size() > 0 )
        {
            maxlevel = i ;
            break ;
        }
    double sonsum = 0 ;
    for ( int i = maxlevel - 1 ; i >= 1; i-- )
        for ( vector<int> :: iterator it = L[i].begin() ; it != L[i].end() ; ++it )
        {
            sonsum = 0 ;
            for ( vector<int> :: iterator iq = Son[*it].begin() ; iq != Son[*it].end() ; ++iq )
                sonsum += S[*iq] ;
            if ( sonsum != 0 )
                sonsum = sonsum / Son[*it].size() ;
            if ( sonsum  > int(sonsum)  )
                sonsum = int(sonsum) + 1 ;
            S[*it] += sonsum ;
        }
    fout << S[radix] ;
    return 0;
}
