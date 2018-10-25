#include <bits/stdc++.h>
#define NMAX 1000010

using namespace std ;

int N ;
vector < int > v ;

int main()
{
    int SOL = 0, x ;
    cin >> N ;

    for ( int i = 1 ; i <= N ; i++ )
    {
        cin >> x ;
        if ( x > 0 )
            v.push_back(x) ;
    }

    sort ( v.begin(), v.end() ) ;
    N = v.size() - 1 ;

    for ( int i = 0 ; i <= N ; i++ )
        for ( int j = i + 1 ; j <= N ; j++ )
        {
            vector < int > ::iterator it = lower_bound(v.begin(), v.end(), v[i] + v[j] ) ;
            if ( it != v.end() && *it == v[i] + v[j] ) it-- ;
            if (  ( it - v.begin() ) -  ( j + 1 ) > 0 )
                SOL += ( it - v.begin() ) - ( j + 1 ) ;
        }

    cout << SOL ;
    return 0 ;
}
