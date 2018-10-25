#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#define NMAX 100000

using namespace std ;

ifstream fin ( "fazan.in" ) ;
ofstream fout ( "fazan.out" ) ;

int T , N ;
map < string , vector < string > > Mx , Mz ;
map < string , int > vis ;
vector < string > W ;

void build_graph()
{
    for ( auto it : W  )
        for ( auto iq : W )
            if ( it != iq )
            {
                string x = it ;
                string y = iq ;
                if ( x[x.size() - 1] == y[0] )
                {
                    Mx[x].push_back(y) ;
                    Mz[y].push_back(x) ;
                }
            }
}

void solve()
{
    build_graph() ;
    int ok = 0 ;
    int nrx = 0 , nrz = 0 ;
    for ( vector < string > :: iterator it = W.begin() ; it != W.end() ; ++it )
    {
        if ( Mx[*it].size() > 2 || Mz[*it].size() > 2 )
        {
            fout << "0" ;
            ok = 1 ;
            break ;
        }
        if ( Mx[*it].size() == 1 && Mz[*it].size() != 1)
            nrx++ ;
        if ( Mz[*it].size() == 1 && Mx[*it].size() != 1)
            nrz++ ;
    }
    if ( nrx != 1 && nrz != 1 )
    {
        fout << "0" ;
        ok = 1 ;
    }
    if ( ok == 0 )
        fout << "1" ;
    fout << '\n' ;
}

void read()
{
    string info  ;
    fin >> T ;
    for ( int i = 1 ; i <= T ; i++ )
    {
        fin >> N ;
        for ( int j = 1 ; j <= N ; j++ )
        {
            fin >> info ;
            W.push_back(info) ;
        }
        solve() ;
        W.clear() ;
        Mx.clear() ;
        Mz.clear() ;
        vis.clear() ;
    }
}

int main()
{
    read() ;
    return 0 ;
}
