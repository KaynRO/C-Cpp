#include <bits/stdc++.h>

using namespace std ;

multiset < int, greater < int > > S ;
multiset < int, greater < int > > :: iterator it ;

int boats, N, C, B ;

ofstream fout ( "barci.out" ) ;

void read()
{
    int value ;
    freopen ( "barci.in", "r", stdin ) ;
    scanf ( "%d %d %d", &N, &C, &B ) ;
    for ( int i = 1 ; i <= N ; i++ )
        scanf ( "%d", &value ), S.insert(value) ; // setul S sorteaza automat valorile descrescator oricand efectuam o operatie
}

void solve()
{
    boats = 0 ;
    while ( !S.empty() )
    {
        int element = *S.begin() ; // luam cel mai greu elev
        S.erase(S.begin()) ; // il eliminam caci el sigur vine intr-o barca
        int maxim = C - element ;
        int minim = element - B ; // vedem ce greutate trebuie sa aiba un elev pentru a fi in barca cu el
        if ( minim > maxim || maxim < 0 ) // daca nu exista il punem singur
        {
            boats++ ;
            continue ;
        }
        else
        {
            it = S.lower_bound(maxim) ; // ideea problemei este ca pentru elevul X sa cautam cel mai greu elev
            if ( *it < minim ) // care respecta conditia problemei
            {
                boats++ ;
                continue ;
            }
            if ( it != S.end() )
                S.erase(it) ;  // am gasit elevul , il stergem si pe el
            boats++ ; // am completat barca
        }
    }
    fout << boats ;
}

int main()
{
    read() ;
    solve() ;
    return 0;
}
