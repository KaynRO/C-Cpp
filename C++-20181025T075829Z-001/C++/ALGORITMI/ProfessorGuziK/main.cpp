#include <bits/stdc++.h>
#define NMAX 2010

using namespace std ;

int elemA, elemB, x , BB[NMAX*NMAX] , start , sA , sB , A[NMAX] , B[NMAX] , aIndex , bIndex , sol , value , sAA , sBB ;
vector < pair < int , pair < int , int > > > tmpB ;
vector < pair < int , int > > aux ;
pair < int , int > best ;

long long F( long long i )
{
    return abs ( sAA + BB[i] - ( sBB - BB[i] ) ) ;
}

int main()
{
    cin >> elemA ;
    for ( int i = 1 ; i <= elemA ; i++ )
        cin >> A[i] , sA += A[i] ;

    cin >> elemB ;
    for ( int i = 1 ; i <= elemB ; i++ )
        cin >> B[i] , sB += B[i] ;


    for ( int i = 1 ; i <= elemB ; i++ )
    for ( int j = i + 1 ; j <= elemB ; j++ )
        {
            BB[++start] = B[i] + B[j] ;
            tmpB.push_back( make_pair( BB[start] , make_pair(i,j) ) ) ;
        }

    sort( tmpB.begin() , tmpB.end() ) ;

    for ( unsigned int i = 0 ; i < tmpB.size() ; i++ )
        aux[i + 1] = tmpB[i].second ;

    sort ( BB + 1 , BB + start ) ;

    sol = min( sol , abs(sA - sB) ) ;

    for ( int i = 1 ; i <= elemA ; i++ ) // o singura schimbare
        for ( int j = 1 ; j <= elemB ; j++ )
        {
            if ( sol > abs( sA - A[i] + B[j] - ( sB + A[i] - B[j] ) ) )
            {
                sol = abs( sA - A[i] + B[j] - ( sB + A[i] - B[j] ) ) ;
                aIndex = i ;
                bIndex = j ;
            }
        }

    for ( int i = 1 ; i <= elemA ; i++ )
        for ( int j = i + 1 ; j <= elemB ; j++ )
        {
            value = A[i] + A[j] ;
            sAA = sA - value ;
            sBB = sB + value ;
            pair < int , int > temp = make_pair(i , j) ;

            int begPos = 1 , endPos = start - 1 ;
            int a1 = 0 , a2 = 0 ;
            long long p , q ;
            while ( begPos < endPos )
            {
                long long l1 = begPos + ( h - l ) / 3 ;
                long long l2 = begPos + ( 2 * ( h - l ) ) / 3 ;
                p = F(l1) , q = F(l2) ;
                if ( p <= q && sol > p )
                {
                    sol = p ;
                    bbPos = l1 ;
                    best = temp ;
                }
            }
        }


    return 0 ;
}
