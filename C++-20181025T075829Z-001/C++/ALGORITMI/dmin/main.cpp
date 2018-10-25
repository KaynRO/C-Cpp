#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#define NMAX 1600
#define MOD 104659
#define PHI 0.0000001
#define INF 1e40
#define mp make_pair

using namespace std ;

ofstream fout ( "dmin.out" ) ;

int N , M , paths[NMAX] , inQueue[NMAX] ;
double dist[NMAX] ;
vector < pair < int , double > > TT[NMAX] ;
queue < int > Q ;


void read()
{
    int x , y , cost ;
    freopen ( "dmin.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &N , &M ) ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        scanf ( "%d %d %d" , &x , &y , &cost ) ; // logaritmam costul pentru a nu lucra cu numere mari si pentru ca log(a*b) = log a + log b
        TT[x].push_back( mp( y , log(cost) ) ) ;
        TT[y].push_back( mp( x , log(cost) ) ) ;
    }
    for ( int i = 2 ; i <= N ; i++ )
        dist[i] = INF ;
}

void bellman_ford()
{
    Q.push(1);
    inQueue[1] = 1;
    paths[1] = 1;

    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        for ( vector < pair < int , double > > :: iterator it = TT[node].begin() ; it != TT[node].end() ; ++it )
        {
            int current = it->first ;
            if( dist[current] - PHI > dist[node] + it->second ) // daca am gasit o distanta mai mica o modificam pe cea curenta si punem nodul in coada
            {
                dist[current] = dist[node] + it->second;
                paths[current] = paths[node];
                if(inQueue[current] == 0)
                {
                    Q.push(current);
                    inQueue[current] = 1;
                }
            }
            else
            {
                if(dist[current] + PHI >= dist[node] + it->second ) // daca distantele sunt egale, reactualizam numarul de drumuri
                {
                    paths[current] += paths[node];
                    paths[current] %= MOD ;
                }

            }
        }
    }

    for ( int i = 2 ; i <= N ; i++ )
        fout << paths[i] << ' ' ;
}


int main()
{
    read() ;
    bellman_ford() ;
    return 0;
}
