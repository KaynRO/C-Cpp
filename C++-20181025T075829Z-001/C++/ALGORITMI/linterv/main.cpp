#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define NMAX 5010

using namespace std ;

ofstream fout ( "linterv.out" ) ;

struct interv
{
    int st ;
    int dr ;
}I[NMAX];

vector < interv > V ;
int T , N , a , b ;
interv myInt ;

bool compare ( interv X , interv Y )
{
    if ( X.st == Y.st )
        return X.dr < Y.dr ;
    else return X.st < Y.st ;
}

void solve()
{
    sort ( V.begin() , V.end() , compare ) ;
    I[1].st = V[0].st , I[1].dr = V[0].dr ;
    int pos = 1 , sum = 0 ;
    for ( vector < interv > :: iterator it = V.begin() ; it != V.end() ; ++it )
    {
        interv now = *it ;
        if ( now.st >= I[pos].dr )
        {
            pos++ ;
            I[pos].st = now.st , I[pos].dr = now.dr ;
        }
        else if ( now.st < I[pos].dr && now.dr > I[pos].dr )
            I[pos].dr = now.dr ;
    }
    for ( int i = 1 ; i <= pos ; i++ )
        sum += I[i].dr - I[i].st ;

    fout << sum << '\n' ;
}

void read()
{
    freopen ( "linterv.in", "r", stdin ) ;
    scanf( "%d", &T ) ;
    for ( int i = 1 ; i <= T ; i++ )
    {
        scanf( "%d", &N ) ;
        for ( int j = 1 ; j <= N ; j++ )
        {
            scanf( "%d %d", &a , &b ) ;
            myInt.st = a, myInt.dr = b ;
            V.push_back(myInt) ;
        }
        solve() ;
        V.clear() ;
    }
}

int main()
{
    read() ;
    return 0;
}
