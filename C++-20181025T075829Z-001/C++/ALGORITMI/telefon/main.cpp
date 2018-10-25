#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ofstream fout ( "telefon.out" ) ;

int vecin[100010] , frunza[100010] , n , gr[100010] , vis[100010] , initial[100010] , nrcicluri , startciclu ;
queue <int>  myqueue ;

void read()
{
    freopen ( "telefon.in" , "r" , stdin ) ;
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        scanf ( "%d" , &vecin[i] ) ;
        initial[i] = vecin[i] ;
        gr[vecin[i]]++ ;
    }
}

void choose()
{
    for ( int i = 1 ; i <= n ; i++ )
        if ( gr[i] == 0 )
            myqueue.push(i) ;
}

void solve()
{
    int inceput = 0 , sfarsit = 0 , nrfrunza = 0 , frunza , nod ;
    while ( !myqueue.empty() )
    {
        nrfrunza++;
        frunza = myqueue.front() ;
        myqueue.pop() ;
        vis[frunza] = 1 ;
        nod = frunza ;
        while ( vis[vecin[nod]] == 0 )
        {
            vis[vecin[nod]] = 1 ;
            nod = vecin[nod] ;
        }
        if ( inceput == 0 ) inceput = nod ;
        if ( sfarsit == 0 ) sfarsit = nod ;
        vecin[nod] = inceput ;
        inceput = frunza ;
    }
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( vis[i] == 0 )
        {
            nrcicluri = 0 ;
            nrcicluri++ ;
            startciclu = i ;
            nod = startciclu ;
            vis[nod] = 1 ;
            while ( vis[vecin[nod]] == 0 )
            {
                vis[vecin[nod]] = 1 ;
                nod = vecin[nod] ;
            }
            if ( inceput == 0 ) inceput = nod ;
            if ( sfarsit == 0 ) sfarsit = nod ;
            vecin[nod] = inceput ;
            inceput = startciclu ;
        }

    }
    vecin[sfarsit] = inceput ;
    int nrmodificari ;
    nrmodificari = nrfrunza + nrcicluri ;
    fout << nrmodificari ;
}

int main()
{
    read() ;
    choose() ;
    solve() ;
    fout << '\n' ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( vecin[i] != initial[i] )
            fout << i << ' ' << vecin[i] << '\n' ;
    return 0;
}
