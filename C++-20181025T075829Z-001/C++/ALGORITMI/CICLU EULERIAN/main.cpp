#include <bits/stdc++.h>
#define NMAX 100100

using namespace std ;

ofstream fout( "ciclueuler.out" ) ;

int N , M ;
bool is_eulerian ;
vector < int >  Path ;
vector < int > :: iterator it ;
list < int > TT[NMAX] ;

void read()
{
    int x , y ;
    freopen( "ciclueuler.in" , "r" , stdin ) ;
    scanf( "%d %d" , &N , &M ) ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf( "%d %d" , &x , &y ) ;
        TT[x].push_back(y) ;
        TT[y].push_back(x) ;
    }
}

void build_path( int start )
{
    stack < int > S ;
    S.push(start) ;
    while ( !S.empty() )
    {
        int node = S.top() ;
        if ( TT[node].size() == 0 )
        {
            S.pop() ;
            Path.push_back(node) ;
        }
        else
        {
            int next = TT[node].front() ;
            TT[node].pop_front() ;
            TT[next].erase(find(TT[next].begin() , TT[next].end() , node ) ) ;
            S.push(next) ;
        }
    }
}

int main()
{
    is_eulerian = true ;
    read() ;
    for ( int i = 1 ; i <= N ; i++ )
        if ( TT[i].size() % 2 == 1 && TT[i].size() )
        {
            is_eulerian = false ;
            break ;
        }
    if ( !is_eulerian )
        fout << "-1" ;
    else
    {
        build_path(1) ;
        if ( Path.size() == 0 )
            fout << "-1" ;
        else
            for ( it = Path.begin() ; it != Path.end() ; ++it )
                fout << *it << ' ' ;
    }
}

