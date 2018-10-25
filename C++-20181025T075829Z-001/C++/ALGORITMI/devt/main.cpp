#include <bits/stdc++.h>
#define NMAX 100010

using namespace std ;

ifstream fin ( "devt.in" ) ;
ofstream fout ( "devt.out" ) ;

int N, A[NMAX], idx, T, prime[NMAX], hp[NMAX], lessP[NMAX] ;

// lessP[i] = cate numere neprime sunt pana la i
// hp[i] = cate numere prime sunt pana la i
// prime[i] = 0 daca i este prim , altfel prime[i] = 1 ;

void Eratostene()
{
    prime[1] = 1 ;
    for ( int i = 2 ; i <= N ; ++i )
    {
        if ( prime[i] == 0 )
            for ( int j = i + i ; j <= N ; j += i )
                prime[j] = 1 ;
    }
}

void compute()
{
    hp[1] = 0 ;
    hp[2] = 0 ;
    for ( int i = 2 ; i <= N ; i++ )
        if ( prime[i] == 0 )
            hp[i + 1] = hp[i] + 1 ; // daca i este prim atunci = cate numere prime sunt pana la ( i - 1 ) + 1
        else hp[i + 1] = hp[i] ;
    for ( int i = 1 ; i <= N ; i++ )
        lessP[i] = i - 1 - hp[i] ; // cate numere sunt pana la i - cate numere prime sunt
}

void read()
{
    int cnt = 0, st, dr ;
    fin >> N >> T ;
    Eratostene() ;
    compute() ;
    for ( int i = 1 ; i <= T ; i++ )
    {
        cnt = 0 ;
        fin >> st >> dr ;
        cnt += ( lessP[dr] - lessP[st] ) ; // cate numere sunt in interval
        if ( prime[dr] == 1 ) cnt++ ; // daca capatul din dreapta este neprim atunci mai adunam 1
        fout << cnt << '\n' ;
    }
}

int main()
{
    read() ;
    return 0;
}
