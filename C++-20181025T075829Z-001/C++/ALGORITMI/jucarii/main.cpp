#include <fstream>
#include <vector>
#include <algorithm>

using namespace std ;

ifstream fin ( "jucarii.in" ) ;
ofstream fout ( "jucarii.out" ) ;

int N , k , p , current_index ;
vector < int > element ;

int SCM()
{
    int dp[15] = {0} , maxim ;
    dp[ N - 1 ] = 1 ;
    for ( int i = N - 2 ; i >= 0 ; i-- )
    {
        maxim = 0 ;
        for ( int j = i + 1 ; j <= N - 1 ; j++ )
            if ( dp[j] > maxim && element[i] < element[j] )
                maxim = dp[j] ;
        dp[i] = maxim + 1 ;
    }
    for ( int i = 0 ; i <= N - 1 ; i++ )
        if ( dp[i] >= k )
            return 1 ;
    return 0 ;
}

int main()
{
    fin >> N >> k >> p ;
    for ( int i = 1 ; i <= N ; i++ )
        element.push_back(i) ;
    do
    {
        if ( SCM() == 1 )
            current_index++ ;
        if ( current_index == p )
        {
            for ( int i = 0 ; i <= N - 1 ; i++ )
                fout << element[i] << ' ' ;
            break ;
        }
    }
    while ( next_permutation( element.begin() , element.end() ) ) ;
    return 0;
}
