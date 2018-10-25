#include <bits/stdc++.h>

using namespace std ;

vector < long long > A, B ;
vector < long long > :: iterator it ;
int N, M, value ;

int main()
{
    cin >> N >> M ;
    for ( int i = 1 ; i <= N ; i++ )
        cin >> value, A.push_back(value) ;
    for ( int i = 1 ; i <= M ; i++ )
        cin >> value, B.push_back(value) ;

    sort ( A.begin(), A.end() ) ;

    for ( int i = 0 ; i < M ; i++ )
    {
        it = lower_bound(A.begin(), A.end(), B[i]);
        while (*it == B[i])
            ++it;
        cout << it - A.begin() << ' ' ;
    }
    return 0;
}
