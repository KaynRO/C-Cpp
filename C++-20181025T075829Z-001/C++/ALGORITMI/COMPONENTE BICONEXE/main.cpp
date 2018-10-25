#include <bits/stdc++.h>
#define NMAX 100100

using namespace std ;

ofstream fout ( "biconex.out" ) ;

vector < int > TT[NMAX] ;
vector < vector < int > > Comp ;
int Level[NMAX], minLevel[NMAX] ;
stack < int > S ;

int N, M, comp ;


void read()
{
    int x, y ;
    freopen ( "biconex.in", "r", stdin ) ;
    scanf ( "%d %d", &N, &M ) ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf ( "%d %d", &x, &y ) ;
        TT[x].push_back(y) ;
        TT[y].push_back(x) ;
    }
}

void addComponent ( int from, int to )
{
    vector < int > Sol ;
    while ( S.top() != to )
    {
        Sol.push_back(S.top()) ;
        S.pop() ;
    }
    Sol.push_back(S.top()) ;
    S.pop() ;
    Sol.push_back(from) ;
    sort (Sol.begin(), Sol.end()) ;
    Comp.push_back(Sol) ;
}

void DFS ( int node, int prev )
{
    Level[node] = Level[prev] + 1 ;
    minLevel[node] = Level[node] ;
    S.push(node) ;
    for ( vector < int > :: iterator it = TT[node].begin() ; it != TT[node].end() ; ++it )
        if ( Level[*it] == 0 )
        {
            DFS ( *it, node ) ;
            minLevel[node] = min ( minLevel[*it], minLevel[node] ) ; // tinem minte cel mai mic nivel unde se poate ajunge din node
            if ( minLevel[*it] >= Level[node] ) // gasesc defapt o muchie de intoarcere
                addComponent( node, *it ) ;  // creez componenta cu toate nodurile de la node la *it
        }
        else
            minLevel[node] = min ( minLevel[node], Level[*it] ) ;
}

int main()
{
    read() ;
    DFS( 1, 0 ) ;
    fout << Comp.size() << '\n' ;
    for ( vector < vector < int > > :: iterator it = Comp.begin() ; it != Comp.end() ; ++it )
    {
        vector < int > nodes = *it ;
        for ( vector < int > :: iterator im = nodes.begin() ; im != nodes.end() ; ++im)
            fout << *im << ' ' ;
        fout << '\n' ;
    }
    return 0 ;
}
