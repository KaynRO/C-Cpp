#include <bits/stdc++.h>
#define NMAX 1130
#define INF ( 1 << 29 )

using namespace std ;

ofstream fout ( "trip.out" ) ;

bool inQueue[NMAX] , vis[NMAX] ;
int source, destination, nr_comp, N, M ;
int dist[NMAX] , SOL ;
int Level[NMAX], minLevel[NMAX], Back[NMAX], Cost[NMAX][NMAX] ;

vector < int >  Comp[NMAX], Which[NMAX], G[NMAX] ;  // Which[i] = toate componentele biconexe in care se afla nodul x
vector < int > path1, path2 ;
stack < int > S ;
queue < int > Q ;

bool cmp ( int x, int y )
{
    return Comp[x].size() > Comp[y].size() ; // nodul x il punem in componenta cea mai mare
}

void addComponent ( int from, int to )
{
    ++nr_comp ;
    while ( S.top() != to )
    {
        int node = S.top() ;
        S.pop() ;
        Comp[nr_comp].push_back(node), Which[node].push_back(nr_comp) ;
    }
    Comp[nr_comp].push_back(S.top()), Which[S.top()].push_back(nr_comp),S.pop() ;
    Comp[nr_comp].push_back(from), Which[from].push_back(nr_comp) ;
}

void DFS ( int node, int prev )
{
    Level[node] = Level[prev] + 1 ;
    minLevel[node] = Level[node] ;
    S.push(node) ;
    for ( vector < int > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
        if ( Level[*it] == 0 )
        {
            DFS ( *it, node ) ;
            minLevel[node] = min ( minLevel[*it], minLevel[node] ) ;
            if ( minLevel[*it] >= Level[node] ) // gasesc defapt o muchie de intoarcere
                addComponent( node, *it ) ;  // creez nr_componenta cu toate nodurile de la node la *it
        }
        else
            minLevel[node] = min ( minLevel[node], Level[*it] ) ;
}

void make_cost()
{
    for ( int i = 1 ; i <= N ; i++ )
        if ( Which[i].size() != 0 )
        {
            sort ( Which[i].begin(), Which[i].end(), cmp ) ; // tin minte doar componenta cea mai mare
            int aux = Which[i][0] ;
            Which[i].clear(), Which[i].push_back(aux) ;
        }
    for ( int i = 1 ; i < N ; i++ )
        for ( int j = i + 1 ; j <= N ; j++ )
            if ( Which[i].size() != 0 && Which[j].size() != 0 && Which[i][0] == Which[j][0] ) // daca sunt aceeasi componenta costul este 0
                Cost[i][j] = Cost[j][i] = 0 ;
}

void bellman_ford()
{
    SOL = INF ;
    for ( int i = 1 ; i <= N ; i++ )
        dist[i] = INF, Back[i] = i ;
    inQueue[source] = true ;
    dist[source] = 0 ;
    Q.push(source) ;
    while ( !Q.empty() )
    {
        int node = Q.front() ;
        int distance = dist[node] ;
        Q.pop() ;
        for ( vector < int > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
        {
            if ( distance + Cost[node][*it] >= dist[*it] || distance + Cost[node][*it] >= SOL )
                continue ;
            dist[*it] = distance + Cost[node][*it] ;
            Back[*it] = node ;
            if ( *it == destination )
            {
                SOL = dist[*it] ;
                continue ;
            }
            if ( !inQueue[*it] )
            {
                Q.push(*it) ;
                inQueue[*it] = true ;
            }

        }
    }
    fout << SOL << '\n' ; // costul minim de la sursa la destinatie
}

void make_path1()
{
    int node = destination ;
    while ( node != source )
    {
        path1.push_back(node) ;  // ma intorc pe drumul minim gasit
        node = Back[node] ;
    }
    path1.push_back(source) ;
    for ( int i = path1.size() - 1 ; i >= 0 ; i-- )
        fout << path1[i] << ' ' ;
    fout << '\n' ;

}

void BDFS( int node )
{
    vis[node] = 1 ;
    if ( node == source )
    {
        for ( int j = 0 ; j <= path2.size() - 1 ; j++ )
            fout << path2[j] << ' ' ;
        exit(0) ;
    }
    else
    {
        for ( vector < int > :: iterator it = G[node].begin() ; it != G[node].end() ; ++it )
            if ( Cost[node][*it] != -1 && !vis[*it] )
            {
                path2.push_back(*it) ;
                BDFS(*it) ;
                path2.pop_back() ;
            }
    }
}

void make_path2()
{
    for ( int i = 0 ; i <= path1.size() - 2 ; i++ )
        if ( Cost[path1[i]][path1[i + 1]] == 0 ) Cost[path1[i]][path1[i + 1]] = Cost[path1[i + 1]][path1[i]] = -1 ;
    path2.push_back(destination) ; // marchez muchiile care nu sunt critice ca sa stiu sa nu le aleg din nou si fac un DFS
    BDFS(destination) ;
}

void read()
{
    int x, y ;
    freopen ( "trip.in", "r", stdin ) ;
    scanf ( "%d %d", &source, &destination ) ;
    scanf ( "%d %d", &N, &M ) ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf ( "%d %d", &x, &y ) ;
        G[x].push_back(y) ;
        G[y].push_back(x) ;
    }
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = i + 1 ; j <= N ; j++ )
            Cost[i][j] = Cost[j][i] = 1 ;
}

int main()
{
    read() ;
    DFS( 1, 0 ) ;
    make_cost() ;
    bellman_ford() ;
    make_path1() ;
    make_path2() ;
    return 0 ;
}
