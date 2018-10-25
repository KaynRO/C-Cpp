#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <bitset>
#define NMAX 20510

using namespace std ;

ofstream fout ( "nr.out" ) ;

bitset <NMAX> used ;
vector < int > divs, SOL ;
int number, V[NMAX];
set < int > S ;

int lowest_factor ( int N )
{
    divs.clear() ;
    S.clear() ;
    for ( int i = 2 ; i * i <= N ; i++ )
        if ( N % i == 0 )
            divs.push_back(i), divs.push_back( N / i ) ;
    divs.push_back(N) ;
    for ( vector < int > :: iterator it = divs.begin() ; it != divs.end() ; ++it )
    {
        int nr = *it ;
        while ( nr <= NMAX )
        {
            S.insert(nr) ;
            nr += (*it) ;
        }
    }
    for ( set < int > :: iterator it = S.begin() ; it != S.end() ; ++it )
        if ( used[*it] == 0 )
            return *it ;
    return 0 ;
}

void solve ( int number )
{
    int st = 2 ;
    used.reset() ;
    if ( number == 1 ) fout << "1" << ' ' << "1" << '\n' ;
    else if ( number == 2 ) fout << "2" << ' ' << "2" << '\n' ;
    else
    {
        V[1] = 1, V[2] = 2, used[1] = 1, used[2] = 1 ;
        while( V[st] != number )
        {
            st++, V[st] = lowest_factor(V[st - 1]) ;
            used[V[st]] = 1 ;
        }

        fout << number << ' ' << st << '\n' ;
    }
}

int main()
{
    for ( int i = 1 ; i <= NMAX ; i++ )
        solve(i) ;
    return 0 ;
}
