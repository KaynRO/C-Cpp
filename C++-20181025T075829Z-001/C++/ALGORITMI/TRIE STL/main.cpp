#include <bits/stdc++.h>
#define MAXL 30
#define MAXN 100010
using namespace std ;

ifstream fin ( "trie.in" ) ;
ofstream fout ( "trie.out" ) ;

int N, n ;

set < string > S ;
set < string > :: iterator I ;
map < string , int >  cnt ;  // cnt[s] = de cate ori apare stringul s in sir

int cmp( string s1, string s2 ) // returneaza lungimea celui mai mare prefix comun
{
    int i, l1, l2 ;
    l1 = s1.size() , l2 = s2.size() ;

    for ( i = 0 ; i < min ( l1 , l2 ) && s1[i] == s2[i] ; i++ ) ;

    return i ;
}

int main()
{
    int test_type , v1 , v2 ;
    string w = "" ;
    w += 'z' + 1 ;

    S.insert(w)  ;

    while ( fin >> test_type >> w )
    {
        if ( test_type == 0 )
        {
            I = S.lower_bound(w) ;

            if ( *I == w ) cnt[w]++ ;
            else {
                     S.insert(w) ;
                     cnt[w] = 1 ;
                 }
        }

        if ( test_type == 1 )
        {
            I = S.lower_bound(w) ;
            cnt[w]-- ;
            if ( cnt[w] == 0 ) S.erase(I) ;
        }

        if ( test_type == 2 )
        {
            I = S.lower_bound(w) ;
            if ( *I == w ) fout << cnt[w] << '\n' ;
            else fout << "0" << '\n' ;
        }

        if ( test_type == 3 )
        {
            v1 = v2 = 0 ;
            I = S.lower_bound(w) ;

            v1 = cmp ( *I , w ) ;

            if ( I != S.begin() )
            {
                I-- ;
                v2 = cmp ( *I , w ) ;
            }

            fout << max(v1, v2) << '\n' ;
        }
    }

    return 0 ;
}
