#include <iostream>
#include <bits/stdc++.h>
#define NMAX 200010

using namespace std ;

vector < int > G[NMAX] , rootDivs ;
int A[NMAX] , N , x , y , solZero[NMAX] , cnt[NMAX] ;
bitset < NMAX > vis ;

int GCD( int x , int y ){

    if ( x == 0 ) return y ;
    if ( y == 0 ) return x ;

    while ( y != 0 ){
        int r = x % y ;
        x = y ;
        y = r ;
    }
    return x ;
}

void read(){

    cin >> N ;

    for ( int i = 1 ; i <= N ; i++ ){
        cin >> A[i] ;
    }

    for ( int i = 1 ; i <= N - 1 ; i++ ){
        cin >> x >> y ;
        G[x].push_back(y) ;
        G[y].push_back(x) ;
    }

}

void DFS( int node , int factor ){

    vis[node] = 1 ;
    int value = GCD( A[node] , factor ) ;
    solZero[node] = value ;

    for ( auto it : G[node] ){
        if ( !vis[it] )
            DFS( it , value ) ;
    }
}

void lvlDFS( int node , int lvl ){

    vis[node] = 1 ;

    for ( int i = 0 ; i < rootDivs.size() ; i++ )
        if ( A[node] % rootDivs[i] == 0 )
            cnt[i]++ ;

    for ( int i = 0 ; i < rootDivs.size() ; i++ )
        if ( cnt[i] >= lvl - 1 ) {
            solZero[node] = max(solZero[node], rootDivs[i]);
            break;
        }

    for ( auto it : G[node] )
        if ( !vis[it] )
            lvlDFS( it , ++lvl ) ;

    for ( int i = 0 ; i < rootDivs.size() ; i++ )
        if ( A[node] % rootDivs[i] == 0 )
            cnt[i]-- ;

}
void solve(){

    int rootFactor = A[1] ;
    A[1] = 0 ;
    //DFS(1 , 0) ;
    solZero[1] = rootFactor ;
    A[1] = rootFactor ;

    for ( int i = 1 ; i * i <= rootFactor ; i++ ) {
        if (rootFactor % i != 0) continue;
        rootDivs.push_back(i);
        int value = rootFactor / i;
        if (value != i)
            rootDivs.push_back(value);
    }

    sort ( rootDivs.begin() , rootDivs.end() , greater<int>() ) ;
    vis.reset() ;
    lvlDFS(1 , 1) ;

    for ( int i = 1 ; i <= N ; i++ )
        cout << solZero[i] << ' ' ;

}

int main() {

    read() ;
    solve() ;

    return 0 ;
}