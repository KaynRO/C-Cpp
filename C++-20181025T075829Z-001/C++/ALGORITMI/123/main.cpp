#include <fstream>

using namespace std;

ifstream fin ( "123.in" ) ;
ofstream fout ( "123.out" ) ;

int lenght , v[400000] , pattern , last , sol ;
int dp[5][400000] ; // cati de i sunt dupa pozitia j in vector

void precalculeaza()
{
    for ( int i = 1 ; i <= 3 ; i++ )
        for ( int j = 1 ; j <= lenght ; j++ )
            if ( v[j] == i )
                for ( int k = 1 ; k <= j - 1 ; k++ )
                    dp[i][k] ++ ;
}


int main()
{
    fin >> lenght ;
    fin >> pattern ;
    for ( int i = 1 ; i <= lenght ; i++ )
        fin >> v[i] ;
    precalculeaza() ;
    int cif1 = pattern / 10 ;
    int cif2 = pattern / 10 % 10 ;
    int cif3 = pattern / 100 ;
    for ( int i = 2 ; i <= lenght - 1 ; i++ )
        if ( v[i] == cif2 )
        {
            int x = dp[cif3][1] - dp[cif3][i] ;
            int y = dp[cif1][i] ;
            sol = sol + x * y ;
        }
    fout << sol ;

    return 0;
}
